#include <iostream>
#include <stdexcept>
#include <vector>
#include <string>

#include "dog.h"
#include "monkey.h"
#include "rescueAnimal.h"

using namespace std;

vector<dog> dogList; //Create global dog list vector
vector<monkey> monkeyList; //Create global monkey list vector

void initializeDogList() { //create three new dog to prevent an empty vector
	dog dog1 = dog("Spot", "German Shepherd", "male", "1", "25.6", "05-12-2019", "United States", "intake", false, "United States");
	dog dog2 = dog("Rex", "Great Dane", "male", "3", "35.2", "02-03-2020", "United States", "Phase I", false, "United States");
	dog dog3 = dog("Bella", "Chihuahua", "female", "4", "25.6", "12-12-2019", "Canada", "in service", true, "Canada");

	dogList.push_back(dog1);
	dogList.push_back(dog2);
	dogList.push_back(dog3);
}

void initializeMonkeyList() { //create three new monkeys to prevent an empty vector
	monkey monkey1 = monkey("Kumquat", "13", "14", "9", "Capuchin", "female", "2", "9.7", "07-04-1776", "England", "intake", false, "United States");
	monkey monkey2 = monkey("Grapeseed", "13", "14", "9", "Tamarin", "male", "1", "0.9", "12-15-1997", "United States", "intake", true, "United States");
	monkey monkey3 = monkey("Lettuce", "13", "14", "9", "Guenon", "female", "3", "9.6", "03-13-1984", "United States", "intake", true, "United States");

	monkeyList.push_back(monkey1);
	monkeyList.push_back(monkey2);
	monkeyList.push_back(monkey3);
}

char printMenu() {
	char menuChoice;
	cout << endl << endl;
	cout << "Rescue Animal System Menu" << endl;
	cout << "1 - Intake new dog" << endl;
	cout << "2 - Print a list of all dogs" << endl;
	cout << "3 - Intake a new monkey" << endl;
	cout << "4 - Print a list of all monkeys" << endl;
	cout << "5 - Print list of all available animals" << endl;
	cout << "6 - Reserve an animal" << endl;
	cout << "q - Quit" << endl << endl;
	cout << "Enter selection" << endl;
	cin >> menuChoice;

	return menuChoice;

}

void intakeNewAnimal(string animalType) {
	//Declare variables
	string name;
	string gender;
	string age;
	string weight;
	string acquisitionDate;
	string acquisitionCountry;
	string trainingStatus;
	string isReserved;
	bool reserved;
	string inServiceCountry;


	cout << "What is the animal's name?" << endl;
	cin >> name;
	cout << endl << "What gender is the dog?" << endl;
	cin >> gender;
	cout << endl << "How old is the animal?" << endl;
	cin >> age;
	cout << endl << "How much does the animal weigh?" << endl;
	cin >> weight;
	cout << endl << "What is today's date?" << endl;
	cin >> acquisitionDate;
	cout << endl << "What country is the animal from?" << endl;
	cin >> acquisitionCountry;
	cout << endl << "What is the training status?" << endl;
	cin >> trainingStatus;
	cout << endl << "Is the animal reserved? yes or no" << endl;
	cin >> isReserved;
	if (isReserved == "yes") {
		reserved = true;
	}
	else if (isReserved == "no") {
		reserved = false;
	}
	else {
		cout << "Invalid answer, defaulting to \"no\". If this is incorrect, please edit after entry creation" << endl;
		reserved = false;
	}
	cout << endl << "What country will the animal be serving in?" << endl;
	cin >> inServiceCountry;

	if (animalType == "dog") {
		string breed;
		cout << endl << "What breed is the dog?" << endl;
		cin >> breed;

		for (int i = 0; i < dogList.size(); ++i) { //Run Check for dog already existing in the list of dogs
			if (name == dogList.at(i).getName()) {
				if (breed == dogList.at(i).getBreed()) {
					if (gender == dogList.at(i).getGender()) {
						if (age == dogList.at(i).getAge()) {
							if (weight == dogList.at(i).getWeight()) {
								if (acquisitionCountry == dogList.at(i).getAcquisitionCountry()) {
									if (inServiceCountry == dogList.at(i).getServiceCountry()) {
										cout << "That dog is already in our system, please double check the information" << endl;
										return;
									}
								}
							}
						}
					}
				}
			}
		}
		dog newDog = dog(name, breed, gender, age, weight, acquisitionDate, acquisitionCountry, trainingStatus, reserved, inServiceCountry);
		dogList.push_back(newDog);
		return;
	}
	else if (animalType == "monkey") {
		string tailLength;
		string height;
		string bodyLength;
		string species;

		cout << endl << "How long is the monkey's tail?" << endl;
		cin >> tailLength;
		cout << endl << "How tall is the monkey?" << endl;
		cin >> height;
		cout << endl << "How long is the monkey's body?" << endl;
		cin >> bodyLength;
		cout << endl << "What species is the monkey?" << endl;
		cin >> species;

		for (int i = 0; i < monkeyList.size(); ++i) { //Run check to see if monkey already exists in the system and return if it does
			if (name == monkeyList.at(i).getName()) {
				if (tailLength == monkeyList.at(i).getTailLength()) {
					if (height == monkeyList.at(i).getHeight()) {
						if (bodyLength == monkeyList.at(i).getBodyLength()) {
							if (species == monkeyList.at(i).getSpecies()) {
								if (gender == monkeyList.at(i).getGender()) {
									if (age == monkeyList.at(i).getAge()) {
										if (weight == monkeyList.at(i).getWeight()) {
											if (acquisitionCountry == monkeyList.at(i).getAcquisitionCountry()) {
												if (inServiceCountry == monkeyList.at(i).getServiceCountry()) {
													cout << "That monkey is already in our system, please double check the information" << endl;
													return;
												}
											}
										}
									}
								}
							}
						}
					}
				}

			}
		}

		monkey newMonkey = monkey(name, tailLength, height, bodyLength, species, gender, age, weight, acquisitionDate, acquisitionCountry, trainingStatus, reserved, inServiceCountry);
		monkeyList.push_back(newMonkey);
		return;
	}

	
}

void reserveAnimal() {
	string type;
	string serviceCountry;

	cout << endl << "Enter the animal type needed" << endl;
	cin >> type;
	if (type == "monkey" || type == "dog") {
		cout << "Enter the service country" << endl;
		cin >> serviceCountry;
		if (type == "monkey") {
			for (int i = 0; i < monkeyList.size(); ++i) {
				if (monkeyList.at(i).getReserved() == false && monkeyList.at(i).getServiceCountry() == serviceCountry && monkeyList.at(i).getTrainingStatus() == "in-service") {
					monkeyList.at(i).setReserved(true);
					cout << monkeyList.at(i).getName() << " in " << serviceCountry << " has been reserved" << endl;
					return;
				}
			}
		}
		else if (type == "dog") {
			for (int i = 0; i < dogList.size(); ++i) {
				if (dogList.at(i).getReserved() == false && dogList.at(i).getServiceCountry() == serviceCountry && dogList.at(i).getTrainingStatus() == "in-service") {
					dogList.at(i).setReserved(true);
					cout << dogList.at(i).getName() << " in " << serviceCountry << " has been reserved" << endl;
					return;
				}
			}
		}
	}
	else {
		cout << "There are no available " << type << "s at this time" << endl;
		return;
	}
}

void printAnimalLists(string animalsToPrint) {
	if (animalsToPrint == "dog") {
		for (int i = 0; i < dogList.size(); ++i) {
			cout << "Name: " << dogList.at(i).getName() << endl;
			cout << "Training status: " << dogList.at(i).getTrainingStatus() << endl;
			cout << "Acquisition country: " << dogList.at(i).getAcquisitionCountry() << endl;
			if (dogList.at(i).getReserved() == true) {
				cout << "Reserved" << endl << endl;
			}
			else if (dogList.at(i).getReserved() == false) {
				cout << "Available" << endl << endl;
			}
		}
	}

	else if (animalsToPrint == "monkey") {
		for (int i = 0; i < monkeyList.size(); ++i) {
			cout << "Name: " << monkeyList.at(i).getName() << endl;
			cout << "Training status: " << monkeyList.at(i).getTrainingStatus() << endl;
			cout << "Acquisition country: " << monkeyList.at(i).getAcquisitionCountry() << endl;
			if (monkeyList.at(i).getReserved() == true) {
				cout << "Reserved" << endl << endl;
			}
			else if (monkeyList.at(i).getReserved() == false) {
				cout << "Available" << endl << endl;
			}
		}
	}

	else if (animalsToPrint == "available") {
		for (int i = 0; i < dogList.size(); ++i) {
			if (dogList.at(i).getReserved() == false) {
				cout << "Name: " << dogList.at(i).getName() << endl;
				cout << "Training status: " << dogList.at(i).getTrainingStatus() << endl;
				cout << "Acquisition country: " << dogList.at(i).getAcquisitionCountry() << endl;
			}
		}
		for (int i = 0; i < monkeyList.size(); ++i) {
			if (monkeyList.at(i).getReserved() == false) {
				cout << "Name: " << monkeyList.at(i).getName() << endl;
				cout << "Training status: " << monkeyList.at(i).getTrainingStatus() << endl;
				cout << "Acquisition country: " << monkeyList.at(i).getAcquisitionCountry() << endl;
			}
		}
	}
	return;
}

int main() {
	//Declare main function variables
	string animalsToPrint;
	char menuChoice = '0';

	initializeDogList(); //seed doglist
	initializeMonkeyList(); //seed monkeylist

	while (menuChoice != 'q') {
		menuChoice = printMenu();
		switch (menuChoice) {
		case '1':
			intakeNewAnimal("dog");
			break;
		case '2':
			printAnimalLists("dog");
			break;
		case '3':
			intakeNewAnimal("monkey");
			break;
		case '4':
			printAnimalLists("monkey");
			break;
		case '5':
			printAnimalLists("available");
			break;
		case '6':
			reserveAnimal();
		case 'q':
			break;
		default:
			cout << "That is an invalid option, please choose again." << endl;
		}
	}
}