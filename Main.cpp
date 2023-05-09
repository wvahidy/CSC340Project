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
Table *tableHead = nullptr;
Table *tableTail = nullptr;

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
         if (menuChoice == 0) {
            break;
        

        Reservation reservation1;
        reservation1.setName("Jason Stehlik");
        reservation1.setPhoneNum(4152982562);
        reservation1.setTime(2000); // 8:00 pm
    }
    return 0;
}
