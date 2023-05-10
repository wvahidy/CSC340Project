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

int Restaurant::getCurrentAvailable() const { return currentAvailable; }

string Restaurant::getRestaurantName() const { return RESTAURANT_NAME; }
