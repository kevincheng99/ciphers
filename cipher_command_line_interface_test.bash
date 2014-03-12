#!/bin/bash

echo "Test case 1: playfair cipher"
echo "./cipher PLF chris ENC sample_input_file.txt sample_output_file.txt"
./cipher PLF chris ENC sample_input_file.txt sample_output_file.txt

echo -e "\n"
echo "Test case 2: playfair cipher"
echo "./cipher PLF chris DEC sample_input_file.txt sample_output_file.txt"
./cipher PLF chris DEC sample_input_file.txt sample_output_file.txt

echo -e "\n"
echo "Test case 3: vigenere cipher"
echo "./cipher VIG chris ENC sample_input_file.txt sample_output_file.txt"
./cipher VIG chris ENC sample_input_file.txt sample_output_file.txt

echo -e "\n"
echo "Test case 4: vigenere cipher"
echo "./cipher VIG chris DEC sample_input_file.txt sample_output_file.txt"
./cipher VIG chris DEC sample_input_file.txt sample_output_file.txt

echo -e "\n"
echo "Test case 5: caesar cipher"
echo "./cipher CES 3 ENC sample_input_file.txt sample_output_file.txt"
./cipher CES 3 ENC sample_input_file.txt sample_output_file.txt

echo -e "\n"
echo "Test case 6: casesar cipher"
echo "./cipher CES 3 DEC sample_input_file.txt sample_output_file.txt"
./cipher CES 3 DEC sample_input_file.txt sample_output_file.txt

echo -e "\n"
echo "Test case 7: invalid number of command line arguments"
echo "./cipher"
./cipher

echo -e "\n"
echo "Test case 8: invalid cipher name"
echo "./cipher kevin chris ENC sample_input_file.txt sample_output_file.txt"
./cipher kevin chris ENC sample_input_file.txt sample_output_file.txt

echo -e "\n"
echo "Test case 9: invalid input file"
echo "./cipher kevin chris ENC invalid_input_file.txt sample_output_file.txt"
./cipher PLF chris ENC invalid_input_file.txt sample_output_file.txt


