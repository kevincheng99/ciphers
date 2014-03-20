# cracking ciphers by testing different keys
# the keys are mostly composed of alpha-numeric.

# rebuild the executables FRESH
make clean
make

# test on Caesar cipher
echo -e "\n"
echo "Test case 26: caesar cipher"
echo "./cipher CES 0 ENC short_input_file.txt ciphertext.txt"
./cipher CES 0 ENC short_input_file.txt ciphertext.txt

echo "short input file:"
cat short_input_file.txt

echo "ciphertext:"
cat ciphertext.txt

echo -e "\n"
echo "Test case 27: caesar cipher"
echo "./cipher CES 0 DEC ciphertext.txt plaintext.txt"
./cipher CES 0 DEC ciphertext.txt plaintext.txt

echo "ciphertext:"
cat ciphertext.txt

echo "decripted ciphertext:"
cat plaintext.txt

# clean up files
rm ciphertext.txt plaintext.txt

echo -e "\n"
echo "Test case 27: caesar cipher"
echo "./cipher CES 100 ENC short_input_file.txt ciphertext.txt"
./cipher CES 100 ENC short_input_file.txt ciphertext.txt

echo "short input file:"
cat short_input_file.txt

echo "ciphertext:"
cat ciphertext.txt

echo -e "\n"
echo "Test case 28: caesar cipher"
echo "./cipher CES 100 DEC ciphertext.txt plaintext.txt"
./cipher CES 100 DEC ciphertext.txt plaintext.txt

echo "ciphertext:"
cat ciphertext.txt

echo "decripted ciphertext:"
cat plaintext.txt

# clean up files
rm ciphertext.txt plaintext.txt

echo -e "\n"
echo "Test case 29: caesar cipher"
echo "./cipher CES k ENC short_input_file.txt ciphertext.txt"
./cipher CES k ENC short_input_file.txt ciphertext.txt

echo "short input file:"
cat short_input_file.txt

echo "ciphertext:"
cat ciphertext.txt

echo -e "\n"
echo "Test case 30: caesar cipher"
echo "./cipher CES k DEC ciphertext.txt plaintext.txt"
./cipher CES k DEC ciphertext.txt plaintext.txt

echo "ciphertext:"
cat ciphertext.txt

echo "decripted ciphertext:"
cat plaintext.txt

# clean up files
rm ciphertext.txt plaintext.txt

echo -e "\n"
echo "Test case 31: caesar cipher"
echo "./cipher CES -1 ENC short_input_file.txt ciphertext.txt"
./cipher CES -1 ENC short_input_file.txt ciphertext.txt

echo "short input file:"
cat short_input_file.txt

echo "ciphertext:"
cat ciphertext.txt

echo -e "\n"
echo "Test case 32: caesar cipher"
echo "./cipher CES -1 DEC ciphertext.txt plaintext.txt"
./cipher CES -1 DEC ciphertext.txt plaintext.txt

echo "ciphertext:"
cat ciphertext.txt

echo "decripted ciphertext:"
cat plaintext.txt

# clean up files
rm ciphertext.txt plaintext.txt

echo -e "\n"
echo "Test case 33: vigenere cipher"
echo "./cipher VIG abcdefghijklmnopqrstuvwxzy ENC short_input_file.txt ciphertext.txt"
./cipher VIG abcdefghijklmnopqrstuvwxzy ENC short_input_file.txt ciphertext.txt

echo "short input file:"
cat short_input_file.txt

echo "ciphertext:"
cat ciphertext.txt

echo -e "\n"
echo "Test case 34: vigenere cipher"
echo "./cipher VIG abcdefghijklmnopqrstuvwxzy DEC ciphertext.txt plaintext.txt"
./cipher VIG abcdefghijklmnopqrstuvwxzy DEC ciphertext.txt plaintext.txt

echo "ciphertext:"
cat ciphertext.txt

echo "decripted ciphertext:"
cat plaintext.txt

# clean up files
rm ciphertext.txt plaintext.txt

echo -e "\n"
echo "Test case 35: vigenere cipher"
echo "./cipher VIG 1 ENC short_input_file.txt ciphertext.txt"
./cipher VIG 1 ENC short_input_file.txt ciphertext.txt

echo "short input file:"
cat short_input_file.txt

echo "ciphertext:"
cat ciphertext.txt

echo -e "\n"
echo "Test case 36: vigenere cipher"
echo "./cipher VIG 1 DEC ciphertext.txt plaintext.txt"
./cipher VIG 1 DEC ciphertext.txt plaintext.txt

echo "ciphertext:"
cat ciphertext.txt

echo "decripted ciphertext:"
cat plaintext.txt

# clean up files
rm ciphertext.txt plaintext.txt

echo -e "\n"
echo "Test case 37: vigenere cipher"
echo "./cipher VIG a ENC short_input_file.txt ciphertext.txt"
./cipher VIG a ENC short_input_file.txt ciphertext.txt

echo "short input file:"
cat short_input_file.txt

echo "ciphertext:"
cat ciphertext.txt

echo -e "\n"
echo "Test case 38: vigenere cipher"
echo "./cipher VIG a DEC ciphertext.txt plaintext.txt"
./cipher VIG a DEC ciphertext.txt plaintext.txt

echo "ciphertext:"
cat ciphertext.txt

echo "decripted ciphertext:"
cat plaintext.txt

# clean up files
rm ciphertext.txt plaintext.txt

echo -e "\n"
echo "Test case 39: vigenere cipher"
echo "./cipher VIG a ENC short_input_file.txt ciphertext.txt"
./cipher VIG a ENC short_input_file.txt ciphertext.txt

echo "short input file:"
cat short_input_file.txt

echo "ciphertext:"
cat ciphertext.txt

echo -e "\n"
echo "Test case 40: vigenere cipher"
echo "./cipher VIG a DEC ciphertext.txt plaintext.txt"
./cipher VIG a DEC ciphertext.txt plaintext.txt

echo "ciphertext:"
cat ciphertext.txt

echo "decripted ciphertext:"
cat plaintext.txt

# clean up files
rm ciphertext.txt plaintext.txt

echo -e "\n"
echo "Test case 41: railfence cipher"
echo "./cipher RFC a ENC short_input_file.txt ciphertext.txt"
./cipher RFC a ENC short_input_file.txt ciphertext.txt

echo "short input file:"
cat short_input_file.txt

echo "ciphertext:"
cat ciphertext.txt

echo -e "\n"
echo "Test case 42: railfence cipher"
echo "./cipher RFC a DEC ciphertext.txt plaintext.txt"
./cipher RFC a DEC ciphertext.txt plaintext.txt

echo "ciphertext:"
cat ciphertext.txt

echo "decripted ciphertext:"
cat plaintext.txt

# clean up files
rm ciphertext.txt plaintext.txt

echo -e "\n"
echo "Test case 43: railfence cipher"
echo "./cipher RFC 0 ENC short_input_file.txt ciphertext.txt"
./cipher RFC 0 ENC short_input_file.txt ciphertext.txt

echo "short input file:"
cat short_input_file.txt

echo "ciphertext:"
cat ciphertext.txt

echo -e "\n"
echo "Test case 44: railfence cipher"
echo "./cipher RFC 0 DEC ciphertext.txt plaintext.txt"
./cipher RFC 0 DEC ciphertext.txt plaintext.txt

echo "ciphertext:"
cat ciphertext.txt

echo "decripted ciphertext:"
cat plaintext.txt

# clean up files
rm ciphertext.txt plaintext.txt

echo -e "\n"
echo "Test case 45: railfence cipher"
echo "./cipher RFC -1 ENC short_input_file.txt ciphertext.txt"
./cipher RFC -1 ENC short_input_file.txt ciphertext.txt

echo "short input file:"
cat short_input_file.txt

echo "ciphertext:"
cat ciphertext.txt

echo -e "\n"
echo "Test case 44: railfence cipher"
echo "./cipher RFC -1 DEC ciphertext.txt plaintext.txt"
./cipher RFC -1 DEC ciphertext.txt plaintext.txt

echo "ciphertext:"
cat ciphertext.txt

echo "decripted ciphertext:"
cat plaintext.txt

# clean up files
rm ciphertext.txt plaintext.txt

echo -e "\n"
echo "Test case 46: railfence cipher"
echo "./cipher RFC 100 ENC short_input_file.txt ciphertext.txt"
./cipher RFC 100 ENC short_input_file.txt ciphertext.txt

echo "short input file:"
cat short_input_file.txt

echo "ciphertext:"
cat ciphertext.txt

echo -e "\n"
echo "Test case 47: railfence cipher"
echo "./cipher RFC 100 DEC ciphertext.txt plaintext.txt"
./cipher RFC 100 DEC ciphertext.txt plaintext.txt

echo "ciphertext:"
cat ciphertext.txt

echo "decripted ciphertext:"
cat plaintext.txt

# clean up files
rm ciphertext.txt plaintext.txt

echo -e "\n"
echo "Test case 48: row transposition cipher"
echo "./cipher RTS +_* ENC short_input_file.txt ciphertext.txt"
./cipher RTS +_* ENC short_input_file.txt ciphertext.txt

echo "short input file:"
cat short_input_file.txt

echo "ciphertext:"
cat ciphertext.txt

echo -e "\n"
echo "Test case 49: row transposition cipher"
echo "./cipher RTS +_* DEC ciphertext.txt plaintext.txt"
./cipher RTS +_* DEC ciphertext.txt plaintext.txt

echo "ciphertext:"
cat ciphertext.txt

echo "decripted ciphertext:"
cat plaintext.txt

# clean up files
rm ciphertext.txt plaintext.txt
rm .rowtransposition_fillers

echo -e "\n"
echo "Test case 50: row transposition cipher"
echo "./cipher RTS @ecs12K# ENC short_input_file.txt ciphertext.txt"
./cipher RTS @ecs12K# ENC short_input_file.txt ciphertext.txt

echo "short input file:"
cat short_input_file.txt

echo "ciphertext:"
cat ciphertext.txt

echo -e "\n"
echo "Test case 51: row transposition cipher"
echo "./cipher RTS @ecs12K# DEC ciphertext.txt plaintext.txt"
./cipher RTS @ecs12K# DEC ciphertext.txt plaintext.txt

echo "ciphertext:"
cat ciphertext.txt

echo "decripted ciphertext:"
cat plaintext.txt

# clean up files
rm ciphertext.txt plaintext.txt
rm .rowtransposition_fillers

echo -e "\n"
echo "Test case 52: row transposition cipher"
echo "./cipher RTS mississipi ENC short_input_file.txt ciphertext.txt"
./cipher RTS mississipi ENC short_input_file.txt ciphertext.txt

echo "short input file:"
cat short_input_file.txt

echo "ciphertext:"
cat ciphertext.txt

echo -e "\n"
echo "Test case 53: row transposition cipher"
echo "./cipher RTS mississipi DEC ciphertext.txt plaintext.txt"
./cipher RTS mississipi DEC ciphertext.txt plaintext.txt

echo "ciphertext:"
cat ciphertext.txt

echo "decripted ciphertext:"
cat plaintext.txt

# clean up files
rm ciphertext.txt plaintext.txt
rm .rowtransposition_fillers


echo -e "\n"
echo "Test case 60: row transposition cipher"
echo "./cipher RTS abcdefghifjklmnopqrstuvwxyz ENC short_input_file.txt ciphertext.txt"
./cipher RTS abcdefghijklmnopqrstuvwxyz ENC short_input_file.txt ciphertext.txt

echo "short input file:"
cat short_input_file.txt

echo "ciphertext:"
cat ciphertext.txt

echo -e "\n"
echo "Test case 61: row transposition cipher"
echo "./cipher RTS abcdefghifjklmnopqrstuvwxyz DEC ciphertext.txt plaintext.txt"
./cipher RTS abcdefghijklmnopqrstuvwxyz DEC ciphertext.txt plaintext.txt

echo "ciphertext:"
cat ciphertext.txt

echo "decripted ciphertext:"
cat plaintext.txt

# clean up files
rm ciphertext.txt plaintext.txt
rm .rowtransposition_fillers

echo -e "\n"
echo "Test case 54: playfair cipher"
echo "./cipher PLF mississipi ENC short_input_file.txt ciphertext.txt"
./cipher PLF mississipi ENC short_input_file.txt ciphertext.txt

echo "short input file:"
cat short_input_file.txt

echo "ciphertext:"
cat ciphertext.txt

echo -e "\n"
echo "Test case 55: playfair cipher"
echo "./cipher PLF mississipi DEC ciphertext.txt plaintext.txt"
./cipher PLF mississipi DEC ciphertext.txt plaintext.txt

echo "ciphertext:"
cat ciphertext.txt

echo "decripted ciphertext:"
cat plaintext.txt

# clean up files
rm ciphertext.txt plaintext.txt
rm .playfair_padding_location

echo -e "\n"
echo "Test case 56: playfair cipher"
echo "./cipher PLF kevincheng99 ENC short_input_file.txt ciphertext.txt"
./cipher PLF kevincheng99 ENC short_input_file.txt ciphertext.txt

echo "short input file:"
cat short_input_file.txt

echo "ciphertext:"
cat ciphertext.txt

echo -e "\n"
echo "Test case 57: playfair cipher"
echo "./cipher PLF kevincheng99 DEC ciphertext.txt plaintext.txt"
./cipher PLF kevincheng99 DEC ciphertext.txt plaintext.txt

echo "ciphertext:"
cat ciphertext.txt

echo "decripted ciphertext:"
cat plaintext.txt

# clean up files
rm ciphertext.txt plaintext.txt
rm .playfair_padding_location

echo -e "\n"
echo "Test case 58: playfair cipher"
echo "./cipher PLF kkkkkkkkkkkkkkkkkkkkkkkkkkk ENC short_input_file.txt ciphertext.txt"
./cipher PLF kkkkkkkkkkkkkkkkkkkkkkkkkkk ENC short_input_file.txt ciphertext.txt

echo "short input file:"
cat short_input_file.txt

echo "ciphertext:"
cat ciphertext.txt

echo -e "\n"
echo "Test case 59: playfair cipher"
echo "./cipher PLF kkkkkkkkkkkkkkkkkkkkkkkkkkk DEC ciphertext.txt plaintext.txt"
./cipher PLF kkkkkkkkkkkkkkkkkkkkkkkkkkk DEC ciphertext.txt plaintext.txt

echo "ciphertext:"
cat ciphertext.txt

echo "decripted ciphertext:"
cat plaintext.txt

# clean up files
rm ciphertext.txt plaintext.txt
rm .playfair_padding_location

echo -e "\n"
echo "Test case 62: playfair cipher"
echo "./cipher PLF abcdefghijklmnopqrstuvwxyz ENC short_input_file.txt ciphertext.txt"
./cipher PLF abcdefghijklmnopqrstuvwxyz ENC short_input_file.txt ciphertext.txt

echo "short input file:"
cat short_input_file.txt

echo "ciphertext:"
cat ciphertext.txt

echo -e "\n"
echo "Test case 63: playfair cipher"
echo "./cipher PLF abcdefghijklmnopqrstuvwxyz DEC ciphertext.txt plaintext.txt"
./cipher PLF abcdefghijklmnopqrstuvwxyz DEC ciphertext.txt plaintext.txt

echo "ciphertext:"
cat ciphertext.txt

echo "decripted ciphertext:"
cat plaintext.txt

# clean up files
rm ciphertext.txt plaintext.txt
rm .playfair_padding_location
