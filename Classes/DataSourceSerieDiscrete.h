#ifndef DataSourceSerieDiscrete_H
#define DataSourceSerieDiscrete_H

class DataSourceSerieDiscrete: public DataSource
{
	private:
		Liste<Data1D> *L;
	public:
		DataSourceSerieDiscrete();
};

#endif