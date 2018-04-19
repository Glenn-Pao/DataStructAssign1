#include "NewEntryInput.h"

///summary
///
/// The main driver of the app
/// This class handles all of the user interactions
/// The main functions it can do are:
/// 1) Allow user to input stats data
/// 2) Compute civ index based on all stats data input so far
/// 3) Print top 5 exploration destinations (or the highest number of stats data)
/// 4) Calculate and print the total travel distance in million km
/// 5) Display all existing entries (can be displayed as-is, in ascending or descending orders of (a) X-Coordinate, (b) Y-Coordinate or (c) Civilization Index
///
/// It also handles majority of the logic calculations required. There are several helper functions that have been created to reduce code clutter and make debugging simpler.
///
///end summary

class MissionPlan
{
private:
	//========= Minimum Requirement Variables =========//
	int totalEntries;
	int civIndexCalculatedAt;		//where the last point civ index calculation was done
	PointTwoD spaceData[150];		//the space data array
	//========= Minimum Requirement Variables =========//

	//========== Useful Additional Variables ==========//
	enum MissionPlanState
	{
		STANDBY,
		INPUT_STATS,
		COMPUTE_CIV_INDEX,
		EXPLORE_DESTINATIONS,
		TRAVEL_DISTANCE,
		SHOW_ALL_ENTRIES,
		QUIT,
		NUM_STATES
	};
	
	bool isRunning;				//is the application running?
	int totalNumEntriesAllowed;		//maximum number of entries in system
	MissionPlanState theState;		//default state to standby mode
	
	//========== Useful Additional Variables ==========//
public:
	enum DataSortType
	{
		CIV_INDEX,
		X_COORD,
		Y_COORD
	};
	
	//========= Constructor and Destructor ==========//
	MissionPlan();
	~MissionPlan();
	//========= Constructor and Destructor ==========//



	//============== Additional Helper Functions ==============//
	void DisplayStandbyText();										//what to show when program is on standby
	void CalculateTopEntries(int totalEntries, int maxEntries, PointTwoD currentList[]);			//the top 5 destinations
	void PrintDestinationEntriesFormula(int minNum, int maxNum, PointTwoD targetArray[]);			//the formula to print the destinations
	void SortAscendingOrderArray(int totalEntries, PointTwoD currentList[], DataSortType targetData);	//sort the array of existing data in ascending order
	void SortDescendingOrderArray(int totalEntries, PointTwoD currentList[], DataSortType targetData);	//sort the array of existing data in descending order	
	void SortedDisplayEntries();										//the main holder that contains the display UI for the user when he wants the data sorted
	void DisplayAllEntries(int totalEntries, PointTwoD targetData[]);					//the main holder that displays all of the sorted data
	float CalculateDistanceEntries(int minNum, int maxNum, PointTwoD targetArray[]);			//calculate the total distance. has a minimum and maximum parameter for added flexibility
	bool NextEntryIsLarger(PointTwoD current, PointTwoD next, DataSortType targetData);			//check if the next entry is larger than the current entry. returns true if it is the case
	//============== Additional Helper Functions ==============//

	//============== Main Router Function(s) ==============//
	void OnStandby();
	//============== Main Router Function(s) ==============//

	//============== State-Based Function(s) ==============//
	void InputStats();
	void ComputeCivIndex();
	void PrintExplorationDestinations();
	void PrintTravelDistance();
	void PrintAllEntries();
	void QuitApplication();
	
	//============== State-Based Function(s) ==============//
	
	//the main function that doesn't return anything
	void main();
};
