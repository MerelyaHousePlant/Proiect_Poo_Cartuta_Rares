#pragma once
#include "UserProfile.h"
#include "FileManager.h"
using namespace std;
class UserProfileFileManager : public FileManager
{
private:
	const std::string userProfileFilePath = "sesiuni.txt";
	static std::vector<UserProfile> userProfiles;
public:
	static vector<UserProfile> getUserProfiles();
	UserProfile getUserProfileByID(int userID);
	UserProfileFileManager();
	void ReadFile();
	//void WriteFile();
};