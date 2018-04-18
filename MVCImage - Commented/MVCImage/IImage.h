// Interface: IImage
// Inherits from: IMedia
// Definition: All concrete image classes must implement this interface
//
// Duncan Baldwin & Adam Harris
// 01/05/2017

#pragma once

#include "stdafx.h"

#include <FreeImagePlus.h>

#include "IMedia.h"

class IImage : public IMedia
{
public:

	// Destructor
	virtual ~IImage()
	{
	}

	// Method: numberOfChannels
	// Definition: Gets the number of channels used by the image file
	// Return: int
	virtual int numberOfChannels() = 0;

	// Method: GetFipImage
	// Definition: Gets the local fipImage stored in the concrete implementation of this interface
	// Return: shared_ptr<fipImage>
	virtual shared_ptr<fipImage> GetFipImage() = 0;

	// Method: SetFipImage
	// Definition: Sets the local fipImage to the parameter
	// Param 1: shared_ptr<fipImage> fipImg
	virtual void SetFipImage(shared_ptr<fipImage> fipImg) = 0;
};

