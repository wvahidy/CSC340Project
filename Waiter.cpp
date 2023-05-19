#include <stdio.h>
#include <fstream>
#include <iostream>
#include <vector>
#include <fstream>
#include "Waiter.h"
using namespace std;

// setters for assigning table assignments for waiters
void Waiter::setTableAssignment1(Table* newTable) {
    this->tableAssignment1 = newTable;
}
void Waiter::setTableAssignment2(Table* newTable) {
    this->tableAssignment2 = newTable;
}
void Waiter::setTableAssignment3(Table* newTable) {
    this->tableAssignment3 = newTable;
}
void Waiter::setTableAssignment4(Table* newTable) {
    this->tableAssignment4 = newTable;
}
void Waiter::setTableAssignment5(Table* newTable) {
    this->tableAssignment5 = newTable;
}

// gets waiter's table assignments
Table* Waiter::getTableAssignments() const {return tableAssignment1;}