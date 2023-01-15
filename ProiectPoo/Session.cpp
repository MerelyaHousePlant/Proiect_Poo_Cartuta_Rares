#include "Session.h"
#include <conio.h>
#include <stdio.h>
#include <chrono>
#include <windows.h>
using namespace std;
using namespace std::chrono;

	int Session::getSessionID()
	{
		return sessionID;
	}

	void Session::setSessionID(int sessionID)
	{
		this->sessionID = sessionID;
	}

	int Session::getProfileID()
	{
		return profileID;
	}

	void Session::setProfileID(int profileID)
	{
		this->profileID = profileID;
	}

	int Session::getSessionDuration()
	{
		return sessionDuration;
	}

	void Session::setSessionDuration(int sessionDuration)
	{
		this->sessionDuration = sessionDuration;
	}

	Session::Session()
	{
		this->sessionID = 0;
		this->profileID = 1;
		this->sessionDuration = 20;
	}
	Session::Session(int sessionID, int profileID, int sessionDuration)
	{
		this->sessionID = sessionID;
		this->profileID = profileID;
		this->sessionDuration = sessionDuration;
	}
	Session::Session(Session const& s)
	{
		this->sessionID = s.sessionID;
		this->profileID = s.profileID;
		this->sessionDuration = s.sessionDuration;
	}
	Session::Session(int sessionDuration)
	{
		this->sessionID = 0;
		this->profileID = 1;
		this->sessionDuration = sessionDuration;
	}

	Session& Session::operator=(Session const& s)
	{
		if (this != &s)
		{
			this->sessionID = s.sessionID;
			this->profileID = s.profileID;
			this->sessionDuration = s.sessionDuration;
		}
		return *this;
	}

	std::ostream& operator<<(ostream& afis, const Session& u) 
	{
		afis << u.sessionID << "," << u.profileID << "," << u.sessionDuration << endl;
		return afis;
	}

	std::istream& operator>>(istream& cit, Session u) 
	{
		//cout << "sessionID";
		//cit >> u.sessionID;
		//cout << "profileID:";
		//cit >> u.profileID;
		cout << "sessionDuration";
		cit >> u.sessionDuration;
		return cit;
	}

	Session Session::operator+(const Session& s)
	{
		Session aux(*this);
		//Session s1 =s;
		aux = this->sessionDuration + s.sessionDuration;
		return aux;
	}
	Session Session::operator-(const Session& s)
	{
		if (this->sessionDuration > s.sessionDuration)
		{
			Session s1 = s;
			s1.sessionDuration = this->sessionDuration - s.sessionDuration;
			cout << "noua valoare a atributului sessionDuration este: " << s1.getSessionDuration();
			return s1;
		}
		else cout << "valoarea atributului nu putut fi schimbata deoarece ar fi rezultat intr-un numar negativ";
		cout << endl;
		return *this;
	}
	Session Session::operator*(const Session& s)
	{
		Session s1 = s;
		s1.sessionDuration = this->sessionDuration * s.sessionDuration;
		cout << "noua valoare a atributului sessionDuration este: " << s1.getSessionDuration() << endl;
		return s1;
	}
	Session Session::operator/(const Session& s)
	{
		if (this->sessionDuration != 0 && s.sessionDuration != 0)
		{
			Session s1 = s;
			s1.sessionDuration = this->sessionDuration / s.sessionDuration;
			cout << "noua valoare a atributului sessionDuration este: " << s1.getSessionDuration() << endl;
		}
		else cout << "valoarea atributului nu a putut fi schimbate deoarece cel putin unul dintre numere e 0";
		return *this;
	}
	Session Session::operator%(const Session& s)
	{
		
		Session s1 = s;
		s1.sessionDuration = this->sessionDuration % s.sessionDuration;
		cout << "noua valoare a atributului sessionDuration este: " << s1.getSessionDuration() << endl;
		return s1;
	}

	int Session::userSession()
	{
		bool capsLockPressed = false;
		bool leftClickPressed = false;
		bool rightClickPressed = false;
		bool leftShiftPressed = false;
		bool rightShiftPressed = false;
		bool leftCtrlPressed = false;
		bool rightCtrlPressed = false;
		UserProfile up(getSessionID(), 0, 0, 0, 0, 0, 0, 0);
		if (this->getSessionID() == up.getProfileID())
		{
			auto old = steady_clock::now();
			char ch1 = 'l';
			while (1)
			{
				if (std::chrono::steady_clock::now() - old > std::chrono::seconds(sessionDuration))
				{
					break;
				}
				if (GetAsyncKeyState(VK_LSHIFT))
				{
					if (!leftShiftPressed)
					{
						cout << "Left Shift key Pressed";
						up.setLeftSideCounter(up.getLeftSideCounter() + 1);
						up.setShiftCounter(up.getShiftCounter() + 1);
						cout << up;
						leftShiftPressed = true;
					}
				}
				else
				{
					leftShiftPressed = false;
				}
				if (GetAsyncKeyState(VK_RSHIFT))
				{
					if (!rightShiftPressed)
					{
						cout << "Right Shift key Pressed";
						up.setRightSideCounter(up.getRightSideCounter() + 1);
						up.setShiftCounter(up.getShiftCounter() + 1);
						cout << up;
						rightShiftPressed = true;
					}
				}
				else
				{
					rightShiftPressed = false;
				}
				if (GetAsyncKeyState(VK_LCONTROL))
				{
					if (!leftCtrlPressed)
					{
						cout << "Left Control key Pressed";
						up.setLeftSideCounter(up.getLeftSideCounter() + 1);
						cout << up;
						leftCtrlPressed = true;
					}
				}
				else
				{
					leftCtrlPressed = false;
				}
				if (GetAsyncKeyState(VK_RCONTROL))
				{
					if (!rightCtrlPressed)
					{
						cout << "Right Control key Pressed";
						up.setRightSideCounter(up.getRightSideCounter() + 1);
						cout << up;
						rightCtrlPressed = true;
					}
				}
				else
				{
					rightCtrlPressed = false;
				}

				if (GetKeyState(0x14) & 0x8000)
				{
					if (!capsLockPressed)
					{
						cout << "CapsLock key Pressed";
						up.setCapslockCounter(up.getCapslockCounter() + 1);
						cout << up;
						capsLockPressed = true;
					}
				}
				else
				{
					capsLockPressed = false;
				}

				if (GetAsyncKeyState(0x01))
				{
					if (!leftClickPressed)
					{
						cout << "Left Click Pressed";
						up.setLeftClickCounter(up.getLeftClickCounter() + 1);
						cout << up;
						leftClickPressed = true;
					}
				}
				else
				{
					leftClickPressed = false;
				}
				if (GetAsyncKeyState(0x02))
				{
					if (!rightClickPressed)
					{
						cout << "Right Click Pressed";
						up.setRightClickCounter(up.getRightClickCounter() + 1);
						cout << up;
						rightClickPressed = true;
					}
				}
				else
				{
					rightClickPressed = false;
				}
			}
			UserProfileFileManager upfm;
			cout << "The file contains the following data:" << endl;
			upfm.ReadFile();
			auto entries = UserProfileFileManager::getUserProfiles();
			for (UserProfile entry : entries)
			{
				//if (entry.getProfileID() == up.getProfileID())
				//{
				if (up.checkProfileSimilarity(entry) == true)
				{
					cout << endl;
					cout << "The Entry: " << entry << "is equal to" << "UP: " << up << " Welcome back";
					cout << endl;
					up.setUserID(entry.getUserID());
					return up.getUserID();
				}
				else
				{
					cout << endl << "User not found" << endl;
					return up.getUserID();
				}
				//}
			}
		}
		else return 0;
	}
