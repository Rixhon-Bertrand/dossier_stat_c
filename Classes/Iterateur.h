#ifndef ITERATEUR_H
#define ITERATEUR_H 

#include "Liste.h"
#include "ListeTriee.h"

template<class T> class Iterateur
{
	protected:
		Liste<T> *_liste;
		Cellule<T> *_pCurrCell;

	public:
		// constructors
		Iterateur(const Liste<T>&); 
		Iterateur(const ListeTriee<T>&); 
		Iterateur(const Iterateur<T>&);
		~Iterateur(); 
		
		// setters--getters
		void setListe(const Liste<T>*);

		// fonctions
		void reset();
		bool end() const;
		
		// operators
		operator T() const;
		T& operator&() const; 
		bool operator++(int); 
};

#endif 