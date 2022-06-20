#include <asx/signal/Signal.h>
#include <gtest/gtest.h>

using asx::Signal;

TEST(Signal, construct)
{
	Signal<void()> signalVoid;
	Signal<void(int)> signalInt;
	Signal<int(int)> signalIntInt;
}

TEST(Signal, connect)
{
	Signal<void(int)> signal;

	signal.connect([](int) {});
}

TEST(Signal, invoke)
{
	Signal<void(int)> signal;

	auto test{false};
	signal.connect([&test](int) { test = true; });
	signal(0);
	EXPECT_TRUE(test);
}
