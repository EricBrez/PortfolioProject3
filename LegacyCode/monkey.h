#pragma once
#ifndef MONKEY_H
#define MONKEY_H
#include "rescueAnimal.h"
#include <string>

class monkey : public rescueAnimal {
public:
	//Declare constructor
	monkey(std::string name, std::string tailLength, std::string height, std::string bodyLength,
		std::string species, std::string gender, std::string age, std::string weight,
		std::string acquisitionDate, std::string acquisitionCountry, std::string trainingStatus,
		bool reserved, std::string inServiceCountry);

	//Declare accessors
	std::string getSpecies();
	std::string getTailLength();
	std::string getHeight();
	std::string getBodyLength();

	//Declare mutators
	void setSpecies(std::string newSpecies);
	void setTailLength(std::string newTailLength);
	void setHeight(std::string newHeight);
	void setBodyLength(std::string newBodyLength);

private:
	//Declare Monkey specific variables
	std::string species;
	std::string tailLength;
	std::string height;
	std::string bodyLength;

};

#endif
