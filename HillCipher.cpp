#include "HillCipher.h"
#include <sstream>
#include <math.h>

/**
* Sets the key to use
* @param key - the key to use
* @return - True if the key is valid and False otherwise
*/
bool HillCipher::setKey(const string& mykey)
{ 
	// validate the key, check if its empty
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
string HillCipher::encrypt(const string& plaintext)
{
	string ciphertext = "";

	vector <int> keycontainer;
	vector < vector <int> > keymatrix;
	vector < vector <int> > textmatrix;
	
	int n;
	int root;
	int count = 0;
	
	stringstream stream(key);
	while (stream >> n)
	{
		keycontainer.push_back(n);
	}
	
	root = sqrt(keycontainer.size());
	
	for (unsigned int i = 0; i < root; i++;)
	{
		for (unsigned int j = 0; j < root; j++;)
		{
			textcontainer.at(i).at(j) = keycontainer.at(count);
			count++;		
		}
	}
	
	
	

	return ciphertext;
}

/**
* Decrypts a string of ciphertext
* @param cipherText - the ciphertext
* @return - the plaintext
*/
string HillCipher::decrypt(const string& cipherText)
{
	string plaintext = "";

	return plaintext;
}
