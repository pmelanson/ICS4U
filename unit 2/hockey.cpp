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
		cout << endl;
	}

//	~player_t : {
//		cout << "WHAT DID I DO WRONG WHY ARE YOU DELETING ME\n";
//	}
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
	cout << "Enter name of file (should also be team name)";
	cin >> fileName;
	team.name = fileName;

	cout << "    Player Name\t\t" << "Height (in.)\t" << "Weight (lbs.)\t" << "Birthdate\n\n";

	fileName += ".csv";
	ifstream file (fileName.c_str());

	while (parseLine (file));
}

unsigned short averageHeight (){

	vector <player_t*>::iterator it = roster.begin();
	unsigned average = 0;

	for (it = roster.begin(); it != roster.end(); ++it)
		average += (*it)->height;

	average /= roster.size();
}

unsigned short averageWeight (){

	vector <player_t*>::iterator it = roster.begin();
	unsigned average = 0;

	for (it = roster.begin(); it != roster.end(); ++it)
		average += (*it)->weight;

	average /= roster.size();
}

unsigned short averageAge (){

	vector <player_t*>::iterator it = roster.begin();
	unsigned average = 0;

	for (it = roster.begin(); it != roster.end(); ++it)
		average += (*it)->height;

	average /= roster.size();
}

void calculate() {


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
