# Name: Tsu-Hsiang Kevin Cheng
# Class: CPSC433
# Assignment: 1
# Email: kevincheng99@csu.fullerton.edu
# Due Date: March 20, 2014
# 
# DESCRIPTION
#		To better comprehend the classical and block ciphers, we
#		implemented five classical ciphers, including Playfair, Row
#		Transposition, Railfence, Vigenre and Caesar, and two block
#		ciphers, DES and RSA.
#

CC = g++
CFLAG = -Wall -g
LDFLAG = -lboost_unit_test_framework -lcrypto

all: cipher RSA_specific test_playfair test_rowtransposition

cipher: cipher.o Playfair.o Caesar.o Vigenere.o RowTransposition.o Railfence.o DES.o RSA.o
	$(CC) $(CFLAG) cipher.o Playfair.o Caesar.o Vigenere.o RowTransposition.o Railfence.o DES.o RSA.o -o cipher $(LDFLAG)

RSA_specific:	RSA_specific.o
	g++ RSA_specific.o -o RSA_specific -lcrypto

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
	
Railfence.o: Railfence.cpp Railfence.h CipherInterface.h
	$(CC) $(CFLAG) -c Railfence.cpp

DES.o:	DES.cpp DES.h
	g++ -g -c DES.cpp

RSA.o:	RSA.cpp RSA.h
	g++ -g -c RSA.cpp

RSA_specific.o:	RSA_specific.cpp
	g++ -g -c RSA_specific.cpp

test_playfair: Playfair_test.cpp Playfair.o
	$(CC) $(CFLAG) -o test_playfair Playfair_test.cpp Playfair.o $(LDFLAG)

test_rowtransposition: RowTransposition_test.cpp RowTransposition.o
	$(CC) $(CFLAG) -o test_rowtransposition RowTransposition_test.cpp RowTransposition.o $(LDFLAG)

.PHONY: clean clean_tests
clean:
	rm *.o cipher RSA_specific

clean_test:
	rm test_playfair test_rowtransposition
