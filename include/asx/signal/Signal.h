#pragma once

#include <asx/signal/Connection.h>
#include <deque>
#include <functional>

namespace asx
{
	template <typename T>
	class Signal;

	template <typename R, typename... Args>
	class Signal<R(Args...)>
	{
	public:
		decltype(auto) connect(std::function<R(Args...)> x)
		{
			// If object is copied, track the connection.
			// Else, do not disconnect.

			this->slots.emplace_back(std::move(x));
			auto it = std::end(this->slots);
			it--;

			return [it, this] { this->slots.erase(it, std::end(this->slots)); };
		}

		R operator()(Args... args)
		{
			for(auto slot : this->slots)
			{
				slot(std::forward<Args>(args)...);
			}
		}

	private:
		std::deque<std::function<R(Args...)>> slots;
	};
}