/*
* Name:			Matthew Wilson
* Email:		mlw0420@unt.edu
* Course:		CSCE 3550.001
* Date:			4-18-22
* Description:	Decrypts text that has been encrypted with many-time pad using the spaces in the columns of characters. 
*/

#include "decrypt.h"
using namespace std;

int main(){
	//file name
	string fname;
	
	//prompts for file
	cout << "Enter the name of the ciphertexts file: ";
	cin >> fname;
	
	//initialize Derypt object with file name
	Decrypt Decryptor(fname);
	
	//convert hex cyphertext into base10
	Decryptor.HexToD();
	
	//calculate and place spaces onto plaintext and calculate keys
	Decryptor.UpdateSpaces();
	
	//use keyes to decrypt corresponding plaintext chars
	Decryptor.ApplyKeys();
	
	//display message
	cout << "Plaintext Messages:" << endl;
	
	//display plaintext
	Decryptor.DisplayPlain();
	
	return 0;
}

