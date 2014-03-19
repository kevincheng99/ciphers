#ifndef PLAYFAIR_H
#define PLAYFAIR_H

#include <cstdio>  /* For standard I/O */
#include <cstdlib> /* For miscellenous C functions */
#include "CipherInterface.h"
#include <vector>   /* For vectors */
#include <string>   /* For C++ strings */
#include <iostream> // std input/output
#include <fstream>  // input and output file
#include <algorithm>  // std::transform
#include <cctype> //::toupper and not std::toupper
#include <utility>  //std::pair

using namespace std;

/**
 * This class implements the playfair cipher.
 * The class extends the abstract class 
 * CipherInterface.
 */

class Playfair: public CipherInterface
{
  /** The public members **/
  public:
    Playfair();

    Playfair(const string& my_key);

    //Playfair(const string& my_key, const string& my_plaintext);

    /**
     * Sets the key to use
     * @param key - the key to use
     * @return - True if the key is valid and False otherwise
     */
    virtual bool setKey(const string& key);

    /** 
     * Encrypts a plaintext string
     * @param plaintext - the plaintext string
     * @return - the encrypted ciphertext string
     */
    virtual string encrypt(const string& plaintext);

    /**
     * Decrypts a string of ciphertext
     * @param ciphertext - the ciphertext
     * @return - the plaintext
     */
    virtual string decrypt(const string& ciphertext);
      
    /**
     * Prints the Playfair matrix
     * @param fp - the file pointer
     */
    void printMatrix(FILE* fp) const;

    /**
     * The member function validates the key string in ASCII.
     */
    //bool validateKey() const;
    static bool validateKey(const string& key);

    /**
     * The member function removes the duplicated letter in a string while
     * preserving the order of characters in the string.
     */ 
    static string removeDuplicates(const string& input_string);

    /**
     * The helper function determines if a given character is either I, J, i or
     * j.
     */
    static bool checkIJ(char test_character);
    
    /**
     * The member funciton pads the text with the specified filler.
     */
    string padText(const string& text, char filler);
   
    /**
     * The member function drop the fillers in the text
     */
    string dropFillers(const string& text) const;

    /**
     * The member function locate the position of character in the key matrix
     */
    pair<int, int> locateCharacter(char my_character) const;

    /**
     * The member function circular shift a character left, right, up or down.
     */
    char circularShift(char target_character, string shift_option) const;

    /**
     * The member function restore the case of decrypted ciphertext
     */
    //string restoreCase(const string& decrypted_text) const;

    /**
     * The member function extracts Non-english letters from the text
     */
    //string extractNonEnglishLetters(const string& text);
    
    /**
     * The member function restores non-english letters to the decrypted
     * ciphertext.
     */
    //string restoreNonEnglishLetters(const string& text);

    /**
     * getters and setters
     */
    //inline string getUserKey() const {return user_key;}

    //inline void setUserKey(const string& my_key) {user_key = my_key;}
    
    inline vector<string> getKeyMatrix() const {return key_matrix;}
    
    //inline string getPlaintext() {return plaintext;}
    
    //inline void setPlaintext(const string& my_plaintext) {
    //  plaintext = my_plaintext;
    //}

    vector<unsigned int> setPaddingLocation(const string& text);

    inline vector<unsigned int> getPaddingLocation() const {
      return padding_location;
    }
    
    //inline string getCiphertext() {return ciphertext;}
    //inline vector<pair<size_t, char> > getNonEnglishLetterLocation() {
    //  return nonenglish_letter_location;
    //}
 
  /* The protected members */
  protected:
    const int kVectorLength;
    const int kStringLength;
    const char filler;
    vector<unsigned int> padding_location;
    vector<string> key_matrix;
    //string user_key;
    //vector<pair<size_t, char> > nonenglish_letter_location;
    //string plaintext;
    //string ciphertext;

  

};

#endif


