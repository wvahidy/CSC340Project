#include <stdio.h>
#include <fstream>
#include <iostream>
#include <vector>
#include <fstream>
#include "Person.h"
using namespace std;

// sets name of created person object
void Person::setName(string newName) {
    name = newName;
}

// gets name of person object
string Person::getName() const {
    return name;
}