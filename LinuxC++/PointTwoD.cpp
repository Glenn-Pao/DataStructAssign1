#include "PointTwoD.h"

//default constructor
PointTwoD::PointTwoD()
{
	//set coordinates to 0, 0
	SetCoordinates(0, 0);
	
	//set civ index to be 0
	SetCivIndex(0.0f);	
	
	//calculate the distance from space center
	SetDistanceFromSpaceCtr();

	//use default constructor of locationData
	locationData = LocationData();
}
PointTwoD::PointTwoD(int x, int y, string newSunType, int numEarthLikePlanets, int numEarthLikeMoons, float particleDensity, float plasmaDensity)
{
	//set coordinates based on input x and y
	SetCoordinates(x, y);

	//set civ index to be 0
	SetCivIndex(0.0f);	

	//calculate the distance from space center
	SetDistanceFromSpaceCtr();
	
	locationData = LocationData(newSunType, numEarthLikePlanets, numEarthLikeMoons, particleDensity, plasmaDensity);
}
PointTwoD::PointTwoD(int x, int y, LocationData theData)
{
	//set coordinates based on input x and y
	SetCoordinates(x, y);

	//calculate the distance from space center
	SetDistanceFromSpaceCtr();
	
	//use the overloaded constructor of locationData
	locationData = theData;
}
//destructor
PointTwoD::~PointTwoD()
{
}

void PointTwoD::SetCoordinates(int x, int y)
{
	this->x = x;
	this->y = y;
}

void PointTwoD::SetXCoordinate(int x)
{
	this->x = x;
}

int PointTwoD::GetXCoordinate()
{
	return this->x;
}

void PointTwoD::SetYCoordinate(int y)
{
	this->y = y;
}

int PointTwoD::GetYCoordinate()
{
	return this->y;
}

void PointTwoD::SetLocationData(LocationData theData)
{
	locationData = theData;
}
LocationData PointTwoD::GetLocationData()
{
	return locationData;
}

void PointTwoD::SetCivIndex(float civIndex)
{
	this->civIndex = civIndex;
}

float PointTwoD::GetCivIndex()
{
	return this->civIndex;
}
void PointTwoD::SetDistanceFromSpaceCtr()
{
	//using the pythagoras theorem
	int squaredDist;
	
	//x2 + y2 since the space center is at origin so there is no need to factor in the origin here
	squaredDist = (x * x) + (y * y);
	
	//establish the distance in square root form
	distFromSpaceCtr = sqrt(squaredDist);
		
	//scale it according to 100 million km
	distFromSpaceCtr *= 100;	
}
float PointTwoD::GetDistanceFromSpaceCtr()
{
	return distFromSpaceCtr;
}
string PointTwoD::ToString()
{
	string temp, coords, civInd, distance, locationDataStats;

	//string stream the non-string variables
	stringstream coordXToS, coordYToS, civToS, distToS;
	
	//into their own respective variables, then convert them into string form
	coordXToS << x;
	coordYToS << y;
	civToS << civIndex;
	distToS << distFromSpaceCtr;
	
	coords =   "Location Coordinates (x, y): (" + coordXToS.str() + ", " + coordYToS.str() + ")" + '\n';
	civInd =   "Civilization Index         : " + civToS.str() + '\n';
	distance = "Distance from Center       : " + distToS.str() + '\n';
	locationDataStats = locationData.ToString();

	//chain the data together into a string that can be read by the console
	temp =  coords + civInd + locationDataStats;

	return temp;
}

string PointTwoD::DestinationOutput()
{
	string temp, coords, civInd;

	//string stream the non-string variables
	stringstream coordXToS, coordYToS, civToS;
	
	//into their own respective variables, then convert them into string form
	coordXToS << x;
	coordYToS << y;
	civToS << civIndex;	
	
	coords =   "Location Coordinates (x, y): (" + coordXToS.str() + ", " + coordYToS.str() + ")" + '\n';
	civInd =   "Civilization Index         : " + civToS.str() + '\n';
	//chain the data together into a string that can be read by the console
	temp =  civInd + coords;

	return temp;
}
string PointTwoD::DistanceOutput()
{
	string temp, coords, distance;

	//string stream the non-string variables
	stringstream coordXToS, coordYToS, distToS;
	
	//into their own respective variables, then convert them into string form
	coordXToS << x;
	coordYToS << y;
	distToS << distFromSpaceCtr;
	
	coords =   "Location Coordinates (x, y): (" + coordXToS.str() + ", " + coordYToS.str() + ")" + '\n';
	distance = "Distance from Center       : " + distToS.str() + '\n';
	//chain the data together into a string that can be read by the console
	temp =  distance + coords;

	return temp;
}

