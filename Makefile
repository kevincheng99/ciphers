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

all: cipher

cipher:	cipher.o Playfair.o Caesar.o
	$(CC) $(CFLAG) cipher.o Playfair.o Caesar.o -o cipher

cipher.o:	cipher.cpp
	$(CC) $(CFLAG)  -c cipher.cpp 

test_playfair: Playfair_test.cpp Playfair.o
	$(CC) $(CFLAG) -o test_playfair Playfair_test.cpp Playfair.o $(LDFLAG)

Playfair.o:	Playfair.cpp Playfair.h CipherInterface.h
	$(CC) $(CFLAG) -c Playfair.cpp

Caesar.o:	Caesar.cpp Caesar.h CipherInterface.h
	$(CC) $(CFLAG) -c Caesar.cpp

.PHONY: clean
clean:
	rm *.o cipher test_playfair

