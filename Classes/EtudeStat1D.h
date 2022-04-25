#ifndef EtudeStat1D_H
#define EtudeStat1D_H

#include "Echantillon.h"

class EtudeStat1D
{
	private:
	Echantillon* _E;
	float _moyenne;
	float _ecartType;
	float _mediane;
	float _mode[3];
	float _variation;
	float _min;
	float _max;

	public:

		EtudeStat1D();
		EtudeStat1D(char*, int);
		~EtudeStat1D();

		void Affiche();
};

#endif

// NOTE : Pas besoin de getters car on utilise que 
// une seule fois les variables dans affiche rapport donc pas necessaire  