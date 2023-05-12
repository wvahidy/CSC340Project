#ifndef RESERVATION_H
#define RESERVATION_H
#include <string>
#include "Restaurant.h"
using namespace std;

class Reservation : public Restaurant {
public:
    Reservation();
    Reservation(string newName, int newTime, int numR, int newNum, string prio);
    void setResName(string newName);
    void setPhoneNum(int newNum);
    void setTime(string newTime);
    void setNext(Reservation *newNext);
    void setPrev(Reservation *newPrev);
    void setPriority(string newPriority);
    void setNumReserved(int newNumReserved);
    static void addReservation(Reservation *newRes);
    string getTime() const;
    string getName() const;
    Reservation *getNext() const;
    Reservation *getPrev() const;
    int getPhoneNum() const;
    string getPriority() const;
    int getNumReserved() const;
    static string militaryToStandard(int time);
    static Reservation* fileToLinkedList(string filename);
private:
    static void updateReservationListFile();
    Reservation *next;
    Reservation *prev;
    string resName;
    string time;
    int numReserved;
    int phoneNum;
    string priority;
};

extern Reservation *resHead;
extern Reservation *resTail;

#endif