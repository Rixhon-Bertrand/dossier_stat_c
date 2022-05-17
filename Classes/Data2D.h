#ifndef Data2D_h
#define Data2D_h

class Data2D
{
	//pour permettre l'affichage des data2D dans la liste
	friend ostream& operator<<(ostream&, const Data2D&);

	private:
		float _val1;
		float _val2;

	public:
		Data2D();
		Data2D(float,float);
		Data2D(const Data2D&);
		~Data2D();

		void setVal1(float val) { _val1 = val; };
		void setVal2(float val) { _val2 = val; };
		float getVal1() const { return _val1; };
		float getVal2() const { return _val2; };
		
		Data2D& operator=(const Data2D&);
		bool operator<=(const Data2D&);
};

#endif