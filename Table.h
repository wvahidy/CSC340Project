#ifndef TABLE_H
#define TABLE_H
#include "Reservation.h"
#include "Restaurant.h"
using namespace std;

extern Table *tableHead;
extern Table *tableTail;

class Table : public Reservation, public Restaurant {
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
        static void addTable(int newStatus, int numSeats);
        void assignReservation(Reservation* res);
    private:
        int status = 0;
        int numSeats = 0;
        Table *next;
        Table *prev;
};
#endif