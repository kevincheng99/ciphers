/**
 *  Implementation note:
 *  std::pair<int, int> is used to represent each element in a matrix, where the
 *  first entry is row and the second entry is column.
 *
 */

#include "Playfair.h"

Playfair::Playfair():kVectorLength(5),
                     kStringLength(5),
                     filler('X') {
                     //user_key("") {
                     //plaintext("") {
  // do nothing
}

Playfair::Playfair(const std::string& my_key ):
              kVectorLength(5),
              kStringLength(5),
              filler('X') {
              //user_key(my_key) {
              //plaintext("") {
  // set the key matrix
  setKey(my_key);
}

/**
 * Sets the key to use. The member function has side effects. It stores the user
 * key. Once the key matrix is computed, it stores the key matrix.
 *
 * @param key - the key to use
 * @return - True if the key is valid and False otherwise
 */
bool Playfair::setKey(const std::string& key) {
  using namespace std;

  // validate the key string
  if (validateKey(key) == false) {return false;}

  // store the user key
  //setUserKey(user_key = key);
 
  // convert the key to upper-case
  // ::toupper is the toupper method in the global namespace instead of
  // std::toupper
  string processed_key = "";

  transform(key.begin(), key.end(), back_inserter(processed_key), ::toupper);
  
  // remove duplicates
  string a_z = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  processed_key = processed_key + a_z;

  processed_key = removeDuplicates(processed_key);
  
  // construct the key matrix
  for (int i = 0; i < kVectorLength; i++) {
    key_matrix.push_back(processed_key.substr(5 * i, kStringLength)); 
  }

	return true;  
}

/**	
 * Encrypts a plaintext string.
 * @param plaintext - the plaintext string
 * @return - the encrypted ciphertext string
 */
std::string Playfair::encrypt(const std::string& myplaintext) { 
  using namespace std;

  // we may have to check if the plaintext is empty here or in the cipher.cpp

  // save the plaintext
  //setPlaintext(myplaintext);

  // extract non-english letters
  //string english_only_text = extractNonEnglishLetters(myplaintext);

  // convert the plaintext to upper-case
  //string processed_plaintext = "";

  //transform(english_only_text.begin(),
  //          english_only_text.end(),
  //          back_inserter(processed_plaintext),
  //          ::toupper);
  
  string processed_plaintext = "";

  transform(myplaintext.begin(),
            myplaintext.end(),
            back_inserter(processed_plaintext),
            ::toupper);
 

  // pad plaintext 
  processed_plaintext = padText(processed_plaintext, filler);

  // for each pair of letters
  //  if they are the same,
  //    report the padding error
  //  else if they are on the same row,
  //    circular shift right
  //  else if they are on the same column,
  //    circluar shift down
  //  else tranlate each letter to its corresponding letter
  string ciphertext = "";

  for (size_t i = 0; i < processed_plaintext.length(); i = i + 2) {
    if (processed_plaintext.at(i) == processed_plaintext.at(i + 1)) {
      cerr << "ERROR: padding error" << endl;
      return "";
    }
    else {
      // get the position of each letter
      pair<int, int> letter1_position =
          locateCharacter(processed_plaintext.at(i));
      pair<int, int> letter2_position = 
          locateCharacter(processed_plaintext.at(i + 1));
      char encrypted_letter1 = '\0';
      char encrypted_letter2 = '\0';

      if (letter1_position.first == letter2_position.first) {
        // circular shift right
        encrypted_letter1 =
            circularShift(processed_plaintext.at(i), "right");
        encrypted_letter2=
            circularShift(processed_plaintext.at(i + 1), "right");
      }
      else if (letter1_position.second == letter2_position.second) {
        // circular shift down
        encrypted_letter1 =
            circularShift(processed_plaintext.at(i), "down");
        encrypted_letter2 =
            circularShift(processed_plaintext.at(i + 1), "down");
      }
      else {
        encrypted_letter1 = key_matrix.at(letter1_position.first)
                                      .at(letter2_position.second);
        encrypted_letter2 = key_matrix.at(letter2_position.first)
                                      .at(letter1_position.second);
      }
      
      ciphertext.push_back(encrypted_letter1); 
      ciphertext.push_back(encrypted_letter2); 
    }
  }

  // BUG: between each execution of program, the padding location will be lost
  // Soln: write it ot file, keep it hidden and document it
  // Alternative soln: use X or Z as fillers and drop all X and Z

  if (padding_location.empty() == false) {
    // initialize the output stream object to the hidden file
    ofstream output_file(".playfair_padding_location", ofstream::out);

    // if the output file can't be open, output the error message
    // else start to save the padding locations
    if(!output_file) {
      perror("open output file");
    }
    else {
      // write the ciphertext and use is as identifier for padding locations
      output_file << ciphertext << " ";

      // write the padding location to the file with a space delimiter
      for (vector<unsigned int>::iterator itr = padding_location.begin();
          itr != padding_location.end();
           ++itr) {
        output_file << *itr << " ";
      }
  
      output_file << endl;

      // close output file stream
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
std::string Playfair::decrypt(const std::string& ciphertext) {
  using namespace std;

  // for each pair of letters
  //  if they are on the same row,
  //    circular shift left 
  //  else if they are on the same column,
  //    circluar shift down 
  //  else tranlate each letter to its corresponding letter
  string decrypted_ciphertext = "";

  for (size_t i = 0; i < ciphertext.length(); i = i + 2) {
    // get the position of each letter
    pair<int, int> letter1_position = locateCharacter(ciphertext.at(i));
    pair<int, int> letter2_position = locateCharacter(ciphertext.at(i + 1));
    char decrypted_letter1 = '\0';
    char decrypted_letter2 = '\0';

    if (letter1_position.first == letter2_position.first) {
      // circular shift left
      decrypted_letter1 = circularShift(ciphertext.at(i), "left");
      decrypted_letter2 = circularShift(ciphertext.at(i + 1), "left");
    }
    else if (letter1_position.second == letter2_position.second) {
      // circular shift up 
      decrypted_letter1 = circularShift(ciphertext.at(i), "up");
      decrypted_letter2 = circularShift(ciphertext.at(i + 1), "up");
     }
    else {
      decrypted_letter1 = key_matrix.at(letter1_position.first)
                                    .at(letter2_position.second);
      decrypted_letter2 = key_matrix.at(letter2_position.first)
                                    .at(letter1_position.second);
    }

    decrypted_ciphertext.push_back(decrypted_letter1); 
    decrypted_ciphertext.push_back(decrypted_letter2); 
  }

  // BUG
  // drop the fillers
  if (padding_location.empty() == false) {
    decrypted_ciphertext = dropFillers(decrypted_ciphertext);
  }
  else {
    // get the padding location from the input file
    // initialze the input file stream to the hidden file
    ifstream input_file(".playfair_padding_location", ifstream::in);

    // check if the hidden file exists
    if (!input_file) {
      perror("open input file");
    }
    else {
      string ciphertext_infile = "";

      // read the ciphertext in the file
      input_file >> ciphertext_infile;

      // if the ciphertext in the input file is equal to the user specified
      // ciphertext, remove the paddings
      if (ciphertext_infile.compare(ciphertext) == 0) {
        unsigned int location = 0;
        
        // get the first padding location
        input_file >> location;

        while (input_file.good()) {
          // store the padding location
          padding_location.push_back(location);

          // get the next padding location
          input_file >> location;
        }
  
        // close input file stream
        input_file.close();
  
        // drop the fillers
        decrypted_ciphertext = dropFillers(decrypted_ciphertext);
      }
    }
    
  }

  // BUG
  // restore the non-English characters
  //decrypted_ciphertext = restoreNonEnglishLetters(decrypted_ciphertext);

  // BUG
  // restore the corresponding upper- and lower-case
  //if (plaintext.empty() == false) {
  //  decrypted_ciphertext = restoreCase(decrypted_ciphertext);
  //}

	return decrypted_ciphertext; 
}

/**
 * The member function validates the key string in ASCII. The key string is
 * composed of upper- and/or lower-case English letters, where A-to-Z is 65 to
 * 90 and a-to-z is 97 to 122. The function also checks if the string is empty.
 * For further improvements, we would consider unicode and other locales.
 *
 * @return - True if the key is valid and False otherwise
 */
//bool Playfair::validateKey() const {
bool Playfair::validateKey(const string& user_key) {
  using namespace std;
  
  // check if the string is empty
  if (user_key.empty()) {
    cerr << "ERROR: key cannot be empty." << endl;
    return false;
  }

  // check if there is non-English letters in ASCII
  for (string::const_iterator itr = user_key.begin();
       itr != user_key.end();
       itr++) {
    if (isupper(*itr) == false && islower(*itr) == false) {
      cerr << "ERROR: key has to be English letters in ASCII" << endl;
      return false;
    }
  }

  return true;
}

/**
 * The member function removes the duplicated letter in a string while
 * preserving the order of characters in the string. It treats I and J are the
 * same character.Here we assume the input string is non-empty and is all upper-
 * or lower-case.
 */
std::string Playfair::removeDuplicates(const std::string& input_string) {
  using namespace std;

  // initialze the string without any duplicates
  string string_of_noduplicates = "";

  string_of_noduplicates.push_back(input_string.at(0));
  
  // select and store the unique characters
  string::const_iterator itr = input_string.begin();
  
  // increment the iterator b/c we processed the first element of input string
  itr++;

  /**
   * for each character, s, in the original string
   *  for each character, t, in the string of no duplicates
   *    if t is any character other than I, J, i or j
   *      if s is the same as t, then, s is a duplicate of t
   *      else s is not a duplicate of t
   *    else
   *      if s is any character other than I, J, i or j, then
   *        s is not a duplicate of t
   *      else
   *        s is a duplicate of t
   *  when s is not a duplicate of t, append s to the string of no duplicates
   */
  for (;itr != input_string.end(); itr++) {
    bool isDuplicate = true;

    for (string::iterator itr_noduplicates = string_of_noduplicates.begin();
         itr_noduplicates != string_of_noduplicates.end();
         ++itr_noduplicates) {
      if (checkIJ(*itr_noduplicates) == false) {
        if (*itr == *itr_noduplicates) {
          isDuplicate = true;
          break;
        }
        else {
          isDuplicate = false;
        }
      }
      else {
        if (checkIJ(*itr) == false) {
          isDuplicate = false;
        }
        else {
          isDuplicate = true;
          break;
        }
      }
    }

    if (isDuplicate == false) {string_of_noduplicates.push_back(*itr);}
  }

  // test the string content
  //cout << string_of_noduplicates << endl;

  return string_of_noduplicates;
}

/**
 * The member function check if the test character is either I, J, i, or j.
 *
 * @param test_character - the character to be tested
 * @return - True if the test character is either I, J, i or j.
 */
bool Playfair::checkIJ(char test_character) {
  switch (test_character) {
    case 'I':
    case 'J':
    case 'i':
    case 'j':
      return true;
    default:
      return false;
  }
}

/**
 * The member funciton processes the plaintext with a filler. It has side
 * effects. It stores the padding position.
 *
 */
std::string Playfair::padText(const std::string& text, char filler) {
  using namespace std;

  string processed_text = "";
  
  // TODO
  // document the padding
  for (size_t i = 0; i < text.length(); i = i + 2) {
    if (i == text.length() - 1) {
      processed_text.push_back(text.at(i));
      processed_text.push_back(filler);
      padding_location.push_back(processed_text.length() - 1);
    }
    else if (text.at(i) == text.at(i + 1)) {
      processed_text.push_back(text.at(i));
      processed_text.push_back(filler);
      padding_location.push_back(processed_text.length() - 1);
      i--;
    }
    else {
      processed_text.push_back(text.at(i));
      processed_text.push_back(text.at(i + 1));
    }
  }

  return processed_text;
}

/**
 * The member function set the padding location.
 */
vector<unsigned int> Playfair::setPaddingLocation(const std::string& text) {
  int length = 0;

  for (size_t i = 0; i < text.length(); i = i + 2) {
    if (i == text.length() - 1) {
      length = length + 2;
      padding_location.push_back(length - 1);
    }
    else if (text.at(i) == text.at(i + 1)) {
      length = length + 2;
      padding_location.push_back(length - 1);
      i--;
    }
    else {
      length = length + 2;
    }
  }

  return padding_location;
}



std::string Playfair::dropFillers(const std::string& text) const {
  using namespace std;

  string no_filler_text = "";

  // drop the filler
  for (size_t i = 0; i < text.length(); i++) {
    bool is_dropped = false;
    
    for (vector<unsigned int>::const_iterator itr = padding_location.begin();
         itr != padding_location.end();
         ++itr) {
      if (i == *itr) {
        is_dropped = true;
        break;
      }
    }
    
    if (is_dropped == false) {
      no_filler_text.push_back(text.at(i));
    }
  }

  return no_filler_text;
}

/**
 * The member function locate the position of target character in the key
 * matrix.
 *
 * @param my_character - target character
 */
std::pair<int, int> Playfair::locateCharacter(char my_character) const {
  using namespace std;

  pair<int, int> myposition(-1, -1);

  // find I/J in the key matrix
  // alternative solution: find the first occurance of I, J, i or j in the
  // key. The first occurance represent the I/J element in the key matrix. But
  // i guess the below code is more simpler and cleaner, so it's easy to
  // maintain
  pair<int, int> ijposition(-1, -1);

  for (size_t i = 0; i < key_matrix.size(); i++) {
    size_t found_location = key_matrix.at(i).find('I');

    if (found_location != string::npos) {
      ijposition.first = i;
      ijposition.second = found_location; //BUG: when using unsinged int type
      break;
    }

    found_location = key_matrix.at(i).find('J');

    if (found_location != string::npos) {
      ijposition.first = i;
      ijposition.second = found_location; //BUG: when using unsinged int type
      break;
   }
  }

  // if the target character is I or J
  if (checkIJ(my_character) == true) {
    myposition = ijposition;
  }
  else {
    for (size_t i = 0; i < key_matrix.size(); i++) {
      size_t found_location = key_matrix.at(i).find(my_character);

      if (found_location != string::npos) {
        myposition.first = i;
        myposition.second = found_location; //BUG: when using unsinged int type
        break;
      }
    } 
  }

  //cout << myposition.first << "," << myposition.second << endl;

  return myposition;
}
  
/**
 * The member function circular shift the character to the left, right, up or
 * down.
 */
char Playfair::circularShift(char target_character,
                             std::string shift_option) const {
  using namespace std;

  // locate the character
  pair<int, int> position = locateCharacter(target_character);

  // shift left, right, up or down
  if (shift_option.compare("left") == 0) {
    position.second = (position.second + kStringLength - 1) % kStringLength;
  }
  else if(shift_option.compare("right") == 0) {
    position.second = (position.second + 1) % kStringLength;
  }
  else if (shift_option.compare("up") == 0) {
    position.first = (position.first + kVectorLength - 1) % kVectorLength;
  }
  else if (shift_option.compare("down") == 0) {
    position.first = (position.first + 1) % kVectorLength;
  }
  else {
    cerr << "ERROR: no such shift option" << endl;
    return '\0';
  }

  return key_matrix.at(position.first).at(position.second);
}

/**
 * The member function restores the upper- and lower-case in the decrypted
 * ciphertext
 */
/*
std::string Playfair::restoreCase(const std::string& decrypted_text) const {
  using namespace std;

  // check the length of decrypted ciphertext
  if (decrypted_text.length() != plaintext.length()) {
    cerr << "ERROR: the length of decrypted ciphertext "; 
    cerr << "does not match the length of plaintext" << endl;
    return decrypted_text;
  }

  // restore case
  string restored_text = "";

  for (size_t i = 0; i < plaintext.length(); i++) {
    if (islower(plaintext.at(i)) && isupper(decrypted_text.at(i))) {
      char lowerChar = tolower(decrypted_text.at(i));
      restored_text.push_back(lowerChar);
    }
    else if (isupper(plaintext.at(i)) && islower(decrypted_text.at(i))) {
      char upperChar = toupper(decrypted_text.at(i));
      restored_text.push_back(upperChar);
    }
    else {
      restored_text.push_back(decrypted_text.at(i));
    }
  }

  //cout << restored_text << endl;

  return restored_text;
}
*/

/**
 * The member function prints the key matrix to the file. It is the caller's
 * responsibility to close the file pointer.
 */
void Playfair::printMatrix(FILE* fp) const {
  using namespace std;

  // construct the output string for the key matrix
  string output = "";

  for (vector<string>::const_iterator itr = key_matrix.begin();
       itr != key_matrix.end();
       ++itr) {
    output = output + *itr + "\n";
  }

  // write the key-matrix string to the file
  fputs(output.c_str(), fp);
}

/**
 * The member function extract Non-english letters from the text
 */
/*
std::string Playfair::extractNonEnglishLetters(const std::string& text) {
  using namespace std;

  string processed_text = "";

  // for each letter
  //  if it is non-english letter
  //    store its location and value
  //  else 
  //    store the value in the processed string
  for (size_t i = 0; i < text.length(); i++) {
    if (isupper(text.at(i)) == false && islower(text.at(i)) == false) {
      pair<size_t, char> letter_location = make_pair(i, text.at(i));
      
      nonenglish_letter_location.push_back(letter_location);
    }
    else {
      processed_text.push_back(text.at(i));
    }
  }

  return processed_text;
}
*/

/**
 * The member function restores non-english letters to the decrypted
 * ciphertext.
 */
/*
std::string Playfair::restoreNonEnglishLetters(const string& text) {
  using namespace std;

  string processed_text = text;

  // insert the non-english letter
  for (vector<pair<size_t, char> >::iterator
           itr = nonenglish_letter_location.begin();
       itr != nonenglish_letter_location.end();
       ++itr) {
    processed_text.insert(itr->first, 1, itr->second);
  }

  return processed_text;
}
*/



