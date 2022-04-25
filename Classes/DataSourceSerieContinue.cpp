#include <stdlib.h>
#include <iostream>
#include <string.h>
#include <fstream> 

using namespace std;
#include "DataSourceSerieContinue.h"
#include "Iterateur.h"

// ------ CONSTRUCTORS
DataSourceSerieContinue::DataSourceSerieContinue()
    :DataSource::DataSource()
{
    #ifdef DEBUG
        cout << "Constructeur par défaut de DataSourceSerieContinue" << endl;
    #endif
        _listeData1D->setTete(NULL);
}

DataSourceSerieContinue::DataSourceSerieContinue(const char* nom, const char* sujet, int eff, int type, Liste<Data1D> *listeData)
    :DataSource::DataSource(nom, sujet, eff, type)
{
    #ifdef DEBUG
        cout << "Constructeur d'init de DataSourceSerieContinue" << endl;
    #endif
        _listeData1D = listeData;

        int tmp;
        cout << "Début de l'Intervalle : ";
        cin >> tmp;
        _debut = tmp;
        
        cout << "Taille de l'Intervalle : ";
        cin >> tmp;
        _intervalle = tmp;

}

DataSourceSerieContinue::~DataSourceSerieContinue()
{
    #ifdef DEBUG
    cout << "Destructeur de DataSourceSerieContinue'" << endl; 
    #endif
}

// ----- SETTERS // GETTERS

// ----- FONCTIONS

void DataSourceSerieContinue::afficheListe()
{
    Affiche();//afiche dataSource
    _listeData1D->Affiche();//affiche les data1D
    cout << "Debut :" << _debut << endl;
    cout << "Intervalle :" << _intervalle << endl;
}
// ----- OPERATORS