/*
 * interface.cpp
 *
 *  Created on: 27 wrz 2018
 *      Author: Mateusz Michalski
 */

#ifndef INTERFACE_CPP_
#define INTERFACE_CPP_

#include "interface.hpp"
#include <iostream>
using namespace std;

Interface :: Interface() : decision_menu{0},language{10},mode{0},lang_number{2},decision{0}
{
	//interface display:
	language_array[ENG_NUMBER] = ENG;
	first[ENG_NUMBER] = FIRST_ENG(Press TRANS_TO_DEFAULT to practice English to  DEFAULT_LANGUAGE.);
	second[ENG_NUMBER] = SEC_ENG(Press TRANS_FROM_DEFAULT to practice  DEFAULT_LANGUAGE  to English.);

	language_array[FR_NUMBER]= FR;
	first[FR_NUMBER] = FIRST_FR(Press TRANS_TO_DEFAULT to practice French to DEFAULT_LANGUAGE.);
	second[FR_NUMBER] = SEC_FR(Press TRANS_FROM_DEFAULT to practice  DEFAULT_LANGUAGE  to French.);
}


void Interface :: menu(void)
{
	do
	{
		cout <<"__MENU__" << endl;
		cout << PRACTICE <<")Practice" << endl;
		cout << REVISION <<")Revision" << endl;
		cout << FIlE_CONF <<")Add/delete/rep words" << endl;
		cout << EXIT <<")Exit" << endl;

		cin >> decision_menu;
		if(decision_menu != PRACTICE && decision_menu != REVISION && decision_menu != FIlE_CONF
				&& decision_menu != EXIT)
		{
			cout << "Wrong number." << "(" ;
			cout << decision_menu << ")"<<endl;
			cin.clear();	//clears flag
			cin.ignore();	// clears sign from buffer
		}

		if(decision_menu == EXIT)	//EXIT
		{
			return;
		}

	}while(decision_menu != PRACTICE && decision_menu != REVISION && decision_menu != FIlE_CONF
			&& decision_menu != EXIT);

	do	//DISPLAY AVAILABLE LANGUAGES
	{

		for(int i =0 ; i < lang_number; i++)
		{
			cout <<"Choose '" << i << "' to learn " <<  language_array[i] << "." << endl;
		}

		cin >> language;
		if(language != ENG_NUMBER && language != FR_NUMBER)
		{
			cout << "Wrong number." << "(" ;
			cout << language << ")"<<endl;
			cin.clear();	//clears flag ,prevents from crashing
			cin.ignore();	// clears sign from buffer
		}
	}
	while(language != ENG_NUMBER && language != FR_NUMBER);


	if(decision_menu == PRACTICE) // configurate practice mode
	{
		do
		{
			cout <<"Choose '" << NORMAL_MODE << "' to play 'normal mode'  - program displays all data from the file" << endl;
			cout <<"one after another." << endl;
			cout <<"Choose '" << RANDOM_MODE << "' to play 'random mode' - program displays random data from the file." << endl;

			cin >> mode;

			if(mode != NORMAL_MODE && mode != RANDOM_MODE)
			{
				cout << "Wrong number." << "(" ;
				cout << mode << ")"<<endl;
				cin.clear();	//clears flag
				cin.ignore();	// clears sign from buffer
			}
		}
		while(mode != NORMAL_MODE && mode != RANDOM_MODE);

		do
		{
			cout << first[language] << endl;	// "Press 1 to translate an other language to Pol"
			cout << second[language] << endl;	// "Press 2 to translate Pol to an other language"
			cin >> decision;

			if(decision != TRANS_TO_DEFAULT && decision != TRANS_FROM_DEFAULT)
			{
				cout << "Wrong number." << "(" ;
				cout << decision << ")"<<endl;
				cin.clear();	//clears flag
				cin.ignore();	// clears sign from buffer
			}
		}
		while(decision != TRANS_TO_DEFAULT && decision != TRANS_FROM_DEFAULT);
	}
}

#endif /* INTERFACE_CPP_ */
