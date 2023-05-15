#include <stdio.h>
#include <fstream>
#include <iostream>
#include <vector>
#include <fstream>
#include "Table.h"
using namespace std;

Table *tableHead = nullptr;
Table *tableTail = nullptr;

Table::Table() {
    status = 0;
    numSeats = 0;
}

Table::Table(int newStatus, int newNum) {
    status = newStatus;
    numSeats = newNum;
} 

void Table::setStatus(int newStatus) {
    this->status = newStatus;
}

void Table::setNumSeats(int newNum) {
    this->numSeats = newNum;
}

void Table::setNext(Table *newNext) {
    next = newNext;
}

void Table::setPrev(Table *newPrev) {
    prev = newPrev;
}

int Table::getStatus() const {return status;}
Table* Table::getNext() const {return next;}
Table* Table::getPrev() const {return prev;}

void Table::addTable(Table *end, int newStatus, int numSeats) {
    Table *table = new Table(newStatus, numSeats);
    if (end == nullptr)
    {
        table->setPrev(nullptr);
        table->setNext(nullptr);
        tableHead = table;
        tableTail = table;
        return;
    }
    tableTail->setNext(table);
    table->setPrev(tableTail);
    table->setNext(nullptr);
    tableTail = table;
}

void Table::assignReservation(Reservation *table) {

}
