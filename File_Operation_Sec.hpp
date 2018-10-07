/*
 * File_Operation_Sec.h
 *
 *  Created on: 3 paü 2018
 *      Author: Mateusz Michalski
 */

#ifndef FILE_OPERATION_SEC_HPP_
#define FILE_OPERATION_SEC_HPP_

#include <iostream>
#include "interface.hpp"

class FileData : public Interface
{
public:
	FileData(const Interface& start);
private:
	int language_flag;
	void Display(std::string FileName);
	int Edit_Menu(void);
	void Edit(std::string FileName);
	void Add(std::string FileName);
	void Delete(std::string FileName);
	void Replace(std::string FileName);
};

#endif /* FILE_OPERATION_SEC_HPP_ */
