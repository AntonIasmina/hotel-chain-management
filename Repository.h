
#ifndef LAB9_LIVE_REPOSITORY_H
#define LAB9_LIVE_REPOSITORY_H
#include "Hotel.h"
#include "Date.h"
#include <vector>
#include <algorithm>
using namespace std;
class Repository{
protected:
    //vector<Hotel> elems;
    int lungime;
    int capacitate;
    Hotel* hotel;
public:
    Repository();
    Repository(const Repository &);
    void adaugare(const Hotel &);
    virtual void stergere(Hotel&);
    virtual void modificare(Hotel&, Hotel&);
    int get_size();
    Hotel* get_All();
    //Repository& operator=(Repository &r);
    //virtual ~Repository();
};
#endif //LAB9_LIVE_REPOSITORY_H
