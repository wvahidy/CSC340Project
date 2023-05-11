#include <stdio.h>
#include <fstream>
#include <iostream>
#include <vector>
#include <fstream>
#include "Reservation.h"
using namespace std;

Reservation *resHead = nullptr;
Reservation *resTail = nullptr;

Reservation::Reservation() {
    resName = "";
    time = 0;
    numReserved = 0;
    phoneNum = 0;
    priority = "";
    next = nullptr;
    prev = nullptr;
}
Reservation::Reservation(Reservation *end, string newName, int newTime, int numR, int newNum, string prio) {
    resName = newName;
    time = newTime;
    numReserved = numR;
    phoneNum = newNum;
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
void Reservation::setTime(int newTime) {
    this->time = newTime;
}
void Reservation::setNumReserved(int newNumReserved) {
    this->numReserved = newNumReserved;
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
    updateReservationListFile();
}
int Reservation::getTime() const { return time; }
string Reservation::getName() const { return resName; }
Reservation *Reservation::getNext() const { return next; }
Reservation *Reservation::getPrev() const { return prev; }
int Reservation::getPhoneNum() const { return phoneNum; }
string Reservation::getPriority() const { return priority; }
int Reservation::getNumReserved() const { return numReserved; }

void Reservation::updateReservationListFile() {
    ofstream reservationList;
    reservationList.open("ReservationList.txt");
    Reservation *current = resHead;
    while (current->getNext() != nullptr)
    {
        reservationList << current->getName() << endl;
        reservationList << current->getPhoneNum() << endl;
        reservationList << current->getNumReserved() << endl;
        reservationList << current->getPriority() << endl;
    }
    reservationList.close();
}
