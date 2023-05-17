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
    next = nullptr;
    prev = nullptr;
}

Table::Table(int newStatus, int newNum) {
    status = newStatus;
    numSeats = newNum;
    next = nullptr;
    prev = nullptr;
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
int Table::getNumSeats() const {return numSeats;}
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
    this->assigned = table;
}

Table* Table::fileToLinkedList(string filename) {
    ifstream tableList;
    string data;
    int temp;
    int status;
    int numSeats;
    tableList.open(filename);
    tableHead = nullptr;
    tableTail = nullptr;
    if (!tableList.is_open()) {
        cout << "ERROR";
        exit(0);
    }
    while (!tableList.eof()) {
        getline(tableList, data);
        if (!data.empty()) {
            temp = stoi(data);
            status = temp;
            getline(tableList, data);
            temp = stoi(data);
            numSeats = temp;
            addTable(tableTail, status, numSeats);
        }
    }
    tableList.close();
    return tableHead;
}

void Table::updateTableList() {
    ofstream tableList;
    tableList.open("tableList.txt");
    Table *current = tableHead;
    while (current != nullptr)
    {
        tableList << current->getStatus() << endl;
        tableList << current->getNumSeats() << endl;
        if (current->getNext() != nullptr) {
            tableList << endl;
        }
        current = current->getNext();
    }
    tableList.close();
}

void Table::deleteTable(Table *table) {
    Table *result = table;
    if (result != nullptr) {
        if (result == tableHead) {
            tableHead = result->getNext();
            result->getNext()->setPrev(nullptr);
            delete result;
            result = nullptr;
        }
        else if (result == tableTail) {
            tableTail = result->getPrev();
            result->getPrev()->setNext(nullptr);
            delete result;
            result = nullptr;
        }
        else {
            result->getPrev()->setNext(result->getNext());
            result->getNext()->setPrev(result->getPrev());
            delete result;
            result = nullptr;
        }
   }

}

void Table::deleteTableList(Table *&tableHead) {
    Table *current = tableHead;
    while (current != nullptr) {
        Table *temp = current->next;
        delete current;
        current = nullptr;
        current = temp;
    }
    tableHead = nullptr;
    tableTail = nullptr;
}
