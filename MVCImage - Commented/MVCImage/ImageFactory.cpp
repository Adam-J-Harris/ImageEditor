#pragma once

#include "ImageFactory.h"
#include "Image.h"

ImageFactory::ImageFactory()
{
}

ImageFactory::~ImageFactory()
{
}

// Method: Create
// Definition: Factory Method Pattern
// Param 1: string uID; a unique ID which will be applied to the created object
// Param 2: string fileName; the fileName were the object is located
// Return: shared_ptr<IImage>
shared_ptr<IImage> ImageFactory::Create(string uID, string fileName)
{
	// Create a shared_ptr to a fipimg
	shared_ptr<fipImage> fipimg(new fipImage());
	// Create a shared_ptr to an IImage
	shared_ptr<IImage> img(new Image());

	// Load the image using the const char field
	if (fipimg->load(fileName.c_str()))
	{
		// Informs the user that the fileName is valid and has been loaded
		cout << "File path valid" << endl;

		// Flip the fipimg object
		fipimg->flipVertical();

		// Set the img objects fipImage value using img->SetFipImage()
		img->SetFipImage(fipimg);
		// Set the img objects fipImage value using img->SetUniqueID()
		img->SetUniqueID(uID);

		// Initialise the image
		img->Initialise();
	}
	else
	{
		// Inform the user that the file path selected is not a valid file path
		throw (false);
	}

	// return img object
	return img;
}
