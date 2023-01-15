#include <iostream>
#include "UserFileManager.h"
using namespace std;

vector<User>UserFileManager::users;
UserFileManager::UserFileManager()
{
	ifstream userFile(userFilePath);
	string lineContents;
	while (!userFile.eof())
	{
		getline(userFile, lineContents);
		User u(lineContents);
		users.push_back(u);
	}
	userFile.close();
}
vector<User>UserFileManager::getUsers()
{
	return users;
}
User UserFileManager::getUserByID(int userID)
{
	for (User user : users)
	{
		if (user.getUserID() == userID)
		{
			return user;
		}
	}
	cout << "no valid match found";
	return User();
}
void UserFileManager::ReadFile()
{
	//vector<User> users;
	for (User item : users)
	{
		cout << item.getUserID() << " and " << item.getUsername() << endl;
	}
}

