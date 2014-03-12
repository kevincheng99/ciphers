# Name: Tsu-Hsiang Kevin Cheng
# Class: CPSC433
# Assignment: 1
# Email: kevincheng99@csu.fullerton.edu
# Due Date: March 20, 2014
# 
# DESCRIPTION
#		To better comprehend the classical ciphers, we implemented five classical
#		ciphers, including Playfair, Row Transposition, Railfence, Vigenre and
#		Caesar. This Makefile would compile and link the Boost testing codes for
#		each classical ciphers. Thus, it is very suitable to perform whitebox
#		testing on each one of classical ciphers. 
#

CC = g++
CFLAG = -Wall -g
LDFLAG = -lboost_unit_test_framework

all: cipher test_playfair test_rowtransposition

cipher: cipher.o Playfair.o Caesar.o Vigenere.o RowTransposition.o
	$(CC) $(CFLAG) cipher.o Playfair.o Caesar.o Vigenere.o -o cipher

cipher.o: cipher.cpp
	$(CC) $(CFLAG)  -c cipher.cpp 

Playfair.o: Playfair.cpp Playfair.h CipherInterface.h
	$(CC) $(CFLAG) -c Playfair.cpp

Caesar.o: Caesar.cpp Caesar.h CipherInterface.h
	$(CC) $(CFLAG) -c Caesar.cpp
	
Vigenere.o: Vigenere.cpp Vigenere.h CipherInterface.h
	$(CC) $(CFLAG) -c Vigenere.cpp

RowTransposition.o: RowTransposition.cpp RowTransposition.h CipherInterface.h
	$(CC) $(CFLAG) -c RowTransposition.cpp

test_playfair: Playfair_test.cpp Playfair.o
	$(CC) $(CFLAG) -o test_playfair Playfair_test.cpp Playfair.o $(LDFLAG)

test_rowtransposition: RowTransposition_test.cpp RowTransposition.o
	$(CC) $(CFLAG) -o test_rowtransposition RowTransposition_test.cpp RowTransposition.o $(LDFLAG)

.PHONY: clean clean_tests
clean:
	rm *.o cipher 

clean_test:
	rm test_playfair test_rowtransposition
