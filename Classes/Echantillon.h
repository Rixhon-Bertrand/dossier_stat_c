#ifndef Echantillon_H
#define Echantillon_H

#include"DataSource.h"
#include "Liste.h"
#include "ListeTriee.h"
#include "Data1D.h"
#include "Data2D.h"
#include "DataSourceSerieContinue.h"
#include "DataSourceSerieDiscrete.h"
#include"DataSourceSerie2D.h"
#include "Iterateur.h"

class Echantillon
{
	private:
		DataSource *_source;
	public:
		Echantillon();
		Echantillon(const char *);
		Echantillon(const char *,int );
		Echantillon(const char *,int ,int );
		~Echantillon();

		DataSource* getSource() const { return _source; };

		bool importeFichier(const char* nomFichier, int col);
		Liste<Data1D>* calculEffectif(ListeTriee<float> listeT);

		float split(char* chaine, const char* delimiteur, int col);
		char* splitNom(char* chaine, const char* delimiteur, int col);
		bool VerifColonnesFichier(char* chaine, const char* delimiteur, int col);
		bool verifColonnes(const char* nomFichier, int col);
		bool importeFichier2D(const char* nomFichier, int col1,int col2);
		float split2D(char* chaine, const char* delimiteur, int col1, int col2);
};

#endif