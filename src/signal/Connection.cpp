#include <asx/signal/Connection.h>

using asx::Connection;

Connection::Connection(const std::weak_ptr<ConnectionBodyBase>& x) : body{x}
{
}

bool Connection::connected() const
{
	auto cx = this->body.lock();

	if(cx != nullptr)
	{
		return cx->getConnected();
	}

	return false;
}

void Connection::disconnect() const
{
	auto cx = this->body.lock();

	if(cx != nullptr)
	{
		cx->disconnect();
	}
}
