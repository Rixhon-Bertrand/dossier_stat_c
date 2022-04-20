#include <stdlib.h>
#include <iostream>
#include <string.h>
#include <fstream> 

using namespace std;
#include "DataSourceSerieDiscrete.h"
#include "Iterateur.h"

// ------ CONSTRUCTORS
DataSourceSerieDiscrete::DataSourceSerieDiscrete()
{
    #ifdef DEBUG
        cout << "Constructeur par défaut de DataSourceSerieDiscrete" << endl;
    #endif
        _listeData1D->setTete(NULL);
}

DataSourceSerieDiscrete::~DataSourceSerieDiscrete()
{
    #ifdef DEBUG
    cout << "Destructeur de DataSourceSerieDiscrete'" << endl; 
    #endif
}


// ----- SETTERS // GETTERS

// ----- FONCTIONS

void DataSourceSerieDiscrete::pushListe(float val, int eff)
{
    _listeData1D->insere(Data1D(val, eff));
}

void DataSourceSerieDiscrete::afficheListe()
{
    _listeData1D->Affiche();
}

// ----- OPERATORS
