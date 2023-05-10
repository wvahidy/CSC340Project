#include <stdio.h>
#include <fstream>
#include <iostream>
#include <vector>
#include <fstream>
#include "Restaurant.h"
using namespace std;

#define MAX_OCCUPANCY 100
#define RESTAURANT_NAME "Boxiwana"

class Restaurant
{
public:
    void decCurrentAvailable(int numPeople)
    {
        if (currentAvailable - numPeople < 0)
        {
            cout << "Not enough seats.Only " << currentAvailable << " seats can be reserved." << endl;
        }
        else
        {
            currentAvailable -= numPeople;
        }
    }
    void incCurrentAvailable(int numPeople)
    {
        if (currentAvailable + numPeople > MAX_OCCUPANCY)
        {
            cout << "Too many seats.Only " << MAX_OCCUPANCY - currentAvailable << " seats can be added." << endl;
        }
        else
        {
            currentAvailable += numPeople;
        }
    }
    void setCurrentAvailable(int numPeople)
    {
        currentAvailable = numPeople;
    }
    int getCurrentAvailable() const {return currentAvailable;}
    string getName() const {return RESTAURANT_NAME;}

private:
    int currentAvailable;
};
