#include <string>
#include "CipherInterface.h"
//#include "Playfair.h"
//#include "Caesar.h"
#include "Vigenere.h"
#include <iostream>

using namespace std;

int main(int argc, char** argv)
{
/* REPLACE THIS PART WITH YOUR CODE
* THE CODE BELOW IS A SAMPLE TO
* ILLUSTRATE INSTANTIATION OF CLASSES
* THAT USE THE SAME INTERFACE.
*/	


/* Create an instance of the Playfair cipher */	
CipherInterface* cipher = new Vigenere();

/* Error checks */
if(!cipher)
{
fprintf(stderr, "ERROR [%s %s %d]: could not allocate memory\n",	
__FILE__, __FUNCTION__, __LINE__);
exit(-1);
}

/* Set the encryption key */

cipher->setKey("Gofman");
cout << "Vigenere Cipher" << endl; 

/* Perform encryption */
string cipherText = cipher->encrypt("KevinEnjoysEncryption");

  cout << "ciphertext: " << cipherText << endl;

/* Perform decryption */
string decrypted_ciphertext = cipher->decrypt(cipherText);

  cout << "decrypted ciphertext: " << decrypted_ciphertext << endl;

return 0;
}
