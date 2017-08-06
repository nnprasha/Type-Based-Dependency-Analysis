#pragma once
//////////////////////////////////////////////////////////////////////////////
// FileD.h - Dummy file to test dependencies.		 						//
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
* showD() - function that prints to std output
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


class FileD {
public:
	void showD();
};

inline void FileD::showD()
{
	std::cout << "\nInside show function of FileD\n";
}
