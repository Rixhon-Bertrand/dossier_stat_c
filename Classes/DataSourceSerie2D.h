#ifndef DataSourceSerie2D_H
#define DataSourceSerie2D_H

#include "DataSource.h"
#include "Liste.h"
#include "Data2D.h"

class DataSourceSerie2D: public DataSource
{
	private:
		Liste<Data2D> _listeData2D;
		char* _sujet2;
		int _type2;
	public:
		DataSourceSerie2D();
		DataSourceSerie2D(const char* nom, const char* sujet1, const char* sujet2, int type1, int type2, int effTotal,Liste<Data2D> listeData);
		~DataSourceSerie2D();

		void setSujet2(const char* intitule);
		void setType2(int type) { _type2 = type; };
		char* getSujet2() const { return _sujet2; };
		int getType2() const { return _type2; };
		Liste<Data2D> getListe() const { return _listeData2D; };
		void setListe(Liste<Data2D>);
};

#endif