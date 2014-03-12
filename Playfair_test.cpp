#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MAIN

#include <vector>
#include <string>
#include <boost/test/unit_test.hpp>
#include <boost/test/test_tools.hpp>
#include "Playfair.h"
//#include "CipherInterface.h"
#include <algorithm>
#include <cctype>
#include <utility>

using namespace std;

BOOST_AUTO_TEST_CASE(test_validateKey1) {
  string my_key = "kevin";
  
  //Playfair playfair_cipher;

  //playfair_cipher.setUserKey(my_key);

  BOOST_CHECK(Playfair::validateKey(my_key) == true);
}

BOOST_AUTO_TEST_CASE(test_validateKey2) {
  string my_key = "KEVIN";

  //Playfair playfair_cipher;

  //playfair_cipher.setUserKey(my_key);

  BOOST_CHECK(Playfair::validateKey(my_key) == true);
}

BOOST_AUTO_TEST_CASE(test_validateKey3) {
  string my_key = "KeViN";

  //Playfair playfair_cipher;

  //playfair_cipher.setUserKey(my_key);

  BOOST_CHECK(Playfair::validateKey(my_key) == true);
}

BOOST_AUTO_TEST_CASE(test_validateKey4) {
  string my_key = "Ke8in";
 
  //Playfair playfair_cipher;

  //playfair_cipher.setUserKey(my_key);
 
  BOOST_CHECK(Playfair::validateKey(my_key) == false);
}

BOOST_AUTO_TEST_CASE(test_validateKey5) {
  string my_key = "Ke[in";
 
  //Playfair playfair_cipher;

  //playfair_cipher.setUserKey(my_key);

  BOOST_CHECK(Playfair::validateKey(my_key) == false);
}

BOOST_AUTO_TEST_CASE(test_validateKey6) {
  string my_key = "Ke|in";
  
  //Playfair playfair_cipher;

  //playfair_cipher.setUserKey(my_key);

  BOOST_CHECK(Playfair::validateKey(my_key) == false);
}

BOOST_AUTO_TEST_CASE(test_validateKey7) {
  string my_key = "";
  
  //Playfair playfair_cipher;

  //playfair_cipher.setUserKey(my_key);

  BOOST_CHECK(Playfair::validateKey(my_key) == false);
}

BOOST_AUTO_TEST_CASE(test_removeDuplicates1){
  string input_string = "KEVIN";

  BOOST_CHECK_EQUAL(input_string, Playfair::removeDuplicates(input_string));
}

BOOST_AUTO_TEST_CASE(test_removeDuplicates2){
  string input_string = "kevin";

  BOOST_CHECK_EQUAL(input_string, Playfair::removeDuplicates(input_string));
}

BOOST_AUTO_TEST_CASE(test_removeDuplicates3){
  string input_string = "BANANA";

  BOOST_CHECK_EQUAL("BAN", Playfair::removeDuplicates(input_string));
}

BOOST_AUTO_TEST_CASE(test_removeDuplicates4){
  string input_string = "mississippi";

  BOOST_CHECK_EQUAL("misp", Playfair::removeDuplicates(input_string));
}

BOOST_AUTO_TEST_CASE(test_removeDuplicates5){
  string input_string = "miSSissippi";

  BOOST_CHECK_EQUAL("miSsp", Playfair::removeDuplicates(input_string));
}

BOOST_AUTO_TEST_CASE(test_removeDuplicates6){
  string input_string = "GOOGLE";

  BOOST_CHECK_EQUAL("GOLE", Playfair::removeDuplicates(input_string));
}

BOOST_AUTO_TEST_CASE(test_removeDuplicates7){
  string input_string = "Google";

  BOOST_CHECK_EQUAL("Gogle", Playfair::removeDuplicates(input_string));
}

BOOST_AUTO_TEST_CASE(test_removeDuplicates8){
  string input_string = "junjglei";

  BOOST_CHECK_EQUAL("jungle", Playfair::removeDuplicates(input_string));
}

BOOST_AUTO_TEST_CASE(test_removeDuplicates9){
  string input_string = "JUNJGLEI";

  BOOST_CHECK_EQUAL("JUNGLE", Playfair::removeDuplicates(input_string));
}

BOOST_AUTO_TEST_CASE(test_removeDuplicates10){
  string input_string = "ipjhojnej";

  BOOST_CHECK_EQUAL("iphone", Playfair::removeDuplicates(input_string));
}

BOOST_AUTO_TEST_CASE(test_removeDuplicates11){
  string input_string = "IJPHJONEJ";

  BOOST_CHECK_EQUAL("IPHONE", Playfair::removeDuplicates(input_string));
}

BOOST_AUTO_TEST_CASE(test_checkIJ){
  BOOST_CHECK(Playfair::checkIJ('I') == true);
  BOOST_CHECK(Playfair::checkIJ('J') == true);
  BOOST_CHECK(Playfair::checkIJ('i') == true);
  BOOST_CHECK(Playfair::checkIJ('j') == true);
  BOOST_CHECK(Playfair::checkIJ('K') == false);
  BOOST_CHECK(Playfair::checkIJ('a') == false);
}

BOOST_AUTO_TEST_CASE(test_setKey1){
  // key is now in lower case
  string key = "kevin";
  string upper_case_key = "";

  // conver the key to upper-case
  transform(key.begin(), key.end(), back_inserter(upper_case_key), ::toupper);
  
  // check the result of conversion
  BOOST_CHECK_EQUAL("KEVIN", upper_case_key);
}


BOOST_AUTO_TEST_CASE(test_setKey2){
  // set the user key
  string test_key = "MONARCHY";

  // initialize playfair
  Playfair playfair_cipher;

  // set the user key and key matrix
  playfair_cipher.setKey(test_key);

  // check the user key
  //BOOST_CHECK_EQUAL(test_key, playfair_cipher.getUserKey());

  // check the key matrix
  vector<string> test_key_matrix = playfair_cipher.getKeyMatrix();
  vector<string> expected_key_matrix;

  expected_key_matrix.push_back("MONAR");
  expected_key_matrix.push_back("CHYBD");
  expected_key_matrix.push_back("EFGIK");
  expected_key_matrix.push_back("LPQST");
  expected_key_matrix.push_back("UVWXZ");

  BOOST_CHECK_EQUAL_COLLECTIONS(test_key_matrix.begin(),
                                test_key_matrix.end(),
                                expected_key_matrix.begin(),
                                expected_key_matrix.end());
}

BOOST_AUTO_TEST_CASE(test_setKey3){
  // set the user key
  string test_key = "KEYWOKWRDYD";

  // initialize playfair
  Playfair playfair_cipher;

  // set the user key and key matrix
  playfair_cipher.setKey(test_key);

  // check the user key
  //BOOST_CHECK_EQUAL(playfair_cipher.getUserKey(), test_key);

  // check the key matrix
  vector<string> test_key_matrix = playfair_cipher.getKeyMatrix();
  vector<string> expected_key_matrix;

  expected_key_matrix.push_back("KEYWO");
  expected_key_matrix.push_back("RDABC");
  expected_key_matrix.push_back("FGHIL");
  expected_key_matrix.push_back("MNPQS");
  expected_key_matrix.push_back("TUVXZ");

  BOOST_CHECK_EQUAL_COLLECTIONS(test_key_matrix.begin(),
                                test_key_matrix.end(),
                                expected_key_matrix.begin(),
                                expected_key_matrix.end());
}

BOOST_AUTO_TEST_CASE(test_setKey4){
  // set the user key
  string test_key = "KEVINNIEVK";

  // initialize playfair
  Playfair playfair_cipher;

  // set the user key and key matrix
  playfair_cipher.setKey(test_key);

  // check the user key
  //BOOST_CHECK_EQUAL(playfair_cipher.getUserKey(), test_key);

  // check the key matrix
  vector<string> test_key_matrix = playfair_cipher.getKeyMatrix();
  vector<string> expected_key_matrix;

  expected_key_matrix.push_back("KEVIN");
  expected_key_matrix.push_back("ABCDF");
  expected_key_matrix.push_back("GHLMO");
  expected_key_matrix.push_back("PQRST");
  expected_key_matrix.push_back("UWXYZ");

  BOOST_CHECK_EQUAL_COLLECTIONS(test_key_matrix.begin(),
                                test_key_matrix.end(),
                                expected_key_matrix.begin(),
                                expected_key_matrix.end());
}

BOOST_AUTO_TEST_CASE(test_setKey5){
  // set the user key
  string test_key = "KEVJN";

  // initialize playfair
  Playfair playfair_cipher;

  // set the user key and key matrix
  playfair_cipher.setKey(test_key);

  // check the user key
  // BOOST_CHECK_EQUAL(playfair_cipher.getUserKey(), test_key);

  // check the key matrix
  vector<string> test_key_matrix = playfair_cipher.getKeyMatrix();
  vector<string> expected_key_matrix;

  expected_key_matrix.push_back("KEVJN");
  expected_key_matrix.push_back("ABCDF");
  expected_key_matrix.push_back("GHLMO");
  expected_key_matrix.push_back("PQRST");
  expected_key_matrix.push_back("UWXYZ");

  BOOST_CHECK_EQUAL_COLLECTIONS(test_key_matrix.begin(),
                                test_key_matrix.end(),
                                expected_key_matrix.begin(),
                                expected_key_matrix.end());
}

BOOST_AUTO_TEST_CASE(test_setKey6){
  // set the user key
  string test_key = "kevin";

  // initialize playfair
  Playfair playfair_cipher;

  // set the user key and key matrix
  playfair_cipher.setKey(test_key);

  // check the user key
  //BOOST_CHECK_EQUAL(playfair_cipher.getUserKey(), test_key);

  // check the key matrix
  vector<string> test_key_matrix = playfair_cipher.getKeyMatrix();
  vector<string> expected_key_matrix;

  expected_key_matrix.push_back("KEVIN");
  expected_key_matrix.push_back("ABCDF");
  expected_key_matrix.push_back("GHLMO");
  expected_key_matrix.push_back("PQRST");
  expected_key_matrix.push_back("UWXYZ");

  BOOST_CHECK_EQUAL_COLLECTIONS(test_key_matrix.begin(),
                                test_key_matrix.end(),
                                expected_key_matrix.begin(),
                                expected_key_matrix.end());
}


BOOST_AUTO_TEST_CASE(test_padText1){
  Playfair playfair_cipher;

  // set the text 
  string text = "BANANA";

  // process plaintext
  char filler = 'X';

  // check the padded plaintext 
  BOOST_CHECK_EQUAL(playfair_cipher.padText(text, filler), text);

  // check the padding position
  BOOST_CHECK(playfair_cipher.getPaddingLocation().empty() == true);
}

BOOST_AUTO_TEST_CASE(test_padText2){
  Playfair playfair_cipher;

  // set the plaintext
  string text = "MISS";

  // process plaintext
  char filler = 'X';

  // check the padded plaintext 
  BOOST_CHECK_EQUAL(playfair_cipher.padText(text, filler), "MISXSX");

  // check the padding position
  vector<unsigned int> test_padding_location =
      playfair_cipher.getPaddingLocation();
  vector<unsigned int> expected_padding_location;
  
  expected_padding_location.push_back(3);
  expected_padding_location.push_back(5);

  BOOST_CHECK_EQUAL_COLLECTIONS(test_padding_location.begin(),
                                test_padding_location.end(),
                                expected_padding_location.begin(),
                                expected_padding_location.end());
}

BOOST_AUTO_TEST_CASE(test_padText3){
  Playfair playfair_cipher;

  // set the plaintex
  string text("mississipi");

  // process plaintext
  char filler = 'X';

  // check the result
  BOOST_CHECK_EQUAL(playfair_cipher.padText(text, filler), "misXsisXsipi");

  // check the padding position
  vector<unsigned int> test_padding_location =
      playfair_cipher.getPaddingLocation();
  vector<unsigned int> expected_padding_location;
  
  expected_padding_location.push_back(3);
  expected_padding_location.push_back(7);

  BOOST_CHECK_EQUAL_COLLECTIONS(test_padding_location.begin(),
                                test_padding_location.end(),
                                expected_padding_location.begin(),
                                expected_padding_location.end());
}

BOOST_AUTO_TEST_CASE(test_padText4){
  Playfair playfair_cipher;

  // set the plaintext
  string text("mississipii");

  // process plaintext
  char filler = 'X';

  // check the result
  BOOST_CHECK_EQUAL(playfair_cipher.padText(text, filler), "misXsisXsipiiX");

  // check the padding position
  vector<unsigned int> test_padding_location =
      playfair_cipher.getPaddingLocation();
  vector<unsigned int> expected_padding_location;
  
  expected_padding_location.push_back(3);
  expected_padding_location.push_back(7);
  expected_padding_location.push_back(13);

  BOOST_CHECK_EQUAL_COLLECTIONS(test_padding_location.begin(),
                                test_padding_location.end(),
                                expected_padding_location.begin(),
                                expected_padding_location.end());
}

BOOST_AUTO_TEST_CASE(test_padText5){
  Playfair playfair_cipher;

  // set the plaintext
  string text("HELLOALL");

  // process plaintext
  char filler = 'X';

  // check the result
  BOOST_CHECK_EQUAL(playfair_cipher.padText(text, filler), "HELXLOALLX");

  // check the padding position
  vector<unsigned int> test_padding_location =
      playfair_cipher.getPaddingLocation();
  vector<unsigned int> expected_padding_location;
  
  expected_padding_location.push_back(3);
  expected_padding_location.push_back(9);

  BOOST_CHECK_EQUAL_COLLECTIONS(test_padding_location.begin(),
                                test_padding_location.end(),
                                expected_padding_location.begin(),
                                expected_padding_location.end());
}

BOOST_AUTO_TEST_CASE(test_locateCharacter1) {
  Playfair playfair_cipher;

  // set the key
  playfair_cipher.setKey("MONARCHY");

  // locate the target character
  pair<int, int> position = playfair_cipher.locateCharacter('K');
  pair<int, int> expected_position(2, 4);

  // check result
  BOOST_CHECK(position == expected_position);
}

BOOST_AUTO_TEST_CASE(test_locateCharacter2) {
  Playfair playfair_cipher;

  // set the key
  playfair_cipher.setKey("MONARCHY");

  // locate the target character
  pair<int, int> position = playfair_cipher.locateCharacter('k');
  pair<int, int> expected_position(-1, -1);

  // check result
  BOOST_CHECK(position == expected_position);
}

BOOST_AUTO_TEST_CASE(test_locateCharacter3) {
  Playfair playfair_cipher;

  // set the key
  playfair_cipher.setKey("MONARCHY");

  // locate the target character
  pair<int, int> position = playfair_cipher.locateCharacter('@');
  pair<int, int> expected_position(-1, -1);

  // check result
  BOOST_CHECK(position == expected_position);
}

BOOST_AUTO_TEST_CASE(test_locateCharacter4) {
  Playfair playfair_cipher;

  // set the key
  playfair_cipher.setKey("MONARCHY");

  // locate the target character
  pair<int, int> position = playfair_cipher.locateCharacter('I');
  pair<int, int> expected_position(2, 3);

  // check result
  BOOST_CHECK(position == expected_position);
}

BOOST_AUTO_TEST_CASE(test_locateCharacter5) {
  Playfair playfair_cipher;

  // set the key
  playfair_cipher.setKey("MONARCHY");

  // locate the target character
  pair<int, int> position = playfair_cipher.locateCharacter('J');
  pair<int, int> expected_position(2, 3);

  // check result
  BOOST_CHECK(position == expected_position);
}

BOOST_AUTO_TEST_CASE(test_circularShift1) {
  Playfair playfair_cipher;

  // set the key
  playfair_cipher.setKey("MONARCHY");

  // circular shift left
  char shifted_character = playfair_cipher.circularShift('E', "left");
  
  // check result
  BOOST_CHECK_EQUAL(shifted_character, 'K');
}

BOOST_AUTO_TEST_CASE(test_circularShift2) {
  Playfair playfair_cipher;

  // set the key
  playfair_cipher.setKey("MONARCHY");

  // circular shift left
  char shifted_character = playfair_cipher.circularShift('G', "left");
  
  // check result
  BOOST_CHECK_EQUAL(shifted_character, 'F');
}

BOOST_AUTO_TEST_CASE(test_circularShift3) {
  Playfair playfair_cipher;

  // set the key
  playfair_cipher.setKey("MONARCHY");

  // circular shift left
  char shifted_character = playfair_cipher.circularShift('G', "up");
  
  // check result
  BOOST_CHECK_EQUAL(shifted_character, 'Y');
}

BOOST_AUTO_TEST_CASE(test_circularShift4) {
  Playfair playfair_cipher;

  // set the key
  playfair_cipher.setKey("MONARCHY");

  // circular shift left
  char shifted_character = playfair_cipher.circularShift('R', "up");
  
  // check result
  BOOST_CHECK_EQUAL(shifted_character, 'Z');
}

BOOST_AUTO_TEST_CASE(test_circularShift5) {
  Playfair playfair_cipher;

  // set the key
  playfair_cipher.setKey("MONARCHY");

  // circular shift left
  char shifted_character = playfair_cipher.circularShift('Q', "right");
  
  // check result
  BOOST_CHECK_EQUAL(shifted_character, 'S');
}

BOOST_AUTO_TEST_CASE(test_circularShift6) {
  Playfair playfair_cipher;

  // set the key
  playfair_cipher.setKey("MONARCHY");

  // circular shift left
  char shifted_character = playfair_cipher.circularShift('T', "right");
  
  // check result
  BOOST_CHECK_EQUAL(shifted_character, 'L');
}

BOOST_AUTO_TEST_CASE(test_circularShift7) {
  Playfair playfair_cipher;

  // set the key
  playfair_cipher.setKey("MONARCHY");

  // circular shift left
  char shifted_character = playfair_cipher.circularShift('T', "down");
  
  // check result
  BOOST_CHECK_EQUAL(shifted_character, 'Z');
}

BOOST_AUTO_TEST_CASE(test_circularShift8) {
  Playfair playfair_cipher;

  // set the key
  playfair_cipher.setKey("MONARCHY");

  // circular shift left
  char shifted_character = playfair_cipher.circularShift('W', "down");
  
  // check result
  BOOST_CHECK_EQUAL(shifted_character, 'N');
}

BOOST_AUTO_TEST_CASE(test_circularShift9) {
  Playfair playfair_cipher;

  // set the key
  playfair_cipher.setKey("MONARCHY");

  // circular shift left
  char shifted_character = playfair_cipher.circularShift('W', "kevin");
  
  // check result
  BOOST_CHECK(shifted_character != 'N');
}

BOOST_AUTO_TEST_CASE(test_encrypt1) {
  // initialize the cipher
  string key = "MONARCHY";
  string plaintext = "ar";
  Playfair playfair_cipher(key);

  //check the encrypted text
  BOOST_CHECK_EQUAL(playfair_cipher.encrypt(plaintext), "RM");
}

BOOST_AUTO_TEST_CASE(test_encrypt2) {
  // initialize the cipher
  string key = "MONARCHY";
  string plaintext = "mu";
  Playfair playfair_cipher(key);

  //check the encrypted text
  BOOST_CHECK_EQUAL(playfair_cipher.encrypt(plaintext), "CM");
}

BOOST_AUTO_TEST_CASE(test_encrypt3) {
  // initialize the cipher
  string key = "MONARCHY";
  string plaintext = "hs";
  Playfair playfair_cipher(key);

  //check the encrypted text
  BOOST_CHECK_EQUAL(playfair_cipher.encrypt(plaintext), "BP");
}

BOOST_AUTO_TEST_CASE(test_encrypt4) {
  // initialize the cipher
  string key = "MONARCHY";
  string plaintext = "ea";
  Playfair playfair_cipher(key);

  //check the encrypted text
  BOOST_CHECK_EQUAL(playfair_cipher.encrypt(plaintext), "IM");
}

BOOST_AUTO_TEST_CASE(test_encrypt5) {
  // initialize the cipher
  string key = "MONARCHY";
  string plaintext = "security";
  Playfair playfair_cipher(key);

  //check the encrypted text
  BOOST_CHECK_EQUAL(playfair_cipher.encrypt(plaintext), "LIEMAKQD");
}

BOOST_AUTO_TEST_CASE(test_encrypt6) {
  // initialize the cipher
  string key = "MONARCHY";
  string plaintext = "mississipi";
  Playfair playfair_cipher(key);

  //check the encrypted text
  BOOST_CHECK_EQUAL(playfair_cipher.encrypt(plaintext), "AEXAXSXAXSSF");
}

BOOST_AUTO_TEST_CASE(test_encrypt7) {
  // initialize the cipher
  string key = "MONARCHY";
  string plaintext = "miss";
  Playfair playfair_cipher(key);

  //check the encrypted text
  BOOST_CHECK_EQUAL(playfair_cipher.encrypt(plaintext), "AEXAXA");
}

BOOST_AUTO_TEST_CASE(test_decrypt1) {
  // initialize the cipher
  string key = "MONARCHY";
  string plaintext = "MISS";
  Playfair playfair_cipher(key);
  
  // set the padding position
  playfair_cipher.setPaddingLocation(plaintext);

  string ciphertext = "AEXAXA";

  // check the content
  BOOST_CHECK_EQUAL(playfair_cipher.decrypt(ciphertext), plaintext);
}

BOOST_AUTO_TEST_CASE(test_decrypt2) {
  // initialize the cipher
  string key = "MONARCHY";
  Playfair playfair_cipher(key);
  
  // check the content
  BOOST_CHECK_EQUAL(playfair_cipher.decrypt("AEXAXA"), "MISXSX");
}

BOOST_AUTO_TEST_CASE(test_decrypt3) {
  // initialize the cipher
  string key = "MONARCHY";
  string plaintext = "MISS";
  Playfair playfair_cipher(key);
  
  // encrypt the plaintext
  string ciphertext = playfair_cipher.encrypt(plaintext);

  // check the content
  BOOST_CHECK_EQUAL(playfair_cipher.decrypt(ciphertext), plaintext);
}

BOOST_AUTO_TEST_CASE(test_decrypt4) {
  // initialize the cipher
  string key = "MONARCHY";
  string plaintext = "SECURITY";
  Playfair playfair_cipher(key);

  // set the padding location
  playfair_cipher.setPaddingLocation(plaintext);

  string ciphertext = "LIEMAKQD";

  // check the content
  BOOST_CHECK_EQUAL(playfair_cipher.decrypt(ciphertext), plaintext);
}

BOOST_AUTO_TEST_CASE(test_decrypt5) {
  // initialize the cipher
  string key = "MONARCHY";
  Playfair playfair_cipher(key);
  
  // check the content
  BOOST_CHECK_EQUAL(playfair_cipher.decrypt("LIEMAKQD"), "SECURITY");
}

BOOST_AUTO_TEST_CASE(test_decrypt7) {
  // initialize the cipher
  string key = "MONARCHY";
  string plaintext = "MISSISSIPI";
  Playfair playfair_cipher(key);

  // set the padding location
  playfair_cipher.setPaddingLocation(plaintext);

  string ciphertext = "AEXAXSXAXSSF";

  // check the content
  BOOST_CHECK_EQUAL(playfair_cipher.decrypt(ciphertext), plaintext);
}

BOOST_AUTO_TEST_CASE(test_decrypt8) {
  // initialize the cipher
  string key = "MONARCHY";
  Playfair playfair_cipher(key);
  
  // check the content
  BOOST_CHECK_EQUAL(playfair_cipher.decrypt("AEXAXSXAXSSF"), "MISXSISXSIPI");
}

// keyword: no I or J
// plaintext: I, upper-case and no filling
BOOST_AUTO_TEST_CASE(test_decrypt6) {
  // initialize the cipher
  string key = "MONARCHY";
  string plaintext = "SECURITY";
  Playfair playfair_cipher(key);
  
  // encrypt the plaintext
  string ciphertext = playfair_cipher.encrypt(plaintext);

  // check the content
  BOOST_CHECK_EQUAL(playfair_cipher.decrypt(ciphertext), plaintext);
}

// keyword: no I or J
// plaintext: I, upper-case and filling
BOOST_AUTO_TEST_CASE(test_decrypt9) {
  // initialize the cipher
  string key = "MONARCHY";
  string plaintext = "MISSISSIPI";
  Playfair playfair_cipher(key);
  
  // encrypt the plaintext
  string ciphertext = playfair_cipher.encrypt(plaintext);

  // check the content
  BOOST_CHECK_EQUAL(playfair_cipher.decrypt(ciphertext), plaintext);
}

// keyword: no I or J
// plaintext: i, lower-case and filling
BOOST_AUTO_TEST_CASE(test_decrypt10) {
  // initialize the cipher
  string key = "MONARCHY";
  string plaintext = "mississipi";
  Playfair playfair_cipher(key);
  
  // encrypt the plaintext
  string ciphertext = playfair_cipher.encrypt(plaintext);

  // check the content
  //BOOST_CHECK_EQUAL(playfair_cipher.decrypt(ciphertext), plaintext);
  BOOST_CHECK_EQUAL(playfair_cipher.decrypt(ciphertext), "MISSISSIPI");
}

// keyword: no I or J
// plaintext: J, upper-case and filling
BOOST_AUTO_TEST_CASE(test_decrypt11) {
  // initialize the cipher
  string key = "MONARCHY";
  string plaintext = "MJSSJSSJPJ";
  Playfair playfair_cipher(key);
  
  // encrypt the plaintext
  string ciphertext = playfair_cipher.encrypt(plaintext);

  // check the content
  BOOST_CHECK_EQUAL(playfair_cipher.decrypt(ciphertext), "MISSISSIPI");
}

// keyword: no I or J
// plaintext: i, j, lower-case and filling
BOOST_AUTO_TEST_CASE(test_decrypt12) {
  // initialize the cipher
  string key = "MONARCHY";
  string plaintext = "mjssjssipi";
  Playfair playfair_cipher(key);
  
  // encrypt the plaintext
  string ciphertext = playfair_cipher.encrypt(plaintext);

  // check the content
  //BOOST_CHECK_EQUAL(playfair_cipher.decrypt(ciphertext), "mississipi");
  BOOST_CHECK_EQUAL(playfair_cipher.decrypt(ciphertext), "MISSISSIPI");
}

// keyword: I
// plaintext: i, j, lower-case and filling
BOOST_AUTO_TEST_CASE(test_decrypt13) {
  // initialize the cipher
  string key = "KEVIN";
  string plaintext = "mjssjssipi";
  Playfair playfair_cipher(key);
  
  // encrypt the plaintext
  string ciphertext = playfair_cipher.encrypt(plaintext);

  // check the content
  //BOOST_CHECK_EQUAL(playfair_cipher.decrypt(ciphertext), "mississipi");
  BOOST_CHECK_EQUAL(playfair_cipher.decrypt(ciphertext), "MISSISSIPI");
}

// keyword: J
// plaintext: i, j, lower-case and filling
BOOST_AUTO_TEST_CASE(test_decrypt14) {
  // initialize the cipher
  string key = "KEVJN";
  string plaintext = "mjssjssipi";
  Playfair playfair_cipher(key);
  
  // encrypt the plaintext
  string ciphertext = playfair_cipher.encrypt(plaintext);

  // check the content
  //BOOST_CHECK_EQUAL(playfair_cipher.decrypt(ciphertext), "mjssjssjpj");
  BOOST_CHECK_EQUAL(playfair_cipher.decrypt(ciphertext), "MJSSJSSJPJ");
}

// keyword: i
// plaintext: i, j, lower-case and filling
BOOST_AUTO_TEST_CASE(test_decrypt15) {
  // initialize the cipher
  string key = "KEViN";
  string plaintext = "mjssjssipi";
  Playfair playfair_cipher(key);
  
  // encrypt the plaintext
  string ciphertext = playfair_cipher.encrypt(plaintext);

  // check the content
  //BOOST_CHECK_EQUAL(playfair_cipher.decrypt(ciphertext), "mississipi");
  BOOST_CHECK_EQUAL(playfair_cipher.decrypt(ciphertext), "MISSISSIPI");
}

// keyword: j
// plaintext: i, j, lower-case and filling
BOOST_AUTO_TEST_CASE(test_decrypt16) {
  // initialize the cipher
  string key = "KEVjN";
  string plaintext = "mjssjssipi";
  Playfair playfair_cipher(key);
  
  // encrypt the plaintext
  string ciphertext = playfair_cipher.encrypt(plaintext);

  // check the content
  //BOOST_CHECK_EQUAL(playfair_cipher.decrypt(ciphertext), "mjssjssjpj");
  BOOST_CHECK_EQUAL(playfair_cipher.decrypt(ciphertext), "MJSSJSSJPJ");
}

// keyword: I
// plaintext: i, j, upper- and lower-case and filling
BOOST_AUTO_TEST_CASE(test_decrypt17) {
  // initialize the cipher
  string key = "KEVIN";
  string plaintext = "mjssJssIpi";
  Playfair playfair_cipher(key);
  
  // encrypt the plaintext
  string ciphertext = playfair_cipher.encrypt(plaintext);

  // check the content
  //BOOST_CHECK_EQUAL(playfair_cipher.decrypt(ciphertext), "missIssIpi");
  BOOST_CHECK_EQUAL(playfair_cipher.decrypt(ciphertext), "MISSISSIPI");
}

// keyword: J
// plaintext: i, j, upper- and lower-case and filling
BOOST_AUTO_TEST_CASE(test_decrypt18) {
  // initialize the cipher
  string key = "KEVJN";
  string plaintext = "mJssjssipI";
  Playfair playfair_cipher(key);
  
  // encrypt the plaintext
  string ciphertext = playfair_cipher.encrypt(plaintext);

  // check the content
  //BOOST_CHECK_EQUAL(playfair_cipher.decrypt(ciphertext), "mJssjssjpJ");
  BOOST_CHECK_EQUAL(playfair_cipher.decrypt(ciphertext), "MJSSJSSJPJ");
}

// keyword: I, J
// plaintext: i, j, upper- and lower-case and filling
BOOST_AUTO_TEST_CASE(test_decrypt19) {
  // initialize the cipher
  string key = "KEVJIN";
  string plaintext = "mJssjssipI";
  Playfair playfair_cipher(key);
  
  // encrypt the plaintext
  string ciphertext = playfair_cipher.encrypt(plaintext);

  // check the content
  //BOOST_CHECK_EQUAL(playfair_cipher.decrypt(ciphertext), "mJssjssjpJ");
  BOOST_CHECK_EQUAL(playfair_cipher.decrypt(ciphertext), "MJSSJSSJPJ");
}

// keyword: I, J
// plaintext: i, j, upper- and lower-case and filling
BOOST_AUTO_TEST_CASE(test_decrypt20) {
  // initialize the cipher
  string key = "KEVIVJN";
  string plaintext = "mJssjssipI";
  Playfair playfair_cipher(key);
  
  // encrypt the plaintext
  string ciphertext = playfair_cipher.encrypt(plaintext);

  // check the content
  //BOOST_CHECK_EQUAL(playfair_cipher.decrypt(ciphertext), "mIssissipI");
  BOOST_CHECK_EQUAL(playfair_cipher.decrypt(ciphertext), "MISSISSIPI");
}

// keyword: I, J
// plaintext: i, j, upper- and lower-case and no filling
BOOST_AUTO_TEST_CASE(test_decrypt21) {
  // initialize the cipher
  string key = "KEVIVJN";
  string plaintext = "SeCujZRity";
  Playfair playfair_cipher(key);
  
  // encrypt the plaintext
  string ciphertext = playfair_cipher.encrypt(plaintext);

  // check the content
  //BOOST_CHECK_EQUAL(playfair_cipher.decrypt(ciphertext), "SeCuiZRity");
  BOOST_CHECK_EQUAL(playfair_cipher.decrypt(ciphertext), "SECUIZRITY");
}

// keyword: I, J
// plaintext: i, j, upper- and lower-case and no filling
BOOST_AUTO_TEST_CASE(test_decrypt22) {
  // initialize the cipher
  string key = "kEVjvIn";
  string plaintext = "SeCujZRity";
  Playfair playfair_cipher(key);
  
  // encrypt the plaintext
  string ciphertext = playfair_cipher.encrypt(plaintext);

  // check the content
  //BOOST_CHECK_EQUAL(playfair_cipher.decrypt(ciphertext), "SeCujZRjty");
  BOOST_CHECK_EQUAL(playfair_cipher.decrypt(ciphertext), "SECUJZRJTY");
}

BOOST_AUTO_TEST_CASE(test_decrypt23) {
  // initialize the cipher
  string key = "kevin";
  string plaintext = "SeCujZRity";
  Playfair playfair_cipher(key);
  
  // encrypt the plaintext
  string ciphertext = playfair_cipher.encrypt(plaintext);

  // check the content
  //BOOST_CHECK_EQUAL(playfair_cipher.decrypt(ciphertext), "SeCuiZRity");
  BOOST_CHECK_EQUAL(playfair_cipher.decrypt(ciphertext), "SECUIZRITY");
}

BOOST_AUTO_TEST_CASE(test_printMatrix) {
  FILE* outfile;
  
  // open file to write
  outfile = fopen ("delete_me.txt" , "w");
  
  // print the matrix to the output file
  if (outfile == NULL) 
    perror("Error opening file"); 
  else {
    Playfair playfair_cipher("MONARCHY");
    playfair_cipher.printMatrix(outfile);
  } 

  fclose (outfile);
}

/*
BOOST_AUTO_TEST_CASE(test_extractNonEnglishLetters1) {
  Playfair playfair_cipher;
  string processed_string =
             playfair_cipher.extractNonEnglishLetters("hello world");

  // check the processed string
  BOOST_CHECK_EQUAL(processed_string, "helloworld");

  // check the extracted non-english character
  vector<pair<size_t, char> > location;
  location = playfair_cipher.getNonEnglishLetterLocation();

  // check the vector size
  BOOST_CHECK_EQUAL(location.size(), 1);

  // check the vector content
  BOOST_CHECK_EQUAL(location.at(0).first, 5);
  BOOST_CHECK_EQUAL(location.at(0).second, ' ');
}

BOOST_AUTO_TEST_CASE(test_extractNonEnglishLetters2) {
  Playfair playfair_cipher;
  string processed_string =
             playfair_cipher.extractNonEnglishLetters("hello,world");

  // check the processed string
  BOOST_CHECK_EQUAL(processed_string, "helloworld");

  // check the extracted non-english character
  vector<pair<size_t, char> > location;
  location = playfair_cipher.getNonEnglishLetterLocation();

  // check the vector size
  BOOST_CHECK_EQUAL(location.size(), 1);

  // check the vector content
  BOOST_CHECK_EQUAL(location.at(0).first, 5);
  BOOST_CHECK_EQUAL(location.at(0).second, ',');
}

BOOST_AUTO_TEST_CASE(test_extractNonEnglishLetters3) {
  Playfair playfair_cipher;

  string text = "To be, or Not to be!";
  string processed_string = playfair_cipher.extractNonEnglishLetters(text);

  // check the processed string
  BOOST_CHECK_EQUAL(processed_string, "TobeorNottobe");

  // check the extracted non-english character
  vector<pair<size_t, char> > location;
  location = playfair_cipher.getNonEnglishLetterLocation();

  // check the vector size
  BOOST_CHECK_EQUAL(location.size(), 7);

  // check the vector content
  BOOST_CHECK_EQUAL(location.at(0).first, 2);
  BOOST_CHECK_EQUAL(location.at(0).second, ' ');
  BOOST_CHECK_EQUAL(location.at(1).first, 5);
  BOOST_CHECK_EQUAL(location.at(1).second, ',');
  BOOST_CHECK_EQUAL(location.at(2).first, 6);
  BOOST_CHECK_EQUAL(location.at(2).second, ' ');
  BOOST_CHECK_EQUAL(location.at(3).first, 9);
  BOOST_CHECK_EQUAL(location.at(3).second,' ');
  BOOST_CHECK_EQUAL(location.at(4).first, 13);
  BOOST_CHECK_EQUAL(location.at(4).second, ' ');
  BOOST_CHECK_EQUAL(location.at(5).first, 16);
  BOOST_CHECK_EQUAL(location.at(5).second,' ');
  BOOST_CHECK_EQUAL(location.at(6).first, 19);
  BOOST_CHECK_EQUAL(location.at(6).second,'!');
}

BOOST_AUTO_TEST_CASE(test_restoreNonEnglishLetters1) {
  Playfair playfair_cipher;

  string text = "To be, or Not to be!";
  string processed_string = playfair_cipher.extractNonEnglishLetters(text);

  // check the processed string
  BOOST_CHECK_EQUAL(processed_string, "TobeorNottobe");

  // restore the letters
  processed_string = playfair_cipher.restoreNonEnglishLetters(processed_string);

  // check the restored string
  BOOST_CHECK_EQUAL(processed_string, text);
}

BOOST_AUTO_TEST_CASE(test_restoreNonEnglishLetters2) {
  Playfair playfair_cipher;

  string text = "Inserts a copy of the sequence of characters in the range [first,last), in the same order.";
  string processed_string = playfair_cipher.extractNonEnglishLetters(text);

  // check the processed string
  BOOST_CHECK_EQUAL(processed_string, "Insertsacopyofthesequenceofcharactersintherangefirstlastinthesameorder");

  // restore the letters
  processed_string = playfair_cipher.restoreNonEnglishLetters(processed_string);

  // check the restored string
  BOOST_CHECK_EQUAL(processed_string, text);
}

BOOST_AUTO_TEST_CASE(test_encryption_decryption1) {
  Playfair playfair_cipher("SecuRity");
  string text = "Inserts a copy of the sequence of characters in the range [first,last), in the same order.";
  string ciphertext = playfair_cipher.encrypt(text);
  string decrypted_ciphertext = playfair_cipher.decrypt(ciphertext);

  BOOST_CHECK_EQUAL(decrypted_ciphertext, text);
}
*/
