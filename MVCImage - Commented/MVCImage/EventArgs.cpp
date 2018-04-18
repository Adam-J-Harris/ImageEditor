#include "EventArgs.h"

// Constructor:
// Definition: Construct this class
// Param 1: shared_ptr<IMedia> pData; the image data to be passed to the events listener
EventArgs::EventArgs(shared_ptr<IMedia> pData) : data(pData)
{
}

EventArgs::~EventArgs()
{
}

// Method: GetData
// Definition: Returns the image data which is stored upon using the constructor
// Return: shared_ptr<IMedia>
shared_ptr<IMedia> EventArgs::GetData()
{
	return data;
}
