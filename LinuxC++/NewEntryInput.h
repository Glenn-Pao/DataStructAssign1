#include <algorithm>
#include "PointTwoD.h"

class NewEntryInput
{
private:
	//========= Messages ==========//
	string newInputPrompts[7];
	string errorMessage;
	//========= Messages ==========//
	
	//========= Internal Variables ==========//
	int maxInputCount;
	int ignoreCharacterCount;

	int tempX, tempY;
	int numEarthLikePlanets, numEarthLikeMoons;
	string newSunType;
	float particleDensity, plasmaDensity;
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
	//========= Required Variables ==========//
	
public:
	//========= Constructor and Destructor ==========//
	NewEntryInput();
	~NewEntryInput();
	//========= Constructor and Destructor ==========//
	
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
