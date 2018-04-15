#include "NewEntryInput.h"
NewEntryInput::NewEntryInput()
{
	//initialize the error output
	errorMessage = "Incorrect input detected. Please try again.";
	
	//initialize state
	currentState = DISPLAY_PROMPTS;
	
	//initialize current count
	currentCount = 0;

	//initialize max input count to 6
	//the input required are: x, y, sunType, numEarthPlanets, numEarthMoons, particleDensity and plasmaDensity
	//this is to reduce the number of magic numbers present in the program;
	maxInputCount = 6;

	//initialize the ignore character count
	//program will ignore this number of characters when using cin.ignore(ignoreCharacterCount);
	ignoreCharacterCount = 256;

	//initialize the prompt outputs
	for(int i = 0; i <= maxInputCount; i++)
	{
		switch(i)
		{
		case 0:
			newInputPrompts[i] = "Input the X-Coordinate                    : ";
			break;
		case 1:
			newInputPrompts[i] = "Input the Y-Coordinate                    : ";
			break;
		case 2:
			newInputPrompts[i] = "Input the Sun Type                        : ";
			break;
		case 3:
			newInputPrompts[i] = "Input the Number of Earth-Like Planets    : ";
			break;
		case 4:
			newInputPrompts[i] = "Input the Number of Earth-Like Moons      : ";
			break;
		case 5:
			newInputPrompts[i] = "Input the Particle Density of Solar System: ";
			break;
		case 6:
			newInputPrompts[i] = "Input the Particle Density of Solar System: ";
			break;
		}
	}
}

NewEntryInput::~NewEntryInput()
{
}

void NewEntryInput::DisplayPrompts()
{	
	//print out the current prompt
	cout << newInputPrompts[currentCount];
	
	//once display is done, standby to take in user input
	currentState = CHECK_INPUT;
}

void NewEntryInput::CheckInput()
{
	//based on the current state of the input retrieval, do the corresponding error checking to ensure integrity of the data
	switch(currentCount)
	{
	case 0:	//coordinate X
		CheckIntValue(CoordX);
		break;
	case 1:	//coordinate Y
		CheckIntValue(CoordY);
		break;
	case 2:	//sun type
		CheckStringValue();
		break;
	case 3:	//number of earth like planets
		CheckIntValue(EarthPlanets);
		break;
	case 4:	//number of earth like moons
		CheckIntValue(EarthMoons);
		break;
	case 5:	//particle density
		CheckFloatValue(PlasmaDensity);
		break;
	case 6:	//plasma density
		CheckFloatValue(ParticleDensity);
		break;
	}
}

void NewEntryInput::InputPass()
{	
	//clear the cin
	cin.clear();

	//ignore characters defined by ignoreCharacterCount until newline
	cin.ignore(ignoreCharacterCount, '\n');

	//check if the operation has ended
	if(currentCount < maxInputCount)
	{
		//increment the count to allow user to provide input
		currentCount++;
		currentState = DISPLAY_PROMPTS;	
	}
	else
	{
		//break out of the loop and end this process
		currentState = END;
	}
}
void NewEntryInput::InputFail()
{	
	//display error message
	cout << errorMessage << endl;
	
	//clear the cin
	cin.clear();

	//ignore characters defined by ignoreCharacterCount until newline
	cin.ignore(ignoreCharacterCount, '\n');

	//return to display prompts state
	currentState = DISPLAY_PROMPTS;	
}

void NewEntryInput::CheckFloatValue(UpdateFloats targetFloatVar)
{	
	//set up temporary variable
	float tempValue;
	cin >> tempValue;

	//send to fail state if input is a bad input
	if(cin.fail())
	{
		//cout << "fail" << endl;
		currentState = INPUT_FAIL;
	}
	//send to pass state if it qualifies as a good input
	else
	{
		//cout << "pass" << endl;
		//update the entry here
		switch(targetFloatVar)
		{
		case PlasmaDensity:
			plasmaDensity = tempValue;
			//cout << plasmaDensity << endl;
			break;
		case ParticleDensity:
			particleDensity = tempValue;
			//cout << particleDensity << endl;
			break;
		}
		currentState = INPUT_PASS;
	}
}
void NewEntryInput::CheckIntValue(UpdateInts targetIntVar)
{
	//set up temporary variable
	float tempValue;
	cin >> tempValue;
	
	//send to fail state if input is a bad input
	if(cin.fail())
	{
		//cout << "fail" << endl;
		currentState = INPUT_FAIL;
	}
	//send to pass state if it qualifies as a good input
	else
	{
		//cout << "pass" << endl;
		//update the entry here
		switch(targetIntVar)
		{
		case CoordX:
			tempX = tempValue;
			//cout << tempX << endl;
			break;
		case CoordY:
			tempY = tempValue;
			//cout << tempY << endl;
			break;
		case EarthPlanets:
			numEarthLikePlanets = tempValue;
			//cout << numEarthLikePlanets << endl;
			break;
		case EarthMoons:
			numEarthLikeMoons = tempValue;
			//cout << numEarthLikeMoons << endl;
			break;
		}
		
		currentState = INPUT_PASS;
	}
}

void NewEntryInput::CheckStringValue()
{
	//discard newline
	//get the entire line
	getline(cin, newSunType);

	//do an error check to see if the input is valid
	if(newData.GetLocationData().CheckSunTypeInput(newSunType))
	{
		//if it returns as positive, send to pass state
		//cout << "pass" << endl;
		
		currentState = INPUT_PASS;
	}
	else
	{
		//if it returns as negative, send to fail state
		//cout << "fail" << endl;
		currentState = INPUT_FAIL;
	}
	
}

void NewEntryInput::RegisterNewItem()
{
	//this is the main function that governs the program's behavior while user is inputting new data into the system
	while(currentState != END)
	{
		switch(currentState)
		{
		case STANDBY:			//does nothing
			break;
		case DISPLAY_PROMPTS:		//display new input prompt
			DisplayPrompts();
			break;
		case CHECK_INPUT:		//checks for user input
			CheckInput();
			break;
		case INPUT_PASS:		//verified that user input is successful
			InputPass();
			break;
		case INPUT_FAIL:		//verified that user input is unsuccessful
			InputFail();
			break;
		}
	}


	//at the end of it, construct an object
	newData = PointTwoD(tempX, tempY, newSunType, numEarthLikePlanets, numEarthLikeMoons, particleDensity, plasmaDensity);
	
	//test that the data input is correct
 	//cout << newData.ToString() << endl;
}

PointTwoD NewEntryInput::ReturnPointTwoDData()
{
	//once the new data has been assembled, use this function to return the newly constructed data
	return newData;
}

