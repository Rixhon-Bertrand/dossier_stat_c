#ifndef DataSourceSerieContinue_H
#define DataSourceSerieContinue_H

#include "DataSource.h"
#include "Liste.h"
#include "Data1D.h"

class DataSourceSerieContinue: public DataSource
{
	private:
		Liste<Data1D> *_listeData1D;
		Liste<Data1D> *_listeNumeric;
		float _debut;
		float _intervalle;
	public:
		DataSourceSerieContinue();
		DataSourceSerieContinue(const char*, const char*, int, int, Liste<Data1D>*);
		~DataSourceSerieContinue();

		Liste<Data1D>* getListe() const { return _listeData1D; };
		Liste<Data1D>* getListeNumeric() const { return _listeNumeric; };
		void setListe(Liste<Data1D>*);

		void afficheListe();
};

#endif