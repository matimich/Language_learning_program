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
#define TRANS_TO_DEFAULT 1
#define TRANS_FROM_DEFAULT 2

//DEFAULT LANGUAGE
#define DEFAULT_LANGUAGE Polish

#define Native(a) bridge_5(a)
#define bridge_5(a) #a

// MACROS FOR ENGLISH SETTINGS
#define ENG_NUMBER 0
#define ENG	"English"

#define FIRST_ENG(a) bridge(a)
#define bridge(a)	#a

#define SEC_ENG(a) bridge_3(a)
#define bridge_3(a) #a

// MACROS FOR FRENCH SETTINGS
#define FR_NUMBER 1
#define FR "French"

#define FIRST_FR(a) bridge_2(a)
#define bridge_2(a) #a

#define SEC_FR(a) bridge_4(a)
#define bridge_4(a) #a


// MACROS FOR ENGLISH FILE SETTINGS
#define ENGLISH_FILE_NAME "eng_words.txt"
// MACROS FOR FRENCH FILE SETTINGS
#define FRENCH_FILE_NAME "fr_words.txt"


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
