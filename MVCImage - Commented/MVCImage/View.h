// Class: View
// Inherits from: IView, IEventListener
// Definition: Concrete Implementation of IView and IEventListener interfaces
//
// Duncan Baldwin & Adam Harris
// 01/05/2017

#pragma once

#include "IView.h"
#include "IEventListener.h"

class View : public IView, public IEventListener
{
public:
	View();
	~View();

#pragma region IView_Implementation

	// Method: SetGui
	// Definition: Gives the view class an IGui
	// Param: shared_ptr<IGui>
	void SetGui(shared_ptr<IGui> pGui);

	// Method: GetGui
	// Definition: Returns an shared_ptr<IGui> type
	// Return: shared_ptr<IGui>
	shared_ptr<IGui> GetGui();

	// Method: SetClicker
	// Definition: Sets a controller as an IClick
	// Param 1: shared_ptr<IClick>
	void SetClicker(shared_ptr<IClick> pClick);

	// Method: GetClicker
	// Definition: Returns the controller as an IClick
	// Return: shared_ptr<IClick>
	shared_ptr<IClick> GetClicker();

	// Method: Run
	// Definition: Runs the fltk software
	void Run();

#pragma endregion

#pragma region IEventListener_Implementation

	// Method: DataModified
	// Definition: Called when key data has been modified : Event Delegate
	// Param 1: shared_ptr<IEventArgs> data; the data passed to the listener from the publisher
	void DataModified(shared_ptr<IEventArgs> data);

#pragma endregion	

private:
	shared_ptr<IGui> mGui;
	shared_ptr<IClick> mClick;
};

