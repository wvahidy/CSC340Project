#include <stdio.h>
#include <fstream>
#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
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

Table::Table(int newStatus, int newNum, string newName) {
    status = newStatus;
    numSeats = newNum;
    rName = newName;
    next = nullptr;
    prev = nullptr;
} 

void Table::setStatus(int newStatus) {
    this->status = newStatus;
}

void Table::setNumSeats(int newNum) {
    this->numSeats = newNum;
}
void Table::setRName(string newName) {
    this->rName = newName;
}
void Table::setNext(Table *newNext) {
    next = newNext;
}

void Table::setPrev(Table *newPrev) {
    prev = newPrev;
}

int Table::getStatus() const {return status;}
int Table::getNumSeats() const {return numSeats;}
string Table::getRName() const {return rName;}
Table* Table::getNext() const {return next;}
Table* Table::getPrev() const {return prev;}

void Table::addTable(Table *end, int newStatus, int numSeats, string newName) {
    Table *table = new Table(newStatus, numSeats, newName);
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

int Table::searchTableName(Table *tHead, string key) {
    Table *current = tHead;
    int tableNum = 1;
    transform(key.begin(), key.end(), key.begin(), ::tolower);
    while (current != nullptr) {
        if (current->getRName() == key) {
            return tableNum;
        }
        current = current->getNext();
        tableNum++;
    } 
    return 0;
}

void Table::assignReservation(Reservation *res) {
    int tableNum = 0;
    if (this->getStatus() == 1) {
        cout << "This table is occupied. Assign failed." << endl;
        return;
    }
    tableNum = searchTableName(tableHead, res->getResName());
    if (tableNum != 0) {
        cout << "This reservation is already assigned to table " << to_string(tableNum);
        cout << ". Assign failed." << endl;
        return;
    }
    if (this->getNumSeats() < res->getNumReserved()) {
        cout << "This table does not have enough seats." << endl;
        return;
    }
    this->assigned = res;
    this->setStatus(1);
    this->setRName(res->getResName());
    cout << res->getResName() << "'s reservation successfully assigned to table " << to_string(tableNum) << endl;
    updateTableList();
}

Table* Table::fileToLinkedList(string filename) {
    ifstream tableList;
    string data;
    int temp;
    int status;
    int numSeats;
    string rName;
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
            getline(tableList, data);
            rName = data;
            addTable(tableTail, status, numSeats, rName);
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
        tableList << current->getRName() << endl;
        if (current->getNext() != nullptr) {
            tableList << endl;
        }
        current = current->getNext();
    }
    tableList.close();
}

Table* Table::getTable(Table *tHead, int key) {
    Table *current = tHead;
    Table *found = nullptr;
    for (int i = 1; i <= key; i++) {
        found = current;
        current = current->getNext();
    }
    return found;
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

void Table::deleteTableList(Table *&tHead) {
    Table *current = tHead;
    while (current != nullptr) {
        Table *temp = current->next;
        delete current;
        current = nullptr;
        current = temp;
    }
    tableHead = nullptr;
    tableTail = nullptr;
}
