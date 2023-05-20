
/*Jeffrey Jeremy Luke Warisha*/#ifndef RESTAURANT_H
#define RESTAURANT_H
using namespace std;

class Restaurant {
    public:
        Restaurant();
        void setCurrentAvailable(int numPeople);
        void decCurrentAvailable(int numPeople);
        void incCurrentAvailable(int numPeople);
        int getCurrentAvailable() const;
        string getRestaurantName() const;
        void viewReservations(string filename);
        void viewTables(string filename);
    private:
        int currentAvailable;
        friend class Reservation;
};

#endif
