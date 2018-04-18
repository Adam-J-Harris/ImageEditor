#include "Controller.h"
#include "IEventListener.h"
#include "IEventPublisher.h"

#include <FL/Fl.H>

Controller::Controller()
{
}


Controller::~Controller()
{
}

#pragma region IController_Implementation

// Method: SetViewAndModel
// Definition: Set the view and model for the controller
// Param 1: shared_ptr<IView>
// Param 2: shared_ptr<IModel>
void Controller::SetViewAndModel(shared_ptr<IView> pView, shared_ptr<IModel> pModel)
{
	mView = pView;
	mModel = pModel;

	// Cast viewer to an IEventListener
	shared_ptr<IEventListener> listener = dynamic_pointer_cast<IEventListener>(mView);
	// Cast model to an IEventPublisher
	shared_ptr<IEventPublisher> publisher = dynamic_pointer_cast<IEventPublisher>(mModel);
	// Subscribe the listener to the publisher
	publisher->Subscribe(listener);
}

// Method: Run
// Definition: Runs the fltk software
void Controller::Run()
{
	Fl::run();
}

#pragma endregion

#pragma region IClick_Implementation

// Method: HandleClick
// Definition: Handles a user click interaction
// Param 1: int inputID
// Param 2: map<IImage> imageCOntainer
// Param 3: double transform
// Param 4: string filePathToSave
void Controller::HandleClick(int inputID, vector<string> pathfilenames, double number, string saveFileName)
{
	mModel->Decipher(inputID, pathfilenames, number, saveFileName);
}

#pragma endregion