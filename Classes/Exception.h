#ifndef Exception_H
#define Exception_H

#include "BaseException.h"

class Exception :public BaseException
{
	private:
		int _code;

	public:

		//constructeurs
		Exception(); 
		Exception(const int); 
		~Exception();
		
		int getCode()const;
		void setCode(const int);

		//variable statique
        static const int ERROR_BEGIN;
};

#endif