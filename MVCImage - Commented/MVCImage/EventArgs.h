// Class: EventArgs
// Inherits from: IEventArgs
// Definition: Impelmentation of IEventArgs; used for passing data through events

// Duncan Baldwin & Adam Harris
// 01/05/2017

#pragma once

#include "IEventArgs.h"

class EventArgs : public IEventArgs
{
public:
	// Constructor:
	// Definition: Construct this class
	// Param 1: shared_ptr<IMedia> pData; the image data to be passed to the events listener
	EventArgs(shared_ptr<IMedia> pData);
	~EventArgs();

	// Method: GetData
	// Definition: Returns the image data which is stored upon using the constructor
	// Return: shared_ptr<IMedia>
	shared_ptr<IMedia> GetData();

private:
	//Declare a shared_ptr<IMedia>
	shared_ptr<IMedia> data;
};
