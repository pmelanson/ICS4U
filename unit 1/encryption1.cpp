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
    inFile.open ("cipher.txt");
    if (inFile.is_open())
        cout << "cipher file has been opened\n";

    //read cipher file
    inFile.getline (cipher, 7);
    cout << cipher << endl;
    inFile.close(), inFile.clear();

    //open plaintext file
    inFile.open ("message.txt");
    if (inFile.is_open())
        cout << "message file has been opened\n";

    //read plaintext file
    inFile.getline (plaintext, 61);
    cout << plaintext << endl;
    inFile.close(), inFile.clear();


    //converts message to ciphertext, ignoring non-alpha characters
    for (i = 0; i < strlen(plaintext); i++)
		if (isalpha (plaintext[i])){
    		ciphertext[n] = encrypt (plaintext[n], cipher[n % strlen(cipher)] );
		    n++;
		}

    cout << "\n\nCiphertext: " << ciphertext << endl;

    system("pause");
    return 0;
}

char encrypt (char plaintext, char cipher){

	 if (plaintext + (cipher - 'A') > 'Z'){
	 	char ciphertext = plaintext + (cipher - 'Z' - 1);
		 cout << "wrapped " << plaintext << " into " << ciphertext << endl;
		}
     else{
 	    char ciphertext = plaintext + (cipher - 'A');
		 cout << "encrypted " << plaintext << " into " << ciphertext << endl;
		}
}
