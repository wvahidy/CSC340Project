/*Jeffrey Jeremy Luke Warisha*/
#ifndef WAITER_H
#define WAITER_H
#include "Person.h"
#include "Table.h"
using namespace std;

//unfinished class
class Waiter : public Person {
public:
    void setTableAssignment1(Table* newTable);
    void setTableAssignment2(Table* newTable);
    void setTableAssignment3(Table* newTable);
    void setTableAssignment4(Table* newTable);
    void setTableAssignment5(Table* newTable);
    Table* getTableAssignments() const;
private:
    friend class Table;
    Table* tableAssignment1;
    Table* tableAssignment2;
    Table* tableAssignment3;
    Table* tableAssignment4;
    Table* tableAssignment5;
};
#endif