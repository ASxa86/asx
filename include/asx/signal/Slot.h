#pragma once

#include <functional>
#include <vector>

namespace asx
{
	template <typename T>
	class Slot;

	template <typename R, typename... Args>
	class Slot<R(Args...)>
	{
	public:
		using ResultType = R;
		using Signature = R(Args...);

		Slot(std::function<Signature> x) : function{std::move(x)}
		{
		}

		ResultType operator()(Args... args)
		{
			if(this->function)
			{
				return this->function(std::forward<Args>(args)...);
			}
		}

		ResultType operator()(Args... args) const
		{
			if(this->function)
			{
				return this->function(std::forward<Args>(args)...);
			}
		}

		bool expired() const
		{
			for(auto& weak : this->trackedObjects)
			{
				if(weak.expired() == true)
				{
					return true;
				}
			}

			return false;
		}

		void track(const std::weak_ptr<void>& x)
		{
			this->trackedObjects.push_back(x);
		}

	private:
		std::function<Signature> function;
		std::vector<std::weak_ptr<void>> trackedObjects;
	};
}