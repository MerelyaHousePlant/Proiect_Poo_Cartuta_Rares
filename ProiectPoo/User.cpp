
#include "User.h"
using namespace std;


	int User::getUserID() const
	{
		return userID;
	}
	void User::setUserID(int userID)
	{
		this->userID = userID;
	}

	string User::getUsername() const
	{
		return username;
	}
	void User::setUsername(string username)
	{
		this->username = username;
	}

	User::User()
	{
		userID = 0;
		username = "";
	}
	User::User(int userID, string username)
	{
		this->userID = userID;
		this->username = username;
	}
	User::User(User const& u)
	{
		this->userID = u.userID;
		this->username = u.username;
	}
	User::User(string userInfo)
	{
		stringstream userStream(userInfo);
		userStream >> userID;
		userStream >> username;
	}
	
	User& User::operator=(User const& u)
	{
		if (this != &u)
		{
			this->userID = u.userID;
			this->username = u.username;
		}
	return *this;
	}

	std::ostream& operator<<(ostream& afis, const User& u) {
		afis << u.getUserID() << "," << u.getUsername() << endl;
		return afis;
	}

	std::istream & operator>>(istream & cit, User u) {
		cout << "userID";
		cit >> u.userID;
		cout << "username:";
		cit >> u.username;
		return cit;
	}

	User& User::operator+=(const User& up)
	{
			this->username += up.username;
			return *this;
	}

	User& User::operator-=(const User& u)
	{
		string newUsername = this->username;
		int minLength = min(this->username.size(), u.username.size());
		for (int i = 0; i < minLength; i++)
		{
			if (u.username.find(this->username[i]) != string::npos)
			{
				newUsername.erase(i--, 1);
				minLength--;
			}
		}
		this->username = newUsername;
		return *this;
	}

	User& User::operator--()
	{
		if (this->username.size() > 2)
		{
			this->username.erase(0, 1);
			this->username.pop_back();
		}
		return *this;
	}

	User& User::operator++()
	{
		if (!this->username.empty())
		{
			std::string firstHalf;
			if (username.size() % 2 == 0) {
				firstHalf = username.substr(0, username.size() / 2);
			}
			else {
				firstHalf = username.substr(0, (username.size() / 2) - 1);
			}
			this->username += firstHalf;
		}
		return *this;
	}

	User User::operator()()
	{
		std::string firstHalf;
		std::string secondHalf;
		if (username.size() % 2 == 0) {
			firstHalf = username.substr(0, username.size() / 2);
			secondHalf = username.substr(username.size() / 2);
		}
		else {
			firstHalf = username.substr(0, (username.size() / 2) + 1);
			secondHalf = username.substr((username.size() / 2) + 1);
		}
		std::reverse(firstHalf.begin(), firstHalf.end());
		return User(firstHalf + secondHalf);
	}
