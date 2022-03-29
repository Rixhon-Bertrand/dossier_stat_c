#ifndef BASE_EXCEPTION_H
#define BASE_EXCEPTION_H

class BaseException
{
	protected:
		char * _message;

	public:

		//destructeur
		virtual ~BaseException();
		
		virtual int getCode()const = 0;
		virtual void setCode(const int) = 0;

		void setMessage(const char*);
		char* getMessage()const;

};

#endif