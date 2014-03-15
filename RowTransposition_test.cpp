#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MAIN

#include <vector>
#include <string>
#include <iostream>
#include <boost/test/unit_test.hpp>
#include <boost/test/test_tools.hpp>
#include "RowTransposition.h"
//#include "CipherInterface.h"
//#include <algorithm>
//#include <cctype>
//#include <utility>

using namespace std;

BOOST_AUTO_TEST_CASE(test_validateKey1) {
  string key = "kevin";

  BOOST_CHECK(RowTransposition::validateKey(key));
}

BOOST_AUTO_TEST_CASE(test_validateKey2) {
  string key = "";

  BOOST_CHECK(RowTransposition::validateKey(key) == false);
}

BOOST_AUTO_TEST_CASE(test_validateKey3) {
  string key = "mississipi";

  BOOST_CHECK(RowTransposition::validateKey(key) == false);
}

BOOST_AUTO_TEST_CASE(test_validateKey4) {
  string key = "123lkjasdKPI>?<MAh";

  BOOST_CHECK(RowTransposition::validateKey(key));
}

BOOST_AUTO_TEST_CASE(test_setKey1) {
  string key = "kevin";
  RowTransposition rt_cipher;

  // set the key
  rt_cipher.setKey(key);

  // get the transformed key
  vector<size_t> rank_key = rt_cipher.getKey();

  // check the key content
  vector<size_t> expected_rank_key;
  expected_rank_key.push_back(2);
  expected_rank_key.push_back(0);
  expected_rank_key.push_back(4);
  expected_rank_key.push_back(1);
  expected_rank_key.push_back(3);

  for (size_t i = 0; i < expected_rank_key.size(); i++) {
    BOOST_CHECK_EQUAL(expected_rank_key.at(i), rank_key.at(i));
  }
}

BOOST_AUTO_TEST_CASE(test_setKey2) {
  string key = "chris";
  RowTransposition rt_cipher;

  // set the key
  rt_cipher.setKey(key);

  // get the transformed key
  vector<size_t> rank_key = rt_cipher.getKey();

  // check the key content
  vector<size_t> expected_rank_key;
  expected_rank_key.push_back(0);
  expected_rank_key.push_back(1);
  expected_rank_key.push_back(3);
  expected_rank_key.push_back(2);
  expected_rank_key.push_back(4);

  for (size_t i = 0; i < expected_rank_key.size(); i++) {
    BOOST_CHECK_EQUAL(expected_rank_key.at(i), rank_key.at(i));
  }
}

BOOST_AUTO_TEST_CASE(test_setKey3) {
  string key = "mississipi";
  RowTransposition rt_cipher;

  // set the key
  rt_cipher.setKey(key);

  // get the transformed key
  vector<size_t> rank_key = rt_cipher.getKey();

  // check the rank key size
  BOOST_CHECK_EQUAL(rank_key.size(), 0);
}

BOOST_AUTO_TEST_CASE(test_setKey4) {
  string key = "z\\@c9%k/|";
  RowTransposition rt_cipher;

  // set the key
  rt_cipher.setKey(key);

  // get the transformed key
  vector<size_t> rank_key = rt_cipher.getKey();

  // check the transformed key content
  vector<size_t> expected_rank_key;
  expected_rank_key.push_back(7);
  expected_rank_key.push_back(4);
  expected_rank_key.push_back(3);
  expected_rank_key.push_back(5);
  expected_rank_key.push_back(2);
  expected_rank_key.push_back(0);
  expected_rank_key.push_back(6);
  expected_rank_key.push_back(1);
  expected_rank_key.push_back(8);

  for (size_t i = 0; i < expected_rank_key.size(); i++) {
    BOOST_CHECK_EQUAL(expected_rank_key.at(i), rank_key.at(i));
  }
}

BOOST_AUTO_TEST_CASE(test_setKey5) {
  string key = "value";
  RowTransposition rt_cipher;

  // set the key
  rt_cipher.setKey(key);

  // get the transformed key
  vector<size_t> rank_key = rt_cipher.getKey();

  // check the transformed key content
  vector<size_t> expected_rank_key;
  expected_rank_key.push_back(4);
  expected_rank_key.push_back(0);
  expected_rank_key.push_back(2);
  expected_rank_key.push_back(3);
  expected_rank_key.push_back(1);

  for (size_t i = 0; i < expected_rank_key.size(); i++) {
    BOOST_CHECK_EQUAL(expected_rank_key.at(i), rank_key.at(i));
  }
}
BOOST_AUTO_TEST_CASE(test_padText1) {
  // initialize the cipher
  string key = "KEVIN";
  RowTransposition rt_cipher(key);

  //pad text
  string text = "AB";
  string processed_text = rt_cipher.padText(text);

  //check the length processed text
  BOOST_CHECK_EQUAL(processed_text.size(), 5);
}

BOOST_AUTO_TEST_CASE(test_padText2) {
  // initialize the cipher
  string key = "KEVIN";
  RowTransposition rt_cipher(key);

  //pad text
  string text = "ABCDE";
  string processed_text = rt_cipher.padText(text);

  //check the length processed text
  BOOST_CHECK_EQUAL(processed_text.size(), 5);
}


BOOST_AUTO_TEST_CASE(test_padText3) {
  // initialize the cipher
  string key = "KEVIN";
  RowTransposition rt_cipher(key);

  //pad text
  string text = "ABCDEF";
  string processed_text = rt_cipher.padText(text);

  //check the length processed text
  BOOST_CHECK_EQUAL(processed_text.size(), 10);
}

BOOST_AUTO_TEST_CASE(test_padText4) {
  // initialize the cipher
  string key = "KEVIN";
  RowTransposition rt_cipher(key);

  //pad text
  string text = "";
  string processed_text = rt_cipher.padText(text);

  //check the length processed text
  BOOST_CHECK_EQUAL(processed_text.size(), 0);
}

BOOST_AUTO_TEST_CASE(test_constructPlaintextMatrix1) {
  // initialize the cipher
  string key = "KEVIN";
  string plaintext = "ABCDEFGHIJ";
  RowTransposition rt_cipher(key);

  // construct the plaintext matrix
  vector<string> plaintext_matrix = rt_cipher.constructPlaintextMatrix(plaintext);

  // check the matrix size
  BOOST_CHECK_EQUAL(plaintext_matrix.size(), 2);
  BOOST_CHECK_EQUAL(plaintext_matrix.at(0).length(), 5);
  BOOST_CHECK_EQUAL(plaintext_matrix.at(1).length(), 5);

  // print the matrix
  //for (vector<string>::iterator itr = plaintext_matrix.begin();
  //     itr != plaintext_matrix.end();
  //     itr++) {
  //  cout << *itr << endl;
  //}
}

BOOST_AUTO_TEST_CASE(test_constructPlaintextMatrix2) {
  // initialize the cipher
  string key = "KEVIN";
  string plaintext = "ABCDE";
  RowTransposition rt_cipher(key);

  // construct the plaintext matrix
  vector<string> plaintext_matrix = rt_cipher.constructPlaintextMatrix(plaintext);

  // check the matrix size
  BOOST_CHECK_EQUAL(plaintext_matrix.size(), 1);
  BOOST_CHECK_EQUAL(plaintext_matrix.at(0).length(), 5);

  // print the matrix
  //for (vector<string>::iterator itr = plaintext_matrix.begin();
  //     itr != plaintext_matrix.end();
  //     itr++) {
  //  cout << *itr << endl;
  //}
}

BOOST_AUTO_TEST_CASE(test_constructPlaintextMatrix3) {
  // initialize the cipher
  string key = "KEVIN";
  string plaintext = "ABCDEFGHIJKLM";
  RowTransposition rt_cipher(key);

  // construct the plaintext matrix
  vector<string> plaintext_matrix = rt_cipher.constructPlaintextMatrix(plaintext);

  // check the matrix size
  BOOST_CHECK_EQUAL(plaintext_matrix.size(), 3);
  BOOST_CHECK_EQUAL(plaintext_matrix.at(0).length(), 5);
  BOOST_CHECK_EQUAL(plaintext_matrix.at(1).length(), 5);
  BOOST_CHECK_EQUAL(plaintext_matrix.at(2).length(), 3);

  // print the matrix
  //for (vector<string>::iterator itr = plaintext_matrix.begin();
  //     itr != plaintext_matrix.end();
  //     itr++) {
  //  cout << *itr << endl;
  //}
}

BOOST_AUTO_TEST_CASE(test_constructPlaintextMatrix4) {
  // initialize the cipher
  string key = "KEVIN";
  string plaintext = "";
  RowTransposition rt_cipher(key);

  // construct the plaintext matrix
  vector<string> plaintext_matrix = rt_cipher.constructPlaintextMatrix(plaintext);

  // check the matrix size
  BOOST_CHECK_EQUAL(plaintext_matrix.size(), 0);

  // print the matrix
  //for (vector<string>::iterator itr = plaintext_matrix.begin();
  //     itr != plaintext_matrix.end();
  //     itr++) {
  //  cout << *itr << endl;
  //}
}

BOOST_AUTO_TEST_CASE(test_encrypt1) {
  // initialize the cipher
  string key = "3421567";
  string plaintext = "attackpostponeduntiltwoamxyz";
  RowTransposition rt_cipher(key);

  // encryption
  string ciphertext = rt_cipher.encrypt(plaintext);

  // check the encryption
  BOOST_CHECK_EQUAL(ciphertext, "TTNAAPTMTSUOAODWCOIXKNLYPETZ");
}

BOOST_AUTO_TEST_CASE(test_encrypt2) {
  // initialize the cipher
  string key = "3421567";
  string plaintext = "attackpostponeduntiltwoam";
  RowTransposition rt_cipher(key);

  // encryption
  string ciphertext = rt_cipher.encrypt(plaintext);

  // check the encryption
  BOOST_CHECK(ciphertext.compare("TTNAAPTMTSUOAODWCOIXKNLYPETZ") != 0);
}

BOOST_AUTO_TEST_CASE(test_encrypt3) {
  // initialize the cipher
  string key = "value";
  string plaintext = "ALICEBOBBYCHRISDELLAEDITHFRANKGRACE";
  RowTransposition rt_cipher(key);

  // encryption
  string ciphertext = rt_cipher.encrypt(plaintext);

  // check the encryption
  BOOST_CHECK_EQUAL(ciphertext, "EYSAHKEABCDEFGIBRLIAACBILTNCLOHEDRR");
}

BOOST_AUTO_TEST_CASE(test_constructCiphertextMatrix1) {
  // initialize the cipher
  string key = "3102";
  string ciphertext= "DHLBFJAEICGK";
  RowTransposition rt_cipher(key);

  // construct the ciphertext matrix
  vector<string> ciphertext_matrix = rt_cipher.constructCiphertextMatrix(ciphertext);
  vector<string> expected_matrix;

  expected_matrix.push_back("AEI");
  expected_matrix.push_back("BFJ");
  expected_matrix.push_back("CGK");
  expected_matrix.push_back("DHL");

  // check the matrix size
  BOOST_CHECK_EQUAL(ciphertext_matrix.size(), 4);
  BOOST_CHECK_EQUAL(ciphertext_matrix.at(3).length(), 3);

  // check the matrix content
  for (size_t i = 0; i < expected_matrix.size(); i++) {
    BOOST_CHECK_EQUAL(expected_matrix.at(i), ciphertext_matrix.at(i));
  }
}

BOOST_AUTO_TEST_CASE(test_constructCiphertextMatrix2) {
  // initialize the cipher
  string key = "3421567";
  string ciphertext= "TTNAAPTMTSUOAODWCOIXKNLYPETZ";
  RowTransposition rt_cipher(key);

  // construct the ciphertext matrix
  vector<string> ciphertext_matrix = rt_cipher.constructCiphertextMatrix(ciphertext);
  vector<string> expected_matrix;

  expected_matrix.push_back("AODW");
  expected_matrix.push_back("TSUO");
  expected_matrix.push_back("TTNA");
  expected_matrix.push_back("APTM");
  expected_matrix.push_back("COIX");
  expected_matrix.push_back("KNLY");
  expected_matrix.push_back("PETZ");

  // check the matrix size
  BOOST_CHECK_EQUAL(ciphertext_matrix.size(), 7);
  BOOST_CHECK_EQUAL(ciphertext_matrix.at(3).length(), 4);

  // check the matrix content
  for (size_t i = 0; i < expected_matrix.size(); i++) {
    BOOST_CHECK_EQUAL(expected_matrix.at(i), ciphertext_matrix.at(i));
  }
}

BOOST_AUTO_TEST_CASE(test_decryption1) {
  // initialize the cipher
  string key = "3421567";
  string plaintext = "attackpostponeduntiltwoam";
  RowTransposition rt_cipher(key);

  // encrypt and then, decrypt
  string ciphertext = rt_cipher.encrypt(plaintext);
  string decrypted_ciphertext = rt_cipher.decrypt(ciphertext);

  //check the process of encryption and decryption
  BOOST_CHECK_EQUAL(decrypted_ciphertext, "ATTACKPOSTPONEDUNTILTWOAM");
}

BOOST_AUTO_TEST_CASE(test_decryption2) {
  // initialize the cipher
  string key = "chris";
  string plaintext = "RETURNSANEWLYCONSTRUCTEDSTRINGOBJECTWITHITSVALUEINITIALIZEDTOA COPYOFASUBSTRINGOFTHISOBJECT";
  RowTransposition rt_cipher(key);

  // encrypt and then, decrypt
  string ciphertext = rt_cipher.encrypt(plaintext);
  string decrypted_ciphertext = rt_cipher.decrypt(ciphertext);

  //check the process of encryption and decryption
  BOOST_CHECK_EQUAL(decrypted_ciphertext, plaintext);
}

BOOST_AUTO_TEST_CASE(test_decryption3) {
  // initialize the cipher
  string key = "chris";
  string plaintext = "ROWTRANSPOSITIONCIPHER";
  RowTransposition rt_cipher(key);

  // encrypt and then, decrypt
  string ciphertext = rt_cipher.encrypt(plaintext);
  string decrypted_ciphertext = rt_cipher.decrypt(ciphertext);

  //check the process of encryption and decryption
  BOOST_CHECK_EQUAL(decrypted_ciphertext, plaintext);
}















