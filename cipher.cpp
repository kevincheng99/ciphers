#include <string>
#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstring>
#include "CipherInterface.h"
#include "Playfair.h"
#include "RowTransposition.h"
#include "Railfence.h"
#include "Caesar.h"
#include "Vigenere.h"
#include "Railfence.h"
#include "DES.h"
#include "RSA.h"

using namespace std;

int main(int argc, char** argv)
{
 /**
  * Professor Gofman's comment block
  * REPLACE THIS PART WITH YOUR CODE
  * THE CODE BELOW IS A SAMPLE TO
  * ILLUSTRATE INSTANTIATION OF CLASSES
  * THAT USE THE SAME INTERFACE.
  */  

  enum CommandLineFieldName {
    kCipherName = 1,
    kKey = 2,
    kEncryptionOrDecryption = 3,
    kInputFile = 4,
    kOutputFile = 5,
  };


  // check the command line argument
  if (argc != 6) {
    cerr << "ERROR: ./cipher <CIPHER NAME> <KEY> <ENC/DEC> <INPUT FILE> <OUTPUT FILE>" << endl;
    return -1;
  }

  // initialize input file stream object
  ifstream input_file(argv[kInputFile], ifstream::in);

  // check input file
  if (!input_file) {
    perror("open input file");
    return -2;
  }

  // read the text (plaintext or ciphertext) from a file into a string
  string text = "";
  
  // read the first line
  input_file >> text;

  // while the input file stream is good, get the next line
  while (input_file.good()) {
    string next_line = "";

    // get the next line
    input_file >> next_line;

    // append to the text
    text.append(next_line);
  }

  // close input file stream
  input_file.close();

  // check if the text is empty
  if (text.empty()) {
    cerr << "ERROR: input file should not be empty" << endl;
    return -10;
  }

  // declare a pointer to the cipher interface
  CipherInterface* cipher;

  // choose a cipher
  if (strcmp("PLF", argv[kCipherName]) == 0) {
    //cout << "Playfair Cipher" << endl; 
    
    // Create an instance of the Playfair cipher  
    cipher = new Playfair();
  }
  else if (strcmp("RTS", argv[kCipherName]) == 0) {
    //cout << "Row Transposition Cipher" << endl; 
    
    // Create an instance of the Row Transposition cipher 
    cipher = new RowTransposition();
   }
  else if (strcmp("RFC", argv[kCipherName]) == 0) {
    //cout << "Railfence Cipher" << endl; 

    // Create an instance of the Railfence cipher 
    cipher = new Railfence();
  }
  else if (strcmp("VIG", argv[kCipherName]) == 0) {
    //cout << "Vigenere Cipher" << endl; 
    
    // Create an instance of the Vignenere cipher 
    cipher = new Vigenere();
  }
  else if (strcmp("CES", argv[kCipherName]) == 0) {
    //cout << "Caesar Cipher" << endl; 
    
    //Create an instance of the Cesar cipher  
    cipher = new Caesar();
  }
  else {
    cerr << "invalid cipher name: " << argv[kCipherName] << endl;
    return -4;
  }

  // Error checks
  if (!cipher) {
    fprintf(stderr, "ERROR [%s %s %d]: could not allocate memory\n",  
    __FILE__, __FUNCTION__, __LINE__);
    exit(-1);
  }

  // Set the encryption/decription key
  string mykey(argv[kKey]);
  
  if (!(cipher->setKey(mykey))) {
    cerr << "invalid key: " << mykey << endl;
    return -5;
  }
  
  // initialize output file stream object
  // warning that this will rewrite the file
  ofstream output_file(argv[kOutputFile], ofstream::out);

  // check the output file
  if (!output_file) {
    perror("open output file");
    return -3;
  }

  // encryption or decryption
  if (strcmp("ENC", argv[kEncryptionOrDecryption]) == 0) {
    // encrypt
    string ciphertext = cipher->encrypt(text);
    
    // write to output file
    output_file << ciphertext << endl;
  }
  else if (strcmp("DEC", argv[kEncryptionOrDecryption]) == 0) {
    // decrypt
    string decrypted_ciphertext = cipher->decrypt(text);
      
    // write to the output file
    output_file << decrypted_ciphertext << endl;
  }
  else {
    cerr << "invalid ENC/DEC option: " << argv[kEncryptionOrDecryption];
    cerr << endl;
            
    // close output file stream object
    output_file.close();

    return -6;
  }
 
  // close output file stream object
  output_file.close();

  return 0;
}
