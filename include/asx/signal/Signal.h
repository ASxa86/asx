#pragma once

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
		void connect(std::function<R(Args...)> x)
		{
			this->slots.emplace_back(std::move(x));
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