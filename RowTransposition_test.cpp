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
  vector<int> rank_key = rt_cipher.getKey();

  // check the key content
  vector<int> expected_rank_key;
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
  vector<int> rank_key = rt_cipher.getKey();

  // check the key content
  vector<int> expected_rank_key;
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
  vector<int> rank_key = rt_cipher.getKey();

  // check the rank key size
  BOOST_CHECK_EQUAL(rank_key.size(), 0);
}

BOOST_AUTO_TEST_CASE(test_setKey4) {
  string key = "z\\@c9%k/|";
  RowTransposition rt_cipher;

  // set the key
  rt_cipher.setKey(key);

  // get the transformed key
  vector<int> rank_key = rt_cipher.getKey();

  // check the transformed key content
  vector<int> expected_rank_key;
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






