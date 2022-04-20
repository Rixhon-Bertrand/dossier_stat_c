#ifndef DataSourceSerieDiscrete_H
#define DataSourceSerieDiscrete_H

#include "DataSource.h"
#include "Liste.h"
#include "Data1D.h"

class DataSourceSerieDiscrete: public DataSource
{
	private:
		Liste<Data1D> *_listeData1D;
	public:
		DataSourceSerieDiscrete();
		~DataSourceSerieDiscrete();

		//fonctions
		void pushListe(float, int);
		void afficheListe();
};

#endif