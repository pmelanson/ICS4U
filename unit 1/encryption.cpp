//Program by Patrick Melanson, ICS4U
#include <iostream>
#include <fstream>
#include <ctype.h>
using namespace std;
int main() {

    //initialization
    int i = 0, n = 0;
    char cipher[7], plaintext[61], ciphertext[61];
    char encrypted;
    ifstream inFile;
    inFile.open ("message.txt");

    inFile.getline (cipher, 7);	//read cipher
    cout << cipher << endl;
    inFile.getline (plaintext, 61);	//read plaintext
    cout << plaintext << endl;

    do	//encrypts message using cipher
		if (isupper (plaintext[i])) {	//checks if the char is an uppercase letter
			encrypted = plaintext[i] + cipher[n % strlen(cipher)] - 'A';  //encrypt
			while (encrypted > 'Z')	encrypted -= 26;	//deals with out-of-ranges
		ciphertext[n++] = encrypted;	//assigns encrypted char to string
	}
	while (plaintext[i++]);
	ciphertext[n] = '\0';	//finishes up with string

	cout << "\n\nCiphertext: " << ciphertext << endl;	//displays encrypted message

	inFile.close(), inFile.clear();	//finishes up with file
    system("pause");
    return 0;
}
