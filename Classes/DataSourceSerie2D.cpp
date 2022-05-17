#include <stdlib.h>
#include <iostream>
#include <string.h>
#include <fstream> 

using namespace std;
#include "DataSourceSerie2D.h"

// ------ CONSTRUCTORS
DataSourceSerie2D::DataSourceSerie2D()
{
    #ifdef DEBUG
        cout << "Constructeur par défaut de DataSourceSerie2D" << endl;
    #endif

}
DataSourceSerie2D::DataSourceSerie2D(const char* nom, const char* sujet1, const char* sujet2, int type1, int type2, int effTotal, Liste<Data2D> listeData)
    :DataSource::DataSource(nom, sujet1, effTotal, type1)
{
    #ifdef DEBUG
        cout << "Constructeur d'init de DataSourceSerie2D" << endl;
    #endif

        setSujet2(sujet2);
        setType2(type2);
        setListe(listeData);
}

DataSourceSerie2D::~DataSourceSerie2D()
{
    #ifdef DEBUG
        cout << "Destructeur de DataSourceSerie2D" << endl;
    #endif

}


// ----- SETTERS // GETTERS

void DataSourceSerie2D::setSujet2(const char* intitule)
{
    if(_sujet2)
    {
        delete []_sujet2;
    }
    if(intitule)
    {
        _sujet2 = new char[strlen(intitule) + 1];
        strcpy(_sujet2,intitule);
        return;
    }
    _sujet2 = NULL;
}

void DataSourceSerie2D::setListe(Liste<Data2D> listeData)
{

    _listeData2D = listeData;
}
// ----- FONCTIONS

// ----- OPERATORS