// Interface: IEventPublisher
// Definition: Any class that publishes events must implement this

// Duncan Baldwin & Adam Harris
// 01/05/2017

#pragma once

#include <memory>

#include "IEventListener.h"

using namespace std;

class IEventPublisher
{
public:
	virtual ~IEventPublisher()
	{
	}

	// Method: Subscribe
	// Definition: Subscribe a listener
	// Param 1: shared_ptr<IEventListener> listener; class to be subscribed to the publisher
	virtual void Subscribe(shared_ptr<IEventListener> listener) = 0;

	// Method: Unsubscribe
	// Definition: Unsubscribe a listener
	// Param 1: shared_ptr<IEventListener> listener; class to be unsubscribed from the publisher
	virtual void Unsubscribe(shared_ptr<IEventListener> listener) = 0;
};