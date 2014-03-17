#include "Railfence.h"

/**
 * Sets the key to use
 * @param key - the key to use
 * @return - True if the key is valid and False otherwise
 */
bool Railfence::setKey(const string& mykey)
{ 	// validate the key, check if its empty
	if ((!mykey.empty()))
	{
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
string Railfence::encrypt(const string& plaintext)
{ 
	string ciphertext = "";
		
	
	return ciphertext; 
}

/**
 * Decrypts a string of ciphertext
 * @param cipherText - the ciphertext
 * @return - the plaintext
 */
string Railfence::decrypt(const string& cipherText) 
{ 
	string plaintext = "";
	
	
	return plaintext; 
}
