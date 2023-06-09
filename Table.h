/*Jeffrey Jeremy Luke Warisha*/
#include <stdio.h>
#ifndef TABLE_H
#define TABLE_H
#include "Reservation.h"
using namespace std;

class Table {
    public:
        Table();
        Table(int newStatus, int numSeats, string rName);
        void setStatus(int newStatus);
        void setNumSeats(int numSeats);
        void setRName(string newName);
        void setNext(Table *newNext);
        void setPrev(Table *newPrev);
        int getStatus() const;
        int getNumSeats() const;
        string getRName() const;
        Table* getNext() const;
        Table* getPrev() const;
        static void addTable(Table *end, int newStatus, int numSeats, string newName);
        static Table* getTable(Table *tHead, int key);
        void assignReservation(Reservation* res, int tableNum);
        static Table* fileToLinkedList(string filename);
        static void deleteTable(Table *table);
        static void deleteTableList(Table *&tHead);
        static int searchTableName(Table *tHead, string key);
        static Table* getResTable(Table *tHead, string key);
        void resetTable();
    private:
        static void updateTableList();
        int status = 0;
        int numSeats = 0;
        string rName;
        Table *next;
        Table *prev;
        Reservation *assigned = nullptr;
};

extern Table *tableHead;
extern Table *tableTail;

#endif