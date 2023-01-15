#pragma once
#include <string>
#include <iostream>
#include <sstream>
#include <algorithm>

class User
{
private:
	int userID;
	std::string username;
public:
	int getUserID() const;
	void setUserID(int userID);
	std::string getUsername() const;
	void setUsername(std::string username);
	User();
	User(int userID, std::string username);
	User(User const& u);
	User(std::string userInfo);
	User& operator=(User const& u);
	User& operator+=(const User& up);
	User& operator-=(const User& u);
	User& operator--();
	User& operator++();
	User operator()();
	friend std::ostream & operator<<(std::ostream & afis, const User & up);
	friend std::istream& operator>>(std::istream& cit, User);
	//void userDisplay()=0
};