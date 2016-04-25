/* SPN.h
 *
 * Header file of a simple substitution-permutation network.
 *
 * Created by Khoa Nguyen on 03/16/2016.
 */

#ifndef __SPN__
#define __SPN__

#include <iostream>
#include <string>

using namespace std;

#define KEY_LEN 8
#define KEY_RANGE 256
#define BLOCK_LEN 8 // 8 bytes = 64 bits, the usual block length of modern block ciphers. 

class SPN {

public:

	// Default constructor: Random key, min# of rounds = 4
	SPN(int nr = 4);
	
	// Destructor
	~SPN();

	// Encryption Rounds
	unsigned char* encrypt(const string plaintext);

	// Decryption Rounds
	string decrypt(const unsigned char ciphertext[], const int len);

	// print an unsigned char array as hexadecimal values
	void printArray(const unsigned char in[], int len);

private:
	
	int numRounds;	
	unsigned char* key; // default length = KEY_LEN
	unsigned char** subkeys; // there are (numRounds + 1) subkeys of length KEY_LEN
	int pMatrix[BLOCK_LEN][BLOCK_LEN]; // matrix for pi_P()
	int pMatrixInverse[BLOCK_LEN][BLOCK_LEN]; // inverse matrix of pi_P()
	
	// Key schedule: populate 2-D array subkeys from key
	void generate_subkeys();

	// XOR operation with key materials
	void operation_XOR(const unsigned char* input, unsigned char XORed[],
		int numSubkey);
	
	// Substitution pi_S()
	void pi_S(const unsigned char* input, unsigned char substituted[]);

	// Permutation pi_P()
	void pi_P(const unsigned char* input, unsigned char permuted[], bool encrypt);

	// Permutation matrix generator for pi_P()
	void generate_permutation_matrix();

	// Input processor: Turn string input into a 2D array of BLOCK_LEN substrings
	void prepare_string_ECB_mode(const string input,
						unsigned char in[][BLOCK_LEN], int numSubInput);
};

#endif
