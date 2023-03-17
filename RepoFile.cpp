#include "RepoFile.h"
#include "Repository.h"
#include "Date.h"
#include <fstream>


/*
RepoFile::RepoFile():Repository() {}


RepoFile::RepoFile( char* fis):Repository() {
    this->fisier = fis;
    ifstream f(fisier);
    while (!f.eof()) {
        int cod;
        char* nume = new char[100];
        char* oras = new char[100];
        Date dataInceput;
        Date dataFinal;
        f>> cod>>nume>>oras>>dataInceput>>dataFinal;
        Hotel h(cod, nume, oras, dataInceput, dataFinal);
        elems.push_back(h);
        delete[]nume;
        delete[]oras;
    }
    f.close();
}


void RepoFile::savetoFile() {
    ofstream f(fisier);
    int i=0;
    for (Hotel& h : elems) {
        f << elems[i].get_cod() << " "<<elems[i].get_nume()<<" "<<elems[i].get_oras()<<" "<< elems[i].get_data_inc()<< " "<< elems[i].get_data_sf()<< endl;
    }
    f << elems[i].get_cod() << " "<<elems[i].get_nume()<<" "<<elems[i].get_oras()<<" "<< elems[i].get_data_inc()<< " "<< elems[i].get_data_sf()<< endl;

    f.close();
}



int RepoFile::adaugare(Hotel &h) {
    elems.push_back(h);
    this->savetoFile();
}

vector<Hotel> RepoFile::getAll() {
    return elems;
}

RepoFile& RepoFile::operator=(RepoFile &r) {
    if(this != &r)
    {
        Repository::operator=(r);
        if(this->fisier)
            delete[] this->fisier;
        this->fisier = new char[strlen(r.fisier) + 3];
        strcpy_s(this->fisier, strlen(r.fisier) + 1, r.fisier);
    }
    return *this;
}

RepoFile::~RepoFile() {}*/


RepoInFile::RepoInFile(){

}
void RepoInFile::adaugare(Hotel &hot) {
    Repository::adaugare(hot);
    saveToFile();
}
void RepoInFile::stergere(Hotel& h) {
    Repository::stergere(h);
    saveToFile();
}
void RepoInFile::modificare(Hotel& v, Hotel& n){
    Repository::modificare(v, n);
    saveToFile();
}
Hotel *RepoInFile::get_All() {
    return Repository::get_All();
}
void RepoInFile::clearFile() {
    ofstream f(this->fileName);
    f<<"";
}
void RepoInFile::saveToFile() {
    if(!this->fileName.empty()){
        ofstream f(this->fileName);
        for(int i=0;i<this->get_size();i++){
            f<<this->get_All()[i];
        }
        f.close();
    }
}
void RepoInFile::set_repo(string &filename) {
    this->fileName=filename;
}
void RepoInFile::loadFile() {
    if(!this->fileName.empty()){
        ifstream f(this->fileName);
        string Str_cod_unic;
        int cod_unic;
        string Str_nume_hotel;
        string nume_hotel;
        string Str_nume_oras;
        string nume_oras;
        string Str_inceput;
        Date inceput;
        string Str_final;
        Date final;
        while(!f.eof())
        {
            f>>Str_cod_unic;f.get();f>>cod_unic;
            f>>Str_nume_oras>>nume_oras;
            f>>Str_nume_hotel>>nume_hotel;
            f>>Str_inceput>>inceput;
            f>>Str_final>>final;
            bool ok= false;
            for(int i=0; i<this->get_size();i++){
                if(this->get_All()[i].get_cod()==cod_unic){ok= true;}
            }
            if(!ok){
                Hotel hotel(cod_unic, nume_hotel, nume_oras, inceput, final);
                this->adaugare(hotel);
            }
        }
        f.close();
    }
}