
#include "Teste.h"
#include "RepoFile.h"
#include <iostream>
#include <cassert>
using namespace std;
/*
void Teste::teste_entitate()
{
    cout << "Teste pentru entitate:" << endl;
    Hotel b;
    assert(b.get_cod() == 0);
    assert(b.get_nume()=="nimic");///datele initiale sunt bune

    Date s1 = {1, 1, 1};
    Date s2 = {2, 2, 2};
    assert(Date::from_string(s1.to_string()).luna == s1.luna);
    Hotel b1(1, "Ozana", "Bistrita", s1, s2);
    assert(b1.get_data_inc().zi == 1);
    assert(b1.get_data_inc().luna == 1);
    assert(b1.get_data_inc().an == 1);
    assert(b1.get_data_sf().zi == 2);
    assert(b1.get_oras()== "Bistrita");
    Date s1_nume = {3, 3, 3};
    b1.set_data_inc(s1_nume);///Schimbam nuumele
   // assert(b1.get_data_inc().zi == 3);
    //assert(b1.get_data_inc().luna == 3);
    //assert(b1.get_data_inc().an == 3);///Numele s a setat cu succes!

    Hotel b2 = b1;
    assert(b2.get_data_sf() == b1.get_data_sf());
    assert(b2.get_cod() == b1.get_cod());///se copiaza bine parametrii
    assert(b2 == b1);
    assert(b2 != b);///Operatii == si != merg su cucces

    b2.set_cod(3);
    assert(b2.get_cod() == 3);
    b2.set_oras("Vaslui");
    assert(b2.get_oras()== "Vaslui");
    b2.set_nume("monopoly");
    assert(b2.get_nume()== "monopoly");

    assert(Hotel::from_string(b2.to_string()) == b2);
    assert(Hotel::from_string(b1.to_string()) == b1);
    assert(Hotel::from_string(b.to_string()) == b);
    cout << "Testele pentru entitate sunt ok!" << endl;
}
void Teste::teste_repository_live()
{
    cout << "Teste repository live:" << endl;
    Repository r;
    assert(r.get_size() == 0);///Nu avem elemente initial
    Date s1 = {1, 1, 1};
    Date s2 = {2, 2, 2};
     b1(1, "Ozana", "Bistrita", s1, s2);
    r.adaugare(b1);
    assert(r.get_size() == 1);
    assert(r.get_All()[0] == b1);///Entitatea s a adaugat succes
    r.adaugare(b1);
    assert(r.get_size() == 1);///Nu se poate adauga iar b1, FIINDCA SE REPETA CODUL UNIC
    cout << "Testele pentru repository live sunt ok!" << endl;
}
void Teste::teste_repository_tema()
{
    cout << "Teste repository tema:" << endl;
    Repository r;
    Date s1 = {1, 1, 1};
    Date s2 = {2, 2, 2};
    Date s3 = {11, 1, 2012};
    Date s4 = {11, 11, 2020};
    Hotel b1(1, "Ozana", "Bistrita", s1, s2);
    r.adaugare(b1);
    assert(r.get_size() == 1);
    Hotel b2(2, "metropolis", "Bistrita", s1, s2);
    Hotel b3(5, "Fagaras", "Monor", s3, s4);
    Hotel b4(6, "metropolis", "Bistrita", s1, s2);
    r.adaugare(b2);
    r.adaugare(b3);
    r.adaugare(b4);
    assert(r.get_size() == 4);
    assert(r.stergere(1) == 1);///S a sters cu succes primul Booking!
    assert(r.get_size() == 3);
    assert(r.stergere(b1.get_cod()) == 0);///B1 nu mai exista!
     b1_new(1, "LaMinuta", "Bistrita", s1, s2);
    assert(r.modificare(b1_new) == 0);///Nu avem cum sa modificam FIINDCA AM STERS PE b1
    assert(r.adaugare(b1) == 1);///Nu mai exista alt booking cu acest id
    assert(r.modificare(b1_new) == 1);///Acum putem modifica!
    cout << "Testele pentru repository tema sunt ok!" << endl;
}
void Teste::teste_service_tema()
{
    cout << "Metodele tema si una live pentru service:" << endl;
    Repository r;
    Service sv(r);
    Date s1 = {1, 1, 1};
    Date s1_close = {4, 1, 1};
    Date s1_after = {7, 1, 1};
    Date s2 = {2, 2, 2};
    Date s3 = {11, 1, 2012};
    Date s4 = {11, 11, 2020};
    Hotel b1_new(1, "LaMinuta", "Bistrita", s1, s2);
    Hotel b2(2, "metropolis", "Bistrita", s1, s2);
    Hotel b3(5, "Fagaras", "Monor", s3, s4);
    Hotel b4(6, "metropolis", "Bistrita", s1, s2);
    sv.add(1, "LaMinuta", "Bistrita", s1, s2);
    assert(sv.get_nr_elem() == 1);///S a adaugat cu succes elementul!
    assert(sv.get_elems()[0] == b1_new);
    assert(sv.add(1, "LaMinuta", "Bistrita", s1, s2) == 0);///Elementul a fost deja adaugat!
    assert(sv.add(2, "metropolis", "Bistrita", s1, s2) == 1);
    sv.add(5, "Fagaras", "Monor", s3, s4);
    sv.add(6, "metropolis", "Bistrita", s1, s2);

    assert(sv.get_nr_elem() == 4);
    assert(sv.del(1) == 1);///S a sters cu succes elementul!
    assert(sv.del(1) == 0);///Acum nu il mai putem sterge!
    assert(sv.get_nr_elem() == 3);
    assert(sv.get_elems()[0] == b2);///b2 e acum primul booking

    assert(sv.modify(1, "LaMinuta", "Bistrita", s1, s2) == 0);///NU il putem Modifica; Acest booking fu STERS!
    assert(sv.add(1, "LaMinuta", "Bistrita", s1, s2) == 1);
    assert(sv.modify(1, "LaRaul", "Bistrita", s3, s3) == 1);///ACUM PUTEM!

    Service sv_nou;
    sv_nou = sv;
    assert(sv_nou.get_nr_elem() == sv.get_nr_elem());///MERGE ATRIBUIREA!
    vector<Hotel> hotele = sv.search_after_oras("Bistrita");
    assert(hotele.size() == 3);///Avem 3 hoteluri Bistrita
    assert(hotele[0] == Hotel(2, "metropolis", "Bistrita", s1, s2));///Primul hotel!
    sv.add(33, "LaRaul", "Magulesti", s3, s3);
    hotele = sv.search_after_oras("LaRaul");
    assert(hotele.capacity() == 0);///Nu avem hoteluri cu acest nume!
    vector<Hotel> oferte;
    oferte = sv.search_booking_oras_perioada("Municipiu", s1, s2);
    assert(oferte.size() == 0);///NU AVEM, nici hoteluri dorite nici sugerate
    oferte = sv.search_booking_oras_perioada("Bistrita", s1, s2);
    assert(oferte.size() == 2);
    assert(oferte.at(0) == b2);

    Repository rnew;
    Service s_new(rnew);
    s_new.add(1, "1", "D", s1, s1);
    s_new.add(2, "Minuta", "D", s1, s1_close);
    s_new.add(3, "Dolhi", "D", s1_after, s1_close);
    s_new.add(4, "Ioo", "D", s1_after, s2);
    oferte = s_new.search_booking_oras_perioada("D", s1_close, s1_after);
    assert(oferte.size() == 2);
    assert(oferte.at(0) == Hotel(4, "Ioo", "D", s1_after, s2));///Ne ducem cu 3 zile la stanga
    oferte = s_new.search_booking_oras_perioada("D", s1, s1);
    cout << oferte.size() << endl;
    cout << oferte.at(0) << oferte.at(1) << endl;
    assert(oferte.size() == 2);///Avem Doua hoteluri DORIT(cel cu cod 1 si cod 2:[s1, s1] si [s1, s4]
    assert(oferte.at(0) == Hotel(1, "1", "D", s1, s1));
    oferte = s_new.search_booking_oras_perioada("D", s1_close, s2);
    assert(oferte.size() == 0);
    cout << "Metodele tema si una live pentru service sunt bune!" << endl;
}

void test_repoFile(){
    RepoFile repFile("hotel.txt");
    repFile.savetoFile();
    Service serv2( &RepoFile);
    cout << "repo txt  " << service.ge()[0]->toString() << endl;
}
 */