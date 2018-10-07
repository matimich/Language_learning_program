/*
 * interface.h
 *
 *  Created on: 27 wrz 2018
 *      Author: Mateusz Michalski
 */

#ifndef INTERFACE_HPP_
#define INTERFACE_HPP_

#include <string>

//MACROS FOR MENU

#define PRACTICE 1
#define REVISION 2
#define FIlE_CONF 3
#define EXIT 4

//MACROS FOR PRACTICE MODE

#define NORMAL_MODE 1
#define RANDOM_MODE 2

#define TO_POLISH 1
#define FROM_POLISH 2



// MACROS FOR ENGLISH SETTINGS
#define FIRST_ENG "Press 1 to practice Eng to Pol."
#define SEC_ENG "Press 2 to practice Pol to Eng."
#define ENG	"English"
#define ENG_NUMBER 0
// MACROS FOR FRENCH SETTINGS
#define FIRST_FR "Press 1 to practice Fr to Pol."
#define SEC_FR "Press 2 to practice Pol to Fr."
#define FR "French"
#define FR_NUMBER 1



using namespace std;

class Interface
{

private:
	string language_array[2] ;
	string first[2];
	string second[2];
public:
	//var
	int decision_menu;	//for setting one of 4 menu operation
	int language;	// for choosing English or French learning mode
	int mode;		//setting one of two practice mode
	int lang_number;
	int decision;
	//fun
	Interface();
	void menu(void);	//menu interface
};

#endif /* INTERFACE_HPP_ */
