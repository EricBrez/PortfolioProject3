#include <algorithm>
#include <iostream>
#include <locale>
#include <tuple>
#include <vector>
#include <cstring>
#include <format>
#include <iomanip>

#include "sqlite3.h"

using namespace std;

const string str_where = " where ";

//Define monkey and dog tuples
typedef tuple<string, string, string, string, string, string, string, string, string, string, string, string, string, string> monkey_record;
typedef tuple<string, string, string, string, string, string, string, string, string, string, string> dog_record;

//Define monkey callback function
static int monkeyCallback(void* possible_vector, int argc, char** argv, char** azColName) {

	if (possible_vector == NULL) { //No vector passed in so just display results
		for (int i = 0; i < argc; i++) {
			cout << azColName[i] << " = " << (argv[i] ? argv[i] : "NULL") << endl;
		}
		cout << endl;
	}
	else {
		vector< monkey_record >* rows =
			static_cast<vector< monkey_record > *>(possible_vector);

		rows->push_back(make_tuple(argv[0], argv[1], argv[2], argv[3], argv[4], argv[5], argv[6], argv[7], argv[8], argv[9], argv[10], argv[11], argv[12], argv[13]));
	}
	return 0;
}

//Define dog callback function
static int dogCallback(void* possible_vector, int argc, char** argv, char** azColName) {

	if (possible_vector == NULL) { //No vector passed in so just display results
		for (int i = 0; i < argc; i++) {
			cout << azColName[i] << " = " << (argv[i] ? argv[i] : "NULL") << endl;
		}
		cout << endl;
	}
	else {
		vector< dog_record >* rows =
			static_cast<vector< dog_record > *>(possible_vector);

		rows->push_back(make_tuple(argv[0], argv[1], argv[2], argv[3], argv[4], argv[5], argv[6], argv[7], argv[8], argv[9], argv[10]));
	}
	return 0;
}

//Initialize animal database
bool initialize_database(sqlite3* db) {
	
	char* error_message = NULL;

	//Create monkey table
	string sql = "CREATE TABLE MONKEYS(" \
		"ID	INT	PRIMARY KEY	NOT NULL," \
		"NAME	TEXT	NOT NULL," \
		"TAIL	TEXT	NOT NULL," \
		"HEIGHT	TEXT	NOT NULL," \
		"LENGTH	TEXT	NOT NULL," \
		"SPECIES	TEXT	NOT NULL," \
		"GENDER	TEXT	NOT NULL," \
		"AGE	TEXT	NOT NULL," \
		"WEIGHT	TEXT	NOT NULL," \
		"DATE	TEXT	NOT NULL," \
		"ORIGIN	TEXT	NOT NULL," \
		"STATUS	TEXT	NOT NULL," \
		"RESERVED TEXT	NOT NULL," \
		"DESTINATION	TEXT	NOT NULL);";

	int result = sqlite3_exec(db, sql.c_str(), monkeyCallback, NULL, &error_message);
	if (result != SQLITE_OK) {
		cout << "Failed to create MONKEYS table. ERROR = " << error_message << endl;
		sqlite3_free(error_message);
		return false;
	}
	cout << "MONKEYS table created." << endl;

	//Create dog table
	sql = "CREATE TABLE DOGS(" \
		"ID	INT	PRIMARY KEY	NOT NULL," \
		"NAME	TEXT	NOT NULL," \
		"BREED	TEXT	NOT NULL," \
		"GENDER	TEXT	NOT NULL," \
		"AGE	TEXT	NOT NULL," \
		"WEIGHT	TEXT	NOT NULL," \
		"DATE	TEXT	NOT NULL," \
		"ORIGIN	TEXT	NOT NULL," \
		"STATUS	TEXT	NOT NULL," \
		"RESERVED TEXT	NOT NULL," \
		"DESTINATION	TEXT	NOT NULL);";

	result = sqlite3_exec(db, sql.c_str(), dogCallback, NULL, &error_message);
	if (result != SQLITE_OK) {
		cout << "Failed to create DOGS table. ERROR = " << error_message << endl;
		sqlite3_free(error_message);
		return false;
	}
	cout << "DOGS table create." << endl;

	//Seed MONKEYS table with three monkeys
	sql = "INSERT INTO MONKEYS (ID, NAME, TAIL, HEIGHT, LENGTH, SPECIES, GENDER, AGE, WEIGHT, DATE, ORIGIN, STATUS, RESERVED, DESTINATION)" \
		"VALUES ('1', 'Kumquat', '13', '14', '9', 'Capuchin', 'female', '2', '9.7', '7 - 04 - 1776', 'England', 'intake', 'false', 'United States');" \
		"INSERT INTO MONKEYS (ID, NAME, TAIL, HEIGHT, LENGTH, SPECIES, GENDER, AGE, WEIGHT, DATE, ORIGIN, STATUS, RESERVED, DESTINATION)" \
		"VALUES ('2', 'Grapeseed', '13', '14', '9', 'Tamarin', 'male', '1', '0.9', '12 - 15 - 1997', 'United States', 'intake', 'true', 'United States');" \
		"INSERT INTO MONKEYS (ID, NAME, TAIL, HEIGHT, LENGTH, SPECIES, GENDER, AGE, WEIGHT, DATE, ORIGIN, STATUS, RESERVED, DESTINATION)" \
		"VALUES ('3', 'Lettuce', '13', '14', '9', 'Guenon', 'female', '3', '9.6', '03 - 13 - 1984', 'United States', 'intake', 'true', 'United States');";

	result = sqlite3_exec(db, sql.c_str(), monkeyCallback, NULL, &error_message);
	if (result != SQLITE_OK) {
		cout << "Failed to seed MONKEYS table. ERROR = " << error_message << endl;
		sqlite3_free(error_message);
		return false;
	}

	//Seed DOG table with three dogs
	sql = "INSERT INTO DOGS (ID, NAME, BREED, GENDER, AGE, WEIGHT, DATE, ORIGIN, STATUS, RESERVED, DESTINATION)" \
		"VALUES ('4', 'Spot', 'German Shepherd', 'male', '1', '25.6', '05 - 12 - 2019', 'United States', 'Intake', 'false', 'United States');" \
		"INSERT INTO DOGS (ID, NAME, BREED, GENDER, AGE, WEIGHT, DATE, ORIGIN, STATUS, RESERVED, DESTINATION)" \
		"VALUES ('5', 'Rex', 'Great Dane', 'male', '3', '35.2', '02 - 03 - 2020', 'United States', 'Phase I', 'false', 'United States');" \
		"INSERT INTO DOGS (ID, NAME, BREED, GENDER, AGE, WEIGHT, DATE, ORIGIN, STATUS, RESERVED, DESTINATION)" \
		"VALUES ('6', 'Bella', 'Chihuahua', 'female', '4', '25.6', '12 - 12 - 2019', 'Canada', 'in service', 'true', 'Canada');";

	result = sqlite3_exec(db, sql.c_str(), dogCallback, NULL, &error_message);
	if (result != SQLITE_OK) {
		cout << "Failed to seed DOGS table. ERROR = " << error_message << endl;
		sqlite3_free(error_message);
		return false;
	}

	return true;
}

//Function to run queries on monkeys table
bool run_monkey_query(sqlite3* db, string& sql, vector< monkey_record >& records) {
	
	records.clear(); //clear any prior results

	//Check for SQL injection in query string
	if (sql.find(" or ") != std::string::npos) { //Check for OR injection
		std::cout << "\"" << sql << "\"" << " is an invalid search, please try again" << std::endl;
		return false;
	}
	else if (sql.find(";") != std::string::npos) { //Check for Query delimiter
		std::cout << "\"" << sql << "\"" << " is an invalid search, please try again" << std::endl;
		return false;
	}
	else if (sql.find("--") != std::string::npos) { //Check for comment delimiter
		std::cout << "\"" << sql << "\"" << " is an invalid search, please try again" << std::endl;
		return false;
	}
	else if (sql.find("/*") != std::string::npos) { //Check for comment delimiter start
		std::cout << "\"" << sql << "\"" << " is an invalid search, please try again" << std::endl;
		return false;
	}
	else if (sql.find("*/") != std::string::npos) { //Check for comment delimiter end
		std::cout << "\"" << sql << "\"" << " is an invalid search, please try again" << std::endl;
		return false;
	}
	else if (sql.find("xp_") != std::string::npos) { //Check for prefix to catalog-extended stored procedures
		std::cout << "\"" << sql << "\"" << " is an invalid search, please try again" << std::endl;
		return false;
	}

	char* error_message;
	if (sqlite3_exec(db, sql.c_str(), monkeyCallback, &records, &error_message) != SQLITE_OK) {
		cout << "Data failed to be queried from MONKEYS table. ERROR = " << error_message << endl;
		return false;
	}
	return true;


}

//Function to run queries on dogs table
bool run_dog_query(sqlite3* db, string& sql, vector< dog_record >& records) {

	records.clear(); //clear any prior results

	//Check for SQL injection in query string
	if (sql.find(" or ") != std::string::npos) { //Check for OR injection
		std::cout << "\"" << sql << "\"" << " is an invalid search, please try again" << std::endl;
		return false;
	}
	else if (sql.find(";") != std::string::npos) { //Check for Query delimiter
		std::cout << "\"" << sql << "\"" << " is an invalid search, please try again" << std::endl;
		return false;
	}
	else if (sql.find("--") != std::string::npos) { //Check for comment delimiter
		std::cout << "\"" << sql << "\"" << " is an invalid search, please try again" << std::endl;
		return false;
	}
	else if (sql.find("/*") != std::string::npos) { //Check for comment delimiter start
		std::cout << "\"" << sql << "\"" << " is an invalid search, please try again" << std::endl;
		return false;
	}
	else if (sql.find("*/") != std::string::npos) { //Check for comment delimiter end
		std::cout << "\"" << sql << "\"" << " is an invalid search, please try again" << std::endl;
		return false;
	}
	else if (sql.find("xp_") != std::string::npos) { //Check for prefix to catalog-extended stored procedures
		std::cout << "\"" << sql << "\"" << " is an invalid search, please try again" << std::endl;
		return false;
	}

	char* error_message;
	if (sqlite3_exec(db, sql.c_str(), dogCallback, &records, &error_message) != SQLITE_OK) {
		cout << "Data failed to be queried from DOGS table. ERROR = " << error_message << endl;
		return false;
	}
	return true;


}

void dump_monkey_results(const string& sql, vector < monkey_record >& records) {
	cout << endl << records.size() << " monkey records found:" << endl;
	for (auto record : records) {
		cout << "ID: " << get<0>(record) << " Name: " << get<1>(record) << "Reserved: " << get<12>(record) << endl;
	}
}

void dump_dog_results(const string& sql, vector < dog_record >& records) {
	cout << endl << records.size() << " dog records found:" << endl;
	for (auto record : records) {
		cout << "ID: " << get<0>(record) << " Name: " << get<1>(record) << "Reserved: " << get<9>(record) << endl;
	}
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
	cin >> setw(1) >> menuChoice;

	return menuChoice;

}

//Intake new animal
void intakeNewAnimal(string animalType, sqlite3* db, int count) {
	//Declare variables
	int countNum = count;
	string type = animalType;
	string name;
	string gender;
	string age;
	string weight;
	string acquisitionDate;
	string acquisitionCountry;
	string trainingStatus;
	string reserved;
	string inServiceCountry;
	string sql;

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
	cin >> reserved;
	cout << endl << "What country will the animal be serving in?" << endl;
	cin >> inServiceCountry;

	if (type == "dog") {
		string breed;
		cout << endl << "What is the dog's breed?" << endl;
		cin >> breed;

		vector< dog_record > records;

		sql = format("SELECT FROM DOGS WHERE ID='{}' AND NAME='{}'", countNum, name);
		
		if (!run_dog_query(db, sql, records)) {
			sql = format("INSERT INTO DOGS (ID, NAME, BREED, GENDER, AGE, WEIGHT, DATE, ORIGIN, STATUS, RESERVED, DESTINATION)" \
				"VALUES ('{}', '{}', '{}', '{}', '{}', '{}', '{}', '{}', '{}', '{}', '{}');", countNum, name, breed, gender, age, weight, acquisitionDate, acquisitionCountry, trainingStatus, reserved, inServiceCountry);
			run_dog_query(db, sql, records);
		}
	}
	else if (type == "monkey") {
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

		vector< monkey_record> records;

		sql = format("SELECT FROM MONKEYS WHERE ID='{}' AND NAME='{}'", countNum, name);

		if (!run_monkey_query(db, sql, records)) {
			sql = format("INSERT INTO MONKEYS (ID, NAME, TAIL, HEIGHT, LENGTH, SPECIES, GENDER, AGE, WEIGHT, DATE, ORIGIN, STATUS, RESERVED, DESTINATION)" \
				"VALUES ('{}', '{}', '{}', '{}', '{}', '{}', '{}', '{}', '{}', '{}', '{}', '{}', '{}', '{}');", countNum, name, tailLength, height, bodyLength, species, gender, age, weight, acquisitionDate, acquisitionCountry, trainingStatus, reserved, inServiceCountry);
			run_monkey_query(db, sql, records);
		}
	}
}

int main() {
	//Initialize random seed
	srand(time(nullptr));

	int return_code = 0;
	cout << "Welcome to the Grazioso Database" << endl << endl;

	//Database handle
	sqlite3* db = NULL;
	char* error_message = NULL;

	//Open database connection
	int result = sqlite3_open(":memory:", &db);

	//Verify connection or close if failed
	if (result != SQLITE_OK) {
		cout << "Failed to connect to the database. Terminating program. ERROR = " << sqlite3_errmsg(db) << endl;
		return -1;
	}

	cout << "Connected to the Grazioso Database" << endl << endl;

	//Initialize Database
	if (!initialize_database(db)) {
		cout << "Database initialization failed. Terminating program" << endl;
		return_code = -1;
	}
	else {
		string sql;
		int count = 7;
		char menuChoice = '0';
		vector< dog_record > dogRecords;
		vector< monkey_record > monkeyRecords;
		//Main operation
		while (menuChoice != 'q') {
			menuChoice = printMenu();
			switch (menuChoice) {
			case '1':
				intakeNewAnimal("dog", db, count);
				count++;
				break;
			case '2':
				sql = "SELECT ID, NAME from DOGS";
				if (!run_dog_query(db, sql, dogRecords)) break;
				dump_dog_results(sql, dogRecords);
				break;
			case '3':
				intakeNewAnimal("monkey", db, count);
				count++;
				break;
			case '4':
				sql = "SELECT ID, NAME from MONKEYS";
				if (!run_monkey_query(db, sql, monkeyRecords)) break;
				dump_monkey_results(sql, monkeyRecords);
				break;
			case '5':
				sql = "Select ID, NAME from DOGS WHERE RESERVED='false'";
				if (!run_dog_query(db, sql, dogRecords)) break;
				dump_dog_results(sql, dogRecords);
				cout << endl;
				sql = "SELECT ID, NAME from MONKEYS WHERE RESERVED='false'";
				if (!run_monkey_query(db, sql, monkeyRecords)) break;
				dump_monkey_results(sql, monkeyRecords);
				break;
			case 'q':
				break;
			default:
				cout << "That is an invalid option, please choose again." << endl;
			}
		}
	}

	//Close connection if opened
	if (db != NULL) {
		sqlite3_close(db);
	}

	return return_code;

}

