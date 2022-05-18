#include <stdlib.h>
#include <iostream>
#include <string.h>
#include <fstream> 
#include <math.h>

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
        setMoyenne(&data );
        setMediane(&data );
        setMode(&data );
        setEcartType(&data );
        setVariation(&data );
        setMin(&data );
        setMax(&data );
        setEtendue();
        AfficheRapport(&data);
    }else
    {
        Echantillon data(intitule, col);
        
        setData(&data);

        //faire calcul 
        setMoyenne(&data );
        setMediane(&data );
        setMode(&data );
        setEcartType(&data );
        setVariation(&data );
        setMin(&data );
        setMax(&data );
        setEtendue();

        AfficheRapport(&data);
    }
    #ifdef DEBUG
        cout << "fin EtudeStat1D" <<endl;
    #endif
    
}

EtudeStat1D::~EtudeStat1D()
{
    #ifdef DEBUG
        cout << "Destructeur de EtudeStat1D" << endl; 
    #endif
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
    pDataD = dynamic_cast<DataSourceSerieDiscrete*> (data->getSource());

    if(pDataC)
    {
        pListe = pDataC->getListe();
    }
    else 
    {
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
    pDataD = dynamic_cast<DataSourceSerieDiscrete*> (data->getSource());

    if(pDataC)
    {
        pListe = pDataC->getListe();
    }
    else 
    {
        if(pDataD)
            pListe = pDataD->getListe();
        else
            cout << "exception error" << endl;
    }

    int effTotal = data->getSource()->getEffTotal();
    //calcul 
    //cas si discret
    if (pDataD != NULL)
    {
        float sommeEffectif = 0;
        
        for(int i = 0; i < pListe->getNombreElements(); i++)
        {
            sommeEffectif += pListe->getElement(i).getEff();
            if(sommeEffectif >= effTotal/2)
            {
                if(sommeEffectif <= (effTotal/2) + 1) //interclasse
                {
                    if(effTotal % 2 == 0) //pair
                    {
                        _mediane = (pListe->getElement(i).getVal() + pListe->getElement(i+1).getVal())/2;
                    }else
                    {
                        _mediane = pListe->getElement(i+1).getVal();
                    }
                }else //intraclasse
                {
                    if(effTotal % 2 == 0) //pair
                    {
                        _mediane = (pListe->getElement(i).getVal() + pListe->getElement(i).getVal())/2;
                    }else
                    {
                        _mediane = pListe->getElement(i).getVal();
                    }
                }
                break;
            }
        }
    }

    //cas si continu
    if (pDataC != NULL)
    {   
        float sommeEffectif = 0; //increment du nombre effectif
        float effectifPrec = 0; //garder le nbr element precedent pour calculer les positions
        float debutIntervalle = 0; // de la plage
        float finIntervalle = 0; // de la plage
        float nbrElements = 0; // de la plage
        float position_1 = 0; // DANS la plage
        float position_2 = 0; // DANS la plage
        bool verif = false;
        float deltaNextInterval = 0;
        float debutNextIntervalle = 0;

        //je cherche dans quelle plage se trouve la mediane
        float plageCherche = data->getSource()->getEffTotal()/2;
        for(int i = 0; i < pListe->getNombreElements(); i++)
        {
            sommeEffectif += pListe->getElement(i).getEff();
            if(sommeEffectif >= plageCherche)
            {
                debutIntervalle = (pListe->getElement(i).getVal()*2 - pDataC->getIntervalle())/2;
                finIntervalle = debutIntervalle + pDataC->getIntervalle();
                nbrElements = pListe->getElement(i).getEff();

                position_1 = plageCherche - effectifPrec;
                position_2 = position_1 + 1;
                if(position_2 > nbrElements)
                {
                    verif = true;
                    debutNextIntervalle = (pListe->getElement(i+1).getVal()*2 - pDataC->getIntervalle())/2;
                    deltaNextInterval = pDataC->getIntervalle()/pListe->getElement(i+1).getEff();
                }
                break;
            }
            effectifPrec = sommeEffectif;
        }

        //je calcule le delta de la plage 
        float delta = (finIntervalle - debutIntervalle)/ nbrElements;

        //je verif si c'est dans la meme classe
        if (verif == false) // meme classe
        {
            // je verifie si c'est pair ou impair 
            if(effTotal % 2 == 0)
            {
                //je prends le debut de mon intervalle + mon delta * la position dans la plage 
                _mediane = ((debutIntervalle + delta * position_1) + (debutIntervalle + delta * position_2))/2;
                // cout << "pair meme classe" <<endl;
            }else
            {
                _mediane = debutIntervalle + delta * position_1;
                // cout << "impair meme classe" <<endl;
            }
        }else // pas meme classe
        {
            // je verifie si c'est pair ou impair 
            if(effTotal % 2 == 0)
            {
                //je prends le debut de mon intervalle + mon delta * la position dans la plage 
                _mediane = ((debutIntervalle + delta * position_1) + (debutNextIntervalle + deltaNextInterval))/2; 
                // cout << "pair meme interclasse" <<endl;
            }else
            {
                _mediane = debutIntervalle + delta * position_1;
                // cout << "impair meme interclasse" <<endl;
            }
        }

    }

}
void EtudeStat1D::setMode(Echantillon* data)
{
    int i,j = 0;
    float valeurEffectif = 0;
    float vecMode[4];

    //init liste 
    Liste<Data1D> *pListe;
    DataSourceSerieContinue* pDataC;
    DataSourceSerieDiscrete* pDataD;

    pDataC = dynamic_cast<DataSourceSerieContinue*> (data->getSource());
    pDataD = dynamic_cast<DataSourceSerieDiscrete*> (data->getSource());

    if(pDataC)
    {
        pListe = pDataC->getListe();
    }
    else 
    {
        if(pDataD)
            pListe = pDataD->getListe();
        else
            cout << "exception error" << endl;
    }

    // parcours une premiere fois pour recuperer la valeur max de l'effectif
    //cas série continue
    for(i = 0;i < pListe->getNombreElements(); i++)
    {
        if(valeurEffectif < pListe->getElement(i).getEff())
        {
            valeurEffectif = pListe->getElement(i).getEff();
        }
    }

    //temps que les effectifs sont les memes je continue
    for(i = 0;i < pListe->getNombreElements() && j < 5; i++)
    {
        if(valeurEffectif == pListe->getElement(i).getEff())
        {
            vecMode[j] = pListe->getElement(i).getVal();

            j++;
        }
    }
    
    // mettre à zero le reste si pas completé
    while(j != 5)
    {
        vecMode[j] = 0;
        j++;
    }
    //set de la variable
    for(i = 0;i < j; i++)
    {
        _mode[i] = vecMode[i];
    }
}
void EtudeStat1D::setEcartType(Echantillon* data)
{
    //init liste 
    Liste<Data1D> *pListe;
    DataSourceSerieContinue* pDataC;
    DataSourceSerieDiscrete* pDataD;

    pDataC = dynamic_cast<DataSourceSerieContinue*> (data->getSource());
    pDataD = dynamic_cast<DataSourceSerieDiscrete*> (data->getSource());

    if(pDataC)
    {
        pListe = pDataC->getListe();
    }
    else 
    {
        if(pDataD)
            pListe = pDataD->getListe();
        else
            cout << "exception error" << endl;
    }

    float ecart = 0;
    for(int i = 0; i < pListe->getNombreElements(); i++)
    {
        ecart += pow((pListe->getElement(i).getVal() - getMoyenne()), 2) * pListe->getElement(i).getEff();
    }
    _ecartType = sqrt((ecart / data->getSource()->getEffTotal()));

    // 1 - On calcule la moyenne arithmétique de la série.
    // 2 - On calcule le carré de l'écart à la moyenne de chacune des valeurs de la série.
    // 3 - On calcule la somme des valeurs obtenues.
    // 4 - On divise par l'effectif de la série.
    // 5 - On calcule la racine carrée du résultat.
}

void EtudeStat1D::setVariation(Echantillon* data)
{
    _variation = (getEcartType() / getMoyenne()) * 100;
}

void EtudeStat1D::setMin(Echantillon* data)
{
    int i;
    float valeurMin = 99999999;

    //init liste 
    Liste<Data1D> *pListe;
    DataSourceSerieContinue* pDataC;
    DataSourceSerieDiscrete* pDataD;

    pDataC = dynamic_cast<DataSourceSerieContinue*> (data->getSource());
    pDataD = dynamic_cast<DataSourceSerieDiscrete*> (data->getSource());

    if(pDataC)
    {
        pListe = pDataC->getListeNumeric();
    }
    else 
    {
        if(pDataD)
            pListe = pDataD->getListe();
        else
            cout << "exception error" << endl;
    }

    for(i = 0;i < pListe->getNombreElements();i++)
    {
        if(valeurMin > pListe->getElement(i).getVal())
        {
            valeurMin = pListe->getElement(i).getVal();
        }
    }
    
    //set de la variable
    _min = valeurMin;
}

void EtudeStat1D::setMax(Echantillon* data)
{
    float i,valeurMax;

    //init liste 
    Liste<Data1D> *pListe;
    DataSourceSerieContinue* pDataC;
    DataSourceSerieDiscrete* pDataD;

    pDataC = dynamic_cast<DataSourceSerieContinue*> (data->getSource());
    pDataD = dynamic_cast<DataSourceSerieDiscrete*> (data->getSource());

    if(pDataC)
    {
        pListe = pDataC->getListeNumeric();
    }
    else 
    {
        if(pDataD)
            pListe = pDataD->getListe();
        else
            cout << "exception error" << endl;
    }

    for(i = 0;i < pListe->getNombreElements();i++)
    {
        if(valeurMax < pListe->getElement(i).getVal())
        {
            valeurMax = pListe->getElement(i).getVal();
        }
    }

    _max = valeurMax;
}

void EtudeStat1D::setEtendue()
{ 
    _etendue = getMax() - getMin();
}

// // ----- FONCTIONS

void EtudeStat1D::AfficheRapport(Echantillon* data)
{
    Liste<Data1D>* pListe;
    DataSourceSerieContinue* pDataC;
    DataSourceSerieDiscrete* pDataD;

    pDataC = dynamic_cast<DataSourceSerieContinue*> (data->getSource());
    if(pDataC)
    {
        pListe = pDataC->getListe();
    }else 
    {
        pDataD = dynamic_cast<DataSourceSerieDiscrete*> (data->getSource());
        if(pDataD)
            pListe = pDataD->getListe();
        else
            cout << "exception error" << endl;
    }
    DataSource* pdataSource = data->getSource();
    
    cout << endl << endl;
    cout << "Etude statistique : " << endl;
    cout << "---------" << endl;
    cout << "Nom : " << pdataSource->getNom() << endl;
    cout << "Sujet de l'etude : " << pdataSource->getSujet() << endl;
    cout << "Type : " << pdataSource->getType() << endl;
    cout << endl;
    
    cout << "Donnees : " << endl;
    cout << "---------" << endl;
    pListe->Affiche();
    
    cout << "Effectif total : " << pdataSource->getEffTotal() << endl;
    cout << "   Moyenne : " << getMoyenne() << endl;
    cout << "   Mediane : " << getMediane() << endl;
    cout << "   Mode    : " << getMode(0) << " : " << getMode(1) << " : " << getMode(2) << " : " << getMode(3) << " : " << getMode(4) << endl;
    cout << "   Ecart type : " << getEcartType() << endl;
    cout << "   Coefficient de variation : " << getVariation() << "%" << endl << endl;
    //controle de qualite = Si la valeur de Xi est comprise dans l’intervalle [x – 2s, x + 2s], 
    // on dit que le processus est sous contrôle (c’est-à-dire le cas de 95% des valeurs
    // observées).
    cout << "Controle de qualite : [ "<< getMoyenne() - 2 *getEcartType() << " - " << getMoyenne() + 2 *getEcartType() << " ]"<< endl;
    cout << "\t  Valeur Minimum : " << getMin() << endl;
    cout << "\t  Valeur Maximum : " << getMax() << endl << endl;
    
}

// ----- OPERATORS