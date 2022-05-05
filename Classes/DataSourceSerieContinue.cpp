#include <stdlib.h>
#include <iostream>
#include <string.h>
#include <fstream> 
#include <cmath>

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

    int tmp;
    cout << "Début de l'Intervalle : ";
    cin >> tmp;
    _debut = tmp;
    
    cout << "Taille de l'Intervalle : ";
    cin >> tmp;
    _intervalle = tmp;

    //convertir la liste par rapport au valeur entree
    setListe(listeData);

    _listeData1D->Affiche();

}

DataSourceSerieContinue::~DataSourceSerieContinue()
{
    #ifdef DEBUG
    cout << "Destructeur de DataSourceSerieContinue'" << endl; 
    #endif
}

// ----- SETTERS // GETTERS

void DataSourceSerieContinue::setListe(Liste<Data1D> *listeData)
{
    Liste<Data1D> *listeFinale = new Liste<Data1D>();
    cout << "setliste" << endl;
    for(int i = 0; i < listeData->getNombreElements(); i++)
    {
        
        if(_debut <= listeData->getElement(i).getVal())
        {
            cout << "val = "<<listeData->getElement(i).getVal() <<endl;
            float debutIntervalle = listeData->getElement(i).getVal();
            cout << "debutIntervalle = "<<debutIntervalle <<endl;
            float finIntervalle = _intervalle + debutIntervalle;
            cout << "finIntervalle = "<<finIntervalle <<endl <<endl;

            int nbrElem = 0;
            while(finIntervalle >= listeData->getElement(i).getVal() )
            {
                i++;    
                nbrElem++;
                cout << "fin" <<endl;
                if(i == listeData->getNombreElements())
                {
                    break;
                }
            };
            cout << "test1" <<endl;
            float calculVal= (debutIntervalle + finIntervalle) /2;
            cout << "test2" <<endl;
            listeFinale->insere(Data1D(calculVal,nbrElem));
            _listeData1D = listeFinale;
            cout << "setliste => fin if" << endl;
        }
        cout << "loop" << endl;
    }
}

// ----- FONCTIONS

void DataSourceSerieContinue::afficheListe()
{
    Affiche();//afiche dataSource
    _listeData1D->Affiche();//affiche les data1D
    cout << "Debut :" << _debut << endl;
    cout << "Intervalle :" << _intervalle << endl;
}
// ----- OPERATORS