
#ifndef LAB9_10_VALIDATOR_HOTEL_H
#define LAB9_10_VALIDATOR_HOTEL_H
#include "Hotel.h"


class ValidatorHotel {
protected:
    int err;
    string mesaj;

public:
    ValidatorHotel();
    ~ValidatorHotel();

    virtual int validate(Hotel*);

    string getMesaj();
    int getErr();

};


#endif //LAB9_10_VALIDATOR_HOTEL_H
