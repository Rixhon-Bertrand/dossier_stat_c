#ifndef Echantillon_H
#define Echantillon_H

#include"DataSource.h"
#include "Liste.h"
#include "ListeTriee.h"
#include "Data1D.h"
#include "DataSourceSerieContinue.h"
#include "DataSourceSerieDiscrete.h"
#include "Iterateur.h"

class Echantillon
{
	private:
		DataSource *_source;
	public:
		Echantillon();
		Echantillon(const char *,int );
		~Echantillon();

		bool importeFichier(const char* nomFichier, int col);
		Liste<Data1D>* calculEffectif(ListeTriee<float> listeT);
};

#endif