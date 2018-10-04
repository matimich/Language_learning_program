/*
 * File_Operation_Sec.cpp
 *
 *  Created on: 3 paü 2018
 *      Author: Mateusz
 */

#include "File_Operation_Sec.h"
#include "FileOperation.h"
#include <iostream>
#include <fstream>
#include <cstdio>
using namespace std;


FileData::FileData(const Interface& start) : language_flag{start.language}
{
	if(start.language==1)	//ENG
	{
		if(start.decision == 2)
		{
			Display(ENGLISH_FILE_NAME);
		}
		else if(start.decision == 3)
		{
			Edit(ENGLISH_FILE_NAME);

		}
	}
	else if (start.language==2)	//FR
	{
		if(start.decision == 2)
		{
			Display(FRENCH_FILE_NAME);
		}
		else if(start.decision == 3)
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
			cin >> decision;
			if(decision != 1 && decision != 2 && decision != 3)
			{
				cout << "Wrong number." << "(" ;
				cout << decision << ")"<<endl;
				cin.clear();	//clears flag
				cin.ignore();	// clears sign from buffer
			}
		}
		while(decision != 1 && decision != 2 && decision != 3);
	return decision;
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
}

void FileData :: Delete(string FileName)
{
	string search;
	string copy;
	int check;

	cout << "Input the word you want to remove:" << endl;
	cin.ignore();
	std::getline(cin,search);
	//FILES CONF
	fstream Delete;
	ofstream TemporaryFile;
	Delete.open(FileName);
	TemporaryFile.open("Temp.txt");
	/*
	if(TemporaryFile.is_open())
	{
		cout << "File has been created." << endl;	//TEST
	}
	*/
	int flag=0,flag_2=0;
	while(getline(Delete,copy))
	{
		check=copy.find(search);
		if(check!=-1)
		{
			flag = 1;
			copy.replace(0,copy.length(),"");
			if(flag==1)
			{
				TemporaryFile << copy;
				flag_2 =1;
			}
			cout << "Done" << endl;
		}
		if(flag == 0)
		{
			TemporaryFile << copy;
			TemporaryFile <<"\n";
		}
		flag = 0;
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
