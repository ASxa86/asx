#include <asx/core/Properties.h>
#include <gtest/gtest.h>

namespace
{
	class Base
	{
	public:
		void setX(int xx)
		{
			this->x = xx;
		}

		int getX() const
		{
			return this->x;
		}

		void setY(int xx)
		{
			this->y = xx;
		}

		int getY() const
		{
			return this->y;
		}

	private:
		int x;
		int y;
	};

	class Derived : public Base
	{
	public:
		void setZ(int xx)
		{
			this->z = xx;
		}

		int getZ() const
		{
			return this->z;
		}

	private:
		int z;
	};
}

TEST(Properties, test)
{
	asx::Factory factory;

	{
		auto& type = factory.registerType<Derived>();
		type.addBase<Base>();
		type.addProperty("z", &Derived::setZ, &Derived::getZ);
	}

	{
		auto& type = factory.registerType<Base>();
		type.addProperty("x", &Base::setX, &Base::getX);
		type.addProperty("y", &Base::setY, &Base::getY);
	}
}
