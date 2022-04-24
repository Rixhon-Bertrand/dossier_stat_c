#ifndef DataSourceSerieContinue_H
#define DataSourceSerieContinue_H

#include "DataSource.h"
#include "Liste.h"
#include "Data1D.h"

class DataSourceSerieContinue: public DataSource
{
	private:
		Liste<Data1D> *_listeData1D;
		float _debut;
		float _intervalle;
	public:
		DataSourceSerieContinue();
		DataSourceSerieContinue(const char*, const char*, int, int, Liste<Data1D>*);
		~DataSourceSerieContinue();

		float calculDebut(); //TO DO
		float calculIntervalle(); //TO DO

		void afficheListe();
};

#endif