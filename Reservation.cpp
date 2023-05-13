#include <stdio.h>
#include <fstream>
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include "Reservation.h"
using namespace std;

Reservation *resHead = nullptr;
Reservation *resTail = nullptr;

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
void Reservation::setResName(string newResName) {
    this->resName = newResName;
}
void Reservation::setPhoneNum(int newNum) {
    this->phoneNum = newNum;
}
void Reservation::setNext(Reservation *newNext) {
    this->next = newNext;
}
void Reservation::setPrev(Reservation *newPrev) {
    this->prev = newPrev;
}
void Reservation::setPriority(string newPriority) {
    this->priority = newPriority;
}
void Reservation::setMilitaryTime(int newMTime) {
    this->mTime = newMTime;
}
void Reservation::setStandardTime(string newSTime) {
    this->sTime = newSTime;
}
void Reservation::setNumReserved(int newNumReserved) {
    this->numReserved = newNumReserved;
}
void Reservation::addReservation(Reservation *end, string newName, int newNum, int mTime, string sTime, int numR, string prio) {
    Reservation *res = new Reservation(newName, newNum, mTime, sTime, numR, prio);
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
int Reservation::getMilitaryTime() const { return mTime; }
string Reservation::getStandardTime() const { return sTime;}
string Reservation::getName() const { return resName; }
Reservation *Reservation::getNext() const { return next; }
Reservation *Reservation::getPrev() const { return prev; }
int Reservation::getPhoneNum() const { return phoneNum; }
string Reservation::getPriority() const { return priority; }
int Reservation::getNumReserved() const { return numReserved; }

Reservation* Reservation::fileToLinkedList(string filename) {
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
            Reservation::addReservation(resTail, resName, phoneNum, mTime, sTime, numReserved, priority);
        }
    }
    resList.close();
    return resHead;
}

void Reservation::updateReservationListFile() {
    ofstream reservationList;
    reservationList.open("reservationList.txt");
    Reservation *current = resHead;
    while (current != nullptr)
    {
        reservationList << current->getName() << endl;
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

static Reservation *sortByPriority(Reservation *start) {
    return resHead;
}
static Reservation *sortByTime(Reservation *start) {
    return resHead;
}
