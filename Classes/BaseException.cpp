#include <iostream>
#include <string.h>

using namespace std;
#include "BaseException.h"

//destructeur 
BaseException::~BaseException()
{
	#ifdef DEBUG
	cout << " *> Destructeur BaseException" << endl; 
	#endif 

	if(_message)
		delete [] _message;
}

// getters

char* BaseException::getMessage()const
{
    return _message;
}

//setters

void BaseException::setMessage(const char* intitule)
{
    if(_message)
    {
        delete []_message;
    }
    if(intitule)
    {
        _message = new char[strlen(intitule) + 1];
        strcpy(_message,intitule);
        return;
    }
    _message = NULL;
}