#ifndef RESERVATION_H
#define RESERVATION_H
#include <string>
using namespace std;

class Reservation
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
    void updateReservationListFile();
    Reservation *next;
    Reservation *prev;
    string resName = "";
    int time;
    int numReserved;
    int phoneNum;
    string priority;
};
#endif