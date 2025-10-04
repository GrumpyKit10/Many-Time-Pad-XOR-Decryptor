/*
* Name:			Matthew Wilson
* Email:		mlw0420@unt.edu
* Course:		CSCE 3550.001
* Date:			4-18-22
* Description:	File header for decrypt object.
*/

#include<iostream>// i/o
#include<string>// strings
#include<fstream>// file i/o
#include<vector>// vectors 
#include<iomanip>// i/o manipulations
using namespace std;

#ifndef DECRYPT_H
#define DECRYPT_H

//Decrypt object class
class Decrypt{
	public:
		//paramterized constructor
		Decrypt(string);
		
		//setters
		void SetCipherText(vector<string>);
		void SetPlainText(vector<string>);
		void SetKey(vector<int>);
		
		//getters
		vector<string> GetCipherText();
		vector<string> GetPlainText();
		vector<int> GetKey();
		
		//displays
		void DisplayCipher();
		void DisplayPlain();
		void DisplayDigi();
		void DisplayKeys();
		
		//converts hexidecimal characters in cyphertext into decimal values.
		void HexToD();
		//checks if space in column of text
		unsigned int CheckSpaces(int, int);
		//places spaces in proper location in plaintext vector and calculates keys
		void UpdateSpaces();
		//applies keys to all valid characters in each line
		void ApplyKeys();
		
	
	private:
		//cipher and plain text vectors
		vector<string> C, M;
		//keys vector
		vector<int> K;
		//Decimal values vector
		vector<vector<int>> D;
};

#endif

