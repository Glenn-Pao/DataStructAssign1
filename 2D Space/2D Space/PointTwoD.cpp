#include "PointTwoD.h"

//default constructor
PointTwoD::PointTwoD()
{
	//set coordinates to 0, 0
	SetCoordinates(0, 0);

	//use default constructor of locationData
	locationData = LocationData();
}

PointTwoD::PointTwoD(int x, int y, LocationData theData)
{
	//set coordinates based on input x and y
	SetCoordinates(x, y);

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