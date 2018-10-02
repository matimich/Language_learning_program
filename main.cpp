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
			FileOperation *File = new FileOperation(start);
			delete File;
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












	return 0;
}



