#include "UserMenu.h"
using namespace std;

void main()
{
	/*User u1(40, "Anastasia");
	User u2(30, "Ana");
	 u2 += u1;
	 cout << u2;*/
	if (UserMenu::Authenticate() == true)
	{
		while (1)
		{
			int userKey;
			UserProfileFileManager upfm;
			UserFileManager ufm;
			cout << "Ai acces la urmatoarele functii: " << endl;
			cout << "1.Calculator: " << endl;
			cout << "2.Vizioneaza toate tipurile de profil existente " << endl;
			cout << "3.Vizioneaza toti utilizatorii existenti " << endl;
			cout << "4.Vizioneaza un tip de profil pe baza id-ului sau " << endl;
			cout << "5.Vizioneaza un utilizator pe baza id-ului sau " << endl;
			cout << "6.Iesi din Program " << endl;
			cin >> userKey;
			if (cin.fail())
			{
				cout << "Introduceti unul dintre numerele de mai sus" << endl;
			}
			cin.clear();
			switch (userKey)
			{
			case 1: 
			{
				UserMenu::CalculatorMenu();
				cin.clear();
				break;
			}
			case 2:
			{
				upfm.ReadFile();
				cout << endl;
				cin.clear();
				break;
			}
			case 3:
			{
				ufm.ReadFile();
				cout << endl;
				cin.clear();
				break;
			}
			case 4:
			{
				int profileID;
				cout << "Introduceti id-ul tipului de profil pe care doriti sa il gasiti: " << endl;
				cin >> profileID;
				cout<<upfm.getUserProfileByID(profileID);
				cin.clear();
				break;
			}
			case 5:
			{
				int userID;
				cout << "Introduceti id-ul tipului de profil pe care doriti sa il gasiti: " << endl;
				cin >> userID;
				cout<<ufm.getUserByID(userID);
				cin.clear();
				break;
			}
			case 6:
			{
				exit(0);
			}
			default:
			{
				cout << "Nu ati introdus un numar valid, incercati din nou. ";
			}
			}
		}
	}
	/*
	//Session s1;
	//s1.usrSession();
	//UserFileManager test;
	//test.ReadFile();
	//cout<<test.getUserByID(2);
	*/
}
