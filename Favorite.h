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


#pragma warning(disable : 4996)

#pragma once
using namespace std;

class Favorite{
    public:
        string name;
        string institution;
        Favorite*nextAdd;
        Favorite*prevAdd;
        DoubleLinkedList<Favorite>favDLL;

        Favorite(string name, string institution) {
            this -> name = name;
            this -> institution = institution;
            this -> nextAdd = NULL;
            this -> prevAdd = NULL;
        }

        Favorite(){
            this -> name = "";
            this -> institution = "";
            this -> nextAdd = NULL;
            this -> prevAdd = NULL;
        }


        void addToFavorite(string name, string institution){
            Favorite* newNode = new Favorite(name, institution);
            favDLL.InsertEnd(newNode);
        }

        void addToFile(){
            ofstream file("favorite.csv",std::ios::app);
            if (file.is_open()){
                Favorite*current = favDLL.tail;
                while (current != NULL)
                {
                    cout << "Name: " << current->name << endl;
                    cout << "Favourited Institutions: " << current->institution <<endl;

                    file << current -> name << ',';
                    file << current -> institution << endl;

                    current = current -> nextAdd;
                }
                cout << "End of favourited institutions" << endl; 
            }
        }
};