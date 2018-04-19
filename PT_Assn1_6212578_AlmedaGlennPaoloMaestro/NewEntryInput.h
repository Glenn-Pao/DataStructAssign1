#include <algorithm>
#include "PointTwoD.h"

///summary
///
/// This class handles the first interaction of MissionPlan class - input new statistical data
/// This is to address the potential maintenance issue of MissionPlan class due to it's size
/// The system of this class is as follows:
/// 1) Display output asking for input from user
/// 2) Once the user enters his input, it will check the input depending on where the input stage is (starting with coordinate X and ends with plasma density)
/// 3) If input does not conform to the required type (eg. sunType input is invalid), the program will display an error output and request for new input
/// 4) If input is successful, it will move on to the next required data
/// 5) If there are no more new data to be captured, the class will construct a new PointTwoD object and LocationData object and return it to the MissionPlan class to store the new entry
///
///end summary

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
