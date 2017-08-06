#ifndef FILEA_H
#define FILEA_H

#pragma once
//////////////////////////////////////////////////////////////////////////////
// FileA.h - Dummy file to test dependencies.		 						//
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
* x - global structure
* abc - global function
* showA() - function that calls uses FileB Object. 
*
* Required Files:
* ---------------
* "FileB.h"
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
#include "FileB.h"
#include "FileC.h"
#include <iostream>


struct  x{};
void abc() {}

namespace TestA {

	void def() {}
	enum Color { RED,GREEN,BLUE};
	class FileA {
	public:
		void showA();
	private:
		FileB fileB;
		TestC::FileA a;
	};

	inline void FileA::showA() {
		std::cout << "\nInside Show Function of FileA\n";
		fileB.showB();
	}
}
#endif // !FILEA_H
