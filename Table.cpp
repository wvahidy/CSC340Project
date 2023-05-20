/*Jeffrey Jeremy Luke Warisha*/#include <stdio.h>

#include <fstream>
#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include "Table.h"
using namespace std;

// declare extern global table linked list head and tail
Table *tableHead = nullptr;
Table *tableTail = nullptr;

// default constructor for Table class
Table::Table() {
    status = 0;
    numSeats = 0;
    next = nullptr;
    prev = nullptr;
    assigned = nullptr;
}

// parameter constructors for Table class
Table::Table(int newStatus, int newNum, string newName) {
    status = newStatus;
    numSeats = newNum;
    rName = newName;
    next = nullptr;
    prev = nullptr;
    assigned = nullptr;
} 

// sets status of Table object
void Table::setStatus(int newStatus) {
    this->status = newStatus;
}
// sets number of seats of Table object
void Table::setNumSeats(int newNum) {
    this->numSeats = newNum;
}
// sets reservation name of Table object
void Table::setRName(string newName) {
    this->rName = newName;
}
// sets next pointer for Table object
void Table::setNext(Table *newNext) {
    next = newNext;
}
// sets prev pointer for Table object
void Table::setPrev(Table *newPrev) {
    prev = newPrev;
}

// getters for Table object
int Table::getStatus() const {return status;}
int Table::getNumSeats() const {return numSeats;}
string Table::getRName() const {return rName;}
Table* Table::getNext() const {return next;}
Table* Table::getPrev() const {return prev;}

// add method for Table object onto Table linked list
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
// returns table number of table with given reservation name
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
// returns table pointer of table with given reservation name
Table* Table::getResTable(Table *tHead, string key) {
    Table *current = tHead;
    transform(key.begin(), key.end(), key.begin(), ::tolower);
    while (current != nullptr) {
        if (current->getRName() == key) {
            return current;
        }
        current = current->getNext();
    } 
    return nullptr;
}
// assigns table with given reservation name at given table number
void Table::assignReservation(Reservation *res, int tableNum) {
    int searchTable = 0;
    if (this->getRName() == res->getResName()) {
        cout << "This reserveration is already assigned to this table." << endl;
        return;
    }
    if (this->getStatus() == 1) {
        cout << "This table is occupied. Assign failed." << endl;
        return;
    }
    searchTable = searchTableName(tableHead, res->getResName());
    if (searchTable != 0) {
        cout << "This reservation is already assigned to table " << to_string(searchTable);
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
    cout << res->getResName() << "'s reservation successfully assigned to table " << to_string(tableNum) << ". " << endl;
    updateTableList();
}
// converts given table file to table linked list
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
// updates table file with current table linked list
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
// returns table at given table number
Table* Table::getTable(Table *tHead, int key) {
    Table *current = tHead;
    Table *found = nullptr;
    for (int i = 1; i <= key; i++) {
        found = current;
        current = current->getNext();
    }
    return found;
}
// resets table object back to default values
void Table::resetTable() {
    this->assigned = nullptr;
    this->setStatus(0);
    this->setRName("N/A"); 
    updateTableList();
}
// deletes table object and updates table linked list
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
   Table::updateTableList();
}
// deletes table linked list
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
