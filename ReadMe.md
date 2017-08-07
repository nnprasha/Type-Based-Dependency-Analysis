Developed and tested a type-based dependency analyzer that uses the analysis machinery based on extracting lexical content
from source code files and building a Type Table for the same. In stage 1, lexical analysis was performed over a set of files in the repository
and a Type Table (container class that stored type information) was constructed based on the types (classes, structs, enums, typedefs, and
aliases) that were inferred from the analysis. In stage 2, dependency analysis was performed for each file in a specified file collection and
logs all other files from the file collection on which they depend by making use of the Type Table constructed in stage 1


To run the project:
--> run compile.bat
--> run run.bat

output has been provided in Output.pdf
