//Program by Patrick Melanson, ICS4U

#include <iostream>
#include <fstream>
#include <ctype.h>
using namespace std;

char encrypt (char plaintext, char cipher);

int main() {

    //initialization
    int i = 0, n = 0;
    char cipher[7], plaintext[61], ciphertext[61];
    ifstream inFile;

    //open cipher file
    inFile.open ("message.txt");
    if (inFile.is_open())
        cout << "file has been opened\n";

    //read cipher
    inFile.getline (cipher, 7);
    cout << cipher << endl;

    //read plaintext
    inFile.getline (plaintext, 61);
    cout << plaintext << endl;

    //close file
    inFile.close(), inFile.clear();

    //converts message to ciphertext, ignoring non-alpha characters
    for (i = 0; i < 13; i++)
		if (plaintext[i] > 'A' && plaintext[i] < 'Z'){
    		ciphertext[n] = encrypt (plaintext[n], cipher[n % strlen(cipher)] );
    		cout << ciphertext[n];
		    n++;
		}

    cout << "\n\nCiphertext: " << ciphertext << endl;

    system("pause");
    return 0;
}

char encrypt (char plaintext, char cipher){

	char ciphertext = plaintext + (cipher - 'A');
	cout << "encrypted " << plaintext << " into " << ciphertext << endl;
}
