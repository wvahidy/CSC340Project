#ifndef RESTAURANT_H
#define RESTAURANT_H
#include <string>
using namespace std;

class Restaurant {
    public:
        void setCurrentAvailable(int numPeople);
        void decCurrentAvailable(int numPeople);
        void incCurrentAvailable(int numPeople);
        int getCurrentAvailable() const;
        string getName() const;
    private:
        int currentAvailable;
};
#endif
