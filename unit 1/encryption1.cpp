//Program by Patrick Melanson, ICS4U

#include <iostream>
#include <fstream>
#include <ctype.h>
using namespace std;

int main() {

    //initialization
    int i = 0, n = 0;
    char cipher[7], plaintext[61], ciphertext[61];
    ifstream inFile;

    //open file
    inFile.open ("message.txt");
    if (inFile.is_open())
        cout << "file has been opened\n";

    //read cipher
    inFile.getline (cipher, 7);
    cout << cipher << endl;

    //read plaintext
    inFile.getline (plaintext, 61);
    cout << plaintext << endl;

    //cleanup
    inFile.close(), inFile.clear();

    //close file
    inFile.close(), inFile.clear();

    //converts message to ciphertext, ignoring non-alpha characters
    while (plaintext[i]){
		if (isupper (plaintext[i])){
    		ciphertext[n] = (plaintext[i] + cipher[n % strlen(cipher)] - 'A') % 'Z';
    		cout << char ((plaintext[i] + cipher[n % strlen(cipher)] - 'A') % 'Z');
		    n++;
		}
		i++;
    }

    ciphertext[n] = '\0';

    cout << "\n\nCiphertext: " << ciphertext << endl;

    system("pause");
    return 0;
}
