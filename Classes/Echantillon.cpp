#include <stdlib.h>
#include <iostream>
#include <string.h>
#include <fstream> 
#include <string.h>
#include <sstream>

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

Echantillon::Echantillon(const char* nom)
{
    #ifdef DEBUG
        cout << "Constructeur d'init de Echantillon" << endl;
    #endif
        
    importeFichier(nom,1);
    #ifdef DEBUG
        cout << "fin Echantillon" <<endl;
    #endif
        
}
//DATA1D
Echantillon::Echantillon(const char* nom, int col)
{
    #ifdef DEBUG
        cout << "Constructeur d'init de Echantillon 1D" << endl;
    #endif
        bool verif;
        verif = verifColonnes(nom,col);
        if(verif == false)
        {
            printf("error");
        }else
        {
            importeFichier(nom,col);
        }
    #ifdef DEBUG
        cout << "fin Echantillon" <<endl;
    #endif
}
//DATA2D
Echantillon::Echantillon(const char* nom, int col1, int col2)
{
    #ifdef DEBUG
        cout << "Constructeur d'init de Echantillon 2D" << endl;
    #endif
        bool verif;
        verif = verifColonnes(nom,col1);
        if(verif == false)
        {
            printf("error\n");
            exit(0);
        }
        verif = verifColonnes(nom,col2);

        if(verif == false)
        {
            printf("error");
        }else
        {
            importeFichier2D(nom,col1,col2);
        }

    #ifdef DEBUG
        cout << "fin Echantillon" <<endl;
    #endif
}

Echantillon::~Echantillon()
{
    #ifdef DEBUG
    cout << "Destructeur de Echantillon" << endl; 
    #endif
    if(_source)
        delete _source;
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
    char* sujet = new char[500];
    int type = -1;
    int effTotal = -1;
    ListeTriee<float> listeT;

    int i = 1;
    // printf("testavantboucle\n");
    while(fichier.getline(buffer, 500))
    {
        if(i == 1)
        {
            // printf("testIF1\n");
            strcpy(nom,buffer);
        }else
        {
            if(i == 2)
            {
                // printf("testIF2\n");
                strcpy (sujet,splitNom(buffer,":", col));
            }else
            {
                if(i == 3)
                {
                    // printf("testIF3\n");
                    if (strcmp(splitNom(buffer,":", col),"D") == 0)
                    {
                        type = 0;
                        // printf("testIF4\n");
                    }else
                    {
                        type = 1;
                    }

                }else
                {
                    // printf("testINSERTION\n");
                    // cout << buffer << endl;
                    listeT.insere(split(buffer,":", col));
                    // printf("testFININSERTION\n");
                }
            }
        }
        i++;
    }
    // printf("testFINBOUCLE\n");
    fichier.close();

    effTotal = i-4;
    Liste<Data1D>* liste;
    liste = calculEffectif(listeT);

    // liste->Affiche();

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
    int i = 0;
    Iterateur<float> it(listeT);
    for (it.reset() ; !it.end() ; it++)
    {
        if((float)it != precedent && isnan(precedent) == false)
        {
            pListe->insere(Data1D(precedent,i));
            i = 0;
        }
        precedent = (float)it;
        i++;
    }
    pListe->insere(Data1D(precedent,i));
    
    return pListe;

}

float Echantillon::split(char* chaine, const char* delimiteur, int col) 
{
    float val = -1;
    // printf("testSPLIT\n");
    char *elem = strtok(chaine, delimiteur);
    int j = 1;
    // cout << "debut" <<endl;
    while(elem != NULL)
    {
        // cout << "Valeur de j = " << j <<  endl << endl;
        // printf("elem = '%s'\n\n", elem);
        if (j == col)
        {
            val = atof(elem);
            // cout << "return:" << val <<endl;
            return val;
        }
        else
        {
            elem = strtok (NULL, delimiteur);
            j++;
        }
    }
    // cout << "fin" <<endl <<endl;
       
    return -1;
}

char* Echantillon::splitNom(char* chaine, const char* delimiteur, int col) 
{
    char* nom = new char[500];
    // printf("testSPLIT\n");
    char *elem = strtok(chaine, delimiteur);
    int j = 1;
    // cout << "debut" <<endl;
    while(elem != NULL)
    {
        // cout << "Valeur de j = " << j <<  endl << endl;
        // printf("elem = '%s'\n\n", elem);
        if (j == col)
        {
            strcpy(nom,elem);
            // cout << "return:" << nom <<endl;
            return nom;
        }
        else
        {
            elem = strtok (NULL, delimiteur);
            j++;
        }
    }
    cout << "fin" <<endl <<endl;
       
    return nom;
}

bool Echantillon::VerifColonnesFichier(char* chaine, const char* delimiteur, int col)
{
    char *elem = strtok(chaine, delimiteur);
    int j = 1;
    while(elem != NULL)
    {
        elem = strtok (NULL, delimiteur);
        j++;
    }
       
    if(col < j)
    {
        return true;
    }
    else
    {
        return false;
    }
    
}

bool Echantillon::verifColonnes(const char* nomFichier,int col)
{
    // flux fichier entrée
    ifstream fichier(nomFichier, ios::in);
    if (!fichier) 
    { 
        cout << "erreur d'ouverture !" << endl;  
        return false;
    }
    int i = 1;
    char buffer[500] = "";
    while(fichier.getline(buffer, 500))
    {
        if(i == 4)
        {
            if(VerifColonnesFichier(buffer,":",col) == false)
            {
                cout << "La colonne choisie est inexistante" << endl << endl;
                return false;
            }
        }
        i++;
    }
    fichier.close();
    return true;
}
// ----- OPERATORS

// ----- 2D

bool Echantillon::importeFichier2D(const char* nomFichier,int col1,int col2)
{

    // flux fichier entrée
    ifstream fichier(nomFichier, ios::in);
    if (!fichier) 
    { 
        cout << "erreur d'ouverture !" << endl;  
        return false;
    }

    char buffer[500] = "";
    char buffer2[500] = "";
    char nom[500] = "";
    char sujet1[500] = "";
    char sujet2[500] = "";
    int type1 = -1;
    int type2 = -1;
    ListeTriee<Data2D> listeT;

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
                strcpy(buffer2,buffer); // car buffer est modifié avec strtok
                strcpy (sujet1,splitNom(buffer,":", col1));
                strcpy (sujet2,splitNom(buffer2,":", col2));
            }else
            {
                if(i == 3)
                {
                    strcpy(buffer2,buffer); // car buffer est modifié avec strtok
                    if (strcmp(splitNom(buffer,":", col1),"D") == 0)
                    {
                        type1 = 0;
                        // printf("testIF4\n");
                    }else
                    {
                        type1 = 1;
                    }

                    if (strcmp(splitNom(buffer2,":", col2),"D") == 0)
                    {
                        type2 = 0;
                        // printf("testIF4\n");
                    }else
                    {
                        type2 = 1;
                    }

                }else
                {
                    listeT.insere(Data2D(split(buffer,":", col1),split(buffer,":", col2)));
                }
            }
        }
        i++;
    }

    fichier.close();

    Liste<Data2D> liste;
    liste = listeT;
    int effTotal = liste.getNombreElements();
    // liste.Affiche();

    DataSourceSerie2D* pDataSourceSerie2D = new DataSourceSerie2D(nom, sujet1, sujet2, type1, type2, effTotal,liste); 
    _source = pDataSourceSerie2D;

    return true;
}
