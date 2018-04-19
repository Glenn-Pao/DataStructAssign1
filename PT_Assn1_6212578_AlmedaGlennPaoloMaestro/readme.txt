To compile the program, please enter the following

g++ Application.cpp LocationData.cpp LocationData.h MissionPlan.cpp MissionPlan.h NewEntryInput.cpp NewEntryInput.h PointTwoD.cpp PointTwoD.h -o PT_Assn1_6212578_AlmedaGlennPaoloMaestro.exe 2>error.txt



To run the program, please enter this after compiling the program
./PT_Assn1_6212578_AlmedaGlennPaoloMaestro.exe



Note: The error.txt is used for debugging. If it is empty, there are no errors encountered and should be able to run the PT_Assn1_6212578_AlmedaGlennPaoloMaestro.exe file

Classes created
LocationData - stores the star system related data
PointTwoD - stores the coordinates, and LocationData data
MissionPlan - main program that deals with the user input and output
NewEntryInput - handles the new statistics input and returns the new data to MissionPlan class for storage

Application.cpp - the main function runs here which contains the MissionPlan object and will continue running until the user enters 6