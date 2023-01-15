#pragma once
#include <iostream>
using namespace std;
class UserProfile
{
private:
	int profileID;
	int userID;
	int rightClickCounter;
	int leftClickCounter;
	int capslockCounter;
	int shiftCounter;
	int leftSideCounter;
	int rightSideCounter;

public:
	int getProfileID() const;

	void setProfileID(int profileID);

	int getUserID() const;

	void setUserID(int userID);

	int getRightClickCounter() const;

	void setRightClickCounter(int rightClickCounter);

	int getLeftClickCounter() const;

	void setLeftClickCounter(int leftClickCounter);

	int getCapslockCounter() const;

	void setCapslockCounter(int capslockCounter);

	int getShiftCounter() const;

	void setShiftCounter(int shiftCounter);

	int getLeftSideCounter() const;

	void setLeftSideCounter(int leftSideCounter);

	int getRightSideCounter() const;

	void setRightSideCounter(int rightSideCounter);

	UserProfile();
	
	UserProfile(int profileID, int userID, int rightClickCounter, int leftClickCounter, int capslockCounter, int shiftCounter, int leftSideCounter, int rightSideCounter);
	
	UserProfile(UserProfile const& up);

	UserProfile(std::string userProfileInfo);
	
	UserProfile& operator=(UserProfile const& up);
	
	friend ostream& operator<<(ostream& afis, const UserProfile& up);
	
	friend istream& operator>>(istream& cit, UserProfile up);
	
	UserProfile operator+(const UserProfile& up);
	
	UserProfile operator++();
	
	UserProfile operator--();
	
	UserProfile operator-(const UserProfile& up);
	
	UserProfile operator+=(const UserProfile& up);
	
	static string stringCoverter(UserProfile up);
	
	bool CheckShiftKeyPreference() const;

	bool CheckLeftSidePreference() const;

	bool checkProfileSimilarity(const UserProfile& up);
};
