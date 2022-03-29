#ifndef Data1D_h
#define Data1D_h

class Data1D
{
	friend ostream& operator<<(ostream&, const Data1D&);

	private:
		float _val;
		int _eff;

	public:
		Data1D();
		Data1D(float, int);
		Data1D(const Data1D&);
		~Data1D();

		void setVal(float);
		int getVal() const {return _val;}
		void setEff(int);
		int getEff() const {return _eff;}

		Data1D& operator=(const Data1D&);
        bool operator<=(const Data1D&); // car besoin pour trier les listes
};

#endif