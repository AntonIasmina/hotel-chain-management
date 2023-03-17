#ifndef LAB9_10_HOTEL_H
#define LAB9_10_HOTEL_H

#include <cstring>
#include <iostream>
#include <sstream>
#include "Date.h"
using namespace std;

class Hotel {
private:
    int cod;
    string nume;
    string oras;
    Date dataInceput;
    Date dataFinal;
public:
    Hotel();
    Hotel(int, string , string , Date, Date);
    //Hotel(const Hotel &h);
    int get_cod();
    string get_nume();
    string get_oras();
    Date get_data_inc();
    Date get_data_sf();
    //void set_cod(int);
    //void set_nume(string);
    //void set_oras(string);
    void set_data_inc(int);
    void set_data_sf(int);
    Hotel& operator=(const Hotel &);
    bool operator==(const Hotel&);
    bool operator!=(const Hotel&);
    friend ostream& operator<<(ostream& os, Hotel&);
    friend istream& operator>>(istream& is, Hotel&);
    //string to_string();
    //static Hotel from_string(char*);
};


#endif //LAB9_10_HOTEL_H
