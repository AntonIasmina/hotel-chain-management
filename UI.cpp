
#include "UI.h"
#include "RepoFile.h"
#include <iostream>
using namespace std;


UI::UI() {
    RepoInFile repo;
    this->repository = repo;

    Service service_1;
    service_1.setRepo("hot.txt");
    this->sv = service_1;
}
UI::UI(RepoInFile &repo, Service &service)
{   this->repository = repo;
    this->sv = service;
    this->sv.setRepo("Hotel.txt");
}

//UI::~UI(){}

void UI::show_menu()
{
    cout << "1.Adaugare " << endl;
    cout << "2.Afisare " << endl;
    cout << "3.Stergere " << endl;
    cout << "4.Modificare " << endl;
    cout << "4.Afisam toate hotelurile dupa oras " << endl;
    cout << "5.Afisam toate cazarile ce au hotelul in orasul dorit si are rezervare disponibila" << endl;
    cout << "in perioada dorita sau o perioada in interval de +/+-3zile distanta" << endl;
    //cout << "6.Afisarea numarului total de cazari" << endl;
    //cout << "7.Cazarile curente" << endl;
    cout << "0.Iesire" << endl;
}
void UI::show_all()
{
    for(int i = 0; i < this->sv.lungime(); i++)
        cout << sv.read()[i] << " " <<endl;
    cout << endl;
}

/*
void UI::numar_entitati()
{
    cout << "Numarul de entitati este: " << this->sv.get_nr_elem() << endl;
}*/

void UI::adaugare()
{
    for (int i = 0; i < sv.lungime(); i++)
        cout << sv.read()[i] << " " << endl;
    cout << endl;
}

void UI::stergere()
{
    Hotel hotel_a;
    cin >> hotel_a;
    sv.sterge(hotel_a);
}
void UI::modificare()
{
    Hotel hotel_old, hotel_new;
    cout << "Citire Hotel pe care vreti sa l actualizati: ";
    cin >> hotel_old;
    cout << "Citire noile date ale hotelului: ";
    cin >> hotel_new;
    sv.modifica(hotel_old, hotel_new);
}
void UI::cautare_hotele()
{
    cout << endl;
    string oras;
    cout << "Introduceti numele Orasului : ";
    cin >> oras;
    sv.cauta_hotel_oras(oras);
}
void UI::cautare_hotele_oras_1()
{
    cout << endl;
    string oras;
    int lungime = 0;
    cout << "Introduceti numele Orasului : ";
    cin >> oras;
    Hotel *lst = sv.cauta_hotel_oras_1(oras, lungime);
    for (int i = 0; i < lungime; i++)
        cout << lst[i] << endl;
}

void UI::rezervari() {
    cout << endl;
    string oras;
    Date data_inceputt, data_finall;
    cout << "Introduceti numele orasului in care doriti sa rezervati un hotel:";
    cin >> oras;
    cout << "Introduceti data de inceput: ";
    cin >> data_inceputt;
    cout << "Introduceti data finala: ";
    cin >> data_finall;
    int lungime = 0;
    Hotel *lst = sv.rezervare(oras, data_inceputt, data_finall, lungime);
    if (lungime == 0)
        cout << "Nu exista rezervari!";
    else {
        int option = -1;
        int ok = 0;
        while (option != lungime && ok == 0) {
            for (int i = 0; i < lungime; i++)
                cout << i << ") " << lst[i].get_nume() << endl << " Data inceput: " << lst[i].get_data_inc()
                     << " Data final : "
                     << lst[i].get_data_inc() << endl;
            cin >> option;
            if (option > lungime)
                cout << "Hotel invalid!";
            else
                for (int i = 0; i < lungime; i++)
                    if (option == i) {
                        sv.update_data(lst[i], data_inceputt, data_finall);
                        ok = 1;
                    }
        }


    }

}


void UI::run_menu()
{
    show_menu();
    int optiune;
    cout << "Introduceti optiunea: " << endl;
    cin >> optiune;
    while (optiune) {
        switch (optiune) {
            case 1:
                adaugare();
                break;
            case 2:
                show_all();
                break;
            case 3:
                stergere();
                break;
            case 4:
                modificare();
                break;
            case 5:
                cautare_hotele();
                break;
            case 6:
                rezervari();
                break;
            default:
                cout << "Comanda invalida !" << endl;
        }
        show_menu();
        cout << "Introduceti optiunea: " << endl;
        cin >> optiune;
    }
}