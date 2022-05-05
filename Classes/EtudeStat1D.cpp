#include <stdlib.h>
#include <iostream>
#include <string.h>
#include <fstream> 

using namespace std;
#include "EtudeStat1D.h"

#include "Liste.h"
#include "ListeTriee.h"
#include "Data1D.h"
#include "Iterateur.h"

// ------ CONSTRUCTORS
EtudeStat1D::EtudeStat1D()
{
    #ifdef DEBUG
        cout << "Constructeur par defaut de EtudeStat1D" << endl;
    #endif

}
EtudeStat1D::EtudeStat1D(char* intitule, int col)
{
    #ifdef DEBUG
        cout << "Constructeur d'init de EtudeStat1D" << endl;
    #endif

    //creer echantillon 
    if(col == 0)
    {
        Echantillon data(intitule);
        setData(&data);

        //faire calcul 
    }else
    {
        Echantillon data(intitule, col);
        
        setData(&data);

        //faire calcul 
    }

}

EtudeStat1D::~EtudeStat1D()
{
    #ifdef DEBUG
        cout << "Destructeur de EtudeStat1D" << endl; 
    #endif
        if(_data)
            delete _data;
}

// // ----- SETTERS // GETTERS
void EtudeStat1D::setData(Echantillon* data )
{
    _data = data;
}
void EtudeStat1D::setMoyenne(Echantillon* data)
{
    //init liste 
    Liste<Data1D> *pListe;
    DataSourceSerieContinue* pDataC;
    DataSourceSerieDiscrete* pDataD;

    pDataC = dynamic_cast<DataSourceSerieContinue*> (data->getSource());
    if(pDataC)
    {
        pListe = pDataC->getListe();
    }
    else 
    {
        pDataD = dynamic_cast<DataSourceSerieDiscrete*> (data->getSource());
        if(pDataD)
            pListe = pDataD->getListe();
        else
            cout << "exception error" << endl;
    }

    //calcul 
    float sommeTotal = 0; 
    for(int i = 0; i < pListe->getNombreElements(); i++)
    {
        sommeTotal += pListe->getElement(i).getVal() * pListe->getElement(i).getEff();
    }
    //set de la variable
    _moyenne = sommeTotal / data->getSource()->getEffTotal();
}
void EtudeStat1D::setMediane(Echantillon* data)
{
    //init liste 
    Liste<Data1D> *pListe;
    DataSourceSerieContinue* pDataC;
    DataSourceSerieDiscrete* pDataD;

    pDataC = dynamic_cast<DataSourceSerieContinue*> (data->getSource());
    if(pDataC)
    {
        pListe = pDataC->getListe();
    }
    else 
    {
        pDataD = dynamic_cast<DataSourceSerieDiscrete*> (data->getSource());
        if(pDataD)
            pListe = pDataD->getListe();
        else
            cout << "exception error" << endl;
    }

    //calcul 
    //cas si discret
    if (pDataD != NULL)
    {
        if(pListe->getNombreElements() % 2 == 0)
        {
            for(int i = 0; i < pListe->getNombreElements(); i++)
            {
                if(i == pListe->getNombreElements()/2)
                {
                    _mediane = (pListe->getElement(i).getVal() + pListe->getElement(i+1).getVal())/2;
                }
            }  
        }else
        {
            int effTotal = data->getSource()->getEffTotal();
            int n = (effTotal-1) / 2;

            for(int i = 0; i < pListe->getNombreElements(); i++)
            {
                if(i == n + 1)
                {
                    _mediane = pListe->getElement(i).getVal();
                }
            } 
        }

    }

    //cas si continu
    if (pDataC != NULL)
    {   
        for(int i = 0; i < pListe->getNombreElements(); i++)
        {
            //TO DO
        }
    }

}
void EtudeStat1D::setMode(Echantillon* data)
{
    //init liste 
    Liste<Data1D> *pListe;
    DataSourceSerieContinue* pDataC;
    DataSourceSerieDiscrete* pDataD;

    pDataC = dynamic_cast<DataSourceSerieContinue*> (data->getSource());
    if(pDataC)
    {
        pListe = pDataC->getListe();
    }
    else 
    {
        pDataD = dynamic_cast<DataSourceSerieDiscrete*> (data->getSource());
        if(pDataD)
            pListe = pDataD->getListe();
        else
            cout << "exception error" << endl;
    }

    //calcul TO DO
}
void EtudeStat1D::setEcartType(Echantillon* data)
{
    //init liste 
    Liste<Data1D> *pListe;
    DataSourceSerieContinue* pDataC;
    DataSourceSerieDiscrete* pDataD;

    pDataC = dynamic_cast<DataSourceSerieContinue*> (data->getSource());
    if(pDataC)
    {
        pListe = pDataC->getListe();
    }
    else 
    {
        pDataD = dynamic_cast<DataSourceSerieDiscrete*> (data->getSource());
        if(pDataD)
            pListe = pDataD->getListe();
        else
            cout << "exception error" << endl;
    }

    //calcul TO DO
}
void EtudeStat1D::setVariation(Echantillon* data)
{
    //init liste 
    Liste<Data1D> *pListe;
    DataSourceSerieContinue* pDataC;
    DataSourceSerieDiscrete* pDataD;

    pDataC = dynamic_cast<DataSourceSerieContinue*> (data->getSource());
    if(pDataC)
    {
        pListe = pDataC->getListe();
    }
    else 
    {
        pDataD = dynamic_cast<DataSourceSerieDiscrete*> (data->getSource());
        if(pDataD)
            pListe = pDataD->getListe();
        else
            cout << "exception error" << endl;
    }

    //calcul TO DO
}

void EtudeStat1D::setMin(Echantillon* data)
{
    //init liste 
    Liste<Data1D> *pListe;
    DataSourceSerieContinue* pDataC;
    DataSourceSerieDiscrete* pDataD;

    pDataC = dynamic_cast<DataSourceSerieContinue*> (data->getSource());
    if(pDataC)
    {
        pListe = pDataC->getListe();
    }
    else 
    {
        pDataD = dynamic_cast<DataSourceSerieDiscrete*> (data->getSource());
        if(pDataD)
            pListe = pDataD->getListe();
        else
            cout << "exception error" << endl;
    }

    //calcul TO DO
}

void EtudeStat1D::setMax(Echantillon* data)
{
    //init liste 
    Liste<Data1D> *pListe;
    DataSourceSerieContinue* pDataC;
    DataSourceSerieDiscrete* pDataD;

    pDataC = dynamic_cast<DataSourceSerieContinue*> (data->getSource());
    if(pDataC)
    {
        pListe = pDataC->getListe();
    }
    else 
    {
        pDataD = dynamic_cast<DataSourceSerieDiscrete*> (data->getSource());
        if(pDataD)
            pListe = pDataD->getListe();
        else
            cout << "exception error" << endl;
    }

    //calcul TO DO
}

void EtudeStat1D::setEtendue()
{ 
    _etendue = getMax() - getMin();
}
// // ----- FONCTIONS



// ----- OPERATORS