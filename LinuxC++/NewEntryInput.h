#include <algorithm>
#include "PointTwoD.h"

class NewEntryInput : PointTwoD
{
private:
	//========= Messages ==========//
	string newInputPrompts[7];
	string errorMessage;
	//========= Messages ==========//
	
	//========= Internal Variables ==========//
	int maxInputCount;
	int ignoreCharacterCount;
	//========= Internal Variables ==========//

	//========= Input States ==========//
	enum InputStates
	{
		STANDBY,
		DISPLAY_PROMPTS,
		CHECK_INPUT,
		INPUT_PASS,
		INPUT_FAIL,	
		END
	};
	InputStates currentState;
	int currentCount;		//to track the current state where the input is

	enum UpdateInts
	{
		CoordX,
		CoordY,
		EarthPlanets,
		EarthMoons,
	};

	enum UpdateFloats
	{
		ParticleDensity,
		PlasmaDensity
	};

	//========= Input States ==========//

	//========= Required Variables ==========//
	PointTwoD newData;
	LocationData newLD;	

	//the coordinates
	int tempX, tempY;

	//the new location data
	string newSunType;
	int numEarthLikePlanets;
	int numEarthLikeMoons;
	float particleDensity;
	float plasmaDensity;
	//========= Required Variables ==========//
	
public:
	//========= Constructor and Destructor ==========//
	NewEntryInput();
	~NewEntryInput();
	//========= Constructor and Destructor ==========//
	
	//========= Get Functions ==========//
	int GetTempX();
	int GetTempY();
	string GetNewSunType();
	int GetNumEarthLikePlanets();
	int GetNumEarthLikeMoons();
	float GetParticleDensity();
	float GetPlasmaDensity();
	//========= Get Functions ==========//


	//========= Input State Functions ==========//
	void DisplayPrompts();
	void CheckInput();
	void InputPass();
	void InputFail();
	//========= Input State Functions ==========//

	
	//========= Error Checking Functions ==========//
	void CheckFloatValue(UpdateFloats targetFloatVar);
	void CheckIntValue(UpdateInts targetIntVar);
	void CheckStringValue();
	//========= Error Checking Functions ==========//


	//========= Main Input Function ==========//
	void RegisterNewItem();
	//========= Main Input Function ==========//

	//========= Main Return Function ==========//
	PointTwoD ReturnPointTwoDData();	
	//========= Main Return Function ==========//
};
