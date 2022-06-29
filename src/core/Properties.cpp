#include <asx/core/Properties.h>

using asx::Properties;

asx::Property* Properties::getProperty(std::string_view x) const noexcept
{
	const auto foundIt = std::find_if(std::begin(this->properties), std::end(this->properties), [x](auto&& p) { return x == p->getName(); });

	if(foundIt != std::end(this->properties))
	{
		return foundIt->get();
	}

	return {};
}

const std::vector<std::unique_ptr<asx::Property>>& Properties::getProperties() const noexcept
{
	return this->properties;
}
