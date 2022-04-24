#include <stdlib.h>
#include <iostream>
#include <string.h>
#include <fstream> 

#include <limits>//pour init float == NULL
#include <cmath> // pour verifier si NULL

using namespace std;
#include "Echantillon.h"


// ------ CONSTRUCTORS
Echantillon::Echantillon()
{
    #ifdef DEBUG
        cout << "Constructeur par défaut de Echantillon" << endl;
    #endif

}

Echantillon::Echantillon(const char* nom, int val)

{
    #ifdef DEBUG
        cout << "Constructeur d'init de Echantillon" << endl;
    #endif
        

}

Echantillon::~Echantillon()
{
    #ifdef DEBUG
    cout << "Destructeur de Echantillon'" << endl; 
    #endif
}
// ----- SETTERS // GETTERS

// ----- FONCTIONS

bool Echantillon::importeFichier(const char* nomFichier)
{
    //TO do
    // flux fichier entrée
    ifstream fichier(nomFichier, ios::in);
    if (!fichier) 
    { 
        cout << "erreur d'ouverture !" << endl;  
        return false;
    }

    char buffer[500] = "";
    char nom[500] = "";
    char sujet[500] = "";
    int type = -1;
    int effTotal = -1;
    float val = -1;
    ListeTriee<float> listeT;

    // char letter = 0; //chaque lettre
    // char delim = ';';
    // char endl = '\n';
    int i = 1;
    while(fichier.getline(buffer, 500))
    {
        if(i == 1)
        {
            strcpy(nom,buffer);
        }else
        {
            if(i == 2)
            {
                strcpy(sujet,buffer);
            }else
            {
                if(i == 3)
                {
                    if (strcmp( buffer, "D" ) == 0)
                    {
                        type = 0;
                    }
                    if (strcmp( buffer, "C" ) == 0)
                    {
                        type = 1;                   
                    }

                }else
                {
                    val = atof(buffer);
                    listeT.insere(val);
                }
            }
        }

        i++;
    }
    fichier.close();

    effTotal = i-3;
    Liste<Data1D>* liste;
    liste = calculEffectif(listeT);

    if (type == 0)
    {
        DataSourceSerieDiscrete* pDataSourceSerieDiscrete = new DataSourceSerieDiscrete(nom, sujet, effTotal, type, liste); 
        _source = pDataSourceSerieDiscrete;
    }
    if (type == 1)
    {
        DataSourceSerieContinue* pDataSourceSerieContinue = new DataSourceSerieContinue(nom, sujet, effTotal, type, liste);            
        _source = pDataSourceSerieContinue;
    }

    return true;
}

//j'ai la liste des float que je dois regrouper par effectif 
Liste<Data1D>* Echantillon::calculEffectif(ListeTriee<float> listeT)
{
    Liste<Data1D> *pListe = new Liste<Data1D>();

    float precedent = numeric_limits<float>::quiet_NaN();;
    int i = 1;
    Iterateur<float> it(listeT);
    for (it.reset() ; !it.end() ; it++)
    {
        if((float)it != precedent && isnan(precedent))
        {
            pListe->insere(Data1D(precedent,i));
            i=1;
        }
        precedent = (float)it;
        i++;
    }
    
    return pListe;
}

// ----- OPERATORS
