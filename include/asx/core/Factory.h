#pragma once

#include <asx/type/TypeName.h>
#include <memory>
#include <unordered_map>

namespace asx
{
	class Properties;

	class Factory
	{
	public:
		template <typename T>
		asx::Properties& registerType(std::string_view x = {});

	private:
		std::unordered_map<std::string, std::unique_ptr<asx::Properties>> map;
	};
}

#include <asx/core/Properties.h>

template <typename T>
asx::Properties& asx::Factory::registerType(std::string_view x)
{
	const auto typeName = std::string{asx::TypeName<T>()};
	auto properties = this->map[typeName].get();

	if(properties == nullptr)
	{
		auto p = std::make_unique<asx::Properties>();
		p->setFactory(this);
		properties = p.get();
		this->map[typeName] = std::move(p);
	}

	return *properties;
}
