#pragma once

#include <asx/core/Properties.h>

namespace asx
{
	class ASX_CORE_EXPORT Object : public Properties
	{
	public:
		Object();

		void setID(std::string_view x);
		std::string_view getID() const;

		virtual bool addChild(std::shared_ptr<Object> x) = 0;
		virtual bool removeChild(std::shared_ptr<Object> x) = 0;
		virtual bool clearChildren() = 0;

		virtual void iterate(const std::function<void(std::shared_ptr<Object>)>& x);

	private:
		std::string id;
	};
}
