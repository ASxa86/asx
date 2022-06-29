#pragma once

#include <asx/core/Property.h>
#include <memory>
#include <vector>

namespace asx
{
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
		void addProperty(std::string_view name, T& p)
		{
		}

		template <typename Writer, typename Reader>
		void addProperty(std::string_view name, Writer writer, Reader reader)
		{
		}

		Property* getProperty(std::string_view name) const noexcept;

		const std::vector<std::unique_ptr<Property>>& getProperties() const noexcept;

	private:
		std::vector<std::unique_ptr<Property>> properties;
	};
}