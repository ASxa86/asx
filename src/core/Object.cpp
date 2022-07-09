#include <asx/core/Object.h>

using asx::Object;

Object::Object()
{
	this->addProperty("id", this->id);
}

void Object::setID(std::string_view x)
{
	this->id = x;
}

std::string_view Object::getID() const
{
	return this->id;
}
