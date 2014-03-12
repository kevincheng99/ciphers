#include "RowTransposition.h"

RowTransposition::RowTransposition() {
  // do nothing
}

RowTransposition::RowTransposition(const std::string& mykey) {
  setKey(mykey);
}

/**
 * Sets the key to use
 * @param key - the key to use
 * @return - True if the key is valid and False otherwise
 */
bool RowTransposition::setKey(const std::string& mykey)
{ 
  using namespace std;

  // validate the key
  if (validateKey(mykey) == false) {return false;} 
  
  // determine the rank of each character in the key
  for (size_t i = 0; i < mykey.length(); i++) {
    int rank = 0;

    for (size_t j = 0; j < mykey.length(); j++) {
      if (mykey.at(i) > mykey.at(j)) {
        rank++;
      }
    }

    rank_key.push_back(rank);
  }

	return true;
}

/**	
 * Encrypts a plaintext string
 * @param plaintext - the plaintext string
 * @return - the encrypted ciphertext string
 */
string RowTransposition::encrypt(const std::string& plaintext)
{ 
	
	
	return ""; 
}

/**
 * Decrypts a string of ciphertext
 * @param cipherText - the ciphertext
 * @return - the plaintext
 */
string RowTransposition::decrypt(const std::string& cipherText) 
{ 
	return ""; 
	
}

/**
 * The member function validates the key
 * We assume that our key is encoded in ASCII
 */
bool RowTransposition::validateKey(const std::string& mykey) {
  using namespace std;

  // check if the key is empy
  if (mykey.empty()) {return false;}

  // check if the key has duplicate characters such as mississipi
  for (size_t i = 0; i < mykey.length(); i++) {
    for (size_t j = i + 1; j < mykey.length(); j++) {
      if (mykey.at(i) == mykey.at(j)) {return false;}
    }
  }
  
  return true;
}
