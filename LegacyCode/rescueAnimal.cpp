#include "rescueAnimal.h"

#include <string>

using namespace std;

rescueAnimal::rescueAnimal() {
	string name = "none";
	string animalType = "none";
	string gender = "none";
	string age = "none";
	string weight = "none";
	string acquisitionDate = "none";
	string acquisitionCountry = "none";
	string trainingStatus = "none";
	bool reserved = false;
	string inServiceCountry = "none";
}

//Accessors

//Return animal name
string rescueAnimal::getName() {
	return name;
}

//Return animal type
string rescueAnimal::getAnimalType() {
	return animalType;
}

//Return animal's gender
string rescueAnimal::getGender() {
	return gender;
}

//Return animal's age
string rescueAnimal::getAge() {
	return age;
}

//Return animal's weight
string rescueAnimal::getWeight() {
	return weight;
}

//Return animal's acquisition date
string rescueAnimal::getDate() {
	return acquisitionDate;
}

//Return animal's acquisition country
string rescueAnimal::getAcquisitionCountry() {
	return acquisitionCountry;
}

//Return animal's training status
string rescueAnimal::getTrainingStatus() {
	return trainingStatus;
}

//Return if reserved
bool rescueAnimal::getReserved() {
	return reserved;
}

//Return service country
string rescueAnimal::getServiceCountry() {
	return inServiceCountry;
}


//Mutators

//set animal name
void rescueAnimal::setName(string newName) {
	name = newName;
}

//set animal type
void rescueAnimal::setType(string newType) {
	animalType = newType;
}

//set animal gender
void rescueAnimal::setGender(string newGender) {
	gender = newGender;
}

//Set animal age
void rescueAnimal::setAge(string newAge) {
	age = newAge;
}

//set animal weight
void rescueAnimal::setWeight(string newWeight) {
	weight = newWeight;
}

//set aquisition date
void rescueAnimal::setAcquisitionDate(string newAcquisitionDate) {
	acquisitionDate = newAcquisitionDate;
}

//set aquisition country
void rescueAnimal::setAcquisitionCountry(string newAcquisitionCountry) {
	acquisitionCountry = newAcquisitionCountry;
}

//set training status
void rescueAnimal::setTrainingStatus(string newTrainingStatus) {
	trainingStatus = newTrainingStatus;
}

//set reserved
void rescueAnimal::setReserved(bool newReserved) {
	reserved = newReserved;
}

//set inService Country
void rescueAnimal::setServiceCountry(string newInServiceCountry) {
	inServiceCountry = newInServiceCountry;
}

