/*
 * interface.cpp
 *
 *  Created on: 27 wrz 2018
 *      Author: Mateusz
 */

#ifndef INTERFACE_CPP_
#define INTERFACE_CPP_

#include <iostream>
#include "interface.h"

using namespace std;

Interface :: Interface() : decision{0},language{10},mode{0}
{}


void Interface :: menu(void)
{
	do
	{
		cout <<"Choose '1' to learn Eng." << endl;
		cout <<"Choose '2' to learn Fr." << endl;

		cin >> language;
		if(language != 1 && language != 2)
		{
			cout << "Wrong number." << "(" ;
			cout << language << ")"<<endl;
			cin.clear();	//clears flag ,prevents from crashing
			cin.ignore();	// clears sign from buffer
		}
	}
	while(language != 1 && language != 2);

	do
	{
		cout <<"__MENU__" << endl;
		cout <<"1)Practice" << endl;
		cout <<"2)Revision" << endl;
		cout <<"3)Add/delete words" << endl;
		cout <<"4)Exit" << endl;

		cin >> decision;
		if(decision != 1 && decision != 2 && decision != 3 && decision != 4)
		{
			cout << "Wrong number." << "(" ;
			cout << decision << ")"<<endl;
			cin.clear();	//clears flag
			cin.ignore();	// clears sign from buffer
		}
	}
	while(decision != 1 && decision != 2 && decision != 3 && decision != 4);


	if(decision==1) // configurate practice mode
	do
	{
		cout <<"Choose '1' to play 'normal mode'  - program displays all data from the file." << endl;
		cout <<"one after another" << endl;
		cout <<"Choose '2' to play 'random mode' - program displays random data from the file" << endl;

		cin >> mode;

		if(mode != 1 && mode != 2)
		{
			cout << "Wrong number." << "(" ;
			cout << mode << ")"<<endl;
			cin.clear();	//clears flag
			cin.ignore();	// clears sign from buffer
		}
	}
	while(mode != 1 && mode != 2);
}

#endif /* INTERFACE_CPP_ */
