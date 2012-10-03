//Program by Patrick Melanson, ICS4U
#include <iostream>
#include <fstream>
#include <ctype.h>
using namespace std;
int main() {

    //initialization
    int i = 0, n = 0;
    string cipher, plaintext, ciphertext;
    char encrypted;
    ifstream inFile ("message.txt");;

    getline (inFile, cipher);	//read cipher
    cout << cipher << endl;
    getline (inFile, plaintext);	//read plaintext
    cout << plaintext << endl;

//		if (isupper (plaintext[i])) {	//checks if the char is an uppercase letter
//    do	//encrypts message using cipher
//			encrypted = plaintext[i] + cipher[n%cipher.length()] - 'A';  //encrypt
//			while (encrypted > 'Z')	encrypted -= 26;	//deals with out-of-ranges
//		ciphertext[n++] = encrypted;	//assigns encrypted char to string
//	}
//	while (plaintext[i++]);
//	ciphertext[n] = '\0';	//finishes up with string

	replace_if(plaintext.begin(), plaintext.end(), isalpha,
		plaintext[i] + cipher[n%cipher.length()] - 'A';  //encrypt
	);
//	transform (plaintext.begin(), plaintext.end(), ciphertext.begin(), plaintext[i] + cipher[n%cipher.length()] - 'A');

	cout << "\n\nCiphertext: " << plaintext << endl;	//displays encrypted message

	inFile.close(), inFile.clear();	//finishes up with file
    system("pause");
    return 0;
}
