#include <asx/core/Factory.h>
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

TEST(Factory, registerType)
{
	asx::Factory factory;

	{
		auto& p = factory.registerType<Derived>();
		p.addBase<Base>();
		p.addProperty("z", &Derived::setZ, &Derived::getZ);
	}

	{
		auto& p = factory.registerType<Base>();
		p.addProperty("x", &Base::setX, &Base::getX);
		p.addProperty("y", &Base::setY, &Base::getY);
	}
}
