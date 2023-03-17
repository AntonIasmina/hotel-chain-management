#ifndef MAIN_CPP_UI_H
#define MAIN_CPP_UI_H
#include "Service.h"
#include "Repository.h"
#include "Hotel.h"
#include <iostream>
#include <string>
using namespace std;
class UI{
private:
    Service sv;
    Repository repository;
    void adaugare();
    void stergere();
    void modificare();
    //void numar_entitati();
    void cautare_hotele();
    void cautare_hotele_oras_1();
    void rezervari();
    void show_all();
public:
    UI();
    UI(RepoInFile&, Service &);
    void show_menu();
    void run_menu();
    //~UI();
};
#endif //MAIN_CPP_UI_H
