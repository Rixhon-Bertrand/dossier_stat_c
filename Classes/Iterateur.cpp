#include <iostream> 
#include <stdlib.h>
using namespace std; 
#include "Iterateur.h" 

//classes dérivées
#include "Data1D.h" 

template class Iterateur<int>;
template class Iterateur<float>;
template class Iterateur<Data1D>;


template <class T> Iterateur<T>::Iterateur(const Liste<T>& newListe)
{
	#ifdef DEBUG
		cout << "Constructeur initilisation d'iterateur Liste" << endl;
	#endif
	setListe((Liste<T>*)&newListe);
}

template <class T> Iterateur<T>::Iterateur(const ListeTriee<T>& newListe)
{
	#ifdef DEBUG
		cout << "Constructeur initilisation d'iterateur ListeTriee" << endl;
	#endif
	setListe((Liste<T>*)&newListe);
}

//constructeur de copie
template <class T> Iterateur<T>::Iterateur(const Iterateur<T>& modele) 
{
	#ifdef DEBUG
		cout << "Constructeur initilisation d'iterateur Iterateur" << endl;
	#endif
	setListe(modele._liste);
	_pCurrCell = modele._pCurrCell;
}

template <class T> Iterateur<T>::~Iterateur() 
{
	#ifdef DEBUG
		cout << "Destructeur d' iterateur" << endl; 
	#endif
}
	
template <class T> void Iterateur<T>::setListe(const Liste<T> *pListe)
{
	_liste = const_cast<Liste<T>*> (pListe);
	reset();
}

template <class T> void Iterateur<T>::reset()
{
	_pCurrCell = _liste->getTete();
}
	
template <class T> bool Iterateur<T>::end() const
{
	if (_pCurrCell == NULL)
	{
		return true;
	}

	return false;
}

// Operators 
template <class T> bool Iterateur<T>::operator++(int)
{ 
	if(end() == false)
	{
		_pCurrCell = _pCurrCell->suivant;
		return true;
	}

	return false;
}

template <class T> Iterateur<T>::operator T() const
{
	return _pCurrCell->valeur;
}