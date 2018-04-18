#pragma once

#include "stdafx.h"

#include "View.h"
#include "ImageGUI.h"

#include <FL/Fl.H>

View::View()
{
	mGui = shared_ptr<IGui>(new ImageGUI(shared_ptr<IView>(this)));
}

View::~View()
{
	/*mGui->~IGui();
	mGui.reset();*/
}

// Method: SetGui
// Definition: Gives the view class an IGui
// Param: shared_ptr<IGui>
void View::SetGui(shared_ptr<IGui> pGui)
{
	mGui = pGui;
}

// Method: GetGui
// Definition: Returns an shared_ptr<IGui> type
// Return: shared_ptr<IGui>
shared_ptr<IGui> View::GetGui()
{
	return mGui;
}

// Method: SetClicker
// Definition: Sets a controller as an IClick
// Param 1: shared_ptr<IClick>
void View::SetClicker(shared_ptr<IClick> pClick)
{
	mClick = pClick;
}

// Method: GetClicker
// Definition: Returns the controller as an IClick
// Return: shared_ptr<IClick>
shared_ptr<IClick> View::GetClicker()
{
	return mClick;
}

// Method: Run
// Definition: Runs the fltk software
void View::Run()
{
	Fl::run();
}

#pragma region IEventListener_Implementation

// Method: DataModified
// Definition: Called when key data has been modified : Event Delegate
// Param 1: shared_ptr<IEventArgs> data; the data passed to the listener from the publisher
void View::DataModified(shared_ptr<IEventArgs> data)
{
	mGui->DataModified(data);
}

#pragma endregion