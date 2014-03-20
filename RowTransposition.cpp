#include "RowTransposition.h"

RowTransposition::RowTransposition():number_of_fillers(0) {
  // may do something
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

  // the key length should not be greater than the plaintext length
  if (rank_key.size() > plaintext.length()) {
    cerr << "WARNING: The key lenght is longer than the length of plaintext" << endl;
    cerr << "WARNING: The encryption may not be desired" << endl;
  }

  // we are assuming the plaintext contains only Engish letters
  // transform the input text to uppercase
  //string processed_plaintext = "";

  //transform(plaintext.begin(),
  //          plaintext.end(),
  //          back_inserter(processed_plaintext),
  //          ::toupper);

  // pad the text
  //processed_plaintext = padText(processed_plaintext);
  string processed_plaintext = padText(plaintext);

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

  // BUG: the number of fillers was lost btw two separated execution of program
  // for encryption and decryption respectively.
  // Solution: store the number of fillers in the file

  if (number_of_fillers != 0) {
    // initialize the output stream object
    ofstream output_file(".rowtransposition_fillers", ofstream::out);

    // if output file stream is valid, write the number of fillers
    if (!output_file) {
      perror("open output file");
    }
    else {
      output_file << ciphertext << " " << number_of_fillers << endl;
      output_file.close();
    }
  }

	return ciphertext; 
}

/**
 * Decrypts a string of ciphertext
 * @param cipherText - the ciphertext
 * @return - the plaintext
 */
string RowTransposition::decrypt(const std::string& ciphertext) {
  // construct ciphertext matrix
  vector<string> ciphertext_matrix = constructCiphertextMatrix(ciphertext);
  
  // read by columns starting from the first column
  string plaintext = "";
  size_t columns = ciphertext.length() / rank_key.size();

  for (size_t j = 0; j < columns; j++) {
    for (size_t i = 0; i < ciphertext_matrix.size(); i++) {
      plaintext.push_back(ciphertext_matrix.at(i).at(j));
    }
  }
 
  // remove the padding
  if (number_of_fillers != 0) {
    plaintext = dropFillers(plaintext);
  }
  else {
    // initalize the input file stream object
    ifstream input_file(".rowtransposition_fillers", ifstream::in);

    // if the input file stream is valid
    //  read the ciphertext and number of fillers 
    //  drop the fillers
    //if (!input_file) {
    //  perror("open input file");
    //}
    //else {
    if (input_file) {
      string ciphertext_infile = "";

      // read the cipher text in file
      input_file >> ciphertext_infile;

      if (ciphertext_infile.compare(ciphertext) == 0) {
        input_file >> number_of_fillers;
        input_file.close();

        plaintext = dropFillers(plaintext);
      }
    }
  }

	return plaintext; 
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
    size_t fillers = rank_key.size() - remainder_of_characters;
    setNumberOfFillers(fillers);

  
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

string RowTransposition::dropFillers(const std::string& text) {
  using namespace std;

  string processed_text = text;
  size_t n_fillers = getNumberOfFillers();
  size_t length = processed_text.length() - n_fillers;
  processed_text = processed_text.substr(0, length);

  // c++11 only: drop the last n number of fillers
  //for (size_t i = 0; i < n_fillers; i++) {
    //processed_text.pop_back();
  //}

  return processed_text;
}



vector<string> RowTransposition::constructPlaintextMatrix(
                                     const std::string& plaintext) {
  using namespace std;

  vector<string> plaintext_matrix;

  for (size_t i = 0; i < plaintext.length(); i = i + rank_key.size()) {
    plaintext_matrix.push_back(plaintext.substr(i, rank_key.size()));
  }

  return plaintext_matrix;
}

vector<string> RowTransposition::constructCiphertextMatrix(
                                     const std::string& ciphertext) {
  using namespace std;

  // compute the number of characters for each row
  size_t characters_per_row  = ciphertext.length() / rank_key.size();

  // construct the ciphertext matrix, where each row is encoded/decoed by a key
  vector<string> ciphertext_matrix;
  ciphertext_matrix.resize(rank_key.size());

  for (size_t i = 0; i < rank_key.size(); i++) {
    string row_string = ciphertext.substr(
                            i * characters_per_row,
                            characters_per_row);
    ciphertext_matrix.at(rank_key.at(i)) = row_string;
  }

  // print the matrix content
  //for (vector<string>::iterator itr = ciphertext_matrix.begin();
  //     itr != ciphertext_matrix.end();
  //     itr++) {
  //  cout << *itr << endl;
  //}

  return ciphertext_matrix;
}




















