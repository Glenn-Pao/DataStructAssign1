#include "LocationData.h"
#include <algorithm>

//pre-defined strings required to qualify for civ index calculation
string LocationData::sunTypeByDefinition[7] = { "TYPE O",  "TYPE B" ,"TYPE A" ,"TYPE F" ,"TYPE G" ,"TYPE K", "TYPE M" };
int LocationData::sunTypeProbability[7] = { 30, 45, 60, 75, 90, 80, 70 };

//default constructor
LocationData::LocationData()
{
	SetSunType("");
	SetNumEarthLikePlanets(0);
	SetNumEarthLikeMoons(0);
	SetParticleDensity(0.0f);
	SetPlasmaDensity(0.0f);
}

//overloaded constructor
LocationData::LocationData(string theType, int numEarthLikePlanets, int numEarthLikeMoons, float particleDensity, float plasmaDensity)
{
	SetSunType(theType);
	SetNumEarthLikePlanets(numEarthLikePlanets);
	SetNumEarthLikeMoons(numEarthLikeMoons);
	SetParticleDensity(particleDensity);
	SetPlasmaDensity(plasmaDensity);
}
LocationData::~LocationData()
{
}

void LocationData::SetSunType(string theType)
{
	//do a check to ensure that the user did not enter any illegal entries
	bool isCorrect = false;

	//change theType string into upper case
	transform(theType.begin(), theType.end(), theType.begin(), ::toupper);

	for (int i = 0; i < sizeof(sunTypeByDefinition); i++)
	{
		//if it is inside the preset definitions, consider this a pass
		if (theType == sunTypeByDefinition[i])
		{
			isCorrect = true;
			sunType = theType;
			break;
		}
	}

	//if (isCorrect)
	//{
	//	cout << "Definition is correct;";
	//}
	//else
	//{
	//	cout << "Definition is wrong;";

	//	//prompt a reentry
	//}
}

string LocationData::GetSunType()
{
	return sunType;
}

void LocationData::SetNumEarthLikePlanets(int numEarthLikePlanets)
{
	noOfEarthLikePlanets = numEarthLikePlanets;
}

int LocationData::GetNumEarthLikePlanets()
{
	return noOfEarthLikePlanets;
}

void LocationData::SetNumEarthLikeMoons(int numEarthLikeMoons)
{
	noOfEarthLikeMoons = numEarthLikeMoons;
}
int LocationData::GetNumEarthLikeMoons()
{
	return noOfEarthLikeMoons;
}

void LocationData::SetParticleDensity(float particleDensity)
{
	aveParticleDensity = particleDensity;
}
float LocationData::GetParticleDensity()
{
	return aveParticleDensity;
}

void LocationData::SetPlasmaDensity(float plasmaDensity)
{
	avePlasmaDensity = plasmaDensity;
}
float LocationData::GetPlasmaDensity()
{
	return avePlasmaDensity;
}

float LocationData::CalculateCivIndex(string sunType, int noOfEarthLikePlanets, int noOfEarthLikeMoons, float aveParticleDensity, float avePlasmaDensity)
{
	//probability calculated by sun type
	int sunTypePercent;
	
	//resulting civ index from calculation
	float result;

	//change theType string into upper case
	transform(sunType.begin(), sunType.end(), sunType.begin(), ::toupper);

	for (int i = 0; i < sizeof(sunTypeByDefinition); i++)
	{
		if (sunType == sunTypeByDefinition[i])
		{
			//assuming the definition of the corresponding int is correct, allocate the life probability by sun type here
			sunTypePercent = sunTypeProbability[i];
			break;
		}
	}

	//based on the formula
	result = ((sunTypePercent / 100) - (aveParticleDensity + avePlasmaDensity) / 200) * (noOfEarthLikePlanets + noOfEarthLikeMoons);

	return result;
}