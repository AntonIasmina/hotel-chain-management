#include "Repository.h"

Repository::Repository()
{
    this->lungime = 0;
    this->capacitate = 20;
    this->hotel = new Hotel[20];
}

Repository::Repository(const Repository &Repo) {
    this->capacitate = Repo.capacitate;
    this->lungime = Repo.lungime;
    this->hotel = new Hotel[this->capacitate];
    for (int i = 0; i < this->lungime; i++)
        this->hotel[i] = Repo.hotel[i];
}

void Repository::adaugare(const Hotel &h)
{
    this->hotel[lungime++] = h;
}


void Repository::stergere(Hotel& hoteluri)
{
    int i = 0, j = 0;
    Hotel *new_hotel = new Hotel[capacitate];
    while (i < lungime) {
        if (this->hotel[i] != hoteluri)
            new_hotel[j++] = hotel[i];
        i++;
    }
    delete[] this->hotel;
    this->lungime = j;
    this->hotel = new_hotel;
}
void Repository::modificare(Hotel &v, Hotel &n)
{
    for (int i = 0; i < lungime; i++)
        if (hotel[i] == v)
            hotel[i] = n;
}
Hotel *Repository::get_All() {
    return this->hotel;
}
int Repository::get_size() {
    return this->lungime;
}
/*
Repository& Repository::operator=(Repository &r)
{
    if(this != &r)
    {
        this->elems.resize(r.get_size());
        for(int i = 0; i < this->get_size(); i++)
            this->elems[i] = r.elems[i];
    }
    return *this;
}*/
//Repository::~Repository() {}