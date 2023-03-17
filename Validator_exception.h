
#ifndef LAB9_10_VALIDATOR_EXCEPTION_H
#define LAB9_10_VALIDATOR_EXCEPTION_H
#include <exception>
using namespace std;

class ValidationException: public exception{
    char* mesaj;
public:
    ValidationException(char* m);
    ~ValidationException();

    const char*what() const throw();
};


#endif //LAB9_10_VALIDATOR_EXCEPTION_H
