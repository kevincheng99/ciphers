# Name: Tsu-Hsiang Kevin Cheng
# Class: CPSC433
# Assignment: 1
# Email: kevincheng99@csu.fullerton.edu
# Due Date: March 20, 2014
# 
# DESCRIPTION
#		To better comprehend the classical ciphers, we implemented five classical
#		ciphers, including Playfair, Row Transposition, Railfence, Vigenre and
#		Caesar.
#


CC = g++
CFLAG = -Wall -g

all: cipher

cipher: cipher.o Playfair.o Caesar.o Vigenere.o
	$(CC) $(CFLAG) cipher.o Playfair.o Caesar.o Vigenere.o -o cipher

cipher.o: cipher.cpp
	$(CC) $(CFLAG)  -c cipher.cpp 

Playfair.o: Playfair.cpp Playfair.h CipherInterface.h
	$(CC) $(CFLAG) -c Playfair.cpp

Caesar.o: Caesar.cpp Caesar.h CipherInterface.h
	$(CC) $(CFLAG) -c Caesar.cpp
	
Vigenere.o: Vigenere.cpp Vigenere.h CipherInterface.h
	$(CC) $(CFLAG) -c Vigenere.cpp

.PHONY: clean
clean:
	rm *.o cipher 

