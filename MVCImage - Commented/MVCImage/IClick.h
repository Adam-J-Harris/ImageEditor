// Interface: IClick
// Definition: Implementation of the strategy pattern
//
// Duncan Baldwin & Adam Harris
// 01/05/2017

#pragma once

using namespace std;

#include <vector>
#include <string>

class IClick
{
public:
	virtual ~IClick() {};

	// Method: HandleClick
	// Definition: Handles a user click interaction
	// Param 1: int inputID
	// Param 2: map<IImage> imageCOntainer
	// Param 3: double transform
	// Param 4: string filePathToSave
	virtual void HandleClick(int inputID, vector<string> pathfilenames, double number, string saveFileName) = 0;
};

