#ifndef TESTEXECUTIVE
#define TESTEXECUTIVE 

#pragma once

/////////////////////////////////////////////////////////////////////////////
// Cpp11-TestExecutive.h - Test Executive								   //
// ver 1.0																   //
// ----------------------------------------------------------------------- //
// copyright � Nikhil Prashar, 2017                                        //
// All rights granted provided that this notice is retained                //
// ----------------------------------------------------------------------- //
// Language:    Visual C++, Visual Studio 2015                             //
// Platform:    HP Spectre, Core i7, Windows 10 Home                       //
// Application: Project 1, CSE687 - Object Oriented Design                 //
// Author:      Nikhil Prashar, Syracuse University                        //
//              (914) 733 8184, nnprasha@syr.edu	                       //
////////////////////////////////////////////////////////////////////////////
/*
* Package Operations:
* -------------------
*This package contains one TestExecutive<Data> class that demonstrates 
*all the functional requirements of this project. Various functions are defines 
*that are called from the main, which demonstrate the requirements of
*the project. 
*
* Public Interface:
* -----------------
* 	void AddKey(NoSqlDB<Data>&) - Saves a new key/value to the database
*	void DeleteKey(NoSqlDB<Data>&) - Deletes a key/Value from the database
*	void DatabaseEditing(NoSqlDB<Data>&) - Edits the database
*	bool QueryManager(NoSqlDB<Data>&) - Querys the database
*
* Required Files:
* ---------------
* NoSqlDB.h
* Query.h
*
* Build Process:
* --------------
* devenv codeAnalyzer.sln /rebuild debug
*
* Maintenance History:
* --------------------
* ver 1.0 : 7th Feb 2017
* - first release
*
* ver 1.1 : 7th March 2017
* - Second Release
*/
#include "NoSqlDB.h"
#include "Query.h"

#include <iostream>
#include <set>
using namespace XmlProcessing;

template<typename Data>
class TestExecutive {
public:

	using Key = std::string;
	using AllKeys = std::vector<Key>;
	void AddKey(NoSqlDB<Data>&);
	void DeleteKey(NoSqlDB<Data>&);
	void DatabaseEditing(NoSqlDB<Data>&);
	bool QueryManager(NoSqlDB<Data>&);	
};



//Function that executes the queries of the Query class
template<typename Data>
bool TestExecutive<Data>::QueryManager(NoSqlDB<Data>& db)
{
	try {
		std::cout << "\n------------------------------------------------------------------\n";
		std::cout << "\tREQUIREMENT NO 7- EXECUTION OF QUERIES";
		std::cout << "\n------------------------------------------------------------------\n";
		std::cout << "\n\n-->State of the database before execution of queries begin: ";
		std::cout << db.show();
		Query<Data> query;
		//Query No 1- Value of a specified key. GetValueFromKey(NoSqlDB<Data>&,Keys,std::string specifiedKey)
		Element<Data> query1 = query.GetValueFromKey(db, db.RetrieveAllKeys(), "NoSqlDB");
		//Query No 2- Children of a specified key. GetChildrenFromKey(NoSqlDB<Data>&,std::string specifiedKey)
		std::vector<std::string> query2 = query.GetChildrenFromKey(db, "NoSqlDB");
		//Query No 3- Return all keys that contain the string "XML". GetKeysFromPattern(NoSqlDB<Data>&,std::string specifiedKey);
		std::vector<Key> query3 = query.GetKeysFromPattern(db, "Exec");

		std::cout << "\n\n-->Executing Query Number 4 over the keys that were obtained in Query Number 2 (Requirement Number 8)";
		//Query No 4- Return all keys from a given set of keys that contain a specified string in their item name. 
		std::vector<Key> query4 = query.GetKeysWithSpecifiedStringInItemName(db, query2, "XML");

		std::cout << "\n\n-->Executing Query Number 5 over the keys that were obtained in Query Number 3 (Requirement Number 8)";
		//Query No 5- Return all keys from a given set of keys that contain a specified string in their category name. 
		std::vector<Key> query5 = query.GetKeysWithSpecifiedStringInCategoryName(db, query3, "abc");

		//Query no 6- All keys that contain a specified string in their template data section when that makes sense.
		std::cout << "\n\n-->Executing Query Number 6 over the UNION OF KEYS that were obtained in Query Number 2 and 3 (Requirement Number 9)";
		std::set<Key> q2(query2.begin(), query2.end());
		std::set<Key> q3(query3.begin(), query3.end());
		std::vector<Key> unionOfQueries1;	//union of keys obtained in query 2 and 3
		std::set_union(q2.begin(), q2.end(), q3.begin(), q3.end(), std::back_inserter(unionOfQueries1));
		std::vector<Key> query6 = query.GetKeysWithSpecifiedStringInTemplateData(db, unionOfQueries1);

		std::set<Key> q4(query4.begin(), query4.end());
		std::set<Key> q5(query5.begin(), query5.end());
		std::vector<Key> unionOfQueries2;	//union of keys obtained in query 2 and 3
		std::set_union(q4.begin(), q4.end(), q5.begin(), q5.end(), std::back_inserter(unionOfQueries2));
		//Query No 7- All keys that contain values written within a specified time-date interval.
		std::cout << "\n\n-->Executing Query Number 7 over the UNION OF KEYS that were obtained in Query Number 4 and 5 (Requirement Number 9)";
		std::vector<Key> query7 = query.GetKeysWithinSpecifiedTimeinterval(db, unionOfQueries2, "2017-01-03.19:55:55", "2017-03-04.19:55:55");		
	}
	catch (...)
	{
		std::cout << "\n\nException caught in Query Manager(TestExecutive.h): ";
		return false;
	}
	return true;
}

//Function to Add a new key to the Database
template<typename Data>
void TestExecutive<Data>::AddKey(NoSqlDB<Data>& db)
{
	//Adding New Element 1
	Element<Data> newElem1;
	newElem1.name = "NewElement1";
	newElem1.key = "NewKey1";
	newElem1.category = "NewCategory1";
	newElem1.desc = "NewDesc1";
	newElem1.timeDate = time(0);
	newElem1.data = "NewData1";

	Keys AllKeys1 = db.RetrieveAllKeys();
	for (Key key : AllKeys1)
		newElem1.children.push_back(key);
	db.SaveToDB(newElem1.key,newElem1);
	std::cout << "\n\n--> New Element 1 stored to the database with key: " << newElem1.key;

	//Adding New Element 2
	Element<Data> newElem2;
	newElem2.name = "NewElement2";
	newElem2.key = "NewKey2";
	newElem2.category = "NewCategory2";
	newElem2.desc = "NewDesc2";
	newElem2.timeDate = time(0);
	newElem2.data = "NewData2";

	Keys AllKeys2 = db.RetrieveAllKeys();
	for (Key key : AllKeys2)
		newElem2.children.push_back(key);

	db.SaveToDB(newElem2.key,newElem2);
	std::cout << "\n\n--> New Element 2 stored to the database with key: " << newElem2.key;

	std::cout << "\n\n--> Displaying Database Items After Addition of new items:";
	std::cout << db.show();

	db.ScheduleSave(true);
}

//Function to delete keys from the database
template<typename Data>
void TestExecutive<Data>::DeleteKey(NoSqlDB<Data>& db)
{
	Keys AllKeys = db.RetrieveAllKeys();

	//Deleting half of the key/Values from the Database
	for (size_t i=0;i<AllKeys.size()/2;i++)
	{
		std::cout << "\n\n--> Deleting database entry which has key: " << AllKeys.at(i);
		db.DeleteFromDB(AllKeys.at(i));
	}
	std::cout << "\n\n--> Displaying Database Items After Deletion of items:";
	std::cout << db.show();	

	db.ScheduleSave(true);
}

//Function to Edit the Database
template<typename Data>
void TestExecutive<Data>::DatabaseEditing(NoSqlDB<Data>& db)
{
	AllKeys keys = db.RetrieveAllKeys();
	for (Key key : keys)
	{
		std::cout << "\n\n-->Editing Values for key: " << key;
		if (!db.EditDatabase(key))
			std::cout << "Key " << key << " not found in database";
	}
	std::cout << "\n\n--> Displaying Database Items After editing:";
	std::cout << db.show();

	db.ScheduleSave(true);
}

#endif // !TESTEXECUTIVE