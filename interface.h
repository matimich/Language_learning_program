/*
 * interface.h
 *
 *  Created on: 27 wrz 2018
 *      Author: Mateusz
 */

#ifndef INTERFACE_H_
#define INTERFACE_H_




class Interface
{

public:
	//var
	int decision;	//for setting one of 4 menu operation
	int language;	// for choosing English or French learning mode
	int mode;		//setting one of two practice mode
	//fun
	Interface();
	void menu(void);	//menu interface
};



#endif /* INTERFACE_H_ */
