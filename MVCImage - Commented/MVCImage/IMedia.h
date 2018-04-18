// Interface: IMedia
// Definition: All media type Interfaces such as IImage must implement this interface
//
// Duncan Baldwin & Adam Harris
// 01/05/2017

#pragma once

#include <string>
#include <vector>
#include <memory>

using namespace std;

struct IMedia
{
public:

	// Destructor
	virtual ~IMedia() {};

	// Method: Initialise 
	// Definition: Initialise private data
	virtual void Initialise() = 0;

	// Method: rawData
	// Definition: return a RAW pointer to the raw media data:
	// Return: unsigned char*
	virtual unsigned char* rawData() = 0;

	// Method: GetUniqueID
	// Definition: Get the unique identification of the IMedia object
	// Return: string
	virtual string GetUniqueID() = 0;

	// Method: SetUniqueID
	// Definition: Set the unique identification of the IMedia object
	// Param 1: string id
	virtual void SetUniqueID(string id) = 0;
};

