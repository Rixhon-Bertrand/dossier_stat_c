#include <stdlib.h>
#include <iostream>
#include <string.h>
#include <fstream> 

using namespace std;
#include "Data1D.h"

// ------ CONSTRUCTORS
Data1D::Data1D()
{
    #ifdef DEBUG
        cout << "Constructeur par défaut de Data1D" << endl;
    #endif

    _val = 0;
    _eff = 0;
}
Data1D::Data1D(float valeur, int effectif)
{
    #ifdef DEBUG
        cout << "Constructeur d'init de Data1D" << endl;
    #endif

    setVal(valeur);
    setEff(effectif);
}
Data1D::Data1D(const Data1D& modele)
{
    #ifdef DEBUG
        cout << "Constructeur de copie de Data1D" << endl;
    #endif
    setVal(modele.getVal());
    setEff(modele.getEff());
}

Data1D::~Data1D()
{
    #ifdef DEBUG
        cout << "Destructeur de Data1D" << endl;
    #endif

}
// ----- SETTERS // GETTERS
void Data1D::setVal(float valeur)
{
    _val = valeur;
}
void Data1D::setEff(int valeur)
{
    _eff = valeur;
}
// ----- FONCTIONS

// ----- OPERATORS
ostream& operator<<(ostream& flux, const Data1D& d)
{
    if(d.getVal() != 0 && d.getEff() != 0)
    {
        flux << "Valeur: " << d.getVal() <<" -- Effectif: "<< d.getEff() << endl;  
        return flux;
    }else
    {
        flux << "Data1D incomplet" << endl;
        return flux;
    }
}

Data1D& Data1D::operator=(const Data1D& d) 
{ 
    setVal(d.getVal());
    setEff(d.getEff());
    return *this; 
}

bool Data1D::operator<=(const Data1D& d) 
{ 
    if (getVal() < d.getVal())
    {
        return true;
    }else
    {
        return false;
    }
}