/*
 * FileOperation.cpp
 *
 *  Created on: 29 wrz 2018
 *      Author: Mateusz Michalski
 */

#include "FileOperation.hpp"

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <time.h>


using namespace std;

FileOperation :: FileOperation(const Interface& start): sign{"-"}, mode_practice{start.mode},
		mode_decision{start.decision}
{
	if(start.language==ENG_NUMBER)	//SETTING LANGUAGE
	{
		sec_lang = ENG;
		Practice(ENGLISH_FILE_NAME);
	}

	else if (start.language == FR_NUMBER)
	{
		sec_lang = FR;
		Practice(FRENCH_FILE_NAME);
	}
}

void FileOperation :: Practice(string FileName)
{
	if(mode_decision == TRANS_TO_DEFAULT)	//USER WILL BE TRANSLATING FROM OTHER LANGUAGE TO POLISH
	{
		Translate(FileName);
	}
	else if(mode_decision == TRANS_FROM_DEFAULT)
	{
		Translate(FileName);	//USER WILL BE TRANSLATING FROM POLISH TO OTHER LANGUAGE
	}
}


void FileOperation :: Translate(string FileName)
{
	int count;	//var for random mode
	int random;	//var for random mode
	ifstream StudyFile;		//file initialization
	StudyFile.open(FileName);

	if(StudyFile.is_open())
	{
		if(mode_practice == NORMAL_MODE)	//NORMAL MODE
		{
			while(getline(StudyFile,full_sentence))	//EXTRACTING WORLD FROM FILE
			{
				if(Check(mode_decision) == "continue")
				{
					continue;
				}
				else
				{
					break;
				}
			}
		}
		else if(mode_practice == RANDOM_MODE)	//RANDOM MODE
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

				srand(time(NULL));					//CREATING RANDOM NUMBER
				random = rand() % count + 1;

				for(int i=0; i<random;i++)			//TAKING RANDOM A WORD FROM THE TEXT FILE
				{
					getline(StudyFile,full_sentence);
				}

				if(Check(mode_decision) == "continue")
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


string FileOperation :: Check(int mode)
{
	string continue_learn = "A";
	string language;
	int check_resul = 0;
	int nr_sign = 0;

	nr_sign = full_sentence.find(sign);	//SEARCHING FOR NON PL PART OF LINE

	BACK:
	if(mode == TRANS_TO_DEFAULT)	//FOR 'TO POLISH' MODE
	{
		string display(full_sentence, 0, nr_sign); //COPYING OTHER LANGUAGE PART OF STRING
		cout<< display << endl;
		language = "Polish";
	}
	else if(mode == TRANS_FROM_DEFAULT)//FOR ' FROM_DEFAULT' MODE
	{
		string display(full_sentence, nr_sign+2, '\n');//COPYING PL PART OF STRING
		cout<< display << endl;
		language = sec_lang;
	}
	//CHECKING
	cout << "Meaning in " << language <<":"<<endl;
	cin.ignore();					//CLEARS BUFFER,'\n' IS IN BUFFER AFTER INPUTTING MENU'S NUMBERS
	std:: getline(std::cin,answer);	//ALLOWS INPUTTING STRINGS WITH 'SPACE' SEPARATION

	check_resul = full_sentence.find(answer);	//CHECKING ANSWER
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
		return "continue";
	}
	else
	{
		return "quit";
	}
}



