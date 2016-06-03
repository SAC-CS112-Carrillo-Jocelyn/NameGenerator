// NameGenerator.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <iostream>
#include <ctime>

using namespace std;

int randSyllableLen, randNumbOfSyllables, randVowelLoc;
string name = " ";
string temp;
bool tempB = false;

//Rules for syllables
void CreateSyllable( int i) {

	randSyllableLen = rand() % 3 + 1;
	//cout << i << " - syllable length: " << randSyllableLen << endl;

	//decide where vowel will be for this syllable---
	do {
		randVowelLoc = rand() % 3 + 1;
		//cout << "vowel location: " << randVowelLoc << endl;

	} while (randVowelLoc > randSyllableLen);
	//-------

	//make syllable
	for (int x = 1; x <= randSyllableLen; x++) {
		// ---if its supposed to be a vowel
		if (x == randVowelLoc) {
			tempB = false;
			do {
				temp = (char)(97 + (rand() % 25));
				if (temp == "a" || temp == "e" || temp == "i" || temp == "o" || temp == "u") {
					name += temp;
					//cout << "Vtempsyllable: " << name << endl;
					tempB = true;
				}
			} while (!tempB);
		} //-----
		else {
			if (temp == "j" || temp == "q" || temp == "v" 
				|| temp == "w" || temp == "x" || temp == "y" || temp == "z") {
				tempB = false;
				do {
					temp = (char)(97 + (rand() % 25));
					if (temp == "a" || temp == "e" || temp == "i" || temp == "o" || temp == "u") {
						name += temp;
						//cout << "V2tempsyllable: " << name << endl;
						tempB = true;
					}
				} while (!tempB);
			}
			else {
				temp = (char)(97 + (rand() % 25));
			}
			name += temp;
			//cout << "tempsyllable: " << name << endl;
			}
		}
}



int main()
{
	srand(time(0));
	
	//Make random syllables to put together
	randNumbOfSyllables = rand() % 3  + 1;
	//cout << "random number of syllables: " << randNumbOfSyllables << endl;

	//First captial Letter
	name += (char)(65 + (rand() % 25));

	//create number of syllables needed
	for (int i = 1; i <= randNumbOfSyllables; i++) {
		
		//create Syllable
		CreateSyllable(i);
	
	}
	cout << "Name: " << name << endl;

    return 0;
}

