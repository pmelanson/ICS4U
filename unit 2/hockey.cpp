#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
using namespace std;

class player_t {

	string name;
	struct height_t {
		unsigned feet;
		unsigned short inches;
	} height;
	unsigned short weight;	//in pounds
	struct birthday_t {
		unsigned short day;
		enum month_t {JAN, FEB, MAR, APR, MAY, JUN, JUL, AUG, SEP, OCT, NOV, DEC} month;
		unsigned year;
	} birthday;

	public:

	string getName(), height_t getHeight(), unsigned short getWeight(), birthday_t getBirthday();

	player_t (string _name, height_t _height, unsigned short _weight, birthday_t _birthday) :	//constructor
		 {name (_name), height (_height), weight (_weight), birthday (_birthday)
	}
};

vector <player_t> team;

bool parseLine (istream &stream, vector <player_t> &team) {

	string line;

	if (getline (stream, line)) {	//reads line
		istringstream iss (line);

		if (iss.getline (string name, 64, ','));	//reads name until the next comma
		else
			return false;

		if (iss.getline (string name, 64, ','));	//reads name until the next comma
		else
			return false;

				if (iss.getline (string name, 64, ','));	//reads name until the next comma
		else
			return false;

		if (iss.getline (string name, 64, ','));	//reads name until the next comma
		else
			return false;

	} else
		return false;

	return true;
}

int main() {

	parse();
	average();
	sort();




	system("pause");
	return 0;
}
