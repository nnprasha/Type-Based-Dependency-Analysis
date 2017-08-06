#ifndef FILEC_H
#define FILEC_H

#pragma once
//////////////////////////////////////////////////////////////////////////////
// FileC.h - Dummy file to test dependencies.		 						//
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
* xyz - global function
* pqr - global function
* abc - global function
* showC() - function that calls uses FileA and FileD Object.
*
* Required Files:
* ---------------
* "FileA.h"
* "FileD.h"
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
#include "FileD.h"
#include "FileA.h"

void xyz() {}
namespace TestC {
	class FileA{};
	void pqr() {}
	class FileC {
	public:
		void showC();
	private:
		TestA::FileA a;
		FileD d;
	};

	inline void FileC::showC()
	{
		a.showA();
		d.showD();
		std::cout << "\nInside show function of FileC\n";
	}

}
 
#endif //Filec.h