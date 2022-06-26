#pragma once

#include <asx/signal/Connection.h>

namespace asx
{
	class ASX_SIGNAL_EXPORT ConnectionShared : public Connection
	{
	public:
		ConnectionShared(const Connection& x);
		~ConnectionShared();

	private:
		const Connection& connection;
		int reference{};
	};
}