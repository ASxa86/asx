#pragma once

#include <asx/signal/Slot.h>
#include <asx/signal/export.hxx>

namespace asx
{
	class ConnectionBodyBase
	{
	public:
		virtual bool getConnected() const = 0;

		void disconnect() const
		{
			this->connected = false;
			this->releaseSlot();
		}

	protected:
		virtual void releaseSlot() const = 0;
		mutable bool connected{true};
	};

	template <typename SlotType>
	class ConnectionBody : public ConnectionBodyBase
	{
	public:
		ConnectionBody(SlotType x) : slot{std::make_shared<SlotType>(std::move(x))}
		{
		}

		bool getConnected() const override
		{
			if(this->slot == nullptr)
			{
				return this->connected;
			}

			if(this->slot->expired() == true)
			{
				this->disconnect();
			}

			return this->connected;
		}

		SlotType& getSlot()
		{
			return *this->slot;
		}

		void releaseSlot() const override
		{
			this->slot.reset();
		}

	private:
		mutable std::shared_ptr<SlotType> slot;
	};

	class ASX_SIGNAL_EXPORT Connection
	{
	public:
		Connection() = default;
		Connection(const std::weak_ptr<ConnectionBodyBase>& x);

		bool connected() const;
		void disconnect() const;

	private:
		std::weak_ptr<ConnectionBodyBase> body;
	};
}
