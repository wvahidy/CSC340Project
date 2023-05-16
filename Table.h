#ifndef TABLE_H
#define TABLE_H
#include "Reservation.h"
using namespace std;

class Table : public Reservation {
    public:
        Table();
        Table(int newStatus, int numSeats);
        void setStatus(int newStatus);
        void setNumSeats(int numSeats);
        void setNext(Table *newNext);
        void setPrev(Table *newPrev);
        int getStatus() const;
        Table* getNext() const;
        Table* getPrev() const;
        static void addTable(Table *end, int newStatus, int numSeats);
        void assignReservation(Reservation* res);
        static Table* fileToLinkedList(string filename);
    private:
        int status = 0;
        int numSeats = 0;
        Table *next;
        Table *prev;
        Reservation *assigned = nullptr;
};

extern Table *tableHead;
extern Table *tableTail;

#endif