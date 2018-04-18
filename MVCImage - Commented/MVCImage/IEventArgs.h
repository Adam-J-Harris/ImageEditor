// Interface: IEventArgs
// Definition: Used for getting access to variables from listeners

// Duncan Baldwin & Adam Harris
// 01/05/2017

#pragma once

#include <memory>
#include "IMedia.h"

using namespace std;

class IEventArgs
{
public:
	virtual ~IEventArgs()
	{
	}

	// Method: GetData
	// Definition: Returns the image data which is stored upon using the constructor
	// Return: shared_ptr<IMedia>
	virtual shared_ptr<IMedia> GetData() = 0;
};