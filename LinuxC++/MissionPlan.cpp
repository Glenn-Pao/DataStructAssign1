#include "MissionPlan.h"

MissionPlan::MissionPlan()
{
	isRunning = true;			//set the application to running = true
	theState = STANDBY;			//set the current state of application to standby mode
	totalEntries = 0;			//set the current total num of entries to 0
	civIndexCalculatedAt = 0;		//set the current civ index calculated at to 0
	totalNumEntriesAllowed = 150;		//set the total number of entries allowed to 150
	spaceData[totalNumEntriesAllowed];	//set the array of spaceData to 150
}

MissionPlan::~MissionPlan()
{
}

//this function is a router function
void MissionPlan::OnStandby()
{
	//display the main menu text
	DisplayStandbyText();

	int choice;
	cout << "Enter your choice: ";
	cin >> choice;
	cout << "=================================================================" << endl;

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
	case 4:		//travel distance, top 5
		theState = TRAVEL_DISTANCE;
		break;
	case 5:		//print detailed entries
		theState = SHOW_ALL_ENTRIES;
		break;
	case 6:		//quit
		theState = QUIT;
		break;
	default:
		cout << "Choice invalid. Please try again." << endl;
		cin.clear();
		cin.ignore();
		OnStandby();		//recursion function to be done here since the user needs to do a new input
		break;
	}
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
		case SHOW_ALL_ENTRIES:
			PrintAllEntries();
			break;
		case QUIT:
			QuitApplication();
			isRunning = false;
			break;
		}
	}
}

void MissionPlan::DisplayStandbyText()
{
	//display the name and ID 
	cout << "=================================================================" << endl;
	cout << "Student ID  : 6212578" << endl;
	cout << "Student Name: Almeda Glenn Paolo Maestro" << endl;

	//display the menu
	cout << "=================================================================" << endl;
	cout << "Welcome to 2D Star Fleet Mission Planner!" << endl;
	cout << "1) Input new statistical data" << endl;
	cout << "2) Calculate Civilization Index of existing dataset" << endl;
	cout << "3) Display the top 5 Exploration Destinations" << endl;
	cout << "4) Display the total distance to travel with the top destinations" << endl;
	cout << "5) Display all existing entries" << endl;
	cout << "6) Quit Application" << endl;
	cout << "=================================================================" << endl;
}

void MissionPlan::InputStats()
{
	//prompt user to input new entry
	NewEntryInput newInput = NewEntryInput();
	
	//start the instance object to take in all the required values
	newInput.RegisterNewItem();
	
	//transfer the all the data to the latest point of the spaceData array
	spaceData[totalEntries] = newInput.ReturnPointTwoDData();
	totalEntries++;

	cout << "New entry added!" << endl;

	//return to standby mode
	theState = STANDBY;
}

void MissionPlan::ComputeCivIndex()
{
	//use local variable to prevent any mishandling of the global variable civIndexCalculatedAt
	int lastPointCalculated = civIndexCalculatedAt;

	//optimized method: calculate from the last point
	//brute force method: calculate every existing entry
	while(lastPointCalculated < totalEntries)
	{
		//store relevant data into local variables to make it easier to read
		string sunType = spaceData[lastPointCalculated].GetLocationData().GetSunType();
		int noOfEarthLikePlanets = spaceData[lastPointCalculated].GetLocationData().GetNumEarthLikePlanets();
		int noOfEarthLikeMoons = spaceData[lastPointCalculated].GetLocationData().GetNumEarthLikeMoons();
		float aveParticleDensity = spaceData[lastPointCalculated].GetLocationData().GetParticleDensity();
		float avePlasmaDensity = spaceData[lastPointCalculated].GetLocationData().GetPlasmaDensity();
	
		//use the calculation and set the result into civIndex
		spaceData[lastPointCalculated].SetCivIndex(LocationData::CalculateCivIndex(sunType, noOfEarthLikePlanets, noOfEarthLikeMoons, aveParticleDensity, avePlasmaDensity));
		cout << spaceData[lastPointCalculated].ToString() << endl;
		//increment the last point calculated
		lastPointCalculated++;
	}
	
	//send a confirmation that it has been successful
	cout << "Total Number of Entries found                       : " << totalEntries << endl;
	cout << "Number of Entries with Civilization Index calculated: " << lastPointCalculated << endl;
	cout << "Updated!" << endl;
	
	//copy the lastPointCalculated into civIndexCalculatedAt
	//this is to continue from where the user left off
	civIndexCalculatedAt = lastPointCalculated;

	//return to standby mode
	theState = STANDBY;
}

bool MissionPlan::NextEntryIsLarger(PointTwoD current, PointTwoD next, DataSortType targetData)
{
	//check if next entry is larger. if not, it will return false.
	switch(targetData)	
	{
	case X_COORD:
		return (current.GetXCoordinate() < next.GetXCoordinate());
		break;
	case Y_COORD:
		return (current.GetYCoordinate() < next.GetYCoordinate());
		break;
	}		
	//return false by default
	return false;
}

void MissionPlan::SortAscendingOrderArray(int totalEntries, PointTwoD currentList[], DataSortType targetData)
{
	int next;
	//sort the current list by civ index
	for(int current = 0; current < totalEntries; current++)
	{
		if(current != totalEntries -1)
		{
			//mark the next variable to be ahead of current by 1
			next = current + 1;
			if(!NextEntryIsLarger(currentList[current], currentList[next], targetData))
			{
				PointTwoD temp;
				temp = currentList[current];

				//swap their places
				currentList[current] = currentList[next];
				currentList[next] = temp;
			}
			next++;
		}
	}
}

void MissionPlan::SortDescendingOrderArray(int totalEntries, PointTwoD currentList[], DataSortType targetData)
{
	int next;
	//sort the current list by civ index
	for(int current = 0; current < totalEntries; current++)
	{
		if(current != totalEntries -1)
		{
			//mark the next variable to be ahead of current by 1
			next = current + 1;
		
			//loop through the entire list using next
			while(next < totalEntries)
			{
				//if the next entry value is larger than the current entry value
						

				if(NextEntryIsLarger(currentList[current], currentList[next], targetData))
				{
					PointTwoD temp;
					temp = currentList[current];

					//swap their places
					currentList[current] = currentList[next];
					currentList[next] = temp;
				}
				next++;
			}
		}
	}
}

void MissionPlan::CalculateTopEntries(int totalEntries, int maxEntries, PointTwoD currentList[])
{
	//consider the situation where the max num of entries < 5
	if(totalEntries < maxEntries)
	{
		//reassign the max num of entries
		maxEntries = totalEntries;
	}

	for(int i = 0; i < totalEntries; i++)
	{	
		//copy the data
		currentList[i] = spaceData[i];
	}	
	
	SortDescendingOrderArray(totalEntries, currentList, CIV_INDEX);
}

void MissionPlan::PrintDestinationEntriesFormula(int minNum,int maxNum, PointTwoD targetArray[])
{
	for(int i = minNum; i < maxNum; i++)
	{
		cout << "Entry " << i+1 << endl;
		cout << targetArray[i].DestinationOutput();
		
		if(i != maxNum - 1)
		{
			cout << "=================================================================" << endl;
		}		
	}
}
void MissionPlan::PrintExplorationDestinations()
{
	//the top five destinations
	int maxEntries = 5;
	//int next = 0;
	if(totalEntries < maxEntries)
	{
		maxEntries = totalEntries;
	}

	//create a local variable to prevent unintentional corruption of data on global variable
	PointTwoD currentList[totalEntries];

	//calculate the top entries	
	CalculateTopEntries(totalEntries, maxEntries, currentList);
	
	//display processing instruction
	cout << "Displaying the top 5 destinations.. " << endl;	
	
	//once the sorting is done, copy over the top 5 and print them out
	PrintDestinationEntriesFormula(0, maxEntries, currentList);
	
	//in the case that there isn't enough entries, display "no data entry" instead
	if(maxEntries < 5)
	{
		while(maxEntries != 5)
		{
			cout << "Entry " << maxEntries+1 << endl;
			cout << "No New Entry Found.." << endl;
			cout << "=================================================================" << endl;
			maxEntries++;
		}
	}

	cout << "End of top 5 destinations" << endl;	

	//return to standby mode
	theState = STANDBY;
}
float MissionPlan::CalculateDistanceEntries(int minNum, int maxNum, PointTwoD targetArray[])
{
	float totalDistance;	

	//once the sorting is done, copy over the top 5 and print them out
	for(int i = minNum; i < maxNum; i++)
	{
		totalDistance += targetArray[i].GetDistanceFromSpaceCtr();		
	}

	return totalDistance;
}

void MissionPlan::PrintTravelDistance()
{
	//1 unit = 100 million km
	float totalDistance;
	
	//the top five destinations
	int maxEntries = 5;
	//int next = 0;

	//create a local variable to prevent unintentional corruption of data on global variable
	PointTwoD currentList[totalEntries];
	
	CalculateTopEntries(totalEntries, maxEntries, currentList);

	cout << "Calculating approximate distance.. " << endl;	

	//once the sorting is done, copy over the top 5 and print them out
	totalDistance = CalculateDistanceEntries(0, maxEntries, currentList);

	cout << "Estimated total distance to travel: " << totalDistance << " million km" << endl;	

	//return to standby mode
	theState = STANDBY;
}
void MissionPlan::DisplayAllEntries(int totalEntries, PointTwoD targetData[])
{
	for(int i = 0 ; i < totalEntries; i++)
	{
		cout << "Entry " << i+1 << endl;
		cout << targetData[i].ToString();
	
		if(i != totalEntries - 1)
		{
			cout << "=================================================================" << endl;
		}
	}
	cout << "End of entry list.."<< endl;
}
void MissionPlan::SortedDisplayEntries()
{
	int typeOfData;
	PointTwoD sortedList[totalEntries];
	
	//copy over the list to prevent any unintentional modification to the master list
	for(int i = 0 ; i < totalEntries; i++)
	{
		sortedList[i] = spaceData[i];
	}
	cout << "=================================================================" << endl;
	cout << "Choose how you want to display the data (type number 1 or 2)" << endl;
	cout << "1) Ascending Order X-Coordinate" << endl;
	cout << "2) Descending Order X-Coordinate" << endl;
	cout << "3) Ascending Order Y-Coordinate" << endl;
	cout << "4) Descending Order Y-Coordinate" << endl;
	
	cin >> typeOfData;
	
	switch(typeOfData)
	{
	case 1:		//x coordinate ascending
		SortAscendingOrderArray(totalEntries, sortedList, X_COORD);
		break;
	case 2:		//x coordinate descending
		SortDescendingOrderArray(totalEntries, sortedList, X_COORD);
	break;
	case 3:		//y coordinate ascending
		SortAscendingOrderArray(totalEntries, sortedList, Y_COORD);
		break;
	case 4:		//y coordinate descending
		SortDescendingOrderArray(totalEntries, sortedList, Y_COORD);
		break;
	default:
		cout << "Choice invalid. Please try again." << endl;
		cin.clear();
		cin.ignore();
		SortedDisplayEntries();		//recursion function to be done here since the user needs to do a new input
		break;
	}
	cout << "Displaying" << endl;
	DisplayAllEntries(totalEntries, sortedList);
}
void MissionPlan::PrintAllEntries()
{
	//note: you can't print stuff in ascending or descending order if you only have 1 entry
	if(totalEntries > 1)
	{
		string temp;
		//let the user choose in what order he would like to display the entries as
		cout << "=================================================================" << endl;
		cout << "Would you like to display the entries as it is?" << endl;
		cout << "Y = YES" << endl;
		cout << "N = NO" << endl;
	
		cin >> temp;

		//change temp string into upper case
		transform(temp.begin(), temp.end(), temp.begin(), ::toupper);
	
		if(temp == "Y")
		{
			DisplayAllEntries(totalEntries, spaceData);
		}
		else if(temp == "N")
		{
			SortedDisplayEntries();
		}
	}	
	else
	{
		DisplayAllEntries(totalEntries, spaceData);
	}
	
	//return to standby mode
	theState = STANDBY;
}

void MissionPlan::QuitApplication()
{
	cout << "Thank you for using the Mission Plan Program! We hope to see you again!" << endl;

	//stop the program
	isRunning = false;
}


