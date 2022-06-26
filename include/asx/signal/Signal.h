#pragma once

#include <asx/signal/Connection.h>
#include <asx/signal/Slot.h>

namespace asx
{
	template <typename T>
	class Signal;

	template <typename R, typename... Args>
	class Signal<R(Args...)>
	{
	public:
		using SlotType = Slot<R(Args...)>;

		Connection connect(Slot<R(Args...)> x)
		{
			auto connection = std::make_shared<ConnectionBody<SlotType>>(SlotType{std::forward<SlotType>(x)});
			this->connections.emplace_back(connection);
			return Connection{connection};
		}

		R operator()(Args... args)
		{
			auto copy = this->connections;
			for(const auto& connection : copy)
			{
				if(connection->getConnected() == false)
				{
					this->connections.erase(std::find(std::begin(this->connections), std::end(this->connections), connection),
											std::end(this->connections));
				}
			}

			for(const auto& connection : this->connections)
			{
				connection->getSlot()(std::forward<Args>(args)...);
			}

			// return combine.result();
			// return {};
		}

	private:
		std::vector<std::shared_ptr<ConnectionBody<SlotType>>> connections;
	};
}