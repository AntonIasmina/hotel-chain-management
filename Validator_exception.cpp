#include "Validator_exception.h"
#include <cstring>

ValidationException::ValidationException(char* m){

    this->mesaj = new char[strlen(m)+];
    strcpy(this->mesaj, m);

}

ValidationException::~ValidationException(){
    if(this->mesaj) delete[]this->mesaj;
}

const char * ValidationException::what() const throw(){

    return this->mesaj;

}