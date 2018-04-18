// Class: Image
// Inherits from: IImage
// Definition: Concrete implementation of the IImage interface and IMedia interface
//
// Duncan Baldwin & Adam Harris
// 01/05/2017

#pragma once

#include "IMedia.h"
#include "IImage.h"

using namespace std;

class Image : public IImage
{
private:
	// DECLARE a reference to the raw data, call it _rawData:
	unsigned char* _rawData;

	// DECLARE a string, call it uniqueID
	string uniqueID;

	// DECLARE a reference to the fipImage object, call it image:
	shared_ptr<fipImage> image;

public:
	Image() {}
	~Image() {}

#pragma region IMedia_Implementation

	// Method: Initialise 
	// Definition: Initialise private data
	void Initialise()
	{
		// Test to make sure the image is initialised
		//cout << image->getWidth() << " " << image->getHeight() << endl;
		// Set _rawData to the images pixels
		_rawData = image->accessPixels();
	}

	// Method: rawData
	// Definition: return a RAW pointer to the raw media data:
	// Return: unsigned char*
	unsigned char* rawData()
	{
		return _rawData;
	};

	// Method: GetUniqueID
	// Definition: Get the unique identification of the IMedia object
	// Return: string
	string GetUniqueID()
	{
		return uniqueID;
	}

	// Method: SetUniqueID
	// Definition: Set the unique identification of the IMedia object
	// Param 1: string id
	void SetUniqueID(string id)
	{
		uniqueID = id;
	}

#pragma endregion

#pragma region IImage_Implementation

	// Method: GetFipImage
	// Definition: Gets the local fipImage stored in the concrete implementation of this interface
	// Return: shared_ptr<fipImage>
	shared_ptr<fipImage> GetFipImage()
	{
		return image;
	}

	// Method: SetFipImage
	// Definition: Sets the local fipImage to the parameter
	// Param 1: shared_ptr<fipImage> fipImg
	void SetFipImage(shared_ptr<fipImage> fipImg)
	{
		image = fipImg;
		// Test to make sure image has been set correctly
		cout << image->getWidth() << " width. " << image->getHeight() << " height." << endl << endl;
	}

	// Method: numberOfChannels
	// Definition: Gets the number of channels used by the image file
	// Return: int
	int numberOfChannels()
	{
		// DECLARE an unsigned short to hold the return value (either 1, 3, or 4), call it rtnVal:
		int rtnVal = 1;

		// SET rtnVal = 4 if (and only if) the 'FREE_IMAGE_COLOR_TYPE' of image = 4:
		unsigned int bpp = image->getBitsPerPixel();
		if (bpp == 24)
		{
			rtnVal = 3;
		}
		else if (bpp == 32)
		{
			rtnVal = 4;
		}

		return rtnVal;
	}

#pragma endregion
};

