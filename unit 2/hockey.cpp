#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;

enum month_t {JAN, FEB, MAR, APR, MAY, JUN, JUL, AUG, SEP, OCT, NOV, DEC};

class player_t {

	string name;
	struct height_t {
		unsigned short feet;
		unsigned short inches;

		height_t (unsigned short _feet, unsigned short _inches) :	//constructor
			feet (_feet), inches (_inches)
		{}
	} height;
	unsigned short weight;	//in pounds
	struct birthday_t {
		unsigned short day;
		month_t month;
		unsigned year;

		birthday_t (unsigned short _day, month_t _month, unsigned _year) :
			day (_day), month (_month), year (_year)
		{}
	} birthday;

public:

	//return functions, to keep everything in the right scope
	string getName() {
		return name;
	}
	string getHeight() {
		string heightString;
		stringstream heightStream (heightString);
		heightStream << height.feet << "' " << height.inches << '"';
//		return string (height.feet + "' " + height.inches + '"');
		return heightStream.str();
	}
	unsigned short getWeight() {
		return weight;
	}
	string getBirthday() {
		string birthdayString;
		stringstream birthStream (birthdayString);
		birthStream << birthday.day << '/' << birthday.month << '/' << birthday.year;
		return birthStream.str();
	}

	player_t (string _name, unsigned short _feet, unsigned short _inches, unsigned short _weight, unsigned short _day, month_t _month, unsigned _year) :	//constructor
		name (_name), height (_feet, _inches), weight (_weight), birthday (_day, _month, _year) {
		cout << "Constructed ";
		cout << name;
		cout << ", " << getHeight();
		cout << " and " << getWeight() << " lbs";
		cout << ", born " << getBirthday();
		cout << endl;
	}
};

vector <player_t> team;

bool parseLine (istream &stream, vector <player_t> &group) {

	string buffer;
	if (getline (stream, buffer)) {	//reads line
		istringstream line (buffer);	//turns the entire line into a stream

		string name;
		unsigned short feet, inches;
		unsigned short day, monthBuff;
		month_t month;
		unsigned year;
		unsigned short weight;

		if (getline (line, name, ','));	//reads name until the next comma
		else
			return false;

		string readHeight;
		if (getline (line, readHeight, ',')) {	//reads height until the next comma (in ft'in" format)
			istringstream heightStream (readHeight);
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
			dateStream >> monthBuff;
			month = (month_t)monthBuff;	//I just typecast to avoid defining >> for month_t
			dateStream.ignore (1, '/');
			dateStream >> year;
		} else
			return false;

		team.push_back (new player_t (name, feet, inches, weight, day, month, year));

	} else
		return false;

	return true;
}

bool setup() {

	ifstream file ("datafile.csv");

	while (parseLine (file, team));
//	while (parseLine (cin, team));
}

int main() {

	if (setup()) {

//		calculate();
//		sort();
//		display();
	}




	return 0;
}
