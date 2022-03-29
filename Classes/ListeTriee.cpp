#include <iostream> 
#include <stdlib.h>
using namespace std; 
#include "ListeTriee.h" 

//classes dérivées
#include "Data1D.h" 

template class ListeTriee<int>;
template class ListeTriee<float>;
template class ListeTriee<Data1D>;


template <class T> ListeTriee<T>::ListeTriee() : Liste<T>::Liste()
{ 
	#ifdef DEBUG
	cout << "Constructeur par défaut de ListeTriee" << endl; 
	#endif
}

template <class T> ListeTriee<T>::ListeTriee(const ListeTriee<T>& copie) 
	: Liste<T>::Liste((Liste<T>&)copie)
{ 
	#ifdef DEBUG
	cout << "Constructeur de copie de ListeTriee" << endl; 
	#endif
}

template <class T> ListeTriee<T>::~ListeTriee()
{ 
	#ifdef DEBUG
	cout << "Destructeur de ListeTriee" << endl; 
	#endif
} 

template <class T> void ListeTriee<T>::insere(const T & valeur)
{
	//je crée une nouvelle cellule
	Cellule<T> *pAjout = new Cellule<T>();
	pAjout->suivant = NULL;
	pAjout->valeur = valeur;
	
	//si la liste est vide
	if(Liste<T>::getTete() == NULL)
	{
		Liste<T>::setTete(pAjout);
		return;
	}
	
	//je parcours la liste
		Cellule<T> *pPrec = NULL;
		Cellule<T> *pCell = Liste<T>::getTete();
		//nécessite de redefinir operator <= 
		while(pCell && pCell->valeur <= pAjout->valeur) 
		{
			pPrec = pCell;
			pCell = pCell->suivant;
		}
		
	//les autres
	if(pPrec != NULL)
	{
		pAjout->suivant = pPrec->suivant;
		pPrec->suivant = pAjout;
	}
	else//premier
	{
		pAjout->suivant = pCell;
		Liste<T>::setTete(pAjout);
	}
}
