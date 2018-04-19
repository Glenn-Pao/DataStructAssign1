#include <iostream>
#include <string>
#include <sstream>
using namespace std;

///summary
///
/// The location data class that is part of PointTwoD class
/// This is a container class that contains the statistics related to the star system (sun type, num earth planets, num earth moons, particle & plasma density)
/// It has a function to check if sunType input is valid [bool CheckSunTypeInput(string input)]
/// It calculates the civilization index of the system based on the star system components [CalculateCivIndex(string sunType, int noOfEarthLikePlanets, int noOfEarthLikeMoons, float aveParticleDensity, float avePlasmaDensity)]
///
///end summary

class LocationData
{
private:
	//========= Minimum Requirement Variables =========//
	string sunType;
	int noOfEarthLikePlanets;
	int noOfEarthLikeMoons;
	float aveParticleDensity;
	float avePlasmaDensity;
	//========= Minimum Requirement Variables =========//

	
	//===== Sun Type Life Probability Conversion =====//	
	//values defined here are always going to be the same thus it is static
	//the strings to compare to based on the sunType input
	
	
	//the corresponding integer values based on the sunType input
	static float sunTypeProbability[];
	//===== Sun Type Life Probability Conversion =====//

public:
	static string sunTypeByDefinition[];	
	//========= Constructor and Destructor ==========//
	LocationData();				//default constructor
	LocationData(string theType, int numEarthLikePlanets, int numEarthLikeMoons, float particleDensity, float plasmaDensity);		//overloaded constructor
	~LocationData();
	//========= Constructor and Destructor ==========//
	


	//============ Get and Set Functions ============//
	void SetSunType(string theType);
	string GetSunType();
	
	void SetNumEarthLikePlanets(int numEarthLikePlanets);
	int GetNumEarthLikePlanets();

	void SetNumEarthLikeMoons(int numEarthLikeMoons);
	int GetNumEarthLikeMoons();

	void SetParticleDensity(float particleDensity);
	float GetParticleDensity();

	void SetPlasmaDensity(float plasmaDensity);
	float GetPlasmaDensity();
	//============ Get and Set Functions ============//

	//============== Special Functions ==============//
	static float CalculateCivIndex(string sunType, int noOfEarthLikePlanets, int noOfEarthLikeMoons, float aveParticleDensity, float avePlasmaDensity);
	
	bool CheckSunTypeInput(string input);
	string ToString();
	//============== Special Functions ==============//

};
