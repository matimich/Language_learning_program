/*
 * FileOperation.cpp
 *
 *  Created on: 29 wrz 2018
 *      Author: Mateusz
 */


#include <iostream>
#include "FileOperation.h"
#include <fstream>
#include <cstring>
#include <string>

using namespace std;



void FileOperation :: Practice(string first,string second,string third)
{
	do
	{
		cout << first << endl;	// "Press 1 to learn Eng/Fr to Pol"
		cout << second << endl;	// "Press 2 to learn Pol to Eng/Fr"

		cin >> decision;
		if(decision != 1 && decision != 2)
		{
			cout << "Wrong number." << "(" ;
			cout << decision << ")"<<endl;
			cin.clear();	//clears flag
			cin.ignore();	// clears sign from buffer
		}
	}
	while(decision != 1 && decision != 2);

	if(decision==1)
	{
		ToPolish(third);
	}
	else
	{
		FromPolish(third);
	}
}


void FileOperation :: ToPolish(string third) // zrobic funkcje z correct  wrzucic jao
{
	char continue_learn = 'A';
	fstream StudyFile;		//file initialization
	StudyFile.open(third);

	if(StudyFile.is_open())
	{
		if(mode_practice==1)
		{
			while(getline(StudyFile,full_sentence))	//EXTRACTING WORLD FROM FILE
			{

				nr_sign = full_sentence.find(sign);	//SEARCHING FOR NON PL PART OF LINE
				string display(full_sentence, 0, nr_sign); //COPYING EXACT NUMBER OF SIGNS
				BACK:
				cout << display << endl;
				//CHECKING
				cout << "Meaning in Polish:" << endl;
				cin >> answer;
				int check_resul = full_sentence.find(answer);
				if(check_resul  >= 0)
				{
					cout << "Correct answer!" <<endl;
				}
				if(check_resul == -1 ) // string::npos =  -1
				{
					cout << "You are wrong." <<endl;
					cout <<"Press 'r' or 'R' to repeat:";
					cin >> continue_learn;
					if(continue_learn == 'r' || continue_learn == 'R')
						goto BACK;
				}
				cout <<"Press 'c' or 'C' to continue:";
				cin >> continue_learn;
				if(continue_learn == 'C' || continue_learn == 'c')
					continue;
				else
					break;
			}
		}
		else if(mode_practice==2)
		{
			do
			{
				for(int i=0; i<2;i++)
				{
					getline(StudyFile,full_sentence);
				}
				nr_sign = full_sentence.find(sign);	//SEARCHING FOR NON PL PART OF LINE
				string display(full_sentence,0,nr_sign);
				cout << display << endl;
				cout << "Meaning in Polish:" << endl;




				StudyFile.seekg(0, ios::beg);
				cout <<"Press 'q' or 'Q' to exit:" <<endl;
				cin >> continue_learn;
			}
				while(continue_learn != 'q' && continue_learn != 'Q');
		}
	}
	else
	{
		cout <<"File not found" << endl;
	}
	StudyFile.close();
}

void FileOperation :: FromPolish(string third)
{

}

void FileOperation :: Check(void)
{

}

FileOperation :: FileOperation(const Interface& start) : nr_sign{0},check_resul{0},mode_practice{start.mode}
{
	if(start.language==1)	//SETTING LANGUAGE
	{
		Practice(FIRST_ENG,SEC_ENG,ENGLISH_FILE_NAME);
	}
	else if (start.language==2)
	{
		Practice(FIRST_FR,SEC_FR,FRENCH_FILE_NAME);
	}


}

