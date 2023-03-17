
#include "Hotel.h"
#include <iostream>
using namespace std;
Hotel::Hotel() {
    this->cod = 0;
    this->nume= "nimic";
    this->oras= "nimic";
    this->dataInceput.setDate(1,1,2022);
    this->dataFinal.setDate(1,1,2022);
    //this->dataInceput = dataInceput;
    //this->dataInceput.luna = 1;
    //this->dataInceput.an = 1;
    //this->dataFinal = dataFinal;
    //this->dataFinal.luna = 1;
    //this->dataFinal.an = 1;
}
Hotel::Hotel(int cod, string nume, string oras, Date data_inc, Date data_sf) {
    this->cod = cod;
    this->nume = nume;
    this->oras = oras;
    this->dataInceput = data_inc;
    this->dataFinal = data_sf;
}
/*
Hotel::Hotel(const Hotel &h) {
    this->cod = h.cod;
    this->nume = h.nume;
    this->oras = h.oras;
    this->dataInceput = h.dataInceput;
    this->dataFinal = h.dataFinal;
}*/

int Hotel::get_cod() {
    return this->cod;
}
string Hotel::get_nume() {
    return this->nume;
}
string Hotel::get_oras() {
    return this->oras;
}
Date Hotel::get_data_inc() {
    return this->dataInceput;
}
Date Hotel::get_data_sf() {
    return this->dataFinal;
}
/*
void Hotel::set_cod(int cod) {
    this->cod = cod;
}
void Hotel::set_nume(string nume) {
    this->nume = nume;
}
void Hotel::set_oras(string oras) {
    this->oras=oras;
}*/
void Hotel::set_data_inc(int dataInceput) {
    this->dataInceput.setZi(dataInceput);
}
void Hotel::set_data_sf(int dataFinal) {
    this->dataFinal.setZi(dataFinal);
}
Hotel& Hotel::operator=(const Hotel &h) {
    if(this != &h)
    {
        this->cod = h.cod;
        this->nume = h.nume;
        this->oras = h.oras;
        this->dataInceput = h.dataInceput;
        this->dataFinal = h.dataFinal;
    }
    return *this;
}

bool Hotel::operator==(const Hotel &S) {
    return ((this->cod == S.cod) && (this->nume==S.nume)
            && (this->oras==S.oras) && (this->dataInceput == S.dataInceput)
            && (this->dataFinal == S.dataFinal));
}
bool Hotel::operator!=(const Hotel &S) {
    //return !(*this == h);
    return ((this->cod != S.cod) || (this->nume!=S.nume)
            || (this->oras!=S.oras) || (this->dataInceput != S.dataInceput)
            || (this->dataFinal != S.dataFinal));

}
ostream& operator<<(ostream& os, Hotel &h)
{
    os << "Codul cazarii este: " << h.cod << endl;
    os << "Numele hotelui cazarii este: " << h.nume << endl;
    os << "Orasul hotelului cazarii este: " << h.oras << endl;
   // h.dataInceput.is_ui = true;
   // h.dataFinal.is_ui = true;
    os << "Pentru data_Inceput_Disponibilitate: " << endl << h.dataInceput << endl;
    os << "Pentru data_Sfarsit_Disponibilitate: " << endl << h.dataFinal << endl;
    //h.dataInceput.is_ui = false;
    //h.dataFinal.is_ui = false;
    return os;
}
istream& operator>>(istream &is, Hotel &h)
{
    cout << "Dati codul cazarii aici: ";
    is >> h.cod;
    cout << endl;
    cout << "Dati numele cazarii aici: ";
    is >> h.nume;
    cout << endl;
    cout << "Dati orasul cazarii aici: ";
    is >> h.oras;
    cout << endl;
    cout << "Pentru data_Inceput_Disponibilitate, avem:" << endl;
    //h.dataInceput.is_ui = true;
    is >> h.dataInceput;
    //h.dataInceput.is_ui = false;
    cout << "Pentru data_Sfarsit_Disponibilitate, avem:" << endl;
    //h.dataFinal.is_ui = true;
    is >> h.dataFinal;
    //h.dataFinal.is_ui = true;
    return is;
}

/*
Hotel Hotel::from_string(char* s) {
    Hotel b;
    istringstream is(s);
    is>>b.cod>>b.nume>>b.oras>>b.dataInceput>>b.dataFinal;
    return b;
}*/