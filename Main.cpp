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

int main() {
    Restaurant aRestaurant;
    aRestaurant.setCurrentAvailable(MAX_OCCUPANCY);
    string resName;
    int time;
    string stdTime;
    int numRes;
    int phone;
    string priority;
    Reservation *reservation;
    int menuChoice = 0;
    while (menuChoice >= 0 && menuChoice <= NUM_OPTIONS)
    {
        cout << "\n--------------------------------------------\n"
             << RESTAURANT_NAME << " MANAGER MENU" << "\n"
             << " (1) View reservations\n"
             << " (2) Add a reservation\n"
             << " (3) Sort list by priority\n"
             << " (4) Sort list by time\n"
             << " (5) Set number of seats per table\n"
             << "Enter a number from 1 to " << NUM_OPTIONS_S << ", or 0 to exit: " << endl;
        cin >> menuChoice;
        switch (menuChoice) {
            case 0:
                cout << "Goodbye!" << endl;
                exit(0);
                break;
            case 1:
                aRestaurant.viewReservations("reservationList.txt");
                break;
            case 2:
                cout << "Name for Reservation: ";
                cin >> resName;
                cout << "Time for Reservation (military): ";
                cin >> time;
                stdTime = Reservation::militaryToStandard(time);
                cout << "Number of people for Reservation: ";
                cin >> numRes;
                cout << "Phone Number: ";
                cin >> phone;
                cout << "Reservation Priority (H or L): ";
                cin >> priority;
                reservation = new Reservation();
                reservation->setResName(resName);
                reservation->setTime(stdTime);
                reservation->setNumReserved(numRes);
                reservation->setPhoneNum(phone);
                reservation->setPriority(priority);
                Reservation::addReservation(reservation);
                break;
            case 3: 
                break;
            case 4:
                break;
            case 5:
                break;
            default: 
                cout << "Invalid input. Please enter a number between 0 and " << NUM_OPTIONS_S << "." << endl;
                menuChoice = 0;
        }
    }
    return 0;
}