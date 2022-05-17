#include <stdlib.h>
#include <iostream>
#include <string.h>
#include <fstream> 

using namespace std;
#include "Data2D.h"

// ------ CONSTRUCTORS
Data2D::Data2D()
{
    #ifdef DEBUG
        cout << "Constructeur par défaut de Data2D" << endl;
    #endif
        setVal1(-999);
        setVal2(-999);
}

Data2D::Data2D(float val1,float val2)
{
    #ifdef DEBUG
        cout << "Constructeur d'init de Data2D" << endl;
    #endif

    setVal1(val1);
    setVal2(val2);
}

Data2D::Data2D(const Data2D& modele)
{
    #ifdef DEBUG
        cout << "Constructeur de copie de Data2D" << endl;
    #endif
    setVal1(modele.getVal1());
    setVal2(modele.getVal2());
}

Data2D::~Data2D()
{
    #ifdef DEBUG
        cout << "Destructeur de Data2D" << endl;
    #endif

}

ostream& operator<<(ostream& flux, const Data2D& d)
{
    if(d.getVal1() != -999 && d.getVal2() != -999)
    {
        flux << d.getVal1() <<" - "<< d.getVal2() << endl;  
        return flux;
    }else
    {
        flux << "Data2D incomplet" << endl;
        return flux;
    }
}

Data2D& Data2D::operator=(const Data2D& d) 
{ 
    setVal1(d.getVal1());
    setVal2(d.getVal2());
    return *this; 
}

bool Data2D::operator<=(const Data2D& d) 
{ 
    if (getVal1() < d.getVal1())
    {
        return true;
    }else
    {
        return false;
    }
}
// ----- SETTERS // GETTERS

// ----- FONCTIONS

// ----- OPERATORS