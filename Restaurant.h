#ifndef RESTAURANT_H
#define RESTAURANT_H
using namespace std;

class Restaurant {
    public:
        void setCurrentAvailable(int numPeople);
        void decCurrentAvailable(int numPeople);
        void incCurrentAvailable(int numPeople);
        int getCurrentAvailable() const;
        string getRestaurantName() const;
    private:
        int currentAvailable;
};
#endif
