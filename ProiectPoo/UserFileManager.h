#pragma once
#include "User.h"
#include "FileManager.h"

class UserFileManager : public FileManager
{
private:
const std::string userFilePath = "userdata.txt";
static std::vector<User> users;
public:
	static std::vector<User> getUsers();
	UserFileManager();
	User getUserByID(int userID);
	void ReadFile();
	//void WriteFile();
};

