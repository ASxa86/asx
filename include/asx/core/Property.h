#pragma once

#include <any>
#include <asx/core/export.hxx>
#include <string>
#include <typeinfo>

namespace asx
{

	///
	///	\brief A base class used to handle setting values to properties from a string.
	///
	class ASX_CORE_EXPORT Property
	{
	public:
		Property(std::string_view x);
		virtual ~Property() = default;

		Property(const Property&) = delete;
		Property(Property&& x) noexcept = delete;
		Property& operator=(const Property&) = delete;
		Property& operator=(Property&&) noexcept = delete;

		///
		///	\brief Get the name identifier for this property.
		///
		std::string_view getName() const noexcept;

		///
		///	\brief Override to expose the property's type information at run time.
		///
		virtual const std::type_info& getTypeInfo() const noexcept = 0;

		///
		///	\brief Override for a more performant method of setting data to the property.
		///
		/// This function will throw if the type is not the same as the underlying data type.
		///
		virtual void setValue(std::any x) = 0;

		///
		///	\brief Override for a more perfromant method of getting data to the property.
		///
		virtual std::any getValue() const = 0;

		///
		///	\brief Override to set the internal value with a string.
		///
		virtual void setValueString(std::string_view x) = 0;

		///
		///	\brief Override to get the internal value as a string.
		///
		virtual std::string getValueString() const = 0;

		///
		///	\brief Get the value by type if the type is known.
		///
		/// This function will throw if the type is not the same as the underlying type.
		///
		template <typename T>
		T getValueType() const
		{
			return std::any_cast<T>(this->getValue());
		}

		///
		///	\brief Check the underlying type of this property.
		///
		template <typename T>
		bool isType() const noexcept
		{
			return this->getTypeInfo() == typeid(T);
		}

	private:
		std::string name;
	};
}
