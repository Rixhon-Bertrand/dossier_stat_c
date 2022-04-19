#include <stdlib.h>
#include <iostream>
#include <string.h>
#include <fstream> 

using namespace std;
#include "DataSourceSerieDiscrete.h"
#include "Iterateur.h"
#include "Horaire.h"

// ------ CONSTRUCTORS
DataSourceSerieDiscrete::DataSourceSerieDiscrete()
{
    #ifdef DEBUG
        cout << "Constructeur par défaut de DataSourceSerieDiscrete" << endl;
    #endif
        L.setTete(NULL);
}

DataSourceSerieDiscrete::~DataSourceSerieDiscrete()
{
    #ifdef DEBUG
    cout << "Destructeur de DataSourceSerieDiscrete'" << endl; 
    #endif
}


// ----- SETTERS // GETTERS

// ----- FONCTIONS

// ----- OPERATORS



#include <stdlib.h>
#include <iostream>
#include <string.h>
#include <fstream> 

using namespace std;

#include "Horaire.h"
#include "Iterateur.h"
#include "Professeur.h" 
#include "Groupe.h" 
#include "Local.h" 

// ------ Professeur -----
void Horaire::ajouteProfesseur(const char* nom,const char* prenom)
{
    _listeProfesseurs.insere(Professeur(Planifiable::idCourant,nom,prenom));
    Planifiable::idCourant++;
}
void Horaire::afficheProfesseurs()
{
    _listeProfesseurs.Affiche();
}

void Horaire::supprimeProfesseurParIndice(int ind)
{
    _listeProfesseurs.retire(ind); 
}

void Horaire::supprimeProfesseurParId(int id)
{
    int i = 0;
    Iterateur<Professeur> it(_listeProfesseurs);
    for (it.reset() ; !it.end() ; it++)
    {
        Professeur p = (Professeur)it;
        if(p.getId() == id)
        {
            _listeProfesseurs.retire(i);
        }
        i++;
    }
}

// ------ Groupe -----
void Horaire::ajouteGroupe(int numero)
{
    _listeGroupes.insere(Groupe(Planifiable::idCourant,numero));
    Planifiable::idCourant++;
}

void Horaire::afficheGroupes()
{
    _listeGroupes.Affiche();
}
void Horaire::supprimeGroupeParIndice(int ind)
{
    _listeGroupes.retire(ind);
}

void Horaire::supprimeGroupeParId(int id)
{
    int i = 0;
    Iterateur<Groupe> it(_listeGroupes);
    for (it.reset() ; !it.end() ; it++)
    {
        Groupe p = (Groupe)it;
        if(p.getId() == id)
        {
            _listeGroupes.retire(i);
        }
        i++;
    }
}