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
	
	vector<string> ctext(key, ""); // To contain the letters in the string for Railfence
	
	for (unsigned int i = 0; i < plaintext.size(); i++)
	{
		ctext.at(i % key).push_back(plaintext.at(i)); // Repeat and loop through each vector string and pushback a character
	}
	
	for (vector<string>::iterator it = ctext.begin(); it != ctext.end(); ++it)
	{
		ciphertext.append(*it); // Concatenate all the strings in order
	}
	
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
	
	vector<string> ptext(key, ""); // To contain the letters in the string for Railfence
	
	int textlength = cipherText.size() / key; // Store length of the string that is split by the size of the key
	int remainder = cipherText.size() % key; // Store the remainder
	int stringcount = 0;
	
	for (unsigned int i = 0; i < key; i++)
	{
		if (remainder > i)
		{
			ptext.at(i).append(cipherText.substr(stringcount,textlength + 1)); // Append this row split by the size of the key plus 1 due to remainder
			stringcount += textlength + 1;
		}
		else
		{
			ptext.at(i).append(cipherText.substr(stringcount,textlength)); // Append this row split by the size of the key
			stringcount += textlength;
		}
	}
	
	// Go through every vector element, check if string is not empty, push back the first character and erase it.
	for (unsigned int i = 0; i < textlength + 1; i++)
	{
		for (unsigned int j = 0; j < key; j++)
		{
			if (!ptext.at(j).empty())
			{
				plaintext.push_back(ptext.at(j).at(0));
				ptext.at(j).erase(0,1);
			}
		}
	}
	
	return plaintext; 
}
