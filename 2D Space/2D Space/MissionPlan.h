#include "globalRequirements.h"
#include "PointTwoD.h"

//allow user to input stats data
//compute civ index based on all stats data input so far
//print top 5 exploration destinations (or the highest number of stats data)
//travel distance

class MissionPlan
{
private:
	int totalEntries;
	int civIndexCalculatedAt;		//where the last point civ index calculation was done
	PointTwoD *spaceData;		//the space data array

	bool isRunning = true;			//is the application running?

	const int totalNumEntriesAllowed = 150;

	enum MissionPlanState
	{
		STANDBY,
		INPUT_STATS,
		COMPUTE_CIV_INDEX,
		EXPLORE_DESTINATIONS,
		TRAVEL_DISTANCE,
		QUIT,
		NUM_STATES
	};

	MissionPlanState theState = STANDBY;
public:
	MissionPlan();
	~MissionPlan();

	void OnStandby();
	void InputStats();
	void ComputeCivIndex();
	void PrintExplorationDestinations();
	void PrintTravelDistance();
	void QuitApplication();

	//the main function that doesn't return anything
	void main();
};