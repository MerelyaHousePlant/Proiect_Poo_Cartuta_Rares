#pragma once
#include "UserProfileFileManager.h"
class Session
{
private:
	int sessionID;
	int profileID;
	int sessionDuration;

public:
	int getSessionID();
	void setSessionID(int sessionID);
	int getProfileID();
	void setProfileID(int profileID);
	int getSessionDuration();
	void setSessionDuration(int sessionID);
	Session();
	Session(int sessionID, int profileID, int sessionDuration);
	Session(Session const& s);
	Session(int sessionDuration);
	Session& operator=(Session const& s);
	friend std::ostream& operator<<(std::ostream& afis, const Session& u);
	friend std::istream& operator>>(std::istream& cit, Session u);
	int userSession();
	Session operator+(const Session& s);
	Session operator-(const Session& s);
	Session operator*(const Session& s);
	Session operator/(const Session& s);
	Session operator%(const Session& s);
};