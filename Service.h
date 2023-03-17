
#ifndef MAIN_CPP_SERVICE_H
#define MAIN_CPP_SERVICE_H
#include "Repository.h"
#include "RepoFile.h"
#include "Hotel.h"
class Service{
private:
    //Repository repo;
    RepoInFile repo;
    //bool verify_period(Date inceput1, Date sfarsit1, Date inceput2, Date sfarsit2);
public:
    Service();

    //Service(RepoInFile &);

    void setRepo(string);

    Hotel* read();

    void adauga(Hotel& );

    void sterge(Hotel& );

    void modifica(Hotel& ,Hotel& );

    void cauta_hotel_oras(string Oras);

    Hotel *cauta_hotel_oras_1(const string &Oras, int &lungime);

    Hotel *rezervare(string, Date, Date, int&);

    void update_data(Hotel &h, Date dataInceput, Date dataFinal);

    int lungime();

    //int get_nr_elem();

    //vector<Hotel> get_elems();
    //vector<Hotel> search_after_oras(string );
    //vector<Hotel> search_booking_oras_perioada(string , Date&, Date&);
    //Service& operator=(Service &);
    ~Service();
};
#endif //MAIN_CPP_SERVICE_H