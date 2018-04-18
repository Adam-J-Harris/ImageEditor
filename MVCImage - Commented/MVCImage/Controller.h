// Class: Controller
// Inherits from: IController, IClick
// Definition: Part of the Model-View-Controller Implementation and handles user clicks
//
// Duncan Baldwin & Adam Harris
// 01/05/2017

#pragma once

#include "IController.h"
#include "IClick.h"

class Controller : public IController, public IClick
{
public:
	Controller();
	~Controller();

#pragma region IController_Implementation

	// Method: SetViewAndModel
	// Definition: Set the view and model for the controller
	// Param 1: shared_ptr<IView>
	// Param 2: shared_ptr<IModel>
	void SetViewAndModel(shared_ptr<IView> view, shared_ptr<IModel> model);

	// Method: Run
	// Definition: Runs the fltk software
	void Run();

#pragma endregion

#pragma region IClick_Implementation

	// Method: HandleClick
	// Definition: Handles a user click interaction
	// Param 1: int inputID; the ID of the button clicked
	// Param 2: vector<string> pathfilenames; used for loading in images
	// Param 3: double number; Can be used for rotation, scaling
	// Param 4: string saveFilePath; used for saving images
	void HandleClick(int inputID, vector<string> pathfilenames, double number, string saveFileName);

#pragma endregion

private:
	//Declare a shared_ptr<IView>
	shared_ptr<IView> mView;

	//Declare a shared_ptr<IModel> 
	shared_ptr<IModel> mModel;
};

