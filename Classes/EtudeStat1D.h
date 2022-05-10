#ifndef EtudeStat1D_H
#define EtudeStat1D_H


#include "Echantillon.h"

class EtudeStat1D
{
	private:
		Echantillon* _data;
		float _moyenne;
		float _ecartType;
		float _mediane;
		float _mode[5];
		float _variation;
		float _min;
		float _max;
		float _etendue;

	public:

		EtudeStat1D();
		EtudeStat1D(char*, int);
		~EtudeStat1D();

	//Setters Calculs
		void setData(Echantillon* );
		void setMoyenne(Echantillon* );
		void setMediane(Echantillon* );
		void setMode(Echantillon* );
		void setEcartType(Echantillon* );
		void setVariation(Echantillon* );
		void setMin(Echantillon* );
		void setMax(Echantillon* );
		void setEtendue();

		
	//Getters
		Echantillon* getData() const { return _data; };
		float getMoyenne() const { return _moyenne; };
		float getMediane() const { return _mediane; };
		float getMode(short i) const { return _mode[i]; };
		const float* getMode() const { return _mode; };
		float getEcartType() const { return _ecartType; };
		float getVariation() const { return _variation; };
		float getMin() const { return _min; };
		float getMax() const { return _max; };
		
		void AfficheRapport(Echantillon* );
};

#endif