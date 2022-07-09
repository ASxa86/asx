#pragma once

#include <asx/core/Property.h>
#include <asx/string/StringConv.h>

namespace asx
{
	///
	///	\brief This class manages ReflProp for public class member variables.
	///
	template <typename T>
	class PropertyTemplateMember : public Property
	{
	public:
		PropertyTemplateMember(std::string_view n, T& p) : Property{n}, property{p}
		{
		}

		void setValue(std::any value) override
		{
			this->property = std::any_cast<T>(value);
		}

		std::any getValue() const override
		{
			return this->property;
		}

		virtual void setValueString(std::string_view x) override
		{
			asx::FromString<T>(x, this->property);
		}

		virtual std::string getValueString() const override
		{
			return asx::ToString(this->property);
		}

		virtual const std::type_info& getTypeInfo() const noexcept override
		{
			return typeid(T);
		}

	private:
		T& property;
	};
}
