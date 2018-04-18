// Interface: IController
// Definition: Part of the MVC architecture
//
// Duncan Baldwin & Adam Harris
// 01/05/2017

#pragma once

#include "IView.h"
#include "IModel.h"

class IController
{
public:
	virtual ~IController() {};

	// Method: SetViewAndModel
	// Definition: Set the view and model for the controller
	// Param 1: shared_ptr<IView>
	// Param 2: shared_ptr<IModel>
	virtual void SetViewAndModel(shared_ptr<IView> view, shared_ptr<IModel> model) = 0;

	// Method: Run
	// Definition: Runs the fltk software
	virtual void Run() = 0;
};

