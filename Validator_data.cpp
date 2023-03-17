
#include "Validator_data.h"

ValidatorData::ValidatorData():ValidatorHotel() {
    //this->err = 0;
    //this->mesaj = nullptr;
}

ValidatorData::~ValidatorData() {

}

int ValidatorData::validate(Date *d) {
    this->err = 0;
    this->mesaj = "";
    if(d->getAn()<2022){
        this->err++;
        this->mesaj+="Nu se pot face rezervari in trecut!";
    }
    if(d->getLuna()>12 || d->getLuna()<1){
        this->err = 0;
        this->mesaj+="Nu exista luna!";
    }
    if (d->getAn()/4==0 && d->getLuna()==2 && d->getZi()>29){
        this->err = 0;
        this->mesaj+="Anul este bisect!";
    }else if(d->getAn()/4!=0 && d->getLuna()==2 && d->getZi()>28){
        this->err = 0;
        this->mesaj+="Anul nu este bisect!";
    }else if((d->getLuna()==1||d->getLuna()==3||d->getLuna()==5||
        d->getLuna()==7||d->getLuna()==8||d->getLuna()==10||
        d->getLuna()==12) && d->getZi()>31){
        this->err = 0;
        this->mesaj+="Luna introdusa nu are mai multe de 31 de zile!";
    }else if((d->getLuna()==2||d->getLuna()==4||d->getLuna()==6||
              d->getLuna()==9||d->getLuna()==11) && d->getZi()>30){
        this->err = 0;
        this->mesaj+="Luna introdusa nu are mai mult de 30 de zile!";
    }
    if(d->getZi()<1){
        this->err = 0;
        this->mesaj+="Nu exista zile mai mici decat 1!";
    }
    return this->err;
}
/*
int ValidatorData::getErr() {
    return this->err;
}

string ValidatorData::getMesaj() {
    return this->mesaj;
}*/