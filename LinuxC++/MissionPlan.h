#include "NewEntryInput.h"

//allow user to input stats data
//compute civ index based on all stats data input so far
//print top 5 exploration destinations (or the highest number of stats data)
//travel distance

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
		EXPLORE_ALL_DESTINATIONS,
		INDIVIDUAL_TRAVEL_DISTANCE,
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
	//========= Constructor and Destructor ==========//
	MissionPlan();
	~MissionPlan();
	//========= Constructor and Destructor ==========//



	//============== Additional Helper Functions ==============//
	void DisplayStandbyText();
	void CalculateTopEntries(int totalEntries, int maxEntries, int next, PointTwoD currentList[]);
	void PrintDestinationEntriesFormula(int minNum, int maxNum, PointTwoD targetArray[]);
	float CalculateDistanceEntries(int minNum, int maxNum, PointTwoD targetArray[]);
	//============== Additional Helper Functions ==============//

	//============== Main Router Function(s) ==============//
	void OnStandby();
	//============== Main Router Function(s) ==============//

	//============== State-Based Function(s) ==============//
	void InputStats();
	void ComputeCivIndex();
	void PrintExplorationDestinations();
	void PrintAllExplorationDestinations();	
	void PrintTravelDistance();
	void PrintIndividualTravelDistance();
	void PrintAllEntries();
	void QuitApplication();
	//============== State-Based Function(s) ==============//
	
	//the main function that doesn't return anything
	void main();
};
