#include <stdio.h>
#include <fstream>
#include <iostream>
#include <vector>
#include <fstream>
#include "Person.h"
using namespace std;

void Person::setName(string newName) {
    name = newName;
}

string Person::getName() const {
    return name;
}