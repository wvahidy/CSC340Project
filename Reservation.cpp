#include <stdio.h>
#include <fstream>
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <algorithm>
#include "Reservation.h"
#include "Restaurant.h"
using namespace std;

// extern global variables for reservation linked list head and tail
Reservation *resHead = nullptr;
Reservation *resTail = nullptr;

// default constructor for Reservation class
Reservation::Reservation() {
    resName = "";
    mTime = 0;
    sTime = "";
    numReserved = 0;
    phoneNum = 0;
    priority = "";
    next = nullptr;
    prev = nullptr;
}
// parameter constructor for Reservation class
Reservation::Reservation(string newName, int newNum, int newMTime, string newSTime, int numR, string prio) {
    resName = newName;
    phoneNum = newNum;
    mTime = newMTime;
    sTime = newSTime;
    numReserved = numR;
    priority = prio;
    next = nullptr;
    prev = nullptr;
}
// sets reservation name of Reservation object
void Reservation::setResName(string newResName) {
    this->resName = newResName;
}
// sets phone number of Reservation object
void Reservation::setPhoneNum(int newNum) {
    this->phoneNum = newNum;
}
// sets next pointer of Reservation object
void Reservation::setNext(Reservation *newNext) {
    this->next = newNext;
}
// sets prev pointer of Reservation object
void Reservation::setPrev(Reservation *newPrev) {
    this->prev = newPrev;
}
// sets priority of Reservation object
void Reservation::setPriority(string newPriority) {
    this->priority = newPriority;
}
// sets military time of Reservation object
void Reservation::setMilitaryTime(int newMTime) {
    this->mTime = newMTime;
}
// sets standard time of Reservation object
void Reservation::setStandardTime(string newSTime) {
    this->sTime = newSTime;
}
// sets reservation size of Reservation object
void Reservation::setNumReserved(int newNumReserved) {
    this->numReserved = newNumReserved;
}
// adds Reservation object to Reservation linked list
void Reservation::addReservation(Restaurant &store, Reservation *end, string newName, int newNum, int mTime, string sTime, int numR, string prio) {
    Reservation *res = new Reservation(newName, newNum, mTime, sTime, numR, prio);
    store.decCurrentAvailable(numR);
    if (end == nullptr)
    {
        res->setPrev(nullptr);
        res->setNext(nullptr);
        resHead = res;
        resTail = res;
        return;
    }
    resTail->setNext(res);
    res->setPrev(resTail);
    res->setNext(nullptr);
    resTail = res;
    updateReservationListFile();
}
// getter methods for Reservation objects
int Reservation::getMilitaryTime() const { return mTime; }
string Reservation::getStandardTime() const { return sTime;}
string Reservation::getResName() const { return resName; }
Reservation *Reservation::getNext() const { return next; }
Reservation *Reservation::getPrev() const { return prev; }
int Reservation::getPhoneNum() const { return phoneNum; }
string Reservation::getPriority() const { return priority; }
int Reservation::getNumReserved() const { return numReserved; }
// prints reservation info for Reservation object
void Reservation::printReservationInfo() {
    cout << "Name: ";
    cout << this->getResName() << endl;
    cout << "Phone: ";
    cout << this->getPhoneNum() << endl;
    cout << "Standard Time: ";
    cout << this->getStandardTime() << endl;
    cout << "Reservation Size: ";
    cout << this->getNumReserved() << endl;
    cout << "Priority: ";
    cout << this->getPriority() << endl;
    cout << endl;
}
// converts reservation file to reservation linked list
Reservation* Reservation::fileToLinkedList(Restaurant &store, string filename) {
    ifstream resList;
    string data;
    string resName;
    int mTime;
    string sTime;
    int temp;
    int numReserved;
    int phoneNum;
    string priority;
    resList.open(filename);
    resHead = nullptr;
    resTail = nullptr;
    if (!resList.is_open()) {
        cout << "ERROR";
        exit(0);
    }
    while (!resList.eof()) {
        getline(resList, data);
        if (!data.empty()) {
            resName = data;
            getline(resList, data);
            temp = stoi(data);
            phoneNum = temp;
            getline(resList, data);
            temp = stoi(data);
            mTime = temp;
            getline(resList, data);
            sTime = data;
            getline(resList, data);
            temp = stoi(data);
            numReserved = temp;
            getline(resList, data);
            priority = data;
            addReservation(store, resTail, resName, phoneNum, mTime, sTime, numReserved, priority);
        }
    }
    resList.close();
    return resHead;
}
// updates reservation file with current reservation linked list
void Reservation::updateReservationListFile() {
    ofstream reservationList;
    reservationList.open("reservationList.txt");
    Reservation *current = resHead;
    while (current != nullptr)
    {
        reservationList << current->getResName() << endl;
        reservationList << current->getPhoneNum() << endl;
        reservationList << current->getMilitaryTime() << endl;
        reservationList << current->getStandardTime() << endl;
        reservationList << current->getNumReserved() << endl;
        reservationList << current->getPriority() << endl;
        if (current->getNext() != nullptr) {
            reservationList << endl;
        }
        current = current->getNext();
    }
    reservationList.close();
}
// converts military time to standard time
string Reservation::militaryToStandard(int time) {
    string newTime;
    int hours = time / 100;
    int minutes = time % 100;
    bool afterNoon = hours >= 12;

    if (hours > 12) {
        hours -= 12;
    }
    newTime = to_string(hours) + ":";
    if (minutes < 10) {
        newTime += "0";}
    newTime += to_string(minutes);

    if (afterNoon) {
        newTime += " PM";
    }
    else {
        newTime += " AM";
    }
    return newTime;
}
// swaps two reservation objects using pointers
void Reservation::swap(Reservation *first, Reservation *second) {
    string tempName = first->getResName();
    first->setResName(second->getResName());
    second->setResName(tempName);

    int tempPhone = first->getPhoneNum();
    first->setPhoneNum(second->getPhoneNum());
    second->setPhoneNum(tempPhone);

    int tempMilitary = first->getMilitaryTime();
    first->setMilitaryTime(second->getMilitaryTime());
    second->setMilitaryTime(tempMilitary);

    string tempStandard = first->getStandardTime();
    first->setStandardTime(second->getStandardTime());
    second->setStandardTime(tempStandard);

    int tempNum = first->getNumReserved();
    first->setNumReserved(second->getNumReserved());
    second->setNumReserved(tempNum);

    string tempPrio = first->getPriority();
    first->setPriority(second->getPriority());
    second->setPriority(tempPrio);
}
// sorts reservation linked list by priority and updates reservation file
void Reservation::sortByPriority(Reservation *start) {
    Reservation *current = start;
    Reservation *track = start;
    Reservation *highP = start;
    while (current != nullptr) {
        highP = current;
        track = current->getNext();
        while (track != nullptr) {
            if (track->getPriority() < highP->getPriority()) {
                highP = track;  
            }
            track = track->next;
        }
        if (highP->getPriority() < current->getPriority()) {
            swap(highP, current);
        }
        current = current->getNext();
    }
    updateReservationListFile();
}
// sorts reservation linked list by time and updates reservation file
void Reservation::sortByTime(Reservation *start) {
    Reservation *current = start;
    Reservation *track = start;
    Reservation *highP = start;
    while (current != nullptr) {
        highP = current;
        track = current->getNext();
        while (track != nullptr) {
            if (track->getMilitaryTime() < highP->getMilitaryTime()) {
                highP = track;  
            }
            track = track->next;
        }
        if (highP->getMilitaryTime() < current->getMilitaryTime()) {
            swap(highP, current);
        }
        current = current->getNext();
    }
    updateReservationListFile();
}
// returns pointer to reservation of given name
Reservation* Reservation::searchName(Reservation *start, string key) {
    Reservation *current = start;
    transform(key.begin(), key.end(), key.begin(), ::tolower);
    while (current != nullptr) {
        if (current->getResName() == key) {
            return current;
        }
        current = current->getNext();
    }
    return nullptr;
}
// returns pointer to reservation of given name and prints it's info
Reservation* Reservation::searchNameInfo(Reservation *start, string key) {
    Reservation *current = start;
    transform(key.begin(), key.end(), key.begin(), ::tolower);
    while (current != nullptr) {
        if (current->getResName() == key) {
            current->printReservationInfo();
            return current;
        }
        current = current->getNext();
    }
    return nullptr;
}
// deletes reservation object given reservation name and updates reservation file
void Reservation::deleteReservation(Restaurant &store, string key) {
    Reservation *found = searchName(resHead, key);
    int resSize = found->getNumReserved();
    if (found != nullptr) {
        if (found == resHead) {
            resHead = found->getNext();
            found->getNext()->setPrev(nullptr);
            delete found;
            found = nullptr;
            cout << "Reservation successfully deleted." << endl;
        }
        else if (found == resTail) {
            resTail = found->getPrev();
            found->getPrev()->setNext(nullptr);
            delete found;
            found = nullptr;
            cout << "Reservation successfully deleted." << endl;
        }
        else {
            found->getPrev()->setNext(found->getNext());
            found->getNext()->setPrev(found->getPrev());
            delete found;
            found = nullptr;
            cout << "Reservation successfully deleted." << endl;
        }
   }
   store.incCurrentAvailable(resSize);
   Reservation::updateReservationListFile();
}
// deletes reservation linked list
void Reservation::deleteReservationList(Reservation *&resHead) {
    Reservation *current = resHead;
    while (current != nullptr) {
        Reservation *temp = current->next;
        delete current;
        current = nullptr;
        current = temp;
    }
    resHead = nullptr;
    resTail = nullptr;
}
