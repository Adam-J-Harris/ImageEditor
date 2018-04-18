// Interface: IView
// Definition: Part of the MVC architecture, all view classes must implement this interface
//
// Duncan Baldwin & Adam Harris
// 01/05/2017

#pragma once

#include <memory>

#include "IGui.h"
#include "IClick.h"

using namespace std;

class IView
{
public:
	virtual ~IView() {};

	// Method: SetGui
	// Definition: Gives the view class an IGui
	// Param: shared_ptr<IGui>
	virtual void SetGui(shared_ptr<IGui> pGui) = 0;

	// Method: GetGui
	// Definition: Returns an shared_ptr<IGui> type
	// Return: shared_ptr<IGui>
	virtual shared_ptr<IGui> GetGui() = 0;

	// Method: SetClicker
	// Definition: Sets a controller as an IClick
	// Param 1: shared_ptr<IClick>
	virtual void SetClicker(shared_ptr<IClick> clicker) = 0;

	// Method: GetClicker
	// Definition: Returns the controller as an IClick
	// Return: shared_ptr<IClick>
	virtual shared_ptr<IClick> GetClicker() = 0;

	// Method: Run
	// Definition: Runs the fltk software
	virtual void Run() = 0;
};

