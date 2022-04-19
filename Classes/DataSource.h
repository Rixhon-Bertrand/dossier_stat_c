#ifndef DataSource_H
#define DataSource_H

class DataSource
{
	private:
		char* _nom;
		char* _sujet;
		int _effTotal;
		int _type;
	public:
		DataSource();
		DataSource(const char*, const char*, int, int);
		DataSource(const DataSource&);
		~DataSource();

		//setter/getter
		void setNom(const char*);
		char* getNom()const;
		void setSujet(const char*);
		char* getSujet()const;
		void setEffTotal(int);
		int getEff() const {return _effTotal;}
		void setType(int);
		int getType() const {return _type;}

		//fonctions
		void Affiche() const;
};

#endif