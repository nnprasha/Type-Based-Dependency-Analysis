ReadMe.txt
----------------

The command line arguments that are passes by default are: 
../FilesToTest/ *.h /xmlDep ../XmlResult/DepAnalResult.xml /xmlSc ../XmlResult/StrongComponent.xml

The first argument is for a bunch of test files for which the dependency would be checked. I have created these dummy just for 
requirement demonstration. You can change this path to whichever folder of files you want to test. As these are dummy files to test, 
I have not included test stubs for that. 

the second set of arguments are for the pattern of files that will be matched in the test files folder. 

/xmlDep - This is just an identifier which specifies that the next argument after this argument is a path for Dependency result file. 
	If you want to check for default file (requirement 8), please remove /xmlDep and the next argument from the set of cmd line arguments.

/xmlSc - This is just an identifier which specifies that the next argument after this argument is a path for StrongComponent result file. 
	If you want to check for default file (requirement 8), please remove /xmlSc and the next argument from the set of cmd line arguments.
