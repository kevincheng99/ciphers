/**
 * This file illustrates how encrypt and decrypt using 
 * RSA in the openssl library.
 * For more information see the following link:
 * http://shanetully.com/2012/04/simple-public-key-encryption-with-rsa-and-openssl/
 */

#include <stdio.h>
#include <stdlib.h>

#include <openssl/evp.h>
#include <openssl/pem.h>
#include <openssl/rsa.h>
#include <openssl/err.h>
#include <openssl/bn.h>
#include <string.h>

/* The modulus size */
#define MOD_SIZE 2048


/**
 * Reads the pem files containing the public and private keys
 * @param pubKeyFile - the public key file
 * @param privKeyFile - the private key file
 * @param pubKey - the read public key
 * @param privKey - the read private key
 */
void readKeys(const char* pubKeyFile, const char* privKeyFile, RSA*& pubKey, RSA*& privKey)
{
	/**** FIRST LETS READ THE PUBLIC KEY **********/
	
	/* Open the public key file */
	FILE* fp = fopen(pubKeyFile, "r");
	
	/* Error checks */
	if(!fp)
	{
		perror("fopen");
		exit(1);		
	}
	
	/* Read the public key */
	pubKey = PEM_read_RSA_PUBKEY(fp, NULL, NULL, NULL);
	
	/* Make sure the file contained a valid key */
	if(!pubKey)
	{
		perror("PEM_read_RSAPublicKey");
		exit(-1);
	}
	
	/* Close the public key file */
	fclose(fp);

	/******** NOW, LETS READ THE PRIVATE KEY **********/
	
	/* Open the file containing the private key */
	fp = fopen(privKeyFile, "r");
	
	/* Error checks */
	if(!fp)
	{
		perror("fopen");
		exit(1);		
	}
	
	/* Read the private key */
	privKey = PEM_read_RSAPrivateKey(fp, NULL, NULL, NULL);
	
	/* Make sure the file contained a valid key */
	if(!privKey)
	{
		perror("PEM_read_RSAPrivateKey");
		exit(-1);
	}
	
	/* Close the public key file */
	fclose(fp);


	
}

 
/**
 * Encrypts a string using RSA public key 
 * @param rsaKeyPair - the RSA public key.
 * @param in - the plaintext buffer
 * @param out - the buffer containing ciphertext
 * @param size - the size of the plaintext
 * @return - the number of bytes encrypted
 */
int RSA_Encrypt(RSA* rsaKeyPair, unsigned char *in, unsigned char *out, const unsigned int& size ) 
{
	printf("EPT: RSA_Encrypt\n");
	fprintf(stderr, "size: %d\n", size);	
	
	/* The number of bytes encrypted */
	int encrypt_len = -1;
	
	/* The buffer containing the error message */
	char errorBuff[130];
	
	/* Encrypt the message using public key */	
	if((encrypt_len = RSA_public_encrypt(size, in, out, rsaKeyPair, RSA_PKCS1_OAEP_PADDING)) < 0) 
	{
	    ERR_load_crypto_strings();
	    ERR_error_string(ERR_get_error(), errorBuff);
	    fprintf(stderr, "Error encrypting message: %s\n", errorBuff);
	}
		
	return encrypt_len;
}

/**
 * Decrypts cipher text using RSA private key
 * @param privKey - the private key to use for decryption
 * @param in - the ciphertext buffer
 * @param out - the buffer containing plaintext
 * @param size - the size of ciphertext
 * @return - the number of bytes decrypted
 */
int RSA_Decrypt(RSA* privKey, unsigned char *in, unsigned char *out, const unsigned int& size ) 
{
	printf("EPT: RSA_Decrypt\n");
	/* The number of bytes encrypted */
	int encrypt_len = -1;
	
	/* The buffer containing the error message */
	char errorBuff[130];
	
	/* The private key */
	if((encrypt_len = RSA_private_decrypt(size, in, out, privKey, RSA_PKCS1_OAEP_PADDING)) < 0) 
	{
	    ERR_load_crypto_strings();
	    ERR_error_string(ERR_get_error(), errorBuff);
	    fprintf(stderr, "Error decrypting message: %s\n", errorBuff);
	}
		
	return encrypt_len;
}

int main(int argc, char** argv)
{
	
	RSA* pub;
	RSA* priv;
	
	readKeys("pubkey.pem", "privkey.pem", pub, priv);
	
	//exit(1);
	
	/* The size of the plaintext */
	unsigned int plainTextSize = 0;
		
	/* Check command line arguments */
	if(argc < 2)
	{
		fprintf(stderr, "USAGE: %s <TEXT>\n", argv[0]);
		exit(-1);
	}
	
	/* Make sure the text size does not exceed the mod size */
	if((plainTextSize = strlen(argv[1])) > (MOD_SIZE/8))
	{
		fprintf(stderr, "Text size (%d bytes) exceeds the modulus size (%d bytes)\n",
			 strlen(argv[1]), (MOD_SIZE/8));
		
		exit(-1);
	}
    
	/* The plaintext pointer */
	unsigned char* plainText = (unsigned char*)argv[1];
		
	/* The ciphertext buffer */
	unsigned  char ciphertext[MOD_SIZE];
	
	/* The decrypted text */
	unsigned char decryptedText[MOD_SIZE];
	
	/* Initialize all buffers to 0 */	
	memset(ciphertext, 0, sizeof(ciphertext));
	memset(decryptedText, 0, sizeof(decryptedText));
	
	/* Encrypt the string using RSA public key */
	printf("Calling RSA_Encrypt\n");
	unsigned size = RSA_Encrypt(pub, plainText, ciphertext, plainTextSize);	
	printf("RSA_Encrypt returned: size=%d\n", size);
	
	/* Decrypt using using the private key */	
	printf("Calling RSA_Decrypt\n");
	RSA_Decrypt(priv, ciphertext, decryptedText, size);
	
	fprintf(stderr, "Plain text: ");
	/* Print the plaintext */	
	for(int index = 0; index < plainTextSize; ++index)
		fprintf(stderr, "%c", plainText[index]);
	
	fprintf(stderr, "\n\nEncrypted text: ");
	/* Print the ciphertext */	
	for(int index = 0; index < sizeof(ciphertext); ++index)
//		fprintf(stderr, "%c", ciphertext[index]);
		fprintf(stderr, "%02x, ", ciphertext[index]);
	fprintf(stderr, "\n\n");
	
	fprintf(stderr, "Decrypted text: ");
	/* Print the decrypted text */	
	for(int index = 0; index < plainTextSize; ++index)
		fprintf(stderr, "%c", decryptedText[index]);

	fprintf(stderr, "\n----------------------------------------------\n");
	return(0);
}

