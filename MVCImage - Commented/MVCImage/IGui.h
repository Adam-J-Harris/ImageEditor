// Interface: IGui
// Definition: All concrete GUIs must implement this interface
// 
// Duncan Baldwin & Adam Harris
// 01/05/2017

#pragma once
#include <memory>

#include "IEventArgs.h"

using namespace std;

class IGui
{
public:
	virtual ~IGui() {};

	// Method: DataModified
	// Definition: Called when data has been changed
	// Param 1: shared_ptr<IEventArgs>
	virtual void DataModified(shared_ptr<IEventArgs> data) = 0;
};

