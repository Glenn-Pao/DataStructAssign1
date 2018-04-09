#include "globalRequirements.h"
#include "LocationData.h"

class PointTwoD
{
	private:
		int x, y;						//the coordinates
		float civIndex;					//civ index, higher the number, the more likely there is life here
		LocationData locationData;	
		
	public:
		PointTwoD();					//default constructor
		PointTwoD(int x, int y, LocationData theData);	//overloaded constructor
		~PointTwoD();

		//------------------- get and set functions ------------------------//
		void SetCoordinates(int x, int y);

		void SetXCoordinate(int x);
		int GetXCoordinate();

		void SetYCoordinate(int y);
		int GetYCoordinate();

		void SetLocationData(LocationData theData);
		LocationData GetLocationData();

		void SetCivIndex(float civIndex);
		float GetCivIndex();
		//------------------- get and set functions ------------------------//

};