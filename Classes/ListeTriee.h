#ifndef LISTETRIEE_H
#define LISTETRIEE_H 

#include "Liste.h"


template<class T> class ListeTriee : public Liste<T>
{ 
	private:
		
	public: 
		// constructors
		ListeTriee(); 
		ListeTriee(const ListeTriee<T>&); 
		~ListeTriee();  
		
		//fonctions
		void insere(const T &);
};
 
#endif 