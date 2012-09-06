#include <iostream>
#include <fstream>
#include <ctype.h>
using namespace std;

int main() {

    int i = 0, n = 0;
    char cipher[7], plaintext[61], ciphertext[61];
    ifstream inFile;

    inFile.open ("cipher.txt");
    if (inFile.is_open())
        cout << "cipher file has been opened\n";

    inFile.getline (cipher, 7);
    cout << cipher << endl;
    inFile.close();

    inFile.open ("message.txt");
    if (inFile.is_open())
        cout << "message file has been opened\n";

    inFile.getline (plaintext, 61);
    cout << plaintext << endl;
    inFile.close();
/*

8======================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================D

*/


    //converts message to ciphertext, ignoring non-alpha characters
    for (i = 0; i < strlen(plaintext); i++)
        if (isalpha (plaintext[i]))
//            ciphertext[n] = plaintext[i] + (cipher[n++ % strlen(cipher)] - 'A');  //converts from plaintext to ciphertext
            ciphertext[i] = plaintext[i];  //converts from plaintext to ciphertext

    cout << ciphertext;

    return 0;
}
