
#ifndef INC_9_10LAB_DATE_H
#define INC_9_10LAB_DATE_H
#include <iostream>
using namespace std;

class Date {
protected:
    int zi;
    int luna;
    int an;
    //bool is_ui = false;

public:
    Date();

    Date(int zi, int luna, int an);

    void setDate(int zi, int luna, int an);

    int getZi();

    void setZi(int);

    int getLuna();

    void setLuna(int);

    int getAn();

    void setAn(int);

    //Date (const Date& d);
    //bool is_ui =false;

    Date& operator=(const Date&);

    bool operator==(const Date&);

    bool operator<(const Date&);

    bool operator>(const Date&);

    bool operator!=(const Date &);

    bool operator<=(const Date &);

    bool operator>=(const Date &);

    ~Date();

    friend istream& operator>>(istream &in, Date &d);

    friend ostream& operator<<(ostream &os, const Date &d);
    /*
    Date bigger_with_3_days()
    {
        Date result = *this;
        if(this->luna == 1 || this->luna == 3 || this->luna == 5 || this->luna == 7 || this->luna == 8 || this->luna == 10)
        {
            if(this->zi + 3 <= 31)
            {
                result.zi = this->zi + 3;
                return result;
            }
            if(this->zi + 3 > 31)
            {
                result.zi = this->zi + 3 - 31;
                result.luna++;
                return result;
            }
        }
        if(this->luna == 4 || this->luna == 6 || this->luna == 9 || this->luna == 11)
        {
            if(this->zi + 3 <= 30)
            {
                result.zi = this->zi + 3;
                return result;
            }
            if(this->zi + 3 > 30)
            {
                result.zi = this->zi + 3 - 30;
                result.luna++;
                return result;
            }
        }
        if(this->luna == 2)
        {
            if(this->zi + 3 <= 28)
            {
                result.zi += 3;
                return result;
            }
            if(this->zi + 3 > 28)
            {
                result.zi = this->zi + 3 - 28;
                result.luna++;
                return result;
            }
        }
        if(this->luna == 12)
        {
            if(this->zi + 3 <= 31)
            {
                result.zi += 3;
                return result;
            }
            if(this->zi + 3 > 31)
            {
                result.zi = this->zi + 3 - 31;
                result.luna = 1;
                result.an++;
                return result;
            }
        }
    }
    Date lower_with_3_days()
    {
        Date result = *this;
        if(this->luna == 2 || this->luna == 4 || this->luna == 6 || this->luna == 8 || this->luna == 9 || this->luna == 11)
        {
            if(this->zi >= 4)
            {
                result.zi -= 3;
                return result;
            }
            if(this->zi <= 3)
            {
                result.zi -= 3;
                result.zi += 31;
                result.luna--;
                return result;
            }
        }
        if(this->luna == 5 || this->luna == 7 || this->luna == 10 || this->luna == 12)
        {
            if(this->zi >= 4)
            {
                result.zi -= 3;
                return result;
            }
            if(this->zi <= 3)
            {
                result.zi -= 3;
                result.zi += 30;
                result.luna--;
                return result;
            }
        }
        if(this->luna == 1) {
            if (this->zi >= 4)
            {
                result.zi -= 3;
                return result;
            }
            if (this->zi <= 3)
            {
                result.zi -= 3;
                result.zi += 31;
                result.luna = 12;
                result.an--;
                return result;
            }
        }
        if(this->luna == 3)
        {
            if(this->zi >= 4)
            {
                result.zi -= 3;
                return result;
            }
            if(this->zi <= 3)
            {
                result.zi -= 3;
                result.zi += 28;
                result.luna--;
                return result;
            }
        }
    }
*/
};

#endif //INC_9_10LAB_DATE_H
