#include <asx/signal/ConnectionShared.h>

using asx::ConnectionShared;

ConnectionShared::ConnectionShared(const Connection& x) : connection{x}
{
	++this->reference;
}

ConnectionShared::~ConnectionShared()
{
	--this->reference;

	if(this->reference == 0)
	{
		this->connection.disconnect();
	}
}
