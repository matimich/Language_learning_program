/*
 * FileOperation.h
 *
 *  Created on: 29 wrz 2018
 *      Author: Mateusz Michalski
 */

#ifndef FILEOPERATION_HPP_
#define FILEOPERATION_HPP_

#include <string>
#include "interface.hpp"
using namespace std;




class FileOperation : public Interface
{
private:
	//VARIABLES
	string full_sentence ;
	const string sign;
	string display;
	string answer;
	string sec_lang;
	int mode_practice;
	int mode_decision;
public:
	//FUNTIONS
	FileOperation(const Interface& start);
private:
	void Practice(string FileName);
	void Translate(string FileName);
	string Check(int mode);
};

#endif /* FILEOPERATION_HPP_ */
