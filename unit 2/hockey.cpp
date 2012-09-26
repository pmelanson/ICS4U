#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <vector>
#include <unistd.h>
using namespace std;

struct team_t {

	string name;	//team name
	float height, weight, age;	//averages of everything

	team_t (string _name, float _height, float _weight, float _age) :	//constructs a team entry, and prints out the data in columns
		name (_name), height (_height), weight (_weight), age (_age) {
		cout << name;
		if (name.length() > 7)
			cout << "\t" << height;
		else
			cout << "\t\t" << height;
		cout << "\t\t" << weight;
		cout << "\t\t" << age;
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
		/*		cout << name;
				if (name.length() > 15)
					cout << "\t" << height;
				else
					cout << "\t\t" << height;
				cout << "\t\t" << weight;
				cout << "\t\t", birthday.printBirthday();
				cout << "\t" << age;
				cout << endl;
		*/
	}


	~player_t() {
		cout << "WHAT DID I DO WRONG WHY ARE YOU DELETING ME\n";
	}
};

vector <player_t*> roster;
vector <team_t*> league;

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

	chdir("AllTeams");
	system("dir > Zdirectory.txt /b");

//	cout << "    Player Name\t\t" << "Height (in.)\t" << "Weight (lbs.)\t" << "Birthdate\t" << "Age\n\n";	//uncomment this if you want to display player stats as they are read in

	cout << "\n\n\nTeam Name\t" << "Height (in.)\t" << "Weight (lbs.)\t" << "Age\n\n";

	ifstream directory ("Zdirectory.txt");
	string teamName ("");

	do {
		getline (directory, teamName, '.');	//read a teamname in from .directory.txt, continuing until the first '.' is reached, at which point...
		if (teamName == "Zdirectory") break;	//it shouldn't read teamdata from the file index
		directory.ignore (256, '\n');	//...we skip to the next line
	} while (getTeam (teamName));	//gets team stats from file

	directory.close();
	system("del Zdirectory.txt");

	return true;
}

void sortHeight(vector <team_t*> &dataset) {

	vector <team_t*>::iterator it, selected, compare = league.begin();	//declares iterators

/* 	for (it = league.begin(); it < --league.end(); ++it) {
 *
 * 		for (compare = ++league.begin(); compare < league.end(); ++compare)	//goes through the entire vector
 * 			if ((*compare)->height < (*selected)->height)	//finds the smallest height
 * 				selected = compare;	//if a smaller height than the one already selected is found, select the smaller height
 *
 * 		iter_swap((*it), (*selected));
 * 	}
 */

}

void sortWeight(vector <team_t*> &dataset) {

	vector <team_t*>::iterator it, selected, compare = league.begin();	//declares iterators

//	for (it = league.begin(); it < --league.end(); ++it) {
//
//		for (compare = ++league.begin(); compare < league.end(); ++compare)	//goes through the entire vector
//			if ((*compare)->weight < (*selected)->weight)	//finds the smallest weight
//				selected = compare;	//if a smaller weight than the one already selected is found, select the smaller weight
//
//		iter_swap((*it), (*selected));
//	}

}

void sortAge(vector <team_t*> &dataset) {

	vector <team_t*>::iterator it, selected, compare = league.begin();	//declares iterators

/* 	for (it = league.begin(); it < --league.end(); ++it) {
 *
 * 		for (compare = ++league.begin(); compare < league.end(); ++compare)	//goes through the entire vector
 * 			if ((*compare)->age < (*selected)->age)	//finds the smallest age
 * 				selected = compare;	//if a smaller age than the one already selected is found, select the smaller age
 *
 * 		iter_swap((*it), (*selected));
 * 	}
 */

}

bool sort(vector <team_t*> dataset) {

	cout << "\n\nWhat do you want to do now?\n";
	cout << "[1] Sort by height\n";
	cout << "[2] Sort by weight\n";
	cout << "[3] Sort by age\n";
	cout << "> ";

	unsigned short choice;
	cin >> choice;

	switch (choice) {
	case 1:
		sortHeight(dataset);
		break;

	case 2:
		sortWeight(dataset);
		break;

	case 3:
		sortAge(dataset);
		break;

	default:
		cout << "Invalid input";
		return false;
	}
}

int main() {

	if (setup()) {

		if (sort(league))	//runs sort
		return 0;
		else
		return 1;	//if sorting fails

	} else return 2;
}
