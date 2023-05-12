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
    time = "";
    numReserved = 0;
    phoneNum = 0;
    priority = "";
    next = nullptr;
    prev = nullptr;
}
Reservation::Reservation(string newName, int newNum, string newTime, int numR, string prio) {
    resName = newName;
    phoneNum = newNum;
    time = newTime;
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
void Reservation::setTime(string newTime) {
    this->time = newTime;
}
void Reservation::setNumReserved(int newNumReserved) {
    this->numReserved = newNumReserved;
}
void Reservation::addReservation(Reservation *end, string newName, int newNum, string newTime, int numR, string prio) {
    Reservation *res = new Reservation(newName, newNum, newTime, numR, prio);
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
string Reservation::getTime() const { return time; }
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
    string time;
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
    while (getline(resList, data)) {
        if (!data.empty()) {
            resName = data;
            getline(resList, data);
            temp = stoi(data);
            phoneNum = temp;
            getline(resList, data);
            time = data;
            getline(resList, data);
            temp = stoi(data);
            numReserved = temp;
            getline(resList, data);
            priority = data;
            Reservation::addReservation(resTail, resName, phoneNum, time, numReserved, priority);
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
        reservationList << current->getTime() << endl;
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
