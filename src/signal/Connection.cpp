#include <asx/signal/Connection.h>

using asx::Connection;

Connection::~Connection()
{
	if(this->raii)
	{
		this->raii();
	}
}
