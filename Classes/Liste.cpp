#include <iostream> 
#include <stdlib.h>
using namespace std; 
#include "Liste.h" 

//classes dérivées
#include "Data1D.h" 

template class Liste<int>;
template class Liste<float>;
template class Liste<Data1D>;

template <class T> Liste<T>::Liste()
{ 
	#ifdef DEBUG
	cout << "Constructeur par défaut de Liste" << endl; 
	#endif
	_pTete = NULL; 
}

template <class T> Liste<T>::Liste(const Liste<T>& modele)
{ 
	#ifdef DEBUG
	cout << "Constructeur de copie de Liste" << endl;
	#endif

	Cellule<T> *pChainage = modele.getTete();
	if(pChainage == NULL)
	{
		_pTete = NULL; 
	}
	else
	{
		Cellule<T> *pTemp = new Cellule<T>();
		setTete(pTemp);
		pTemp->valeur = pChainage->valeur;
		pTemp->suivant = NULL;
		
		while(pChainage->suivant)
		{
			pChainage = pChainage->suivant;
			pTemp->suivant = new Cellule<T>();
			pTemp = pTemp->suivant;
			
			pTemp->valeur = pChainage->valeur;
			pTemp->suivant = NULL;
		}
	}
}

template <class T> Liste<T>::~Liste()
{ 
	#ifdef DEBUG
	cout << "Destructeur de Liste" << endl; 
	#endif
	Cellule<T> *pSuivant = NULL;

	while(_pTete) 
	{ 
		pSuivant = _pTete->suivant;
		delete _pTete; 
		_pTete = pSuivant;
	} 
} 

// -------- SETTERS et GETTERS

template <class T> void Liste<T>::setTete(const Cellule<T> *pCell)
{
	_pTete = const_cast<Cellule<T>*> (pCell);
}

template <class T> Cellule<T>* Liste<T>::getTete() const
{
	return _pTete;
}

// -------- FONCTIONS
template <class T> bool Liste<T>::estVide() const
{
	if(_pTete != NULL)
	{
		return false;
	}
	return true;
}

template <class T> int Liste<T>::getNombreElements() const
{
	int i = 0;
	Cellule<T> *pCell = getTete();
	while(pCell)
	{
		pCell = pCell->suivant;
		i++;
	}
	return i;
}

// -------- AFFICHAGE
template <class T> void Liste<T>::Affiche() const
{
	Cellule<T> *pCell = getTete();
	while(pCell)
	{
		cout << pCell->valeur << endl;
		pCell = pCell->suivant;
	}
}

template <class T> void Liste<T>::insere(const T & val)
{
	//je crée une nouvelle cellule
	Cellule<T> *pAjout = new Cellule<T>();
	pAjout->suivant = NULL;
	pAjout->valeur = val;
	
	//si la liste est vide
	if(getTete() == NULL)
	{
		setTete(pAjout);
	}else
	{
		//je parcours la liste
		Cellule<T> *pCell = getTete();
		while(pCell->suivant)
		{
			pCell = pCell->suivant;
		}
		pCell->suivant = pAjout;
	}
	
}

template <class T> const T Liste<T>::retire(const int ind)
{
	int i = 0;

	//initialise valeur de retour
	T valeurReturn;

	//je crée une nouvelle cellule qui fera la jonction
	Cellule<T> *pPrec = new Cellule<T>();
	pPrec->suivant = NULL;

	//si la liste est vide
	if(getTete() == NULL)
	{
		return valeurReturn;
	}else
	{
		Cellule<T> *pCell = getTete();

		while(pCell->suivant)
		{
			if(i == ind && i == 0)	//premiere place
			{
				setTete(pCell->suivant);

				valeurReturn = pCell->valeur;
				delete pCell;
				return valeurReturn;
			}
			if(i == ind && i != 0) // les autres
			{
				//je rattache pPrec à Psuiv
				pPrec->suivant = pCell->suivant;

				//return + free
				valeurReturn = pCell->valeur;
				delete pCell;
				return valeurReturn;
			}

			//je retiens la cellule precedente
			pPrec = pCell;

			//je place la cellule actuelle sur la suivante 
			pCell = pCell->suivant;

			i++;
		}

		if(pCell->suivant == NULL && i == ind)		//derniere place
		{
			pPrec->suivant = NULL;

			valeurReturn = pCell->valeur;
			delete pCell;
			return valeurReturn;
		}
		return valeurReturn;
	}

}

template <class T> T  Liste<T>::getElement(int n) const {
	Cellule<T>* tmp = _pTete;
	
	for(int i = 0; i < n; i++)
		tmp = tmp->suivant;
	
	return tmp->valeur;
}
// -------- OERATORS
template <class T> const Liste<T>* Liste<T>::operator=(const Liste<T>& pCellparam)
{
	Cellule<T> *pChainage = pCellparam.getTete();

	Cellule<T> *pTemp = new Cellule<T>();

	if(pChainage == NULL)
	{
		// je return une cellule == NULL
		setTete(pTemp);
		pTemp->valeur = pChainage->valeur;
		pTemp->suivant = NULL;
	}else
	{
		// je copie la nouvelle file en fesant une nouvelle aloccation 
		// pour ne pas alterer les données
		setTete(pTemp);
		pTemp->valeur = pChainage->valeur;
		pTemp->suivant = NULL;
		
		while(pChainage->suivant)//parcours de la liste parametre
		{
			pChainage = pChainage->suivant;
			pTemp->suivant = new Cellule<T>();
			pTemp = pTemp->suivant;
			
			pTemp->valeur = pChainage->valeur;
			pTemp->suivant = NULL;
		}
	}

	return this;
}
