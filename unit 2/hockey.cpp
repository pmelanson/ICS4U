#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;

struct team_t {

	string name;	//team name
	unsigned short height;	//average
	unsigned short weight;	//also average
	unsigned short age;	//again, average
};

struct player_t {

	string name;
	unsigned short height;	//in inches
	unsigned short weight;	//in pounds
	struct birthday_t {
		unsigned short day;
		unsigned short month;
		unsigned year;

		void printBirthday() {
			cout << day << '/' << month << '/' << year;
		}

		birthday_t (unsigned short _day, unsigned short _month, unsigned _year) :
			day (_day), month (_month), year (_year)
		{}
	} birthday;
	unsigned short age;



	player_t (string _name, unsigned short _height, unsigned short _weight, unsigned short _day, unsigned short _month, unsigned _year, unsigned short _age) :	//constructor
		name (_name), height (_height), weight (_weight), birthday (_day, _month, _year), age (_age) {
		cout << name;
		if (name.length() > 15)
			cout << "\t" << height;
		else
			cout << "\t\t" << height;
		cout << "\t\t" << weight;
		cout << "\t\t", birthday.printBirthday();
		cout << "\t" << age;
		cout << endl;
	}

	~player_t() {
		cout << "WHAT DID I DO WRONG WHY ARE YOU DELETING ME\n";
	}
};

vector <player_t*> roster;

bool parseLine (istream &stream) {

	string buffer;
	if (getline (stream, buffer)) {	//reads line into buffer
		istringstream line (buffer);	//turns the entire line into a stream

		string name;	//declarations
		unsigned short feet, inches;
		unsigned short day, month;
		unsigned year;
		unsigned short weight;
		unsigned short age;

		if (getline (line, name, ','));	//reads name until the next comma
		else
			return false;

		string readHeight;
		if (getline (line, readHeight, ',')) {	//reads height until the next comma (in ft'in" format)
			istringstream heightStream (readHeight);
			heightStream.ignore (1, '"');
			heightStream >> feet;
			heightStream.ignore (1, '\'');
			heightStream >> inches;
		} else
			return false;

		string readWeight;
		if (getline (line, readWeight, ',')) {	//reads weight until the next comma
			istringstream weightStream (readWeight);
			weightStream >> weight;
		} else
			return false;

		string readDate;
		if (getline (line, readDate, ',')) {	//reads birthday, end of line
			istringstream dateStream (readDate);
			dateStream >> day;
			dateStream.ignore (1, '/');
			dateStream >> month;
			dateStream.ignore (1, '/');
			dateStream >> year;
		} else
			return false;

		string readAge;
		if (getline (line, readAge, ',')) {	//reads birthday, end of line
			istringstream ageStream (readAge);
			ageStream >> age;
		} else
			return false;

		roster.push_back (new player_t (name, (12 * feet) + inches, weight, day, month, year, age));

	} else
		return false;

	return true;
}

bool setup() {

	string fileName;
	team_t team;
<<<<<<< HEAD
	cout << "Enter team name (should also be file name): ";
=======
	cout << "Enter name of file (should also be team name): ";
>>>>>>> dbe0a255d000477a5a76a085eb4daa8ebdd7e349
	cin >> fileName;
	team.name = fileName;

	cout << "    Player Name\t\t" << "Height (in.)\t" << "Weight (lbs.)\t" << "Birthdate\t" << "Age\n\n";

	fileName += ".txt";
	ifstream file (fileName.c_str());
	if (file.good())
		cout << "opened " << fileName << endl;

<<<<<<< HEAD
	while (parseLine (file))
		cout << "read line\n";
=======
	while (parseLine (file));	//loops, reading in a line from the file into a new player, until it fails
>>>>>>> dbe0a255d000477a5a76a085eb4daa8ebdd7e349
}

unsigned short average (){

	vector <player_t*>::iterator it = roster.begin();
	unsigned short averageAge=0, averageWeight=0, averageHeight=0;

	for (it = roster.begin(); it != roster.end(); ++it){
		averageHeight += (*it)->height;
		averageWeight += (*it)->height;
		averageAge += (*it)->height;
	}

	averageHeight /= roster.size();
	averageWeight /= roster.size();
	averageAge /= roster.size();
}

int main() {

	if (setup()) {

//		calculate();
//		sort();
//		display();

		return 0;
	}
	else return 1;





}
