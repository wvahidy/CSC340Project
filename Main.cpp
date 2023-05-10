#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "Restaurant.h"
#include "Reservation.h"
#include "Table.h"
using namespace std;

#define MAX_OCCUPANCY 100
#define RESTAURANT_NAME "Boxiwana"
#define NUM_OPTIONS 6
#define NUM_OPTIONS_S "6"

Reservation *resHead = nullptr;
Reservation *resTail = nullptr;

void Reservation::setResName(string newResName) {
    resName = newResName;
}
void Reservation::setPhoneNum(int newNum) {
    phoneNum = newNum;
}
void Reservation::setNext(Reservation *newNext) {
    next = newNext;
}
void Reservation::setPrev(Reservation *newPrev) {
    prev = newPrev;
}
void Reservation::setPriority(string newPriority) {
    priority = newPriority;
}
void Reservation::setTime(int newTime) {
    time = newTime;
}
void Reservation::setNumReserved(int newNumReserved) {
    numReserved = newNumReserved;
}
void Reservation::addReservation(Reservation *newRes) {
    if (resTail == nullptr)
    {
        Reservation *res = new Reservation;
        res->setPrev(nullptr);
        res->setNext(nullptr);
        resHead = res;
        resTail = res;
    }
    Reservation *res = new Reservation;
    resTail->setNext(res);
    res->setPrev(resTail);
    res->setNext(nullptr);
    resTail = res;
}

void Restaurant::setCurrentAvailable(int numPeople) {
    currentAvailable = numPeople;
}

int main() {
    Restaurant aRestaurant;
    aRestaurant.setCurrentAvailable(MAX_OCCUPANCY);
    int menuChoice = 0;
    while (menuChoice >= 0 && menuChoice <= NUM_OPTIONS)
    {
        cout << "\n--------------------------------------------\n"
             << "Options menu: \n"
             << " (1)View reservations\n"
             << " (2)Add a reservation\n"
             << " (3)Sort list by priority\n"
             << " (4)Sort list by time\n"
             << " (5)Set number of seats per table\n"
             << "Enter a number from 1 to " << NUM_OPTIONS_S << ", or 0 to exit: " << endl;
        cin >> menuChoice;
        switch (menuChoice) {
            case 0:
                cout << "Goodbye!" << endl;
                exit(0);
                break;
            case 1:
                break;
            case 2:
                break;
            case 3: 
                break;
            case 4:
                break;
            case 5:
                break;
            default: 
                cout << "Invalid input. Please enter a number between 0 and " << NUM_OPTIONS_S << "." << endl;
                continue;
        }
    }
    Reservation *reservation1;
    reservation1->setResName("Jason Stehlik");
    reservation1->setPhoneNum(4152982562);
    reservation1->setTime(2000); // 8:00 pm
    resHead->addReservation(reservation1);
    return 0;
}
