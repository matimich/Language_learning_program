/*
 * FileOperation.h
 *
 *  Created on: 29 wrz 2018
 *      Author: Mateusz
 */

#ifndef FILEOPERATION_H_
#define FILEOPERATION_H_


#include <string>
#include "interface.h"

using namespace std;


// MACROS FOR ENGLISH
#define ENGLISH_FILE_NAME "pol_eng_words.txt"

#define FIRST_ENG "Press 1 to practice Eng to Pol."
#define SEC_ENG "Press 2 to practice Pol to Eng."

#define ENG	"English"



// MACROS FOR FRENCH
#define FRENCH_FILE_NAME "pol_fr_words.txt"

#define FIRST_FR "Press 1 to practice Fr to Pol."
#define SEC_FR "Press 2 to practice Pol to Fr."

#define FR "French"


class FileOperation : public Interface
{
private:
	//VARIABLES
	string full_sentence ;
	string sign  =  "-";
	string display;
	string answer;
	string sec_lang;
	int nr_sign; // number_of_signs_to_copy
	int check_resul; //checking your answer
	int mode_practice;
	int random;
	int count;
public:

	//FUNTIONS
	FileOperation(const Interface& start);
	void Practice(string first,string second,string third);
private:
	void Translate(string third);
	void FromPolish(string third);
	int Check(int mode);
};



#endif /* FILEOPERATION_H_ */
