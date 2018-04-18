#include "Model.h"
#include "EventArgs.h"

#include "ImageFactory.h"

#include <iostream>

using namespace std;

Model::Model()
{
	imgF = unique_ptr<IFactory<shared_ptr<IImage>>>(new ImageFactory());

	imageContainer = map<string, shared_ptr<IImage>>();
}

Model::~Model()
{
}

// Method: Decipher
// Definition: Based on the parameter, choose the right method to alter the view
// Param 1: int 
void Model::Decipher(int id, vector<string> pathfilenames, double number, string saveFileName)
{

	switch (id)
	{
	case 1:
		Load(pathfilenames);
		break;
	case 2:
		Previous();
		break;
	case 3:
		Next();
		break;
	case 4:
		Save(saveFileName);
		break;
	case 5:
		RotateLeft(number);
		break;
	case 6:
		RotateRight(number);
		break;
	case 7:
		FlipHorizontal();
		break;
	case 8:
		FlipVertical();
		break;
	case 9:
		ScaleUp(number);
		break;
	case 10:
		ScaleDown(number);
		break;
	}

	OnDataChange();
}

#pragma region IEventPublisher_Implementation

// Method: Subscribe
// Definition: Subscribe a listener
// Param 1: shared_ptr<IEventListener> listener; class to be subscribed to the publisher
void Model::Subscribe(shared_ptr<IEventListener> listener)
{
	// Add the listener to the 'listeners' container
	listeners.push_back(listener);
}

// Method: Unsubscribe
// Definition: Unsubscribe a listener
// Param 1: shared_ptr<IEventListener> listener; class to be unsubscribed from the publisher
void Model::Unsubscribe(shared_ptr<IEventListener> listener)
{
	// Remove listener from the 'listeners' container
	//listeners.erase(listener);

	//listeners.erase(remove(listeners.begin(), listeners.end(), listener), listeners.end());
}

#pragma endregion

// Method: OnDataChange
// Definition: Called when the key data has changed
void Model::OnDataChange()
{
	// Create an IEventArgs 
	shared_ptr<IEventArgs> data = shared_ptr<IEventArgs>(new EventArgs(currentImg));

	// Create an iterator of IEventListeners
	vector<shared_ptr<IEventListener>>::iterator it;
	// Loop through the listeners
	for (it = listeners.begin(); it != listeners.end(); it++)
	{
		// Tell listener through dereferencing that data has changed
		(*it)->DataModified(data);
	}
}

// Method: GetMediaItem
// Definition: Return a media item specified by 'key':
// Param 1: string key; unique identifier for the image to be returned
// Return: shared_ptr<IMedia>
shared_ptr<IMedia> Model::GetMediaItem(string key)
{
	// Get the element using the unique ID
	shared_ptr<IMedia> local = dynamic_pointer_cast<IMedia>(imageContainer.at(key));

	// Make sure the element has been found
	//cout << local->GetUniqueID() << endl;

	// Return element
	return local;
}

// Method: GetMediaItem
// Definition: Return a copy of the image parameter as an IMedia
// Param 1: shared_ptr<IImage> image; image to be converted
// Return: shared_ptr<IMedia>
shared_ptr<IMedia> Model::GetMediaItem(shared_ptr<IImage> image)
{
	shared_ptr<IMedia> returnMe = dynamic_pointer_cast<IMedia>(image);
	return returnMe;
}

// Method: Load
// Definition: Load an image or multiple images
void Model::Load(vector<string> pathfilenames)
{
	cout << "Load... Model.cpp" << endl;

	// PROCEED only if imageFiles contains some strings:
	if (pathfilenames.size() > 0)
	{
		// Iterate using a iterator through the vector<string> pathfilenames
		for (vector<string>::iterator it = pathfilenames.begin(); it != pathfilenames.end(); it++)
		{
			// Create a unique identification to assign to the IImage object
			const string uid = "Image" + to_string(i);

			try
			{
				//cout << uid << " ImageModel.cpp Line 29" << endl;
				// Create a shared_ptr<IImage> and intialise to the imgF->Create(): pass the uid and pathfilenames current element
				shared_ptr<IImage> image = imgF->Create(uid, *it);

				//cout << uid << " ImageModel.cpp Line 31" << endl;
				// Insert the image field into the imageContainer 
				imageContainer.insert(pair<string, shared_ptr<IImage>>(uid, image));
			}
			catch (bool b)
			{
				if (!b)
				{
					cout << "File path must have extension of .png or .jpg - the following file is invalid" << endl;
					cout << *it << endl << endl;
					i--;
				}
			}

			// Increment i
			i++;
		}

		currentItem = 0;
		currentImg = imageContainer.at("Image" + to_string(currentItem));
	}
}

// Method: Previous
// Definition: Display the previous image
void Model::Previous()
{
	cout << "Previous... Model.cpp" << endl;	

	try
	{
		if (currentImg == nullptr)
		{
			throw(true);
		}

		if (currentItem <= 0)
		{
			currentItem = imageContainer.size();
		}

		currentImg = imageContainer.at("Image" + to_string(--currentItem));
	}
	catch (bool b)
	{
		cout << "No data selected;" << endl;
		cout << "Please use the 'Load' button to load an item." << endl;
	}
}

// Method: Next
// Definition: Display the next image
void Model::Next()
{
	cout << "Next... Model.cpp" << endl;

	try
	{
		if (currentImg == nullptr)
		{
			throw(true);
		}

		if (currentItem + 1 >= imageContainer.size())
		{
			currentItem = -1;
		}

		currentImg = imageContainer.at("Image" + to_string(++currentItem));
	}
	catch (bool b)
	{
		cout << "No data selected;" << endl;
		cout << "Please use the 'Load' button to load an item." << endl;
	}
}

// Method: Save
// Definition: Save the current image with specified file path
// Param 1: string
void Model::Save(string savePath)
{
	cout << "Next... Model.cpp" << endl;

	try
	{
		if (currentImg == nullptr)
		{
			throw(true);
		}

		currentImg->GetFipImage()->flipVertical();

		currentImg->GetFipImage()->save(savePath.c_str());

		currentImg->GetFipImage()->flipVertical();
	}
	catch (bool b)
	{
		cout << "No data selected;" << endl;
		cout << "Please use the 'Load' button to load an item." << endl;
	}
}

// Method: RotateLeft
// Definition: Rotate the current image anti-clockwise
void Model::RotateLeft(double rot)
{
	cout << "Next... Model.cpp" << endl;

	try
	{
		if (currentImg == nullptr)
		{
			throw(true);
		}

		currentImg->GetFipImage()->rotate(rot);
	}
	catch (bool b)
	{
		cout << "No data selected;" << endl;
		cout << "Please use the 'Load' button to load an item." << endl;
	}
}

// Method: RotateRight
// Definition: Rotate the current image clockwise
void Model::RotateRight(double rot)
{
	cout << "Next... Model.cpp" << endl;

	try
	{
		if (currentImg == nullptr)
		{
			throw(true);
		}

		currentImg->GetFipImage()->rotate(-rot);
	}
	catch (bool b)
	{
		cout << "No data selected;" << endl;
		cout << "Please use the 'Load' button to load an item." << endl;
	}
}

// Method: FlipHorizontal
// Definition: Flips the current image on x-axis
void Model::FlipHorizontal()
{
	cout << "Next... Model.cpp" << endl;

	try
	{
		if (currentImg == nullptr)
		{
			throw(true);
		}

		currentImg->GetFipImage()->flipHorizontal();
	}
	catch (bool b)
	{
		cout << "No data selected;" << endl;
		cout << "Please use the 'Load' button to load an item." << endl;
	}
}

// Method: FlipVertical
// Definition: Flips the current image on y-axis
void Model::FlipVertical()
{
	cout << "Next... Model.cpp" << endl;

	try
	{
		if (currentImg == nullptr)
		{
			throw(true);
		}

		currentImg->GetFipImage()->flipVertical();
	}
	catch (bool b)
	{
		cout << "No data selected;" << endl;
		cout << "Please use the 'Load' button to load an item." << endl;
	}
}

// Method: ScaleUp
// Definition: Make it bigger
// Param 1: double
void Model::ScaleUp(double scale)
{
	cout << "Next... Model.cpp" << endl;

	try
	{
		if (currentImg == nullptr)
		{
			throw(true);
		}

		currentImg->GetFipImage()->rescale((currentImg->GetFipImage()->getWidth() / scale) + currentImg->GetFipImage()->getWidth()
			, (currentImg->GetFipImage()->getHeight() / scale) + currentImg->GetFipImage()->getHeight(), FILTER_CATMULLROM);
	}
	catch (bool b)
	{
		cout << "No data selected;" << endl;
		cout << "Please use the 'Load' button to load an item." << endl;
	}
}

// Method: ScaleDown
// Definition: Make image smaller
// Param 1: double
void Model::ScaleDown(double scale)
{
	cout << "Next... Model.cpp" << endl;

	try
	{
		if (currentImg == nullptr)
		{
			throw(true);
		}

		currentImg->GetFipImage()->rescale(currentImg->GetFipImage()->getWidth() - (currentImg->GetFipImage()->getWidth() / scale)
			, currentImg->GetFipImage()->getHeight() - (currentImg->GetFipImage()->getHeight() / scale), FILTER_CATMULLROM);
	}
	catch (bool b)
	{
		cout << "No data selected;" << endl;
		cout << "Please use the 'Load' button to load an item." << endl;
	}
}