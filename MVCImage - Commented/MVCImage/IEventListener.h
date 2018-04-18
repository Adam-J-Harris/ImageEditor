// Interface: IEventListener
// Definition: Inheriting this class means can subscribe to the EventPublisher class

// Duncan Baldwin & Adam Harris
// 01/05/2017

#pragma once

#include <memory>

#include "IEventArgs.h"

using namespace std;

class IEventListener
{
public:
	virtual ~IEventListener()
	{
	}

	// Method: DataModified
	// Definition: Called when key data has been modified : Event Delegate
	// Param 1: shared_ptr<IEventArgs> data; the data passed to the listener from the publisher
	virtual void DataModified(shared_ptr<IEventArgs> data) = 0;
};

