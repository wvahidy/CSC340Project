#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "Restaurant.h"
#include "Reservation.h"
#include "Table.h"
using namespace std;

#define MAX_OCCUPANCY 100  // max occupancy of a restaurant
#define MAX_TABLE_SEATS 15 // max number of seats at a table and reservation
#define RESTAURANT_NAME "Boxiwana" // name of restaurant
#define NUM_OPTIONS 8 // number of options as int
#define NUM_OPTIONS_S "8" // number of options as string

int main() {
    Restaurant aRestaurant;
    aRestaurant.setCurrentAvailable(MAX_OCCUPANCY);
    string nameKey;
    string resName;
    string delKey;
    string assignRes;
    int assignTable;
    int mTime;
    string stdTime;
    int numRes;
    int phone;
    string priority;
    Reservation *searchRes;
    Reservation *targetRes;
    Table *targetTable;
    Table *temp;
    int menuChoice = 0;
    resHead = Reservation::fileToLinkedList(aRestaurant, "reservationList.txt");
    tableHead = Table::fileToLinkedList("tableList.txt");
    while (menuChoice >= 0 && menuChoice <= NUM_OPTIONS)
    {
        cout << "\n--------------------------------------------\n"
             << RESTAURANT_NAME << " Manager Menu"
             << "\n--------------------------------------------\n"
             << " (1) View reservations\n"
             << " (2) View Tables\n"
             << " (3) Add a reservation\n"
             << " (4) Delete a reservation\n"
             << " (5) Sort list by priority\n"
             << " (6) Sort list by time\n"
             << " (7) Assign reservations\n"
             << " (8) Search reservations\n"
             << "Enter a number from 1 to " << NUM_OPTIONS_S << ", or 0 to exit: " << endl;
        cin >> menuChoice;
        cout << endl;
        switch (menuChoice) {
            case 0:
                cout << "Closing the restaurant. Goodbye!" << endl;
                exit(0);
                break;
            case 1:
                aRestaurant.viewReservations("reservationList.txt");
                break;
            case 2:
                aRestaurant.viewTables("tableList.txt");
                break;
            case 3:
                cout << "Name for Reservation: ";
                cin >> resName;
                cout << "Phone Number: ";
                cin >> phone;
                cout << "Time for Reservation (military time): ";
                cin >> mTime;
                stdTime = Reservation::militaryToStandard(mTime);
                cout << "Number of people for Reservation: ";
                cin >> numRes;
                while (numRes > MAX_TABLE_SEATS) {
                    cout << "ERROR! Exceeds max table occupancy (15)." << endl;
                    cout << "Number of people for Reservation: ";
                    cin >> numRes;
                }
                cout << "Reservation Priority (H)igh or (L)ow: ";
                cin >> priority;
                if (aRestaurant.getCurrentAvailable() - numRes == 0) {
                    Reservation::addReservation(aRestaurant, resTail, resName, phone, mTime, stdTime, numRes, priority);
                    cout << "Reservation Created. Restaurant now at full capacity. " << endl;
                    cout << "Available Space: " << aRestaurant.getCurrentAvailable() << endl;
                }
                else if (aRestaurant.getCurrentAvailable() - numRes < 0) {
                    cout << "Reservation Failed. Restaurant full capacity. " << endl;
                    cout << "Available Space: " << aRestaurant.getCurrentAvailable() << endl;
                }
                Reservation::addReservation(aRestaurant, resTail, resName, phone, mTime, stdTime, numRes, priority);
                cout << "Reservation Created. " << endl;
                cout << "Available Space: " << aRestaurant.getCurrentAvailable() << endl;
                break;
            case 4:
                cout << "Enter name of reservation to delete: " << endl;
                cin >> delKey;
                Reservation::deleteReservation(aRestaurant, delKey);
                temp = Table::getResTable(tableHead, delKey);
                temp->resetTable();
                break;
            case 5: 
                Reservation::sortByPriority(resHead);
                cout << "Reservations successfully sorted by priority." << endl;
                break;
            case 6:
                Reservation::sortByTime(resHead);
                cout << "Reservations successfully sorted by time." << endl;
                break;
            case 7:
                cout << "Enter name of reservation you want to assign: ";
                cin >> assignRes;
                targetRes = Reservation::searchName(resHead, assignRes);
                cout << "Enter table number you want to assign a reservation to (1-16): ";
                cin >> assignTable;
                cout << endl;
                targetTable = Table::getTable(tableHead, assignTable);
                targetTable->assignReservation(targetRes, assignTable);
                break;
            case 8:
                cout << "Search: ";
                cin >> nameKey;
                searchRes = Reservation::searchNameInfo(resHead, nameKey);
                if (searchRes == nullptr) {
                    cout << nameKey << "'s reservation not found." << endl;
                }
                else {
                    cout << searchRes->getResName() << "'s reservation found." << endl;
                }
                break;
            default: 
                cout << "Invalid input. Please enter a number between 0 and " << NUM_OPTIONS_S << "." << endl;
                menuChoice = 0;
        }
    }
    Reservation::deleteReservationList(resHead);
    Table::deleteTableList(tableHead);
    return 0;
}