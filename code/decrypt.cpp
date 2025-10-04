/*
* Name:			Matthew Wilson
* Email:		mlw0420@unt.edu
* Course:		CSCE 3550.001
* Date:			4-18-22
* Description:	Defines functions for decrypt object.
*/

#include "decrypt.h"

//constructor
Decrypt::Decrypt(string fname){
	string temp;//temp string
	
	ifstream fin;//file input
	fin.open(fname);//opens file
	
	if(!fin){//checks if file opened
		cout << "Unable to open " << fname << " file. Terminating..." << endl;
		
		exit(0);//exits if file not opened
	}
	
	
	while(getline(fin, temp)){//populates cyphertext vector
		C.push_back(temp);
	}
		
	fin.close();///closes file
		
	for(unsigned int i = 0; i < C.size(); i++){//populates plaintext vector with '_'
		for(unsigned int j = 0; j < C[i].size()/2; j++){
			temp.push_back('_');
			//M[i][j] = '_';
		}
		
		M.push_back(temp);
		
		temp = "";
	}
	
	for(unsigned int i = 0; i < M[0].size(); i++){//populates key vector with -1's
		K.push_back(-1);
	}
}
//---------------------------------------------------------------------------------
//setters
void Decrypt::SetCipherText(vector<string> CT){//sets cyphertext vector
	C = CT;
}

void Decrypt::SetPlainText(vector<string> MT){//set plaintext vector
	M = MT;
}

void Decrypt::SetKey(vector<int> Key){//sets key vector
	K = Key;
}
//---------------------------------------------------------------------------------
//getters	
vector<string> Decrypt::GetCipherText(){//gets cyphertext vector
	return C;
}

vector<string> Decrypt::GetPlainText(){//get plaintext vector
	return M;
}

vector<int> Decrypt::GetKey(){//gets key vector
	return K;
}
//--------------------------------------------------------------------------------
//displays
void Decrypt::DisplayCipher(){//displays ciphertext vector
	for(unsigned int i = 0; i < C.size(); i++){
		for(unsigned int j = 0; j < C[i].size(); j++){
			cout << C[i][j];
		}
		
		cout << endl << endl;
	}
}

void Decrypt::DisplayPlain(){//diplays plaintext vector
	for(unsigned int i = 0; i < M.size(); i++){
		for(unsigned int j = 0; j < M[i].size(); j++){
			cout << M[i][j];
		}
		
		cout << endl << endl;
	}
}

void Decrypt::DisplayDigi(){//displays digits vector
	for(unsigned int i = 0; i < D.size(); i++){
		for(unsigned int j = 0; j < D[i].size(); j++){
			cout << D[i][j] << " ";
		}
		
		cout << endl << endl;;
	}
}

void Decrypt::DisplayKeys(){//displays keys vector
	for(unsigned int i = 0; i < K.size(); i++){
		cout << K[i] << " ";
	}
	
	cout << endl << endl;
}
//------------------------------------------------------------------------------
//hex to digit converter
void Decrypt::HexToD(){	
	string temp;//temp string
	int num = 0;//converted digit
	vector<int> DD;//vector of converted digits
	
	for(unsigned int i = 0; i < C.size(); i++){//for every line in cyphertext vector
		for(unsigned int j = 0; j < C[i].size(); j+=2){//for every 2 chars in each line
			temp = C[i].substr(j, 2);//temp = group of 2 chars(1 byte)
			
			num = stoul(temp, nullptr, 16);//convert byte into digit
			
			DD.push_back(num);//push onto int vector
			
			//cout << num << " ";
		}
		
		D.push_back(DD);//push onto vector of int vectors
		
		DD.clear();//clear int vector
	}
}

//checks if char at column and row coordinate is a space
unsigned int Decrypt::CheckSpaces(int col, int row){
	unsigned int count = 0;//number of matches
	
	for(unsigned int i = row; i < D.size()-1; i++){//checks rows above at col
	//if char being checked XOR'ed with a char above it > 64 or == 0
		if((D[row][col] ^ D[i+1][col]) > 64 || (D[row][col] ^ D[i+1][col]) == 0){
			count++;//increment count
		}
	}
	
	for(unsigned int i = row; i > 0; i--){//checks rows below at col
	//if char being checked XOR'ed with a char below it > 64 or == 0
		if((D[row][col] ^ D[i-1][col]) > 64 || (D[row][col] ^ D[i-1][col]) == 0){
			count++;//increment count
		}
	}
	
	return count;//return the count value
}

//updates valid chars in paintext vector to spaces 
void Decrypt::UpdateSpaces(){
	for(unsigned int i = 0; i < D.size(); i++){//for every row
		for(unsigned int j = 0; j < D[i].size(); j++){//for every number
			//if CheckSpaces at digit >= vector of int vectors size - 1
			if(CheckSpaces(j, i) >= D.size()-1){
				//set space
				M[i][j] = ' ';
				
				//calculate key for the column
				K[j] = M[i][j] ^ D[i][j];
			}
		}
	}
}

//applies keys to all chars in same column
void Decrypt::ApplyKeys(){
	//int count = 0;
	
	for(unsigned int i = 0; i < M.size(); i++){//for every row in plaintext vector
		for(unsigned int j = 0; j < M[i].size(); j++){//for every char in each row
			//if has a valid key
			if(K[j] >= 0){
				//use key to calculate actual plaintext 
				M[i][j] = D[i][j] ^ K[j];
				
				//count++;
			}
		}
		
		//cout << count << " characters decrypted on line " << i+1 << endl;
		
		//count = 0;
	}
}

