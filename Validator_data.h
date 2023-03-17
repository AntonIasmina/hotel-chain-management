
#ifndef LAB9_10_VALIDATOR_DATA_H
#define LAB9_10_VALIDATOR_DATA_H
#include <cstring>
#include "Validator_hotel.h"
#include "Date.h"

class ValidatorData:public ValidatorHotel{
public:
    ValidatorData();
    ~ValidatorData();

    int validate(Date *);

    //string getMesaj();
    //int getErr();

};


#endif //LAB9_10_VALIDATOR_DATA_H
