#ifndef RESERVATION_H
#define RESERVATION_H
#include <string>
#include "Restaurant.h"
using namespace std;

class Reservation : public Restaurant {
public:
    Reservation();
    Reservation(Reservation *end, string newName, int newTime, int numR, int newNum, string prio);
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
    void updateReservationListFile();
    Reservation *next;
    Reservation *prev;
    string resName;
    int time;
    int numReserved;
    int phoneNum;
    string priority;
};

extern Reservation *resHead;
extern Reservation *resTail;

#endif