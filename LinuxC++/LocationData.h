#include <iostream>
#include <string>
#include <sstream>
using namespace std;

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
