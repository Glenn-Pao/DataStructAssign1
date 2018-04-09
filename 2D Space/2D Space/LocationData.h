#include "globalRequirements.h"

class LocationData
{
private:
	string sunType;
	int noOfEarthLikePlanets;
	int noOfEarthLikeMoons;
	float aveParticleDensity;
	float avePlasmaDensity;

	int sunTypeValue;

	///the strings to compare with the sun type definitions
	static string sunTypeByDefinition[];

	//using the strings defined, convert them into integer probabilities using this array
	static int sunTypeProbability[];		

public:
	LocationData();
	LocationData(string theType, int numEarthLikePlanets, int numEarthLikeMoons, float particleDensity, float plasmaDensity);
	~LocationData();

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

	//------------------- special functions ------------------------//
	static float CalculateCivIndex(string sunType, int noOfEarthLikePlanets, int noOfEarthLikeMoons, float aveParticleDensity, float avePlasmaDensity);
};

