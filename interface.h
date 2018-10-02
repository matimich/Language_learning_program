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
	int decision;
	int language;
	char quit;
	int mode;
	Interface();
	void menu(void);
};




#endif /* INTERFACE_H_ */
