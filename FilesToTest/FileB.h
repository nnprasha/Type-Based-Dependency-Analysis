#ifndef FILEB_H
#define FILEB_H

//////////////////////////////////////////////////////////////////////////////
// FileB.h - Dummy file to test dependencies.		 						//
//																			//
// ----------------------------------------------------------------------- //
// copyright © Nikhil Prashar, 2017                                        //
// All rights granted provided that this notice is retained                //
// ----------------------------------------------------------------------- //
// Language:    Visual C++, Visual Studio 2015                             //
// Platform:    HP Spectre, Core i7, Windows 10 Home                       //
// Application: Project 2, CSE687 - Object Oriented Design                 //
// Author:      Nikhil Prashar, Syracuse University                        //
//              (914) 733 8184, nnprasha@syr.edu	                       //
////////////////////////////////////////////////////////////////////////////
/*
* Module Operations:
* -------------------
* Dummy file that is being used for dependency analysis.
*
* Public Interface:
* -----------------
* showB() - function that calls uses FileC Object.
*
* Required Files:
* ---------------
* "FileC.h"
*
* Build Process:
* --------------
* devenv CodeAnalyzer.sln /rebuild debug
*
* Maintenance History:
* --------------------
* ver 1.0 : 7th March 2017
* - first release
*
*/

#include <iostream>
#include "FileC.h"


class FileB {
public:
	void showB();
private:
	TestC::FileC c;

};

inline void FileB::showB() {
	std::cout << "\nInside File B show Function\n";
	c.showC();
}



#endif // !FILEB_H
