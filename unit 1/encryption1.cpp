#include <iostream>
#include <fstream>
using namespace std;

int main() {

	char key[7], text[61];
	ifstream keyFile;
	keyFile.open ("key.txt");
	if (keyFile.is_open())
		cout << "key file has been opened\n";

	keyFile >> key;

	system("pause");
	return 0;
}
