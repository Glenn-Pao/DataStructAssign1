#include "MissionPlan.h"

MissionPlan::MissionPlan()
{
	totalEntries = 0;
	civIndexCalculatedAt = 0;
	spaceData = new PointTwoD[totalNumEntriesAllowed];
	//considering that there is a static array already in place, the spaceData will initialize itself
	for (int i = 0; i < totalNumEntriesAllowed; i++)
	{
		//default constructor
		spaceData[i] = PointTwoD();
		cout << "Data initialized: space data " << i << endl;
	}
}

MissionPlan::~MissionPlan()
{
	//prevent memory leak but ensure that there is something that exists in the first place
	if (spaceData)
	{
		delete[] spaceData;
		spaceData = nullptr;
	}
}

//this function is a router function
void MissionPlan::OnStandby()
{
	int choice;
	cout << "Enter your choice: ";
	cin >> choice;

	//translate the choices into the enum states
	switch (choice)
	{
	case 1:		//input stats
		theState = INPUT_STATS;
		break;
	case 2:		//compute civ index
		theState = COMPUTE_CIV_INDEX;
		break;
	case 3:		//explore destination
		theState = EXPLORE_DESTINATIONS;
		break;
	case 4:		//travel distance
		theState = TRAVEL_DISTANCE;
		break;
	case 5:		//quit
		theState = QUIT;
		break;
	default:
		cout << "Choice invalid. Please try again." << endl;
		OnStandby();
		break;
	}
}

void MissionPlan::InputStats()
{

}
void MissionPlan::ComputeCivIndex()
{

}
void MissionPlan::PrintExplorationDestinations()
{

}
void MissionPlan::PrintTravelDistance()
{

}
void MissionPlan::QuitApplication()
{
	cout << "Thank you for using the Mission Plan Program! We hope to see you again!" << endl;

	//stop the program
	isRunning = false;
}

void MissionPlan::main()
{
	while (isRunning)
	{
		//check on the current state of the application
		switch (theState)
		{
		case STANDBY:
			OnStandby();
			break;
		case INPUT_STATS:
			InputStats();
			break;
		case COMPUTE_CIV_INDEX:
			ComputeCivIndex();
			break;
		case EXPLORE_DESTINATIONS:
			PrintExplorationDestinations();
			break;
		case TRAVEL_DISTANCE:
			PrintTravelDistance();
			break;
		case QUIT:
			QuitApplication();
			isRunning = false;
			break;
		}
	}
}