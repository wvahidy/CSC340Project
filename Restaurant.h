#ifndef RESTAURANT_H
#define RESTAURANT_H
#include "Reservation.h"
using namespace std;

class Restaurant {
    public:
        void setCurrentAvailable(int numPeople);
        void decCurrentAvailable(int numPeople);
        void incCurrentAvailable(int numPeople);
        int getCurrentAvailable() const;
        string getRestaurantName() const;
        void viewReservations(string filename);
        static Reservation *searchName(Reservation *start, string key);
    private:
        int currentAvailable;
};

#endif
