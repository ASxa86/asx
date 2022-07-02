#pragma once

#include <asx/core/Property.h>
#include <memory>
#include <vector>

namespace asx
{
	class Factory;

	class ASX_CORE_EXPORT Properties
	{
	public:
		Properties() = default;
		virtual ~Properties() = default;
		Properties(const Properties&) = delete;
		Properties(Properties&& x) noexcept = delete;
		Properties& operator=(const Properties&) = delete;
		Properties& operator=(Properties&&) noexcept = delete;

		template <typename T>
		void addBase();

		template <typename T>
		void addProperty(std::string_view name, T p)
		{
		}

		template <typename Writer, typename Reader>
		void addProperty(std::string_view name, Writer writer, Reader reader)
		{
		}

		Property* getProperty(std::string_view name) const noexcept;

		const std::vector<std::unique_ptr<Property>>& getProperties() const noexcept;

		void setFactory(Factory* x);

	private:
		std::vector<Properties*> base;
		std::vector<std::unique_ptr<Property>> properties;
		Factory* factory{};
	};
}

#include <asx/core/Factory.h>

template <typename T>
void asx::Properties::addBase()
{
	auto& p = this->factory->template registerType<T>();
	this->base.push_back(&p);
}
