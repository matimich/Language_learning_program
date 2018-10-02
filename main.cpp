/*
 * main.cpp
 *
 *  Created on: 27 wrz 2018
 *      Author: Mateusz
 */

#include <iostream>
#include "interface.h"
#include "FileOperation.h"
#include <string>
#include <cstring>
using namespace std;


int main(void)
{

	Interface start;

	while(start.decision != 4)
	{
		start.menu();
		switch(start.decision)
		{
		case 1:
		{
			FileOperation File(start);
			break;
		}

		case 2:
			break;
		case 3:
			break;
		case 4:
			break;
		}
	}



/*
	string a =  "A cat-koty";
	string b = "-";
	int check = a.find(b);
	if(check  >= 0)
	{
		cout << "Correct answer!" <<endl;
		cout << check <<endl;
	}
	if(check == -1 ) // string::npos =  -1
	{
		cout << "You are wrong." <<endl;
	}
*/






	return 0;
}



