#include "MissionPlan.h"

///summary
///
/// This is the main program where all of the components are joined together to run the main program
/// Any errors detected will always go into MissionPlan class and the components it holds
///
///end summary

int main()
{
	cout << "mainProgram init" << endl;
	//init the object
	MissionPlan mainProgram = MissionPlan();
	mainProgram.main();
}
