#include "dog.h"
#include <string>

using namespace std;

//Define constructor
dog::dog(string name, string breed, string gender,
	string age, string weight, string acquisitionDate,
	string acquisitionCountry, string trainingStatus,
	bool reserved, string inServiceCountry) {
	setName(name);
	setBreed(breed);
	setGender(gender);
	setAge(age);
	setWeight(weight);
	setAcquisitionDate(acquisitionDate);
	setAcquisitionCountry(acquisitionCountry);
	setTrainingStatus(trainingStatus);
	setReserved(reserved);
	setServiceCountry(inServiceCountry);
}

//Return dog breed
string dog::getBreed() {
	return breed;
}

//Set dog breed
void dog::setBreed(string newBreed) {
	breed = newBreed;
	return;
}