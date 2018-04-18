// Class: Model
// Inherits from: IModel, IEventPublisher
// Definition: Concrete Implementation of the IModel and IEventPublisher interfaces
//
// Duncan Baldwin & Adam Harris
// 01/05/2017

#pragma once

#include <vector>
#include <map>

#include "IModel.h"
#include "IEventPublisher.h"

#include "IFactory.h"
#include "IImage.h"

class Model : public IModel, public IEventPublisher
{
public:
	Model();
	~Model();

	// Method: GetMediaItem
	// Definition: Return a media item specified by 'key':
	// Param 1: string key; unique identifier for the image to be returned
	// Return: shared_ptr<IMedia>
	shared_ptr<IMedia> GetMediaItem(string key);

	// Method: GetMediaItem
	// Definition: Return a copy of the image parameter as an IMedia
	// Param 1: shared_ptr<IImage> image; image to be converted
	// Return: shared_ptr<IMedia>
	shared_ptr<IMedia> GetMediaItem(shared_ptr<IImage> image);

#pragma region IModel_Implementation

	// Method: Decipher
	// Definition: Based on the parameter, choose the right method to alter the view
	// Param 1: int 
	void Decipher(int id, vector<string> pathfilenames, double number, string saveFileName);

#pragma endregion
	
#pragma region IEventPublisher_Implementation

	// Method: Subscribe
	// Definition: Subscribe a listener
	// Param 1: shared_ptr<IEventListener> listener; class to be subscribed to the publisher
	void Subscribe(shared_ptr<IEventListener> listener);

	// Method: Unsubscribe
	// Definition: Unsubscribe a listener
	// Param 1: shared_ptr<IEventListener> listener; class to be unsubscribed from the publisher
	void Unsubscribe(shared_ptr<IEventListener> listener);

#pragma endregion

private:

#pragma region Variables

	unique_ptr<IFactory<shared_ptr<IImage>>> imgF;

	int i = 0;

	// container which stores all listeners
	vector<shared_ptr<IEventListener>> listeners;

	// currentimage
	shared_ptr<IImage> currentImg;

	// currnetItem in image container
	int currentItem = 0;
	

	// map of all images
	map<string, shared_ptr<IImage>> imageContainer;

#pragma endregion

#pragma region Methods

	// Method: OnDataChange
	// Definition: Called when the key data has changed
	void OnDataChange();

	// Method: Load
	// Definition: Load an image or multiple images
	// Param 1: vector<string> pathfilenames; a vector of image file locations 
	void Load(vector<string> pathfilenames);

	// Method: Previous
	// Definition: Display the previous image
	void Previous();

	// Method: Next
	// Definition: Display the next image
	void Next();

	// Method: Save
	// Definition: Save the current image with specified file path
	// Param 1: string
	void Save(string savePath);

	// Method: RotateLeft
	// Definition: Rotate the current image anti-clockwise
	void RotateLeft(double number);

	// Method: RotateRight
	// Definition: Rotate the current image clockwise
	void RotateRight(double number);

	// Method: ScaleUp
	// Definition: Make it bigger
	// Param 1: double
	void ScaleUp(double scale);

	// Method: ScaleDown
	// Definition: Make image smaller
	// Param 1: double
	void ScaleDown(double scale);

	// Method: FlipHorizontal
	// Definition: Flips the current image on x-axis
	void FlipHorizontal();

	// Method: FlipVertical
	// Definition: Flips the current image on y-axis
	void FlipVertical();

#pragma endregion
};

