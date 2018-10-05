/*
 * main.cpp
 *
 *  Created on: 27 wrz 2018
 *      Author: Mateusz Michalski
 */
#include "interface.h"
#include "FileOperation.h"
#include "File_Operation_Sec.h"



int main(void)
{
	Interface start;

	while(start.decision != 4)
	{
		start.menu();
		switch(start.decision)
		{
		case 1:		//practice mode
		{
			FileOperation *File = new FileOperation(start);
			delete File;
			break;
		}

		case 2:	//revision mode - display data
		{
			FileData *Revision = new FileData(start);
			delete Revision;
			break;
		}
		case 3:	//edit text file
		{
			FileData *AddDelRep = new FileData(start);
			delete AddDelRep;
		}
			break;
		case 4:	//exit
			break;
		}
	}
	return 0;
}



