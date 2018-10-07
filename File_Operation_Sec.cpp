/*
 * File_Operation_Sec.cpp
 *
 *  Created on: 3 paü 2018
 *      Author: Mateusz Michalski
 */

#include "File_Operation_Sec.hpp"

#include <iostream>
#include <fstream>
#include <cstdio>

#include "FileOperation.hpp"
using namespace std;


FileData::FileData(const Interface& start): language_flag{start.language}
{
	if(start.language == ENG_NUMBER)	//ENG
	{
		if(start.decision_menu == REVISION)
		{
			Display(ENGLISH_FILE_NAME);
		}
		else if(start.decision_menu == FIlE_CONF)
		{
			Edit(ENGLISH_FILE_NAME);

		}
	}
	else if (start.language == FR_NUMBER)	//FR
	{
		if(start.decision_menu == REVISION)
		{
			Display(FRENCH_FILE_NAME);
		}
		else if(start.decision_menu == FIlE_CONF)
		{
			Edit(ENGLISH_FILE_NAME);
		}
	}
}

void FileData:: Display(std::string FileName)
{
	string display;
	ifstream Display;
	Display.open(FileName);

	if(Display.is_open())
	{
		while(getline(Display,display))
		{
			cout << display << endl;
		}
	}
	else
	{
		cout <<"File not found" << endl;
	}
	Display.close();
}

int FileData :: Edit_Menu()
{
	do
		{
			cout <<"1)Add new word." << endl;
			cout <<"2)Delete existing word." << endl;
			cout <<"3)Replace word." << endl;
			cin >> decision_menu;
			if(decision_menu != 1 && decision_menu != 2 && decision_menu != 3)
			{
				cout << "Wrong number." << "(" ;
				cout << decision_menu << ")"<<endl;
				cin.clear();	//clears flag
				cin.ignore();	// clears sign from buffer
			}
		}
		while(decision_menu != 1 && decision_menu != 2 && decision_menu != 3);
	return decision_menu;
}

void FileData :: Edit(string FileName)
{
	switch(Edit_Menu())
	{
		case 1:
		{
			Add(FileName);
			break;
		}
		case 2:
		{
			Delete(FileName);
			break;
		}
		case 3:
		{
			Replace(FileName);
			break;
		}
	}
}

void FileData :: Add(string FileName)
{
	string new_word;
	cout << "Add new word, remember about:" <<endl;
	cout << "'foreign_word - polish_word'" << endl;
	cout << "construction:" <<endl;
	cin.ignore();
	std::getline(cin,new_word);
	ofstream Add;
	Add.open(FileName,ios::in | ios::ate );	//file configuration
	Add << "\n";
	Add << new_word;
	Add.close();
	cout << "Done!" <<endl;
}

void FileData :: Delete(string FileName)
{
	string search;
	string copy;
	int check, loops = 0;
	int flag=0,flag_2=0;

	cout << "Input the word you want to remove:" << endl;
	cin.ignore();
	std::getline(cin,search);
	//FILES CONF
	fstream Delete;
	ofstream TemporaryFile;
	Delete.open(FileName);
	TemporaryFile.open("Temp.txt");

	Delete.seekg(0, ios:: beg);
	while(getline(Delete,copy))
	{
		loops++;
	}
	loops -= 1;

	Delete.clear();
	Delete.seekg(0, ios:: beg);


	while(getline(Delete,copy))
	{
		check=copy.find(search);
		if(check!=-1)
		{
			flag = 1;
			flag_2 =1;
			cout << "Done!" << endl;
		}
		if(flag == 0)
		{
			if(loops!=0)
			{
				TemporaryFile << copy;
				TemporaryFile <<"\n";	// TO MI ROBI!! , sprawdzic na replace
			}
			else if(loops==0)
			{
				TemporaryFile << copy;
			}
		}
		flag = 0;
		loops--;
	}

	if(flag_2 == 0)
	{
		cout << "Word not found." << endl;
	}

	TemporaryFile.close();
	Delete.close();

	if(language_flag==1)	//Eng
	{
		const char* File = ENGLISH_FILE_NAME;
		remove(File);
		rename("Temp.txt",File);
	}

	else if(language_flag==2)	//Fr
	{
		const char* File = FRENCH_FILE_NAME;
		remove(File);
		rename("Temp.txt",File);
	}
}

void FileData :: Replace(string FileName)
{
	string search_replace;
	string copy;
	int check;
	int flag=0,flag_2=0,loops =0;

	cout << "Input the word you want to replace:" << endl;
	cin.ignore();
	std::getline(cin,search_replace);

	cout << "WPisales:" << search_replace<<endl;
	//FILES CONF
	fstream Delete;
	ofstream TemporaryFile;
	Delete.open(FileName);
	TemporaryFile.open("Temp.txt");

	Delete.seekg(0, ios:: beg);
	while(getline(Delete,copy))
	{
		loops++;
	}
	loops -= 1;

	Delete.clear();
	Delete.seekg(0, ios:: beg);

	while(getline(Delete,copy))
	{
		check=copy.find(search_replace);
		if(check!=-1)	//WORD FOUND
		{
			flag = 1;
			cout << "Input the word you want to add." << endl;
			cout << "Remember about 'foreign - polish' format." << endl;
			std::getline(cin,search_replace);

			copy.replace(0,copy.length(),search_replace);
			if(loops !=0)
			{
				TemporaryFile << copy;
				TemporaryFile << "\n";
				flag_2 = 1;
				cout << "Done!" << endl;
			}
			else if(loops==0)
			{
				TemporaryFile << copy;
				flag_2 = 1;
				cout << "Done!" << endl;
			}
		}
		if(flag == 0)
		{
			if(loops !=0)
			{
				TemporaryFile << copy;
				TemporaryFile << "\n";
				flag_2 = 1;
			}
			else
			{
				TemporaryFile << copy;
				flag_2 = 1;
			}
		}
		flag = 0;
		loops--;
	}
	if(flag_2 == 0)
	{
		cout << "Word not found." << endl;
	}

	TemporaryFile.close();
	Delete.close();

	if(language_flag == ENG_NUMBER)	//Eng
	{
		const char* File = ENGLISH_FILE_NAME;
		remove(File);
		rename("Temp.txt",File);
	}

	else if(language_flag == FR_NUMBER)	//Fr
	{
		const char* File = FRENCH_FILE_NAME;
		remove(File);
		rename("Temp.txt",File);
	}
}


