#include <asx/signal/Signal.h>
#include <gtest/gtest.h>

using asx::Signal;
using asx::Slot;

TEST(Signal, construct)
{
	Signal<void()> signalVoid;
	Signal<void(int)> signalInt;
	Signal<int(int)> signalIntInt;
}

TEST(Signal, connect)
{
	Signal<void()> signal;
	std::function<void()> f{[]() {}};
	signal.connect(f);
}

TEST(Signal, invoke)
{
	Signal<void()> signal;

	auto test{false};

	{
		std::function<void()> f{[&test]() { test = true; }};
		asx::Connection cx = signal.connect(f);
		signal();
		EXPECT_TRUE(test);
		EXPECT_TRUE(cx.connected());
		cx.disconnect();
	}

	test = false;
	signal();
	EXPECT_FALSE(test);
}

TEST(Signal, track)
{
	Signal<void()> signal;

	auto test{false};
	Slot<void()> slot{[&test]() { test = true; }};

	{
		auto object = std::make_shared<int>();
		slot.track(object);
		signal.connect(slot);
		signal();
		EXPECT_TRUE(test);
	}

	test = false;
	signal();
	EXPECT_FALSE(false);
}
