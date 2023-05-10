#ifndef TABLE_H
#define TABLE_H
#include "Restaurant.h"
using namespace std;

extern Table *tableHead = nullptr;
extern Table *tableTail = nullptr;

class Table : public Restaurant {
    public:
        void setStatus(int newStatus);
        void setNumSeats(int numSeats);
        int getStatus() const;
    private:
        int status = 0;
        int numSeats = 0;
};
#endif