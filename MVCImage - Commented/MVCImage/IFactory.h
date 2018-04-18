// Interface: IFactory
// Definition: Implementation of the Factory Pattern
//
// Duncan Baldwin & Adam Harris
// 01/05/2017

#pragma once
#include <memory>
#include <string>

using namespace std;

template<class T>
class IFactory
{
public:

	// Destructor
	virtual ~IFactory()
	{
	}

	// Method: Create
	// Definition: Factory Method Pattern
	// Param 1: string uID; a unique ID which will be applied to the created object
	// Param 2: string fileName; the fileName were the object is located
	// Return: T; Generic class which should be IMedia to allow for multiple type polymorphism
	virtual T Create(string uID, string fileName) = 0;
};

