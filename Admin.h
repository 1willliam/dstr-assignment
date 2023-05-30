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
#include "feedback.h"
#include "RegisteredUser.h"
#include "Favorite.h"

#pragma warning(disable : 4996)
#pragma once
using namespace std;

class Admin {
public:
    

   struct UserNode {
    string name;
    string password;
};
void adminMenu(University * uni, User * user, RegisteredUser * reguser, Admin * admin, Favorite * fav, Feedback * feedb) {
        int choice;
        int userCount = 0;
        int userFavCount = 0;

        do {
            std::cout << "University Ranking System\n" << std::endl;
            std::cout << "What would you like to do? \n\n" << std::endl;
            std::cout << "==========================================\n" << std::endl;
            std::cout << "1. View user details" << std::endl;
            std::cout << "2. View users feedback" << std::endl;
            std::cout << "3. View customers favourite universities" << std::endl;
            std::cout << "4. Generate Report" << std::endl;
            std::cout << "5. Logout\n" << std::endl;
            std::cout << "==========================================\n" << std::endl;
            std::cout << "Please select an option (1-4): " << std::endl;
            std::cin >> choice;

            switch (choice) {
                case 1: //view user details
                    int sortchoice;

                    std::cout << "1. Merge Sort\n" << std::endl;
                    std::cout << "2. Quick Sort\n\n" << std::endl;
                    std::cout << "How would you like to sort the user details?: " << std::endl;
                    std::cin >> sortchoice;

                    switch (sortchoice) {
                        case 1:
                            admin->displayMergeSortedUserData();

                            

                        case 2:
                            admin->displayQuickSortedUserData();

                        default:
                            std::cout << "Invalid input!" << std::endl;
                            adminMenu(uni, user, reguser, admin, fav, feedb);
                    }

                    int userchoice;

                    std::cout << "1. Change password\n" << std::endl;
                    std::cout << "2. Back\n\n" << std::endl;
                    std::cout << "What would you like to do next?" << std::endl;
                    std::cin >> userchoice;

                    switch (sortchoice){
                        case 1:
                            void updatePassword();
                        
                        case 2:
                            adminMenu(uni, user, reguser, admin, fav, feedb);

                        case 3:
                            std::cout << "Invalid input!" << std::endl;
                            adminMenu(uni, user, reguser, admin, fav, feedb);
                    }

                    
                case 2: //view user feedback
                    int sortchoice2;

                    std::cout << "1. Merge Sort\n" << std::endl;
                    std::cout << "2. Quick Sort\n\n" << std::endl;
                    std::cout << "How would you like to sort the user feedback?: " << std::endl;
                    std::cin >> sortchoice2;

                    switch(sortchoice2){
                        case 1:
                            admin->displayMergeSortedUserFeedback();
                        
                        case 2: 
                            admin->displayQuickSortedUserFeedback();
                        default:
                            std::cout << "Invalid input!" << std::endl;
                            adminMenu(uni, user, reguser, admin, fav, feedb);
                    }
                    break;
                case 3: //view customers favorite unis
                    int sortchoice3;

                    std::cout << "1. Merge Sort\n" << std::endl;
                    std::cout << "2. Quick Sort\n\n" << std::endl;
                    std::cout << "How would you like to sort the user's favorite universities?: " << std::endl;
                    std::cin >> sortchoice3;

                    switch(sortchoice3){
                        case 1:
                            admin->displayMergeSortedUserFav();
                        
                        case 2: 
                            admin->displayQuickSortedUserFav();
                        default:
                            std::cout << "Invalid input!" << std::endl;
                            adminMenu(uni, user, reguser, admin, fav, feedb);
                    }
                    break;
                case 4:
                    //
                    break;
                case 5:
                    void UserMainMenu();
                    break;
                default:
                    std::cout << "Invalid choice, please try again" << std::endl;
                    break;
            }
        } while (choice != 1 && choice != 2 && choice != 3 && choice != 4);
    }
// void updatePassword(const string& filename) {
//     DoubleLinkedList<UserNode> userNodeDLL;
//     ifstream file(filename);
    
//     if (!file) {
//         cout << "Failed to open file: " << filename << endl;
//         return;
//     }
    
//     UserNode userNode;
//     string line;
    
//     // Read and parse the file
//     while (getline(file, line)) {
//         size_t pos = line.find(", ");
//         if (pos != string::npos) {
//             userNode.name = line.substr(0, pos);
//             userNode.password = line.substr(pos + 2);
//             userNodeDLL.push_back(userNode);
//         }
//     }
    
//     file.close();
    
//     // Ask for the name of the user to update
//     string nameToUpdate;
//     cout << "Enter the name of the user to update: ";
//     getline(cin, nameToUpdate);
    
//     // Find the user to update
//     bool found = false;
//     for (User& u : users) {
//         if (u.name == nameToUpdate) {
//             found = true;
//             cout << "Enter the new password for " << u.name << ": ";
//             getline(cin, u.password);
//             break;
//         }
//     }
    
//     if (!found) {
//         cout << "User not found." << endl;
//         return;
//     }
    
//     // Write the updated users to the file
//     ofstream outFile(filename);
//     if (!outFile) {
//         cout << "Failed to open file: " << filename << endl;
//         return;
//     }
    
//     for (const User& u : users) {
//         outFile << u.name << ", " << u.password << endl;
//     }
    
//     outFile.close();
    
//     cout << "File updated successfully." << endl;
// }

// void changeUserPassword(){
//     const string filename = "userdata.txt";
//     updatePassword(filename);
// }

void displayMergeSortedUserData(){
    const string filename = "userdata.csv";
    readCSVMergeSort(filename);
}

void displayQuickSortedUserData(){
    string filename = "userdata.csv";
    // readCSVQuickSort(filename);
}

void displayMergeSortedUserFeedback(){
    const string filename = "feedback.csv";
    readCSVMergeSort(filename);
}

void displayQuickSortedUserFeedback(){
    const string filename = "feedback.csv";
    // readCSVQuickSort(filename);
}

void displayMergeSortedUserFav(){
    const string filename = "favorite.csv";
    // readCSVMergeSort(filename);
}

void displayQuickSortedUserFav(){
    const string filename = "favorite.csv";
    // readCSVQuickSort(filename);
}

};