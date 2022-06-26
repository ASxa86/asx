#pragma once

#include <asx/type/TypeTraits.h>
#include <asx/string/export.hxx>
#include <charconv>
#include <magic_enum.hpp>
#include <nlohmann/json.hpp>
#include <string>

namespace asx
{
	///
	///	\brief Special ToString overload to support floating point precision and format.
	///
	///	\param x The float to convert.
	///	\param precision The decimal precision to output.
	///	\param fmt Specify either scientific or fixed format.
	///
	ASX_STRING_EXPORT std::string ToString(float x, int precision = std::numeric_limits<float>::max_digits10,
										   std::chars_format fmt = std::chars_format::fixed);

	///
	///	\brief Special ToString overload to support floating point precision and format.
	///
	///	\param x The double to convert.
	///	\param precision The decimal precision to output.
	///	\param fmt Specify either scientific or fixed format.
	///
	ASX_STRING_EXPORT std::string ToString(double x, int precision = std::numeric_limits<double>::max_digits10,
										   std::chars_format fmt = std::chars_format::fixed);

	template <concepts::boolean T>
	std::string ToString(T x)
	{
		if(x == true)
		{
			return "true";
		}

		if(x == false)
		{
			return "false";
		}

		return {};
	}

	template <concepts::integral T>
	std::string ToString(T x)
	{
		constexpr auto digits = std::numeric_limits<T>::digits10;

		std::string s;
		s.resize(digits);

		const auto [p, ec] = std::to_chars(s.data(), s.data() + s.size(), x);

		if(!ec)
		{
			s.resize(p - s.data());
		}

		return s;
	}

	template <concepts::string T>
	std::string ToString(const T& x)
	{
		return x;
	}

	template <concepts::duration T>
	std::string ToString(T x)
	{
		return ToString(x.count());
	}

	template <concepts::container T>
	std::string ToString(const T& x)
	{
		nlohmann::json j = x;
		return j.dump();
	}

	template <typename T>
	typename std::remove_reference<T>::type FromString(std::string_view x);

	template <concepts::boolean T>
	void FromString(std::string_view x, T& t)
	{
		if(x == "true")
		{
			t = true;
		}
		else if(x == "false")
		{
			t = false;
		}
	}

	template <typename T>
	typename std::remove_reference<T>::type FromString(std::string_view x)
	{
		using TNoRef = typename std::remove_const<typename std::remove_reference<T>::type>::type;

		TNoRef t{};
		FromString(x, t);
		return t;
	}
}
