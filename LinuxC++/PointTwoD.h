#include "LocationData.h"
#include <cmath>
class PointTwoD
{
private:
	//========= Minimum Requirement Variables =========//
	int x, y;
	float civIndex;
	LocationData locationData;
	//========= Minimum Requirement Variables =========//

	float distFromSpaceCtr;
		
public:
	//========= Constructor and Destructor ==========//
	PointTwoD();					//default constructor
	PointTwoD(int x, int y, string newSunType, int numEarthLikePlanets, int numEarthLikeMoons, float particleDensity, float plasmaDensity);
	PointTwoD(int x, int y, LocationData theData);	//overloaded constructor
	~PointTwoD();
	//========= Constructor and Destructor ==========//

	//============ Get and Set Functions ============//
	void SetCoordinates(int x, int y);

	void SetXCoordinate(int x);
	int GetXCoordinate();

	void SetYCoordinate(int y);
	int GetYCoordinate();

	void SetLocationData(LocationData theData);
	LocationData GetLocationData();

	void SetCivIndex(float civIndex);
	float GetCivIndex();
	
	void SetDistanceFromSpaceCtr();
	float GetDistanceFromSpaceCtr();
	//============ Get and Set Functions ============//

	string ToString();				//display all of the data in string
	string DestinationOutput();			//display the destination output
	string DistanceOutput();			//display the distance
	
};
