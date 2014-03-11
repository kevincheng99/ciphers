#include "Caesar.h"
#include <stdlib.h>		


/**
 * Sets the key to use
 * @param key - the key to use
 * @return - True if the key is valid and False otherwise
 */
bool Caesar::setKey(const string& key)
{ 
	return (!key.empty() && atoi(key.c_str()) > -1 && atoi(key.c_str()) < 26);
}




/**	
 * Encrypts a plaintext string
 * @param plaintext - the plaintext string
 * @return - the encrypted ciphertext string
 * Equation (ASCII): c - 'A' + n % 26 + 'A'
 */	
string Caesar::encrypt(const string& plaintext)
{ 
	string ciphertext = "";
	for (unsigned int i = 0; i < plaintext.size()-1; i++)
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
	for (unsigned int i = 0; i < cipherText.size()-1; i++)
	{
		if (isupper(cipherText.at(i)))
		{
			plaintext.push_back((cipherText.at(i) - 'A' - key) % 26 + 'A');
		}
		else
		{
			plaintext.push_back((cipherText.at(i) - 'a' - key) % 26 + 'a');
		}
	}
	
	return plaintext; 
}
