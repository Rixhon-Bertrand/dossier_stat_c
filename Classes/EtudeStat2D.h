#ifndef EtudeStat2D_H
#define EtudeStat2D_H

#include "Echantillon.h"

class EtudeStat2D
{
	private:
		Echantillon* _data;
		float _moyenne1; // X
		float _moyenne2; // Y
		float _A;
		float _B;
		float _corr;
	public:
		EtudeStat2D();
		EtudeStat2D(char*,int,int);
		~EtudeStat2D();

		//setters
		void setData(Echantillon* );
		void setMoyenne(Echantillon*);
		void setCoeffA(Echantillon*);
		void setCoeffB(Echantillon*);
		void setCorr(Echantillon*);

		//getters 
		Echantillon* getData() const { return _data; };
		float getMoyenneX() const { return _moyenne1; };
		float getMoyenneY() const { return _moyenne2; };
		float getA() const { return _A; };
		float getB() const { return _B; };
		long double getCorr() const { return _corr; };

		void AfficheRapport(Echantillon* data);
};

#endif