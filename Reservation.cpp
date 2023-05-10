#include <stdio.h>
#include <fstream>
#include <iostream>
#include <vector>
#include <fstream>
#include "Reservation.h"
using namespace std;

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
