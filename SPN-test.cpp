/* testSPN.cpp
 *
 * Testing of a simple substitution-permutation network.
 *
 * Created by Khoa Nguyen on 03/16/2016.
 *
 * Instruction: Compile the source code by typing in the terminal:
 *                     $ g++ -std=c++11 -o SPN SPN.cpp testSPN.cpp
 *              To run the binary file, type:
 *                     $ ./SPN
 */

#include "SPN.h"

using namespace std;

void testSPN();

int main() {
	testSPN();
	return 0;		 
}

void testSPN() {
	SPN tmp(4);
	string cont = "y";
	string plaintext;

	cout << "Enter plaintext: ";
	getline(cin, plaintext);

	while (true) {
		cout << endl;
   
		int cipherLen = plaintext.length();
		if (plaintext.length() % BLOCK_LEN != 0) {
			cipherLen = cipherLen - (plaintext.length() % BLOCK_LEN) + BLOCK_LEN;
		}

		cout << "--------------------------------------------------" << endl;
		cout << "* ENCRYPTION *************************************" << endl;
		cout << "--------------------------------------------------" << endl;
		unsigned char* cipher = tmp.encrypt(plaintext);
		cout << endl;

		cout << "--------------------------------------------------" << endl;
		cout << "* DECRYPTION *************************************" << endl;
		cout << "--------------------------------------------------" << endl;
		tmp.decrypt(cipher, cipherLen);
		delete [] cipher;
		cout << endl;

		cout << "Continue? (y/n)" << endl;;
		cin >> cont;
		if (cont != "y" && cont != "Y") break;
		cout << "Enter plaintext: ";
		cin.get();
		getline(cin, plaintext);
	}
}