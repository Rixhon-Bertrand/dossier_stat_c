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
    float debutIntervalle = _debut;
    for(int i = 0; i < listeData->getNombreElements(); i++)
    {
        float finIntervalle = _intervalle + debutIntervalle;
        int nbrElem = 0;
        if(debutIntervalle < listeData->getElement(i).getVal() )
        {
            while(finIntervalle > listeData->getElement(i).getVal())
            {
                // cout <<i <<" :: loop2 : " << listeData->getElement(i).getVal()<< endl;
                i++;
                nbrElem++;
                if(i==listeData->getNombreElements())
                {
                    break;
                }
            }
            listeFinale->insere(Data1D(debutIntervalle,nbrElem));
            debutIntervalle = finIntervalle;
            i--;
        }
        
        // cout << "loop : " << listeData->getElement(i).getVal() << " -- debutIntervalle :"<<debutIntervalle<<endl;
    }
    _listeData1D = listeFinale;

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