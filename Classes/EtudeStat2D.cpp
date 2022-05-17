#include <stdlib.h>
#include <iostream>
#include <string.h>
#include <fstream> 
#include <math.h>

using namespace std;
#include "EtudeStat2D.h"

// ------ CONSTRUCTORS
EtudeStat2D::EtudeStat2D()
{
    #ifdef DEBUG
        cout << "Constructeur par défaut de EtudeStat2D" << endl;
    #endif

}

EtudeStat2D::EtudeStat2D(char* intitule, int col1,int col2)
{
    #ifdef DEBUG
        cout << "Constructeur d'init de EtudeStat2D" << endl;
    #endif

    Echantillon data(intitule, col1, col2);
        
    setData(&data);

    //faire calcul 
    setMoyenne(&data);
    setCorr(&data);
    setCoeffA(&data);
    setCoeffB(&data);

    //Affichage
    AfficheRapport(&data);

    #ifdef DEBUG
        cout << "fin EtudeStat2D" <<endl;
    #endif
    
}

EtudeStat2D::~EtudeStat2D()
{
    #ifdef DEBUG
        cout << "Destructeur de EtudeStat2D" << endl; 
    #endif
}
// ----- SETTERS // GETTERS
void EtudeStat2D::setData(Echantillon* data )
{
    _data = data;
}

void EtudeStat2D::setMoyenne(Echantillon* data)
{
        //init liste 
    Liste<Data2D> pListe;
    DataSourceSerie2D* pData2D;

    pData2D = dynamic_cast<DataSourceSerie2D*> (data->getSource());

    if(pData2D)
    {
        pListe = pData2D->getListe();
    }
    else 
    {
        cout << "error" << endl;
    }

    //calculs
    float sommeTotalVal1 = 0; 
    float sommeTotalVal2 = 0; 
    for(int i = 0; i < pListe.getNombreElements(); i++)
    {
        sommeTotalVal1 += pListe.getElement(i).getVal1();
        sommeTotalVal2 += pListe.getElement(i).getVal2();
    }

    //set des variables
    _moyenne1 = sommeTotalVal1 / pListe.getNombreElements();
    _moyenne2 = sommeTotalVal2 / pListe.getNombreElements();
}

void EtudeStat2D::setCorr(Echantillon* data)
{
    //init liste 
    Liste<Data2D> pListe;
    DataSourceSerie2D* pData2D;

    pData2D = dynamic_cast<DataSourceSerie2D*> (data->getSource());

    if(pData2D)
    {
        pListe = pData2D->getListe();
    }
    else 
    {
        cout << "error" << endl;
    }
    //init des valeurs dont j'ai besoin pour faire l'équation (page 17)
    float n = pListe.getNombreElements();
    float sommeX = 0;
    float sommeY = 0;
    float sommeProduit_X_Y = 0;
    float sommeDesCarresDeX = 0;
    float sommeDesCarresDeY = 0;
    for (int i = 0; i < pListe.getNombreElements(); i++)
    {
        sommeX += pListe.getElement(i).getVal1();
        sommeY += pListe.getElement(i).getVal2();
        sommeProduit_X_Y += pListe.getElement(i).getVal1() * pListe.getElement(i).getVal2();
        sommeDesCarresDeX += pow(pListe.getElement(i).getVal1(), 2);
        sommeDesCarresDeY += pow(pListe.getElement(i).getVal2(), 2);
    }
    float numerateur = sommeProduit_X_Y - ((sommeX * sommeY) / n);
    float denominateur = sqrt((sommeDesCarresDeX - (pow(sommeX,2) / n))) * sqrt((sommeDesCarresDeY - (pow(sommeY,2) / n)));

    _corr = numerateur / denominateur;
}

void EtudeStat2D::setCoeffA(Echantillon* data)
{
    //init liste 
    Liste<Data2D> pListe;
    DataSourceSerie2D* pData2D;

    pData2D = dynamic_cast<DataSourceSerie2D*> (data->getSource());

    if(pData2D)
    {
        pListe = pData2D->getListe();
    }
    else 
    {
        cout << "error" << endl;
    }
    //init des valeurs dont j'ai besoin pour faire l'équation (page 17)
    int n = pListe.getNombreElements();
    float sommeX = 0;
    float sommeY = 0;
    float sommeProduit_X_Y = 0;
    float sommeDesCarresDeX = 0;
    for (int i = 0; i < pListe.getNombreElements(); ++i)
    {
        sommeX += pListe.getElement(i).getVal1();
        sommeY += pListe.getElement(i).getVal2();
        sommeProduit_X_Y += pListe.getElement(i).getVal1() * pListe.getElement(i).getVal2();
        sommeDesCarresDeX += pow(pListe.getElement(i).getVal1(), 2);
    }
    float numerateur = sommeProduit_X_Y - ((sommeX * sommeY) / n);
    float denominateur = sommeDesCarresDeX - (pow(sommeX,2) / n);

    _A = numerateur / denominateur ;
}


void EtudeStat2D::setCoeffB(Echantillon* data)
{
    _B = getMoyenneY() - (getA() * getMoyenneX());
}

// ----- FONCTIONS

void EtudeStat2D::AfficheRapport(Echantillon* data)
{
    //init liste 
    Liste<Data2D> pListe;
    DataSourceSerie2D* pData2D;

    pData2D = dynamic_cast<DataSourceSerie2D*> (data->getSource());

    if(pData2D)
    {
        pListe = pData2D->getListe();
    }
    else 
    {
        cout << "error" << endl;
    }
    
    cout << endl << "Etude Statistique:" << endl;
    cout << "------------------" << endl << endl;
    
    cout << "Nom : \t\t  " << pData2D->getNom() << endl;
    cout << "Sujet de l'etude  " << pData2D->getSujet() << "  --  " << pData2D->getSujet2() << endl;
    cout << "Effectif Total :  " << pData2D->getEffTotal() << endl;
    cout << "Type :\t\t  " << pData2D->getType() << "\t" << pData2D->getType2() << endl;
    cout << endl << endl;
    
    cout << "Valeurs : " << endl;
    cout << "---------" << endl;
    pListe.Affiche();
    cout << endl;
    
    cout << "   Moyenne Val1 : " << getMoyenneX() << endl;
    cout << "   Moyenne Val2 : " << getMoyenneY() << endl;
    cout << endl << endl;
    
    cout << "Corrélation :" << endl;
    cout << "-------------" << endl;
    cout << "   Coefficient de correlation : " << getCorr() << endl;
    cout << "   Coefficient a : " << getA() << endl;
    cout << "   Coefficient b : " << getB() << endl << endl;
    
    // MENU 
    float x = 0;
    float y = 0;
    int choix = 0;
    while(choix != 3)
    {
        fflush(stdin);
        cout << "       1 : Prévision pour : " << pData2D->getSujet() << endl;
        cout << "       2 : Prévision pour : " << pData2D->getSujet2() << endl;
        cout << "       3 : Sortie " << endl;
        cin >> choix;
        
        switch(choix) {
        case 1:
            cout << "Entrer la valeur pour " << pData2D->getSujet() << " : ";
            cin >> x;
            y = getA() * x + getB(); // y = (a*x) + b
            cout << "La valeur prevue : " << y << endl << endl;
            break;
        case 2:
            cout << "Entrer la valeur pour " << pData2D->getSujet2() << " : ";
            cin >> y;
            x = (y - getB()) / getA(); // x = (y-b) / a
            cout << "La valeur prevue : " << x << endl << endl;
            break;
        case 3:
            cout << "Fin" << endl;
            break;
        default:
            choix = 0;
        }
        
    }
    
}

// ----- OPERATORS