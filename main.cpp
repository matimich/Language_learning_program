/*
 * main.cpp
 *
 *  Created on: 27 wrz 2018
 *      Author: Mateusz Michalski
 */
#include "File_Operation_Sec.hpp"
#include "FileOperation.hpp"
#include "interface.hpp"



int main(void)
{
	Interface start;

	while(start.decision_menu != EXIT)
	{
		start.menu();
		switch(start.decision_menu)
		{
		case PRACTICE:		//practice mode
		{
			FileOperation *File = new FileOperation(start);
			delete File;
			break;
		}
		case REVISION:	//revision mode - display data
		{
			FileData *Revision = new FileData(start);
			delete Revision;
			break;
		}
		case FIlE_CONF:	//edit text file
		{
			FileData *AddDelRep = new FileData(start);
			delete AddDelRep;
			break;
		}
		case EXIT:	//exit
			break;
		}
	}
	return 0;
}



