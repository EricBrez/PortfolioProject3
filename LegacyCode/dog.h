#pragma once
#ifndef DOG_H
#define DOG_H
#include "rescueAnimal.h"
#include <string>


class dog : public rescueAnimal {
public:
	//Constructor
	dog(std::string name, std::string breed, std::string gender,
		std::string age, std::string weight, std::string acquisitionDate,
		std::string acquisitionCountry, std::string trainingStatus,
		bool reserved, std::string inServiceCountry);

	//Declare accessor
	std::string getBreed();

	//Declare Mutator
	void setBreed(std::string dogBreed);

private:
	std::string breed;

};

#endif
