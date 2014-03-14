#ifndef ROWTRANSPOSITION_H
#define ROWTRANSPOSITION_H

#include <vector>     /* For vectors */
#include <string>     /* For C++ strings */
#include <iostream>   //i/o stream
#include <algorithm>  //std::transform
#include <cctype>     //::toupper
#include <cstdio>     /* For standard I/O */
#include <cstdlib>    /* For miscellenous C functions */
#include <ctime>
#include "CipherInterface.h"


/**
 * This class implements the playfair cipher.
 * The class extends the abstract class 
 * CipherInterface.
 */

using namespace std;

class RowTransposition: public CipherInterface
{
  /** The public members **/
	public:
    RowTransposition();
    
    RowTransposition(const string& mykey);

		/**
		 * Sets the key to use
		 * @param key - the key to use
		 * @return - True if the key is valid and False otherwise
		 */
		virtual bool setKey(const string& mykey);

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
		 * Prints the RowTransposition matrix
		 * @param fp - the file pointer
		 */
		//void printMatrix(FILE* fp);
		
    /**
     * The member function validates the key
     */
    static bool validateKey(const string& mykey);

    /**
     * The member function pad the plaintext to be the multiple of the size of
     * rank key
     */
    string padText(const string& text);

    /**
     * The member function transform the linear sequence of plaintext to the
     * matrix form
     */
    vector<string> constructPlaintextMatrix(const string& plaintext);


    /**
     * getters and setters
     */
    inline vector<size_t> getKey() const {return rank_key;}

		/* The protected members */
	protected:
    vector<size_t> rank_key;


};

#endif
