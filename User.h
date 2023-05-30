#pragma once
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
#include "Admin.h"
#include "feedback.h"
#include "Univeristy.h"
#include "RegisteredUser.h"
#include "Favorite.h"
#include "RegisterUsers.h"


#pragma warning(disable : 4996)
using namespace std;

class User{

private:

	string username;
	string password;

public:

	void static SignUp() {

		string UserUsername, UserPassword;


		cout << "Welcome Future Member!" << endl;
		cout << "Please Enter Your Desired Username: " << endl;
		cin >> UserUsername;
		cout << "Please Enter Your Desired Password: " << endl;
		cin >> UserPassword;

		ofstream file("userdata.csv", ios::app);
		if (file.is_open()) {

			file << UserUsername << "," << UserPassword << "\n";
			file.close();
			cout << "The Sign Up is Successful, Welcome New Member!" << endl;

		}

		else {
			cerr << "The Sign Up Process is Unsuccessful, Please Try Again!" << endl;

		}

	}

	void static Login(University * uni, User * user, RegisteredUser * reguser, Admin * admin, Favorite * Favorite, Feedback * feedb) {

		string UsernameEntered, PasswordEntered;
		cout << "Welcome to the Login Menu! Please Enter Your Credentials!" << endl;
		cout << "Please Enter Your Username: ";
		cin >> UsernameEntered;
		cout << "Please Enter Your Password: ";
		cin >> PasswordEntered;

		ifstream file("userdata.csv");
		if (file.is_open()) {
			string line;
			while (getline(file, line)) {
				stringstream ss(line);
				string Username, Password;
				getline(ss, Username, ',');
				getline(ss, Password, ',');

				if (UsernameEntered == Username && PasswordEntered == Password) {
					file.close();
					return;
				}

			}
			file.close();
		}
        else if (UsernameEntered == "Admin" && PasswordEntered == "Password") {
            adminMenu(uni, user, reguser, admin, Favorite, feedb);
            file.close();
        }
		else {
			cerr << "Login Failed!Please Re-Enter the Credentials!" << endl;
		}

		return;

	}

};