#include <asx/core/Property.h>

using asx::Property;

Property::Property(std::string_view x) : name{x}
{
}

std::string_view Property::getName() const noexcept
{
	return this->name;
}
