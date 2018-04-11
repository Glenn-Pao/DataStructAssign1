#include "LocationData.h"
#include <algorithm>

//define the static values
string LocationData::sunTypeByDefinition[7] = { "TYPE O",  "TYPE B" ,"TYPE A" ,"TYPE F" ,"TYPE G" ,"TYPE K", "TYPE M" };
float LocationData::sunTypeProbability[7] = { 30, 45, 60, 75, 90, 80, 70 };

//default constructor
LocationData::LocationData()
{
	//use the set functions instead of directly setting them
	SetSunType("");
	SetNumEarthLikePlanets(0);
	SetNumEarthLikeMoons(0);
	SetParticleDensity(0.0f);
	SetPlasmaDensity(0.0f);
}

//overloaded constructor
LocationData::LocationData(string theType, int numEarthLikePlanets, int numEarthLikeMoons, float particleDensity, float plasmaDensity)
{
	//use the set functions instead of directly setting them
	SetSunType(theType);
	SetNumEarthLikePlanets(numEarthLikePlanets);
	SetNumEarthLikeMoons(numEarthLikeMoons);
	SetParticleDensity(particleDensity);
	SetPlasmaDensity(plasmaDensity);
}

//destructor, it will delete the data when the application closes
//there is no need to do anything here since there is no "new" command called
LocationData::~LocationData()
{
}

void LocationData::SetSunType(string theType)
{
	sunType = theType;
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
	//in the event that the sun type does not fall under the correct category, sunTypePercent should be default to 0
	//the default value of 0 should not happen since there will be relevant error checking before the creation of the new object but it should be placed as a safeguard
	float sunTypePercent = 0.0f;
	
	//resulting civ index from calculation
	float result;

	//change theType string into upper case
	transform(sunType.begin(), sunType.end(), sunType.begin(), ::toupper);

	for (int i = 0; i < 7; i++)
	{
		if (sunType == sunTypeByDefinition[i])
		{
			//assuming the definition of the corresponding int is correct, allocate the life probability by sun type here
			sunTypePercent = sunTypeProbability[i];
			break;
		}
	}		
	
	//based on the formula	
	result = ((sunTypePercent / 100) - ((aveParticleDensity + avePlasmaDensity) / 200)) * (noOfEarthLikePlanets + noOfEarthLikeMoons);
	cout << "Final Result: " <<  result << endl;

	return result;
}

bool LocationData::CheckSunTypeInput(string input)
{
	//change input string into upper case
	transform(input.begin(), input.end(), input.begin(), ::toupper);
	
	//run through the loop and see if the input is correct
	for (int i = 0; i < 7; i++)
	{
		//if it tallies, return true
		if (input == sunTypeByDefinition[i])
		{
			return true;
		}
	}
	//if it falls through, then return false
	return false;
}

string LocationData::ToString()
{
	string temp, sun, planet, moon, particle, density;
	
	//string stream the non-string variables
	stringstream planetToS, moonToS, particleDToS, plasmaDToS;
	
	//into their own respective variables, then convert them into string form
	planetToS << noOfEarthLikePlanets;
	moonToS << noOfEarthLikeMoons;
	particleDToS << aveParticleDensity;	
	plasmaDToS << avePlasmaDensity;
	
	//define the various strings and prepare them for displaying of data
	sun =      "Sun Type                   : " + sunType + '\n';
	planet =   "Num of Earth Like Planets  : " + planetToS.str() + '\n';
	moon =     "Num of Earth Like Moons    : " + moonToS.str() + '\n';
	particle = "Average Particle Density   : " + particleDToS.str() + '\n';
	density =  "Average Plasma Density     : " + plasmaDToS.str() + '\n';

	//chain the data together into a string that can be read by the console
	temp =  sun + planet + moon + particle + density;

	return temp;
}
