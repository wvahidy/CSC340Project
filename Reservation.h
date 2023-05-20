/*Jeffrey Jeremy Luke Warisha*/
#ifndef RESERVATION_H
#define RESERVATION_H
#include <string>
#include "Restaurant.h"
using namespace std;

class Reservation {
public:
    Reservation();
    Reservation(string newName, int newNum, int mTime, string newTime, int numR, string prio);
    void setResName(string newName);
    void setPhoneNum(int newNum);
    void setMilitaryTime(int newMTime);
    void setStandardTime(string newSTime);
    void setNext(Reservation *newNext);
    void setPrev(Reservation *newPrev);
    void setPriority(string newPriority);
    void setNumReserved(int newNumReserved);
    static void addReservation(Restaurant &store, Reservation *end, string newName, int newNum, int mTime, string newTime, int numR, string prio);
    int getMilitaryTime() const;
    string getStandardTime() const;
    string getResName() const;
    Reservation* getNext() const;
    Reservation* getPrev() const;
    int getPhoneNum() const;
    string getPriority() const;
    int getNumReserved() const;
    static string militaryToStandard(int time);
    static Reservation* fileToLinkedList(Restaurant &store, string filename);
    static void sortByPriority(Reservation *start);
    static void sortByTime(Reservation *start);
    static Reservation* searchName(Reservation *start, string key);
    static Reservation* searchNameInfo(Reservation *start, string key);
    void printReservationInfo();
    static void deleteReservation(Restaurant &store, string key);
    static void deleteReservationList(Reservation *&resHead);
private:
    static void updateReservationListFile();
    static void swap(Reservation *first, Reservation *second);
    Reservation *next;
    Reservation *prev;
    string resName;
    int mTime;
    string sTime;
    int numReserved;
    int phoneNum;
    string priority;
    friend class Table;
};

extern Reservation *resHead;
extern Reservation *resTail;

#endif