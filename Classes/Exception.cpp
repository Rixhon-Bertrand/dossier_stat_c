#include <iostream>
#include <string.h>

using namespace std;
#include "Exception.h"

const int Exception::ERROR_BEGIN = 1;

//constructeur par défaut
Exception::Exception()
{
	#ifdef DEBUG	
	cout << " *> Constructeur par déf. Exception" << endl;
	#endif 

	_message = NULL;
	setCode(-1);
}
//constructeur d'initialisation 
Exception::Exception(const int code)
{
	#ifdef DEBUG
	cout << " *> Constructeur init. Exception" << endl; 
	#endif 

	setCode(code);
	_message = NULL;

	switch(code)
	{
		case 1:
			setMessage("Erreur mauvais parametre");
			break;
		default:
			break;
	}

}

//destructeur 
Exception::~Exception()
{
	#ifdef DEBUG
	cout << " *> Destructeur Exception" << endl; 
	#endif 
}

// getters

int Exception::getCode()const
{
    return _code;
}

// setters

void Exception::setCode(const int code)
{
    _code = code;
}