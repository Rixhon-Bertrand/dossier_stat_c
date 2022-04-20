#ifndef DataSourceSerieContinue_H
#define DataSourceSerieContinue_H

#include "DataSource.h"
#include "Liste.h"
#include "Data1D.h"

class DataSourceSerieContinue: DataSource
{
	private:
		Liste<Data1D> *L;
		float _debut;
		float _intervalle;
	public:
		DataSourceSerieContinue();
		~DataSourceSerieContinue();
};

#endif