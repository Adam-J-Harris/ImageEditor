// MVCImage.cpp : Defines the entry point for the console application.
//
#pragma once

#include "stdafx.h"

#include "View.h"
#include "Model.h"

#include "IController.h"
#include "Controller.h"

int main()
{
	shared_ptr<IView> view = shared_ptr<IView>(new View());
	shared_ptr<IModel> model = shared_ptr<IModel>(new Model());

	shared_ptr<IController> controller = shared_ptr<IController>(new Controller());
	
	// Set the view and model for the controller
	controller->SetViewAndModel(view, model);

	// Inject an IClick type into the View
	shared_ptr<IClick> clicker = dynamic_pointer_cast<IClick>(controller);
	view->SetClicker(clicker);

	controller->Run();

    return 0;
}

