#ifndef RESERVATION_H
#define RESERVATION_H
#include "Restaurant.h"
#include "Person.h"
#include "Table.h"
using namespace std;

class Reservation : public Restaurant, public Table
{
public:
    void setResName(string newName);
    void setPhoneNum(int newNum);
    void setTime(int newTime);
    void setNext(Reservation *newNext);
    void setPrev(Reservation *newPrev);
    void setPriority(string newPriority);
    void setNumReserved(int newNumReserved);
    void addReservation(Reservation *newRes);
    int getTime() const;
    string getName() const;
    Reservation *getNext() const;
    Reservation *getPrev() const;
    int getPhoneNum() const;
    string getPriority() const;
    int getNumReserved() const;
private:
    void updateReservationListFile(string name);
    Reservation *next;
    Reservation *prev;
    string resName = " ";
    int time;
    int numReserved;
    int phoneNum;
    string priority;
};
#endif