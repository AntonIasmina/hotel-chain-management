#ifndef LAB9_10_REPOFILE_H
#define LAB9_10_REPOFILE_H

#include "Repository.h"
#include "RepoFile.h"
#include <bits/stdc++.h>
#include <fstream>
#include <cstring>
#include <vector>
#include "Date.h"

using namespace std;

class RepoInFile: public Repository{
private:
    string fileName;
public:
    explicit RepoInFile();
    void set_repo(string& filename);
    void adaugare(Hotel& hot);
    void stergere(Hotel&);
    void modificare(Hotel& v, Hotel& n);
    Hotel* get_All();
    void loadFile();
    void saveToFile();
    void clearFile();
    /*
    RepoFile();
    RepoFile(char *);
    void savetoFile();
    int adaugare(Hotel& h);
    int size();
    vector<Hotel> getAll();
    RepoFile& operator=(RepoFile &r);
    ~RepoFile();*/
};


#endif //LAB9_10_REPOFILE_H
