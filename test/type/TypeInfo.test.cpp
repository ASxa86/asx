#include <asx/type/TypeInfo.h>
#include <gtest/gtest.h>

namespace asx
{
	class TypeOne
	{
	};

	struct TypeTwo
	{
	};
}

TEST(TypeInfo, typeName_struct)
{
	constexpr std::string_view test = asx::TypeName<asx::TypeTwo>();
	EXPECT_EQ(test, "asx::TypeTwo");
}

TEST(TypeInfo, typeName_class)
{
	constexpr std::string_view test = asx::TypeName<asx::TypeOne>();
	EXPECT_EQ(test, "asx::TypeOne");
}
