#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MAIN

#include <vector>
#include <string>
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






