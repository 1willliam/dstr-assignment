#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <ctime>
#include <iomanip>
#include <chrono>
#include "SingleLinkedList.h"
#include "DoubleLinkedList.h"
#include "BinarySearch.h"
#include "InterpolationSearch.h"
#include "MergeSort.h"
#include "QuickSort.h"
#include "User.h"
#include "Admin.h"
#include "feedback.h"
#include "Univeristy.h"
#include "RegisteredUser.h"
#include "Favorite.h"

#pragma once
using namespace std;

void userMainMenu(University * uni, User * user, RegisteredUser * reguser, Admin * admin, Favorite * fav, Feedback * feedb) {
		int Menu;
		cout << "\n Hello New User, Welcome to the University Ranking System!" << endl;
		cout << "\n\n\n\n Please Select the Menu from the Main Menu ;) " << endl;
		cout << "\n ===========================================================" << endl;
		cout << "\n 1. Sign Up" << endl;
		cout << "\n 2. Log In" << endl;
		cout << "\n 3. View Universities" << endl;
		cout << "\n 4. Search University" << endl;
		cout << "\n 5. Sort Universities" << endl;
		cout << "\n 6. Exit" << endl;
		cout << "\n Please Input your Selection (1-5):  " << endl;
		cin >> Menu;


		switch(Menu) {
			case 1:
				void SignUp();
				break;

			case 2:
				void Login();
				break;

			case 3:
				uni->display_univinfo();
				break;

			case 4:
				void SearchUniversity();
				break;

			case 5:
				void SortUniversities();
				break;

			case 6:
				cout << "Thank You for Visiting the Universities Ranking System, Have a Nice Day!" << endl;
				return;

			default:
				cout << "The Selection is Invalid, Please Select other Options" << endl;

		}

	};

int main()
{
    string rank, institution, locationCode, location, arScore, arRank, erScore, erRank, fsrScore, fsrRank, cpfScore, 
            cpfRank, ifrScore, ifrRank, isrScore, isrRank, irnScore, irnRank, gerScore, gerRank, scoreScaled;
    string username, password;

    University * uni = new University();
    User * user = new User();
    RegisteredUser * reguser = new RegisteredUser();
    Admin * admin = new Admin();
    Favorite * fav = new Favorite();
    Feedback * feedb = new Feedback();
    fstream file;
    file.open("2023 QS World University Rankings.csv", ios::in);
    if (file.is_open()) 
    {
            while (file.good())
        {
            getline(file, rank, ',');
            getline(file, institution, ',');
            getline(file, locationCode, ',');
            getline(file, location, ',');
            getline(file, arScore, ',');
            getline(file, arRank, ',');
            getline(file, erScore, ',');
            getline(file, erRank, ',');
            getline(file, fsrScore, ',');
            getline(file, fsrRank, ',');
            getline(file, cpfScore, ',');
            getline(file, cpfRank, ',');
            getline(file, ifrScore, ',');
            getline(file, ifrRank, ',');
            getline(file, isrScore, ',');
            getline(file, isrRank, ',');
            getline(file, irnScore,',');
            getline(file, irnRank, ',');
            getline(file, gerScore, ',');
            getline(file, gerRank, ',');
            getline(file, scoreScaled);
            // if (rank == "Rank")
            // {
            //     continue;
            // }
            // else if (rank == "")
            // {
            //     break;
            // }
            uni-> InsertToEndList(rank, institution, locationCode, location, arScore, arRank, erScore, erRank, fsrScore, 
            fsrRank, cpfScore, cpfRank, ifrScore, ifrRank, isrScore, isrRank, irnScore, irnRank, gerScore, gerRank, scoreScaled);

        }
    }

    userMainMenu(uni, user, reguser, admin, fav, feedb);

    // cout << "2023 QS WORLD UNIVERSITY RANKINGS ARE AS SHOWN BELOW: \n\n" << endl << string(50, '=') << endl;
    // void display_univinfo();
    // cout << endl;
    // return 0;

}