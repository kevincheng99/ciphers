#!/bin/bash

# make the submission directory
submission="./p1-TsuHsiang/"

if [ ! -d $submission ]; then
  echo -e "mkdir $submission\n"
  mkdir $submission
fi

# copy header files to the submission directory
cp CipherInterface.h $submission
cp Caesar.h $submission
cp Playfair.h $submission
cp Railfence.h $submission
cp RowTransposition.h $submission
cp Vigenere.h $submission

# copy implementation files to the submission directory
cp cipher.cpp $submission
cp Caesar.cpp $submission
cp Playfair.cpp $submission
cp Railfence.cpp $submission
cp RowTransposition.cpp $submission
cp Vigenere.cpp $submission

# copy the makefile to the submisison directory
cp Makefile $submission

# copy the readme to the submission directory
cp README.txt $submission
