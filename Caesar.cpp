#include "Caesar.h"
#include <stdlib.h>		


/**
 * Sets the key to use
 * @param key - the key to use
 * @return - True if the key is valid and False otherwise
 */
bool Caesar::setKey(const string& mykey)
{ 	// validate the key, check if its empty and if its within 0-25 range
	if ((!mykey.empty() && atoi(mykey.c_str()) > -1 && atoi(mykey.c_str()) < 26)) {
		key = atoi(mykey.c_str());
		return true;
	}
	else
		return false;
}




/**	
 * Encrypts a plaintext string
 * @param plaintext - the plaintext string
 * @return - the encrypted ciphertext string
 */	
string Caesar::encrypt(const string& plaintext)
{ 
	string ciphertext = "";
	
	// Iterate through every letter and shift it to the right. We use ASCII scheme to do the math
	for (unsigned int i = 0; i < plaintext.size(); i++)
	{
		if (isupper(plaintext.at(i)))
		{
			ciphertext.push_back((plaintext.at(i) - 'A' + key) % 26 + 'A');
		}
		else
		{
			ciphertext.push_back((plaintext.at(i) - 'a' + key) % 26 + 'a');
		}
	}
	
	return ciphertext; 
}

/**
 * Decrypts a string of ciphertext
 * @param cipherText - the ciphertext
 * @return - the plaintext
 */
string Caesar::decrypt(const string& cipherText) 
{ 
	string plaintext = "";
	
	// Iterate through every letter and shift it to the left. We use ASCII scheme to do the math
	for (unsigned int i = 0; i < cipherText.size(); i++)
	{
		if (isupper(cipherText.at(i)))
		{
			plaintext.push_back((cipherText.at(i) - 'A' + (26 - key)) % 26 + 'A');
		}
		else
		{
			plaintext.push_back((cipherText.at(i) - 'a' + (26 - key)) % 26 + 'a');
		}
	}
	
	return plaintext; 
}
