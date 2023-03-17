
#ifndef LAB9_10_MYEXCEPTION_H
#define LAB9_10_MYEXCEPTION_H
#include <exception>
#include <string>
using namespace std;

class MyException: public exception{
protected:
    string msg;
public:
    explicit MyException(string msg) {
        this->msg = move(msg);
    }
    string what(){
        return this->msg;
    }
};

#endif //LAB9_10_MYEXCEPTION_H
