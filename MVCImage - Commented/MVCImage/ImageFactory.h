// Class: ImageFactory
// Inherits from: IFactory<shared_ptr<IImage>
// Definition: Factory to create objects of type IImage
//
// Duncan Baldwin & Adam Harris
// 01/05/2017

#pragma once

#include "stdafx.h"

#include <string>
#include <iostream>
#include <memory>

#include <FreeImagePlus.h>

#include "IFactory.h"
#include "IImage.h"

using namespace std;

class ImageFactory : public IFactory<shared_ptr<IImage>>
{
public:
	ImageFactory();
	~ImageFactory();

	// Method: Create
	// Definition: Factory Method Pattern
	// Param 1: string uID; a unique ID which will be applied to the created object
	// Param 2: string fileName; the fileName were the object is located
	// Return: shared_ptr<IImage>
	shared_ptr<IImage> Create(string uID, string fileName);
};

