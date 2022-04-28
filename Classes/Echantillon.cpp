#include <stdlib.h>
#include <iostream>
#include <string.h>
#include <fstream> 
#include <string.h>

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

Echantillon::Echantillon(const char* nom, int col)

{
    #ifdef DEBUG
        cout << "Constructeur d'init de Echantillon" << endl;
    #endif
        
        importeFichier(nom,col);
}

Echantillon::~Echantillon()
{
    #ifdef DEBUG
    cout << "Destructeur de Echantillon'" << endl; 
    #endif
}
// ----- SETTERS // GETTERS

// ----- FONCTIONS

bool Echantillon::importeFichier(const char* nomFichier,int col)
{
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
    ListeTriee<float> listeT;

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
                    if (buffer[0] == 'D')
                    {
                        type = 0;
                    }else
                    {
                        type = 1;
                    }

                }else
                {
                    listeT.insere(split(buffer,":", col));
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

    float precedent = numeric_limits<float>::quiet_NaN();
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

float Echantillon::split(char* chaine, const char* delimiteur, int col) 
{
    float val = -1;

    char *elem = strtok(chaine, delimiteur);

    int j = 0;
    while(elem != NULL)
    {
        // printf("'%s'\n", elem);
        if (j == col)
        {
             elem = strtok(NULL, elem);
        }
    }
       
    val = atof(elem);
    return val;
}
// ----- OPERATORS
