#include <stdio.h>
#include <fstream>
#include <iostream>
#include <vector>
#include <fstream>
#include "Restaurant.h"

using namespace std;

#define MAX_OCCUPANCY 100
#define RESTAURANT_NAME "Boxiwana"

void Restaurant::decCurrentAvailable(int numPeople) {
    if (currentAvailable - numPeople < 0) {
        cout << "Not enough seats.Only " << currentAvailable << " seats can be reserved." << endl;
    } else {
        currentAvailable -= numPeople;
    }
}

void Restaurant::incCurrentAvailable(int numPeople) {
    if (currentAvailable + numPeople > MAX_OCCUPANCY) {
        cout << "Too many seats.Only " << MAX_OCCUPANCY - currentAvailable << " seats can be added." << endl;
    } else {
        currentAvailable += numPeople;
    }
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
    while (getline(resList, data)) {
        if (!data.empty()) {
            cout << "Reservation #" << resCount << " " << endl;
            cout << "Name: ";
            cout << data << endl;
            getline(resList, data);
            cout << "Phone: ";
            cout << data << endl;
            getline(resList, data);
            cout << "Time: ";
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

int Restaurant::getCurrentAvailable() const { return currentAvailable; }

string Restaurant::getRestaurantName() const { return RESTAURANT_NAME; }
