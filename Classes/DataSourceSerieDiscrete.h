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
		DataSourceSerieDiscrete(const char*, const char*, int, int, Liste<Data1D>* );
		virtual ~DataSourceSerieDiscrete();

		//fonctions
		void afficheListe();
};

#endif