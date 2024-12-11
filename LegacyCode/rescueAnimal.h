#pragma once
#ifndef RESCUEANIMAL_H
#define RESCUEANIMAL_H

#include <string>


class rescueAnimal {

public:
	//Declare default constructor
	rescueAnimal();
	//Declare accessors
	std::string getName();
	std::string getAnimalType();
	std::string getGender();
	std::string getAge();
	std::string getWeight();
	std::string getDate();
	std::string getAcquisitionCountry();
	std::string getTrainingStatus();
	bool getReserved();
	std::string getServiceCountry();


	//Declare mutators
	void setName(std::string newName);
	void setType(std::string newType);
	void setGender(std::string newGender);
	void setAge(std::string newAge);
	void setWeight(std::string newWeight);
	void setAcquisitionDate(std::string newAcquisitionDate);
	void setAcquisitionCountry(std::string newAcquisitionCountry);
	void setTrainingStatus(std::string newTrainingStatus);
	void setReserved(bool newReserved);
	void setServiceCountry(std::string newInServiceCountry);

	//Ideclare Private Class Variables
private:
	std::string name;
	std::string animalType;
	std::string gender;
	std::string age;
	std::string weight;
	std::string acquisitionDate;
	std::string acquisitionCountry;
	std::string trainingStatus;
	bool reserved;
	std::string inServiceCountry;



};

#endif