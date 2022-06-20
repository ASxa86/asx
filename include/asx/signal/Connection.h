#pragma once

#include <asx/signal/export.hxx>
#include <functional>

namespace asx
{
	class ASX_SIGNAL_EXPORT Connection
	{
	public:
		template <typename T>
		Connection(T x)
		{
			this->raii = std::move(x);
		}

		~Connection();

	private:
		std::function<void()> raii;
	};
}
