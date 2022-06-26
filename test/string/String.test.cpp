#include <asx/string/StringConv.h>
#include <gtest/gtest.h>

TEST(String, bool)
{
	constexpr auto test{false};
	const auto string = asx::ToString(test);
	const auto value = asx::FromString<bool>(string);
	EXPECT_EQ(value, test);
}
