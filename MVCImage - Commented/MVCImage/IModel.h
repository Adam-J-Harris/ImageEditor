// Interface: IModel
// Definition: Part of the MVC architecture implementation, all model classes must implement this interface
//
// Duncan Baldwin & Adam Harris
// 01/05/2017

#pragma once

#include <vector>
#include <string>

#include "IMedia.h"

using namespace std;

class IModel
{
public:
	virtual ~IModel() {};

	// Method: Decipher
	// Definition: Based on the parameter, choose the right method to alter the view
	// Param 1: int id; ID of the button
	// Param 2: vector<string> pathfilenames; Names of all image file locations which the user wants to load
	// Param 3: double number; Number which can be used to alter the Scale or the Rotation of the image
	// Param 4: string saveFileName; the save file location
	virtual void Decipher(int id, vector<string> pathfilenames, double number, string saveFileName) = 0;
};

