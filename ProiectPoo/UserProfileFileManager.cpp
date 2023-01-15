#include "UserProfileFileManager.h"
using namespace std;

vector<UserProfile>UserProfileFileManager::userProfiles;
vector<UserProfile>UserProfileFileManager::getUserProfiles()
{
	return userProfiles;
}
UserProfile UserProfileFileManager::getUserProfileByID(int userID)
{
	for (UserProfile profile : userProfiles)
	{
		if (profile.getUserID() == userID)
		{
			return profile;
		}
	}
	cout << "no valid match found";
	return UserProfile();
}
UserProfileFileManager::UserProfileFileManager()
{
	//userProfiles.clear();
	ifstream userFile(userProfileFilePath);
	string lineContents;
	while (!userFile.eof())
	{
		getline(userFile, lineContents);
		UserProfile up(lineContents);
		userProfiles.push_back(up);
	}
	userFile.close();
}
void UserProfileFileManager::ReadFile()
{
	for (UserProfile item : userProfiles)
	{
		cout << item;
	}
}