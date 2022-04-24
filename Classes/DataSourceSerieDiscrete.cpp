#include <stdlib.h>
#include <iostream>
#include <string.h>
#include <fstream> 

using namespace std;
#include "DataSourceSerieDiscrete.h"
#include "Iterateur.h"

// ------ CONSTRUCTORS
DataSourceSerieDiscrete::DataSourceSerieDiscrete()
    :DataSource::DataSource()
{
    #ifdef DEBUG
        cout << "Constructeur par défaut de DataSourceSerieDiscrete" << endl;
    #endif
        _listeData1D->setTete(NULL);
}

DataSourceSerieDiscrete::DataSourceSerieDiscrete(const char* nom, const char* sujet, int eff, int type, Liste<Data1D> *listeData)
    :DataSource::DataSource(nom, sujet, eff, type)
{
    #ifdef DEBUG
        cout << "Constructeur d'init de DataSourceSerieDiscrete" << endl;
    #endif
        _listeData1D = listeData;
}

DataSourceSerieDiscrete::~DataSourceSerieDiscrete()
{
    #ifdef DEBUG
    cout << "Destructeur de DataSourceSerieDiscrete'" << endl; 
    #endif
}


// ----- SETTERS // GETTERS

// ----- FONCTIONS

void DataSourceSerieDiscrete::afficheListe()
{
    Affiche();//afiche dataSource
    _listeData1D->Affiche();//affiche les data1D
}

// ----- OPERATORS
