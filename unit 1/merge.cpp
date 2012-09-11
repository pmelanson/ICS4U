//Program by Patrick Melanson, ICS4U
#include <iostream>
#include <fstream>
using namespace std;
int main() {

	//initialize
	unsigned list[2][100], sorted[200];
	unsigned short length[2];
	unsigned i = 0, a = 0, b = 0;
	ifstream fin;

	//read from file
	fin.open ("merge1.txt");
	while (!fin.eof())
		fin >> list[0][i++];
	fin.close(), fin.clear();
	length[0] = i - 1;
	for (i = 0; i < length[0]; i++)
		cout << list[0][i] << ", ";
	cout << endl;
	i = 0;

	fin.open ("merge2.txt");
	while (!fin.eof())
		fin >> list[1][i++];
	fin.close(), fin.clear();
	length[1] = i - 1;
	for (i = 0; i < length[1]; i++)
		cout << list[1][i] << ", ";
	cout << endl;
	i = 0;

	//merge and sort
	while (a < length[0] && b < length[1]) {
		if (list[0][a] < list[1][b])
			sorted[i++] = list[0][a++];

		else
			sorted[i++] = list[1][b++];
	}

	while (a < length[0])
		sorted[i++] = list[0][a++];

	while (b < length[1])
		sorted[i++] = list[1][b++];

	//output
	ofstream fout;
	fout.open ("merged.txt");

	for (i = 0; i < length[0] + length[1] - 2; i++){
		fout << sorted[i] << "\n";
		cout << sorted[i] << ", ";
	}
	fout.close(), fout.clear();

	cout<<endl, system("pause");
	return 0;
}
