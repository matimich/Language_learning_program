/*
 * File_Operation_Sec.h
 *
 *  Created on: 3 paü 2018
 *      Author: Mateusz
 */

#ifndef FILE_OPERATION_SEC_H_
#define FILE_OPERATION_SEC_H_

#include "interface.h"
#include <iostream>





class FileData : public Interface
{
public:
	FileData(const Interface& start);
private:
	void Display(std::string FileName);
	int Edit_Menu(void);
	void Edit(std::string FileName);
	void Add(std::string FileName);
};



#endif /* FILE_OPERATION_SEC_H_ */
