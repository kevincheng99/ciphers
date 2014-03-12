#include <string>
#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstring>
#include "CipherInterface.h"
#include "Playfair.h"
#include "Caesar.h"
#include "Vigenere.h"

using namespace std;

int main(int argc, char** argv)
{
  /* REPLACE THIS PART WITH YOUR CODE
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

  // initialize output file stream object
  // warning that this will rewrite the file
  ofstream output_file(argv[kOutputFile], ofstream::out);

  // check the output file
  if (!output_file) {
    perror("open output file");
    return -3;
  }

  if (strcmp("PLF", argv[kCipherName]) == 0) {
    cout << "Playfair Cipher" << endl; 
    
    // Create an instance of the Playfair cipher	
    CipherInterface* cipher = new Playfair();
  
    // Error checks
    if(!cipher)
    {
      fprintf(stderr, "ERROR [%s %s %d]: could not allocate memory\n",	
      __FILE__, __FUNCTION__, __LINE__);
      exit(-1);
    }

    // Set the encryption key
    string mykey(argv[kKey]);

    if (!(cipher->setKey(mykey))) {
      cerr << "invalid key: " << mykey << endl;
      
      // close input file stream object
      input_file.close();

      // close output file stream object
      output_file.close();

      return -5;
    }

    // encryption or decryption
    if (strcmp("ENC", argv[kEncryptionOrDecryption]) == 0) {
      // read from input file
      // encrypt
      // write to output file

      // test to read input file
      string input_line = "";
      input_file >> input_line;
      
      while (!input_file.eof()) {
        cout << input_line << endl;
        input_file >> input_line;
      }
      
      string cipherText = cipher->encrypt("hereisanicestringcanyouseeit");
      
      cout << "ciphertext: " << cipherText << endl;
    }
    else if (strcmp("DEC", argv[kEncryptionOrDecryption]) == 0) {
      // read from input file
      // decrypt
      // write to output file

      string cipherText = cipher->encrypt("hereisanicestringcanyouseeit");
      string decrypted_ciphertext = cipher->decrypt(cipherText);

      cout << "decrypted ciphertext: " << decrypted_ciphertext << endl;
      
      // write to the output file
      output_file << "decrypted ciphertext: " << decrypted_ciphertext << endl;
    }
    else {
      cerr << "invalid ENC/DEC option: " << argv[kEncryptionOrDecryption];
      cerr << endl;
            
      // close input file stream object
      input_file.close();

      // close output file stream object
      output_file.close();

      return -6;
    }
  }
  else if (strcmp("RTS", argv[kCipherName]) == 0) {
    cout << "Row Transposition Cipher" << endl; 
  }
  else if (strcmp("RFC", argv[kCipherName]) == 0) {
    cout << "Railfence Cipher" << endl; 
  }
  else if (strcmp("VIG", argv[kCipherName]) == 0) {
    cout << "Vigenere Cipher" << endl; 
    
    //Create an instance of the Cesar cipher	
    CipherInterface* cipher = new Vigenere();
  
    //Error checks
    if(!cipher)
    {
      fprintf(stderr, "ERROR [%s %s %d]: could not allocate memory\n",	
      __FILE__, __FUNCTION__, __LINE__);
      exit(-1);
    }

    // Set the encryption key
    //cipher->setKey("Gofman");
    string mykey(argv[kKey]);

    if (!(cipher->setKey(mykey))) {
      cerr << "invalid key: " << mykey << endl;
                  
      // close input file stream object
      input_file.close();

      // close output file stream object
      output_file.close();

      return -5;
    }

    // encryption or decryption
    if (strcmp("ENC", argv[kEncryptionOrDecryption]) == 0) {
      // read from input file
      // encrypt
      // write to output file

      string cipherText = cipher->encrypt("KevinEnjoysEncryption");
      
      cout << "ciphertext: " << cipherText << endl;
    }
    else if (strcmp("DEC", argv[kEncryptionOrDecryption]) == 0) {
      // read from input file
      // decrypt
      // write to output file

      string cipherText = cipher->encrypt("KevinEnjoysEncryption");
      string decrypted_ciphertext = cipher->decrypt(cipherText);

      cout << "decrypted ciphertext: " << decrypted_ciphertext << endl;
    }
    else {
      cerr << "invalid ENC/DEC option: " << argv[kEncryptionOrDecryption];
      cerr << endl;
                  
      // close input file stream object
      input_file.close();

      // close output file stream object
      output_file.close();

      return -6;
    }
  }
  else if (strcmp("CES", argv[kCipherName]) == 0) {
    cout << "Caesar Cipher" << endl; 
    
    //Create an instance of the Cesar cipher	
    CipherInterface* cipher = new Caesar();
  
    //Error checks
    if(!cipher)
    {
      fprintf(stderr, "ERROR [%s %s %d]: could not allocate memory\n",	
      __FILE__, __FUNCTION__, __LINE__);
      exit(-1);
    }

    // Set the encryption key
    //string mykey("3");
    string mykey(argv[kKey]);

    if (!(cipher->setKey(mykey))) {
      cerr << "invalid key: " << mykey << endl;
            
      // close input file stream object
      input_file.close();

      // close output file stream object
      output_file.close();

       return -5;
    }

    // encryption or decryption
    if (strcmp("ENC", argv[kEncryptionOrDecryption]) == 0) {
      // read from input file
      // encrypt
      // write to output file

      string cipherText = cipher->encrypt("KevinIsAwesomeXYZ");
      
      cout << "ciphertext: " << cipherText << endl;
    }
    else if (strcmp("DEC", argv[kEncryptionOrDecryption]) == 0) {
      // read from input file
      // decrypt
      // write to output file

      string cipherText = cipher->encrypt("KevinIsAwesomeXYZ");
      string decrypted_ciphertext = cipher->decrypt(cipherText);

      cout << "decrypted ciphertext: " << decrypted_ciphertext << endl;
    }
    else {
      cerr << "invalid ENC/DEC option: " << argv[kEncryptionOrDecryption];
      cerr << endl;
                  
      // close input file stream object
      input_file.close();

      // close output file stream object
      output_file.close();

      return -6;
    }
  }
  else {
    cerr << "invalid cipher name: " << argv[kCipherName] << endl;
                
      // close input file stream object
      input_file.close();

      // close output file stream object
      output_file.close();

      return -4;
  }

  // close input file stream object
  input_file.close();

  // close output file stream object
  output_file.close();

  return 0;
}
