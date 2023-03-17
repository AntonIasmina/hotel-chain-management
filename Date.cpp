#include "Date.h"
#include <iostream>
Date::Date()
{
}

Date::Date(int zi, int luna, int an)
{
    this->zi = zi;
    this->luna = luna;
    this->an = an;

}

void Date::setDate(int zi, int luna, int an)
{
    this-> an= an;
    this->zi = zi;
    this->luna = luna;
}

int Date::getZi() {
    return this->zi;
}

void Date::setZi(int zzi) {
    Date::zi = zzi;
}

int Date::getLuna() {
    return this->luna;
}

void Date::setLuna(int lluna) {
    Date::luna = lluna;
}

int Date::getAn() {
    return this->an;
}

void Date::setAn(int aan) {
    Date::an = aan;
}

bool Date::operator==(const Date &S) {
    return ((this->zi==S.zi)&&(this->luna==S.luna)&&(this->an==S.an));
}

Date &Date::operator=(const Date &S) {
    if (this != &S) {
        this->an = S.an;
        this->luna = S.luna;
        this->zi = S.zi;
    }
}

bool Date::operator!=(const Date &S) {
    return ((this->zi != S.zi) || (this->luna != S.luna) || (this->an != S.an));
}

bool Date::operator>=(const Date &S) {
    return ((this->zi >= S.zi) && (this->luna >= S.luna) && (this->an >= S.an));
}

bool Date::operator<=(const Date &S) {
    return ((this->zi <= S.zi) && (this->luna <= S.luna) && (this->an <= S.an));
}

/*
Date::Date(const Date& d)
{
    this->zi = d.zi;
    this->luna = d.luna;
    this->an = d.an;
}*/

Date::~Date()
{}

istream& operator>>(istream &in, Date &d){
    cout << "Dati anul datei: ";
    in >> d.an;
    cout << endl;
    cout << "Dati luna datei: ";
    in >> d.luna;
    cout << endl;
    cout << "Dati ziua datei: ";
    in >> d.zi;
    cout << endl;
    return in;
}

ostream& operator<<(ostream &os, const Date &d){

    os << "Ziua datei este: " << d.zi << endl;
    os << "Luna datei este: " << d.luna << endl;
    os << "Anul datei este: " << d.an << endl;

    return os;
}

bool Date::operator>(const Date &data) {
    if(this->an > data.an)
        return true;
    if(this->an == data.an)
    {
        if (this->luna > data.luna)
            return true;
        if (this->luna == data.luna)
            if (this->zi < data.zi)
                return true;
    }
    return false;
}

bool Date::operator<(const Date &data) {
    if(this->an < data.an)
        return true;
    if(this->an == data.an)
    {
        if (this->luna < data.luna)
            return true;
        if (this->luna == data.luna)
            if (this->zi < data.zi)
                return true;
    }
    return false;
}
