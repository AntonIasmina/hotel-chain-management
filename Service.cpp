
#include "Service.h"
#include "MyException.h"
#include "RepoFile.h"

Service::Service() {

}

/*
Service::Service(RepoInFile &r)
{
    this->repo = r;
}

bool Service::verify_period(Date inceput1, Date sfarsit1, Date inceput2, Date sfarsit2)
{
    if(inceput1 > sfarsit1)
        return false;
    if(inceput2 > sfarsit2)
        return false;
    if(inceput1 < inceput2)
        return false;
    if(sfarsit1 > sfarsit2)
        return false;
    return true;
}
int Service::get_nr_elem()
{
    return this->repo.get_size();
}
*/


void Service::setRepo(string filename) {
    this->repo.set_repo(filename);
}

Hotel *Service::read() {
    return repo.get_All();
}

void Service::adauga(Hotel &h)
{
    //Hotel h(cod, nume, oras, inceput, sfarsit);
    repo.adaugare(h);
}

void Service::sterge(Hotel &h)
{
    repo.stergere(h);
}
void Service::modifica(Hotel &v, Hotel &n)
{
    repo.modificare(v,n);
}

int Service::lungime() {
    return repo.get_size();
}

void Service::cauta_hotel_oras(string Oras) {
    for (int i = 0; i < repo.get_size(); i++)
        if (repo.get_All()[i].get_oras() == Oras)
            cout << repo.get_All()[i] << endl;
}

Hotel *Service::cauta_hotel_oras_1(const string &Oras, int &lungime) {
    Hotel *lst = new Hotel[20];
    int j = 0;
    for (int i = 0; i < repo.get_size(); i++)
        if (repo.get_All()[i].get_oras() == Oras)
            lst[j] = repo.get_All()[i], j++;
    lungime = j;
    return lst;
}


void Service::update_data(Hotel &h, Date dataInceput, Date dataFinal) {
    Hotel temp;
    temp = h;
    if(h.get_data_inc() == dataInceput && dataFinal <=h.get_data_sf())
        temp.set_data_inc(dataFinal.getZi() +1),repo.modificare(h,temp);
    else if(h.get_data_inc() <= dataInceput && dataFinal ==h.get_data_sf())//ikkk
        temp.set_data_inc(dataInceput.getZi() -1),repo.modificare(h,temp);
    else if (h.get_data_inc() <= dataInceput && dataFinal <=h.get_data_sf() )
        temp.set_data_sf(dataInceput.getZi()), repo.modificare(h, temp);
    else if (dataFinal.getZi() <= h.get_data_inc().getZi())
        temp.set_data_inc(h.get_data_inc().getZi() + (dataFinal.getZi() - dataInceput.getZi()) +1),repo.modificare(h,temp);
    else if(dataInceput.getZi()>=h.get_data_sf().getZi())
        temp.set_data_sf(h.get_data_sf().getZi()-(dataFinal.getZi()-dataInceput.getZi())-1),repo.modificare(h,temp);
    else if(dataInceput.getZi()<=h.get_data_inc().getZi() && dataFinal.getZi()>=h.get_data_inc().getZi())
        temp.set_data_inc(h.get_data_inc().getZi() + (dataFinal.getZi() - dataInceput.getZi()) +1),repo.modificare(h,temp);
    else if(dataInceput.getZi()<=h.get_data_sf().getZi() && dataFinal.getZi()>=h.get_data_sf().getZi())
        temp.set_data_sf(h.get_data_sf().getZi()-(dataFinal.getZi()-dataInceput.getZi())-1),repo.modificare(h,temp);
}


Hotel *Service::rezervare(string oras, Date data_inceput, Date data_sfarist, int &lungime) {
    Hotel *lst = new Hotel[30];
    Hotel *lst_2 = new Hotel[30];
    Hotel *lst_3 = new Hotel[30];
    int interval_user = data_sfarist.getZi() - data_inceput.getZi();
    int j = 0;
    int k = 0;
    int l = 0;
    for (int i = 0; i < repo.get_size(); i++) {
        int interval_hotel =
                repo.get_All()[i].get_data_sf().getZi() - repo.get_All()[i].get_data_inc().getZi();
        if (repo.get_All()[i].get_oras() == oras && repo.get_All()[i].get_data_sf() >= data_inceput &&
            repo.get_All()[i].get_data_inc() <= data_sfarist &&
            interval_user <= interval_hotel
                ) {
            lst[j] = repo.get_All()[i];
            j++;
        } else if (repo.get_All()[i].get_oras() == oras &&
                   interval_user <= interval_hotel &&
                   (repo.get_All()[i].get_data_inc().getZi() - data_inceput.getZi() <= 3)
                ) {
            lst_2[k] = repo.get_All()[i];
            k++;
        } else if (repo.get_All()[i].get_oras() == oras &&
                   interval_user <= interval_hotel &&
                   (data_sfarist.getZi() - repo.get_All()[i].get_data_sf().getZi() <= 3)) {
            lst_3[l] = repo.get_All()[i];
            l++;
        }
    }
    if (j != 0) {
        lungime = j;
        return lst;
    } else if (k != 0) {
        lungime = k;
        return lst_2;
    } else if (l != 0) {
        lungime = l;
        return lst_3;
    } else
        lungime = 0;
    return lst;
}

/*
vector<Hotel> Service::get_elems()
{
    return this->repo.get_All();
}
vector<Hotel> Service::search_after_oras(string oras)
{
    vector<Hotel> hotele_dorite;
    for(int i = 0; i < this->get_nr_elem(); i++)
        if(this->get_elems()[i].get_oras()==oras)
            hotele_dorite.push_back(this->get_elems()[i]);
    return hotele_dorite;
}
vector<Hotel> Service::search_booking_oras_perioada(string oras, Date &begin, Date &end)
{
    vector<Hotel> hoteluri_oras;
    for(int i = 0; i < this->get_nr_elem(); i++)
        if(this->get_elems()[i].get_oras()==oras)
            hoteluri_oras.push_back(this->get_elems()[i]);
    vector<Hotel> hoteluri_dorite;
    for(int i = 0; i < hoteluri_oras.size(); i++)
        if(verify_period(begin, end, hoteluri_oras[i].get_data_inc(), hoteluri_oras[i].get_data_sf()))
            hoteluri_dorite.push_back(hoteluri_oras[i]);
    if(!hoteluri_dorite.empty())
    {
        return hoteluri_dorite;
    }
    if(hoteluri_dorite.empty())
    {
        vector<Hotel> hoteluri_sugerate;
        Date new_begin = begin.bigger_with_3_days();
        Date new_end = end.bigger_with_3_days();
        for(int i = 0; i < hoteluri_oras.size(); i++)
            if(verify_period(new_begin, new_end,hoteluri_oras[i].get_data_inc(), hoteluri_oras[i].get_data_sf()))
                hoteluri_sugerate.push_back(hoteluri_oras[i]);
        new_begin = begin.lower_with_3_days();
        new_end = end.lower_with_3_days();
        for(int i = 0; i < hoteluri_oras.size(); i++)
            if(verify_period(new_begin, new_end,hoteluri_oras[i].get_data_inc(), hoteluri_oras[i].get_data_sf()))
                hoteluri_sugerate.push_back(hoteluri_oras[i]);
        return hoteluri_sugerate;
    }
}*/
Service::~Service() {}