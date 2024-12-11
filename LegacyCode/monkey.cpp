#include "monkey.h"
#include <string>

using namespace std;

//Define constructor
monkey::monkey(string name, string tailLength, string height, string bodyLength,
	string species, string gender, string age, string weight,
	string acquisitionDate, string acquisitionCountry, string trainingStatus,
	bool reserved, string inServiceCountry) {
	setName(name);
	setTailLength(tailLength);
	setHeight(height);
	setBodyLength(bodyLength);
	setSpecies(species);
	setGender(gender);
	setAge(age);
	setWeight(weight);
	setAcquisitionDate(acquisitionDate);
	setAcquisitionCountry(acquisitionCountry);
	setTrainingStatus(trainingStatus);
	setReserved(reserved);
	setServiceCountry(inServiceCountry);
}

//Define Accessors

//Species
string monkey::getSpecies() {
	return species;
}

//Tail Length
string monkey::getTailLength() {
	return tailLength;
}

//Height
string monkey::getHeight() {
	return tailLength;
}

string monkey::getBodyLength() {
	return bodyLength;
}

//Define mutators

//Species
void monkey::setSpecies(string newSpecies) {
	species = newSpecies;
	return;
}

//Tail Length
void monkey::setTailLength(string newTailLength) {
	tailLength = newTailLength;
	return;
}

//Height
void monkey::setHeight(string newHeight) {
	height = newHeight;
	return;
}

//Body Lenght
void monkey::setBodyLength(string newBodyLength) {
	bodyLength = newBodyLength;
	return;
}