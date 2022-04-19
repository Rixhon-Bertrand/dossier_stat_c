#include <stdlib.h>
#include <iostream>
#include <string.h>
#include <fstream> 

using namespace std;
#include "DataSource.h"

// ------ CONSTRUCTORS
DataSource::DataSource()
{
    #ifdef DEBUG
        cout << "Constructeur par défaut de DataSource" << endl;
    #endif

    _nom = NULL;
    _sujet = NULL;
    setEffTotal(-1);
    setType(-1);
}
DataSource::DataSource(const char* nom, const char* sujet, int eff, int type)
{
    #ifdef DEBUG
        cout << "Constructeur d'init de DataSource" << endl;
    #endif

    _nom = NULL;
    setNom(nom);
    _sujet = NULL;
    setSujet(sujet);
    setEffTotal(eff);
    setType(type);
}
DataSource::DataSource(const DataSource& modele)
{
    #ifdef DEBUG
        cout << "Constructeur de copie de DataSource" << endl;
    #endif

    _nom = NULL;
    setNom(modele.getNom());
    _sujet = NULL;
    setSujet(modele.getSujet());
    setEffTotal(modele.getEff());
    setType(modele.getType());
}

DataSource::~DataSource()
{
    #ifdef DEBUG
        cout << "Destructeur de DataSource" << endl;
    #endif

    if(_nom)
        delete []_nom;
    if(_sujet)
        delete _sujet;
}
// ----- SETTERS // GETTERS
void DataSource::setNom(const char* intitule)
{
    if(_nom)
    {
        delete []_nom;
    }
    if(intitule)
    {
        _nom = new char[strlen(intitule) + 1];
        strcpy(_nom,intitule);
        return;
    }
    _nom = NULL;
}

void DataSource::setSujet(const char* intitule)
{
    if(_sujet)
    {
        delete []_sujet;
    }
    if(intitule)
    {
        _sujet = new char[strlen(intitule) + 1];
        strcpy(_sujet,intitule);
        return;
    }
    _sujet = NULL;
}

void DataSource::setEffTotal(int effTotal)
{
    _effTotal = effTotal;
}
void DataSource::setType(int type)
{
    _type = type;
}

char* DataSource::getNom() const
{
    return _nom;
}
char* DataSource::getSujet() const
{
    return _sujet;
}
// ----- FONCTIONS
void DataSource::Affiche() const
{
    if(getNom())
    {
        cout << "Titre : " << getNom() << endl;
    }else
    {
        cout << "Pas de titre !!" << endl;
    }

    if(getSujet())
    {
        cout << "Sujet de l'etude :" << getSujet() << endl;
    }else
    {
        cout << "Pas de sujet !!" <<endl;
    }

    if(getEff() != -1)
    {
        cout << "Effectif Total : " << getEff() << endl;
    }else
    {
        cout << "Effectif total manquant !!" <<endl;
    }

    if(getType() != -1)
    {
        cout << "Type : " << getType() << endl;
    }else
    {
        cout << "Type manquant !!" <<endl;
    }
}

// ----- OPERATORS