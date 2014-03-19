#!/bin/bash

# make the executables FRESH
make clean
make

# tests start here
echo "Test case 1: playfair cipher"
echo "./cipher PLF chris ENC short_input_file.txt ciphertext.txt"
./cipher PLF chris ENC short_input_file.txt ciphertext.txt

echo "short input file:"
cat short_input_file.txt

echo "ciphertext:"
cat ciphertext.txt

echo -e "\n"
echo "Test case 2: playfair cipher"
echo "./cipher PLF chris DEC ciphertext.txt plaintext.txt"
./cipher PLF chris DEC ciphertext.txt plaintext.txt

echo "ciphertext:"
cat ciphertext.txt

echo "decrypted ciphertext"
cat plaintext.txt

rm ciphertext.txt plaintext.txt

echo -e "\n"
echo "Test case 3: row transposition cipher"
echo "./cipher RTS chris short_input_file.txt ciphertext.txt"
./cipher RTS chris ENC short_input_file.txt ciphertext.txt

echo "short input file:"
cat short_input_file.txt

echo "ciphertext:"
cat ciphertext.txt

echo -e "\n"
echo "Test case 4: row transposition cipher"
echo "./cipher RTS chris DEC ciphertext.txt plaintext.txt"
./cipher RTS chris DEC ciphertext.txt plaintext.txt

echo "ciphertext:"
cat ciphertext.txt

echo "decrypted ciphertext"
cat plaintext.txt

rm ciphertext.txt plaintext.txt

echo -e "\n"
echo "Test case 5: railfence cipher"
echo "./cipher RFC 3 short_input_file.txt ciphertext.txt"
./cipher RFC 3 ENC short_input_file.txt ciphertext.txt

echo "short input file:"
cat short_input_file.txt

echo "ciphertext:"
cat ciphertext.txt

echo -e "\n"
echo "Test case 6: railfence cipher"
echo "./cipher RFC 3 DEC ciphertext.txt plaintext.txt"
./cipher RFC 3 DEC ciphertext.txt plaintext.txt

echo "ciphertext:"
cat ciphertext.txt

echo "decrypted ciphertext"
cat plaintext.txt

rm ciphertext.txt plaintext.txt

echo -e "\n"
echo "Test case 7: vigenere cipher"
echo "./cipher VIG kevin ENC short_input_file.txt ciphertext.txt"
./cipher VIG kevin ENC short_input_file.txt ciphertext.txt

echo "short input file:"
cat short_input_file.txt

echo "ciphertext:"
cat ciphertext.txt

echo -e "\n"
echo "Test case 8: vigenere cipher"
echo "./cipher VIG kevin DEC ciphertext.txt plaintext.txt"
./cipher VIG kevin DEC ciphertext.txt plaintext.txt

echo "ciphertext:"
cat ciphertext.txt

echo "decrypted ciphertext"
cat plaintext.txt

rm ciphertext.txt plaintext.txt

echo -e "\n"
echo "Test case 9: caesar cipher"
echo "./cipher CES 3 ENC short_input_file.txt ciphertext.txt"
./cipher CES 3 ENC short_input_file.txt ciphertext.txt

echo "short input file:"
cat short_input_file.txt

echo "ciphertext:"
cat ciphertext.txt

echo -e "\n"
echo "Test case 10: caesar cipher"
echo "./cipher CES 3 DEC ciphertext.txt plaintext.txt"
./cipher CES 3 DEC ciphertext.txt plaintext.txt

echo "ciphertext:"
cat ciphertext.txt

echo "decrypted ciphertext"
cat plaintext.txt

rm ciphertext.txt plaintext.txt

echo -e "\n"
echo "Test case 11: invalid number of command line arguments"
echo "./cipher"
./cipher

echo -e "\n"
echo "Test case 12: invalid cipher name"
echo "./cipher kevin chris ENC sample_input_file.txt delete_me.txt"
./cipher kevin chris ENC sample_input_file.txt delete_me.txt

echo -e "\n"
echo "Test case 13: invalid input file"
echo "./cipher kevin chris ENC invalid_input_file.txt delete_me.txt"
./cipher PLF chris ENC invalid_input_file.txt delete_me.txt

rm delete_me.txt

echo -e "\n"
echo "Test case 14: railfence cipher"
echo "./cipher RFC 100 short_input_file.txt ciphertext.txt"
./cipher RFC 100 ENC short_input_file.txt ciphertext.txt

echo "short input file:"
cat short_input_file.txt

echo "ciphertext:"
cat ciphertext.txt

echo -e "\n"
echo "Test case 15: railfence cipher"
echo "./cipher RFC 100 DEC ciphertext.txt plaintext.txt"
./cipher RFC 100 DEC ciphertext.txt plaintext.txt

echo "ciphertext:"
cat ciphertext.txt

echo "decrypted ciphertext"
cat plaintext.txt

rm ciphertext.txt plaintext.txt



































