#include <iostream>
using namespace std;

//#include "Data1D.h"
#include "EtudeStatDescriptive.h"
//#include "Echantillon.h"
#include "Exception.h"


int main(int argc,char* argv[])
{

	printf("Début de l'applic\n");

	try
	{
		EtudeStatDescriptive E(argc,argv);
	}
	catch (Exception const& e)
	{
		cout << "Err. : " << e.getMessage() << endl;
	}
}
