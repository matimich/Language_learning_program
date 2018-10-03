/*
 * FileOperation.cpp
 *
 *  Created on: 29 wrz 2018
 *      Author: Mateusz
 */


#include <iostream>
#include "FileOperation.h"
#include <fstream>
#include <string>
#include <cstdlib>
#include <time.h>


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
		Translate(third);
	}
	else if(decision==2)
	{
		Translate(third);
	}
}


void FileOperation :: Translate(string third) // zrobic funkcje z correct  wrzucic jao
{
	ifstream StudyFile;		//file initialization
	StudyFile.open(third);

	if(StudyFile.is_open())
	{
		if(mode_practice==1)	//NORMAL MODE
		{
			while(getline(StudyFile,full_sentence))	//EXTRACTING WORLD FROM FILE
			{
				if(Check(decision)==1)
				{
					continue;
				}
				else
				{
					break;
				}
			}
		}
		else if(mode_practice==2)	//RANDOM MODE
		{
			count = 0;

			while(getline(StudyFile,full_sentence))	//EXTRACTING LINE FROM FILE
			{
				count++;
			}

			while(1)
			{
				if(ios::eof) //CHECKING IF EOF FLAG IS SET
				{
					StudyFile.clear();				//CLEARING EOF FLAG IS A MUST!
					StudyFile.seekg(0,ios::beg);	//to the beginning of the file
				}
				srand (time(NULL));
				random = rand() % count + 1;


				for(int i=0; i<random;i++)
				{
					getline(StudyFile,full_sentence);
				}

				if(Check(decision)==1)
				{
					continue;
				}
				else
				{
					break;
				}
			}
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

int FileOperation :: Check(int mode)
{
	string continue_learn = "A";
	string language;

	nr_sign = full_sentence.find(sign);	//SEARCHING FOR NON PL PART OF LINE

	BACK:
	if(mode==1)	//FOR 'TO POLISH' MODE
	{
		string display(full_sentence, 0, nr_sign);//COPYING EXACT NUMBER OF SIGNS
		cout<< display << endl;
		language = "Polish";
	}
	else if(mode ==2)//FOR 'FROM POLISH' MODE
	{
		string display(full_sentence, nr_sign+2, '\n');//COPYING EXACT NUMBER OF SIGNS
		cout<< display << endl;
		language = sec_lang;
	}
	//CHECKING
	cout << "Meaning in " << language <<":"<<endl;
	//cin >> answer;
	cin.ignore();					//CLEARS BUFFER ('\n' IN BUFFER)
	std::getline(std::cin,answer);	//ALLOWS INPUTTING STRINGS WITH 'SPACE' SEPARATION

	int check_resul = full_sentence.find(answer);
	if(check_resul  >= 0)
	{
		cout << "Correct answer!" <<endl;
	}
	if(check_resul == -1 ) // string::npos =  -1
	{
		cout << "You are wrong." <<endl;
		cout <<"Press 'r' or 'R' to repeat:" <<endl;
		cin >> continue_learn;
		if(continue_learn == "r" || continue_learn == "R")
		goto BACK;
	}
	cout <<"Press 'c' or 'C' to continue:" << endl;
	cin >> continue_learn;
	if(continue_learn == "C" || continue_learn == "c")
	{
		return 1;
	}
	else
	{
		return 2;
	}
}

FileOperation :: FileOperation(const Interface& start) : nr_sign{0},check_resul{0},mode_practice{start.mode}
{
	if(start.language==1)	//SETTING LANGUAGE
	{
		sec_lang = "English";
		Practice(FIRST_ENG,SEC_ENG,ENGLISH_FILE_NAME);
	}
	else if (start.language==2)
	{
		sec_lang = "French";
		Practice(FIRST_FR,SEC_FR,FRENCH_FILE_NAME);
	}
}

