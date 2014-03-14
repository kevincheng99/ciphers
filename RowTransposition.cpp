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
    size_t rank = 0;

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
string RowTransposition::encrypt(const std::string& plaintext) {
  using namespace std;

  // transform the input text to uppercase
  string processed_plaintext = "";

  transform(plaintext.begin(),
            plaintext.end(),
            back_inserter(processed_plaintext),
            ::toupper);

  // pad the text
  processed_plaintext = padText(processed_plaintext);

  // construct the processed plaintext matrix
  vector<string> matrix = constructPlaintextMatrix(processed_plaintext);

  // read off column based on the rank key
  string ciphertext = "";

  for (vector<size_t>::iterator location = rank_key.begin();
       location != rank_key.end();
       ++location) {
    for (vector<string>::iterator row = matrix.begin();
         row != matrix.end();
         ++row) {
      ciphertext.push_back(row->at(*location));
    }
  }

	return ciphertext; 
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

string RowTransposition::padText(const std::string& text) {
  using namespace std;

  string processed_text = text;
 
  // compute the number of needed fillers
  size_t remainder_of_characters = text.length() % rank_key.size();

  if (remainder_of_characters > 0) {
    size_t number_of_fillers = rank_key.size() - remainder_of_characters;
  
    //initialize the random seed
    srand(time(NULL));
    
    for (size_t i = 0; i < number_of_fillers; i++) {
      char filler = (char) (rand() % 26) + 'A';

      processed_text.push_back(filler);
    }
  }

  //cout << processed_text << endl;
  
  return processed_text;
}

vector<string> RowTransposition::constructPlaintextMatrix(
                                     const string& plaintext) {
  using namespace std;

  vector<string> plaintext_matrix;

  for (size_t i = 0; i < plaintext.length(); i = i + rank_key.size()) {
    plaintext_matrix.push_back(plaintext.substr(i, rank_key.size()));
  }

  return plaintext_matrix;
}






















