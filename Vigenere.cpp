#include "Vigenere.h"
#include <stdlib.h>	
#include <iostream>
using namespace std;

/**
 * Sets the key to use
 * @param key - the key to use
 * @return - True if the key is valid and False otherwise
 */
bool Vigenere::setKey(const string& mykey)
{ 	// validate the key, check if its empty
	if ((!mykey.empty()))
	{
		key = mykey;
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
string Vigenere::encrypt(const string& plaintext)
{ 
	string ciphertext = "";
		
	// Make the key and plaintext string to all lowercase
	string lowerkey, lowerptext = "";
	
	for (unsigned int i = 0; i < key.size(); i++)
	{
		lowerkey.push_back(tolower(key.at(i)));
	}
	
	for (unsigned int i = 0; i < plaintext.size(); i++)
	{
		lowerptext.push_back(tolower(plaintext.at(i)));
	}
	
	char base; // This is the starting base ASCII for each char of the key
	
	// Iterate through each char of the key, set each one as base and use that to encrypt
	for (unsigned int i = 0; i < lowerptext.size(); i++)
	{
		base = lowerkey.at(i % lowerkey.size()); // Use modulus to loop through the key string
		ciphertext.push_back((base - 'a' + lowerptext.at(i) - 'a') % 26 + 'a');
	}
	
	return ciphertext; 
}

/**
 * Decrypts a string of ciphertext
 * @param cipherText - the ciphertext
 * @return - the plaintext
 */
string Vigenere::decrypt(const string& cipherText) 
{ 
	string plaintext = "";
	
	// Make the key and cipherText string to all lowercase
	string lowerkey, lowerctext = "";
	
	for (unsigned int i = 0; i < key.size(); i++)
	{
		lowerkey.push_back(tolower(key.at(i)));
	}
	
	for (unsigned int i = 0; i < cipherText.size(); i++)
	{
		lowerctext.push_back(tolower(cipherText.at(i)));
	}
	
	char base; // This is the starting base ASCII for each char of the key
	
	// Iterate through each char of the key, set each one as base and use that to decrypt
	for (unsigned int i = 0; i < lowerctext.size(); i++)
	{
		base = lowerkey.at(i % lowerkey.size()); // Use modulus to loop through the key string
		plaintext.push_back(((26 + lowerctext.at(i) - 'a') - (base - 'a')) % 26 + 'a');
	}
	
	return plaintext; 
}
