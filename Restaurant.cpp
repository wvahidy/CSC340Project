#include <stdio.h>
#include <fstream>
#include <iostream>
#include <vector>
#include <fstream>
#include "Restaurant.h"
#include "Reservation.h"
#include <string>

using namespace std;

#define MAX_OCCUPANCY 100
#define RESTAURANT_NAME "Boxiwana"

Restaurant::Restaurant() {
    currentAvailable = MAX_OCCUPANCY;
}

void Restaurant::decCurrentAvailable(int numPeople) {
    currentAvailable -= numPeople;
}

void Restaurant::incCurrentAvailable(int numPeople) {
    currentAvailable += numPeople;
}

void Restaurant::setCurrentAvailable(int numPeople) {
    currentAvailable = numPeople;
}

void Restaurant::viewReservations(string filename) {
    ifstream resList;
    string data;
    int resCount = 1;
    resList.open(filename);
    if (!resList.is_open()) {
        cout << "ERROR";
        exit(0);
    }
    while (!resList.eof()) {
        getline(resList, data);
        if (!data.empty()) {
            cout << "Reservation #" << resCount << endl;
            cout << "Name: ";
            cout << data << endl;
            getline(resList, data);
            cout << "Phone: ";
            cout << data << endl;
            getline(resList, data);
            // cout << "Military Time: ";
            // cout << data << endl;
            getline(resList, data);
            cout << "Reserved Time: ";
            cout << data << endl;
            getline(resList, data);
            cout << "Reservation Size: ";
            cout << data << endl;
            getline(resList, data);
            cout << "Priority: ";
            cout << data << endl;
            resCount++;
            cout << endl;
        }
    }
    resList.close();
}

void Restaurant::viewTables(string filename) {
    ifstream tableList;
    string data;
    int tableCount = 1;
    tableList.open(filename);
    if (!tableList.is_open()) {
        cout << "ERROR";
        exit(0);
    }
    while (!tableList.eof()) {
        getline(tableList, data);
        if (!data.empty()) {
            cout << "Table #" << tableCount << endl;
            cout << "Status: ";
            if (data == "0") {
                cout << "Available " << endl;
            }
            else if (data == "1") {
                cout << "Reserved " << endl;
            }
            getline(tableList, data);
            cout << "Table Size: ";
            cout << data << endl;
            getline(tableList, data);
            cout << "Reservation: ";
            cout << data << endl;
            tableCount++;
            cout << endl;
        }
    }
    tableList.close();
}

int Restaurant::getCurrentAvailable() const { return currentAvailable; }

string Restaurant::getRestaurantName() const { return RESTAURANT_NAME; }
