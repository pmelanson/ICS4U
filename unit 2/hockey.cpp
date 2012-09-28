#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <vector>
#include <unistd.h>
#include <math.h>
using namespace std;

struct team_t {

	string name;	//team name
	float height, weight, age;	//averages of everything
	void printHeight() {	//prints height as (feet' inches")
		unsigned short feet = (height / 12 + 0.5);
		cout << feet  << "'" << fmodf(height, 12) << "\"\t ";
//		cout << setw(10) << height;
	}

	team_t (string _name, float _height, float _weight, float _age) :	//constructs a team entry, and prints out the data in columns
		name (_name), height (_height), weight (_weight), age (_age) {
		///prints team information///
		cout << setw(15) << name;
		printHeight();
		cout << setw(10) << weight;
		cout << setw(10) << age;
		cout << endl;
	}
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
		///uncomment this if you want players to print their data when constructed///
//		cout << setw(15) << "Player Name";
//		cout << setw(10) << "Height";
//		cout << setw(10) <<  "Weight";
//		cout << setw(10) << "Birthdate";
//		cout << setw(10) << "Age";
//		cout << endl;
	}


	~player_t() {
		cout << "WHAT DID I DO WRONG WHY ARE YOU DELETING ME\n";
	}
};

vector <player_t*> roster;
vector <team_t*> league;
bool debug = false;

void printTeams (vector <team_t*> list) {

	vector <team_t*>::iterator it;

	for (it = list.begin(); it < list.end(); ++it) {
		cout << setw(15) << (*it)->name;
		(*it)->printHeight();
		cout << setw(10) << (*it)->weight;
		cout << setw(10) << (*it)->age;
		cout << endl;
	}
}

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
			heightStream.ignore (2, '"');
			heightStream >> feet;
			heightStream.ignore (2, '\'');
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

void average (vector <player_t*> dataset, float &height, float &weight, float &age) {

	vector <player_t*>::iterator it = dataset.begin();

	for (it = dataset.begin(); it != dataset.end(); ++it) {
		height += (*it)->height;
		weight += (*it)->weight;
		age += (*it)->age;
	}

	height /= dataset.size();
	weight /= dataset.size();
	age /= dataset.size();
}

bool getTeam (string teamName) {

	ifstream file (string(teamName+".txt").c_str());	//adds .txt to teamName, opens the team's datafile

	while (parseLine (file));	//reads all players
	float height=0, weight=0, age=0;

	average (roster, height, weight, age);
	league.push_back (new team_t(teamName, height, weight, age));	//creates a new team, with the calculated data

	roster.clear();	//cleans up for the next time getTeam will be called
	file.close(), file.clear();	//closes file

	return true;
}

bool setup() {

	chdir("AllTeams");	//changes working directory to the folder with all the teams in it
	system("dir > Zdirectory.txt /b");	//generates a directory listing

	cout << fixed << left << setprecision(1);	//sets cout flags
//	cout << setw(15) << "Player Name" << setw(10) << "Height" << setw(10) <<  "Weight" << setw(10) << "Birthdate" << setw(10) << "Age" << endl << endl;	//uncomment this if you want to display player stats as they are read in
	cout << setw(15) << "Team Name" << setw(10) << "Height" << setw(10) << "Weight" << setw(10) << "Age\n" << endl;	//prints column titles

	ifstream directory ("Zdirectory.txt");	//opens up directory listing for reading
	string teamName ("");	//initializes buffer for reading from directory list

	do {
		getline (directory, teamName, '.');	//read a teamname in from .directory.txt, continuing until the first '.' is reached, at which point...
		if (teamName == "Zdirectory") break;	//...(it shouldn't read teamdata from the file index)...
		directory.ignore (256, '\n');	//...we skip to the next line
	} while (getTeam (teamName));	//gets team stats from file

	//cleaning up
	directory.close();
	system("del Zdirectory.txt");

	return true;
}

void sortHeight(vector <team_t*> &dataset) {

	vector <team_t*>::iterator it, selected, compare = dataset.begin();	//declares iterators

	for (it = dataset.begin(); it != ----dataset.end(); ++it) {
		if (debug) cout << "\n\nITERATING";	//debug
		if (debug) cout << "\nbegin: " << &(*dataset.begin()) << ", end: " << &(*dataset.end());	//debug
		selected = it;
		++selected;

		for (compare = ++selected; compare < dataset.end(); ++compare) {	//goes through the entire vector
			if (debug) cout << "\n" << &(*compare);	//debug
			if ((*compare)->height < (*selected)->height) {	//finds the smallest height
			if (debug) cout << "\tFOUND ONE: " << (*compare)->height << " < " << (*selected)->height;	//debug
			selected = compare;	//if a smaller height than the one already selected is found, select the smaller height
			}
		}

		iter_swap((*it), (*selected));	//swaps smallest height with position n
		if (debug) cout << "\n\nit = " << &(*it);	//debug
	}
}

void sortWeight(vector <team_t*> &dataset) {

	vector <team_t*>::iterator it, selected, compare = dataset.begin();	//declares iterators

	for (it = dataset.begin(); it != ----dataset.end(); ++it) {
		if (debug) cout << "\n\nITERATING";	//debug
		if (debug) cout << "\nbegin: " << &(*dataset.begin()) << ", end: " << &(*dataset.end());	//debug
		selected = it;
		++selected;

		for (compare = ++selected; compare < dataset.end(); ++compare) {	//goes through the entire vector
			if (debug) cout << "\n" << &(*compare);	//debug
			if ((*compare)->weight < (*selected)->weight) {	//finds the smallest weight
			if (debug) cout << "\tFOUND ONE: " << (*compare)->weight << " < " << (*selected)->weight;	//debug
			selected = compare;	//if a smaller weight than the one already selected is found, select the smaller weight
			}
		}

		iter_swap((*it), (*selected));	//swaps smallest weight with position n
		if (debug) cout << "\n\nit = " << &(*it);	//debug
	}
}

void sortAge(vector <team_t*> &dataset) {

	vector <team_t*>::iterator it, selected, compare = dataset.begin();	//declares iterators

	for (it = dataset.begin(); it != ----dataset.end(); ++it) {
		if (debug) cout << "\n\nITERATING";	//debug
		if (debug) cout << "\nbegin: " << &(*dataset.begin()) << ", end: " << &(*dataset.end());	//debug
		selected = it;
		++selected;

		for (compare = ++selected; compare < dataset.end(); ++compare) {	//goes through the entire vector
			if (debug) cout << "\n" << &(*compare);	//debug
			if ((*compare)->age < (*selected)->age) {	//finds the smallest age
			if (debug) cout << "\tFOUND ONE: " << (*compare)->age << " < " << (*selected)->age;	//debug
			selected = compare;	//if a smaller age than the one already selected is found, select the smaller age
			}
		}

		iter_swap((*it), (*selected));	//swaps smallest age with position n
		if (debug) cout << "\n\nit = " << &(*it);	//debug
	}
}

void shouldDebug() {

	cout << "\nDo you want to print debug information [y/n]?";
	cout << "\n>";
	char shouldDebugInput;
	cin >> shouldDebugInput;

	switch (shouldDebugInput) {
	case 'y':
	case 'Y':
	case '1':
		debug = true;
		break;
	case 'n':
	case 'N':
	case '0':
		debug = false;
		break;
	default:
		cout << "\nThat doesn't make sense, defaulting to no debug";
		debug = false;
		break;
	}
}

bool sort(vector <team_t*> dataset) {

	cout << "\n\nWhat do you want to do now?\n";
	cout << "[1] Sort by height\n";
	cout << "[2] Sort by weight\n";
	cout << "[3] Sort by age\n";
	cout << "[q] Quit\n";
	cout << ">";

	char choice;

	cin >> choice;
	while (choice != '1' && choice != '2' && choice != '3' && tolower(choice) != 'q') {
		cout << "\nThat choice wasn't listed\n";
		cout << ">";
		cin >> choice;
	}

	switch (choice) {
	case '1':
		shouldDebug();
		sortHeight(dataset);
		break;

	case '2':
		shouldDebug();
		sortWeight(dataset);
		break;

	case '3':
		shouldDebug();
		sortAge(dataset);
		break;

	case 'q':
	case 'Q':
		return false;

	default:
		cout << "Invalid input";
		return false;
	}

	cout << setw(15) << "Team Name" << setw(10) << "Height" << setw(10) << "Weight" << setw(10) << "Age\n" << endl;	//prints column titles
	printTeams (dataset);

	return true;
}

int main() {

	if (setup()) {

		while (sort(league));	//runs sort
		return 0;
//		else
//			return 1;	//if sorting fails

	} else return 2;
}
