#include "UserProfile.h"
using namespace std;
#include <sstream>
#include <string>



	int UserProfile::getProfileID() const
	{
		return profileID;
	}
	void UserProfile::setProfileID(int profileID)
	{
		this->profileID = profileID;
	}

	int UserProfile::getUserID() const
	{
		return userID;
	}
	void UserProfile::setUserID(int userID)
	{
		this->userID = userID;
	}

	int UserProfile::getRightClickCounter() const
	{
		return rightClickCounter;
	}
	void UserProfile::setRightClickCounter(int rightClickCounter)
	{
		this->rightClickCounter = rightClickCounter;
	}

	int UserProfile::getLeftClickCounter() const
	{
		return leftClickCounter;
	}
	void UserProfile::setLeftClickCounter(int leftClickCounter)
	{
		this->leftClickCounter = leftClickCounter;
	}

	int UserProfile::getCapslockCounter() const
	{
		return capslockCounter;
	}
	void UserProfile::setCapslockCounter(int capslockCounter)
	{
		this->capslockCounter = capslockCounter;
	}

	int UserProfile::getShiftCounter() const
	{
		return shiftCounter;
	}
	void UserProfile::setShiftCounter(int shiftCounter)
	{
		this->shiftCounter = shiftCounter;
	}

	int UserProfile::getLeftSideCounter() const
	{
		return leftSideCounter;
	}
	void UserProfile::setLeftSideCounter(int leftSideCounter)
	{
		this->leftSideCounter = leftSideCounter;
	}

	int UserProfile::getRightSideCounter() const
	{
		return rightSideCounter;
	}
	void UserProfile::setRightSideCounter(int rightSideCounter)
	{
		this->rightSideCounter = rightSideCounter;
	}
	UserProfile::UserProfile(std::string userProfileInfo)
	{
		stringstream userProfileStream(userProfileInfo);
		userProfileStream >> profileID;
		userProfileStream >> userID;
		userProfileStream >> rightClickCounter;
		userProfileStream >> leftClickCounter;
		userProfileStream >> capslockCounter;
		userProfileStream >> shiftCounter;
		userProfileStream >> leftSideCounter;
		userProfileStream >> rightSideCounter;
	}
	UserProfile::UserProfile()
	{
		this->profileID = 1;
		this->userID = 2;
		this->rightClickCounter = 3;
		this->leftClickCounter = 4;
		this->capslockCounter = 5;
		this->shiftCounter = 6;
		this->leftSideCounter = 7;
		this->rightSideCounter = 8;
	}

	UserProfile::UserProfile(int profileID, int userID, int rightClickCounter, int leftClickCounter, int capslockCounter, int shiftCounter, int leftSideCounter, int rightSideCounter)
	{
		this->profileID = profileID;
		this->userID = userID;
		this->rightClickCounter = rightClickCounter;
		this->leftClickCounter = leftClickCounter;
		this->capslockCounter = capslockCounter;
		this->shiftCounter = shiftCounter;
		this->leftSideCounter = leftSideCounter;
		this->rightSideCounter = rightSideCounter;
	}

	UserProfile::UserProfile(UserProfile const& up)
	{
		if (this != &up)
		{
			this->profileID = up.profileID;
			this->userID = up.userID;
			this->rightClickCounter = up.rightClickCounter;
			this->leftClickCounter = up.leftClickCounter;
			this->capslockCounter = up.capslockCounter;
			this->shiftCounter = up.shiftCounter;
			this->leftSideCounter = up.leftSideCounter;
			this->rightSideCounter = up.rightSideCounter;
		}
		else
		{
			cout << "they are identical" << endl;
		}
	}
	UserProfile& UserProfile::operator=(UserProfile const& up)
	{
		if (this != &up)
		{
			this->profileID = up.profileID;
			this->userID = up.userID;
			this->rightClickCounter = up.rightClickCounter;
			this->leftClickCounter = up.leftClickCounter;
			this->capslockCounter = up.capslockCounter;
			this->shiftCounter = up.shiftCounter;
			this->leftSideCounter = up.leftSideCounter;
			this->rightSideCounter = up.rightSideCounter;
		}
		else
		{
			cout << "they are identical" << endl;
		}
		return *this;
	}
	std::ostream& operator<<(ostream& afis, const UserProfile& up) {
		afis << up.profileID << "," << up.userID << "," << up.rightClickCounter
			<< "," << up.leftClickCounter
			<< "," << up.capslockCounter
			<< "," << up.shiftCounter
			<< "," << up.leftSideCounter
			<< "," << up.rightSideCounter << endl;
		return afis;
	}

	std::istream& operator>>(istream& cit, UserProfile up) {
		cout << "profileID";
		cit >> up.profileID;
		cout << "userID";
		cit >> up.userID;
		cout << "rightClickCounter ";
		cit >> up.rightClickCounter;
		cout << "leftClickCounter";
		cit >> up.leftClickCounter;
		cout << "capslockCounter";
		cit >> up.capslockCounter;
		cout << "shiftCounter";
		cit >> up.shiftCounter;
		cout << "leftSideCounter";
		cit >> up.leftSideCounter;
		cout << "rightSideCounter";
		cit >> up.rightSideCounter;
		return cit;
	}

	UserProfile UserProfile::operator+(const UserProfile& up)
	{
		UserProfile aux(*this);
		aux.rightClickCounter = up.rightClickCounter + this->rightClickCounter;
		aux.leftClickCounter = up.leftClickCounter + this->leftClickCounter;
		aux.capslockCounter = up.capslockCounter + this->capslockCounter;
		aux.shiftCounter = up.shiftCounter + this->shiftCounter;
		aux.leftSideCounter = up.leftSideCounter + this->leftSideCounter;
		aux.rightSideCounter = up.rightSideCounter + this->rightSideCounter;
		return aux;
	}
	UserProfile UserProfile::operator++()
	{
		this->rightClickCounter++;
		this->leftClickCounter++;
		this->capslockCounter++;
		this->shiftCounter++;
		this->leftSideCounter++;
		this->rightSideCounter++;
		return *this;
	}

	UserProfile UserProfile::operator--()
	{
		if (this->rightClickCounter >= 0 || this->leftClickCounter >= 0 || this->capslockCounter >= 0 ||
			this->shiftCounter >= 0 || this->leftSideCounter >= 0 || this->rightSideCounter >= 0)
		{
			this->rightClickCounter--;
			this->leftClickCounter--;
			this->capslockCounter--;
			this->shiftCounter--;
			this->leftSideCounter--;
			this->rightSideCounter--;
			return *this;
		}
		else cout << "Invalid operation. The decrementation of one or more attributes results in a negative value" << endl;
	}

	UserProfile UserProfile::operator-(const UserProfile& up)
	{
		UserProfile aux(*this);
		if (aux.rightClickCounter >= 0 || aux.leftClickCounter >= 0 || aux.capslockCounter >= 0 ||
			aux.shiftCounter >= 0 || aux.leftSideCounter >= 0 || aux.rightSideCounter >= 0)
		{
			aux.rightClickCounter = up.rightClickCounter - this->rightClickCounter;
			aux.leftClickCounter = up.leftClickCounter - this->leftClickCounter;
			aux.capslockCounter = up.capslockCounter - this->capslockCounter;
			aux.shiftCounter = up.shiftCounter - this->shiftCounter;
			aux.leftSideCounter = up.leftSideCounter - this->leftSideCounter;
			aux.rightSideCounter = up.rightSideCounter - this->rightSideCounter;
			return aux;
		}
		else cout << "Invalid Operation, the subtraction between the attributes of the 2 classes results in at least one negative value" << endl;
	}

	UserProfile UserProfile::operator+=(const UserProfile& up)
	{
		if (this->userID = up.userID)
		{
			UserProfile aux(*this);
			aux.rightClickCounter = up.rightClickCounter + this->rightClickCounter;
			aux.leftClickCounter = up.leftClickCounter + this->leftClickCounter;
			aux.capslockCounter = up.capslockCounter + this->capslockCounter;
			aux.shiftCounter = up.shiftCounter + this->shiftCounter;
			aux.leftSideCounter = up.leftSideCounter + this->leftSideCounter;
			aux.rightSideCounter = up.rightSideCounter + this->rightSideCounter;
			return aux;
		}
		else cout << "Invalid Operation. Both UserProfiles must have the same userID in order for the addition to take place" << endl;
	}

	bool UserProfile::CheckShiftKeyPreference() const
	{
		if (this->getShiftCounter() > this->getCapslockCounter())
		{
			return true;
		}
		else return false;
	}
	bool UserProfile::CheckLeftSidePreference() const 
	{
		if (this->getLeftSideCounter() > this->getRightSideCounter())
		{
			return true;
		}
		else return false;
	}

	 bool UserProfile::checkProfileSimilarity(const UserProfile& up)
	 {
		 bool shiftkeyPreference = false;
		
		 if (this->leftClickCounter < up.leftClickCounter  || this->leftClickCounter > up.leftClickCounter )
		 {
			 return false;
		 }
		 if (this->rightClickCounter < up.rightClickCounter  || this->rightClickCounter > up.rightClickCounter)
		 {
			 return false;
		 }
		 if (this->CheckLeftSidePreference()!= up.CheckLeftSidePreference())
		 {
			 return false;
		 }
		 if (this->CheckShiftKeyPreference()!= up.CheckShiftKeyPreference())
		 {
			 return false;
		 }
		 return true;
	 }

