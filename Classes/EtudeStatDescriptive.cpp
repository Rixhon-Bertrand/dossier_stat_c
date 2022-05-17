#include <stdlib.h>
#include <iostream>
#include <string.h>
#include <fstream> 

using namespace std;
#include "EtudeStatDescriptive.h"
#include "Exception.h"
#include "EtudeStat1D.h"
#include "EtudeStat2D.h"
// ------ CONSTRUCTORS
EtudeStatDescriptive::EtudeStatDescriptive(int argc, char* argv[])
{
    #ifdef DEBUG
        cout << "Constructeur par d'init de EtudeStatDescriptive" << endl;
    #endif

    if (argc == 2)
    {
        EtudeStat1D E(argv[1],0);
    }
    else if (argc == 3)
    {
        EtudeStat1D E(argv[1],atoi(argv[2]));
    }

    else if (argc == 4)
    {
        EtudeStat2D E(argv[1],atoi(argv[2]),atoi(argv[3]));
    }
    else
    {
        throw Exception(Exception::ERROR_BEGIN);
    }
}

EtudeStatDescriptive::~EtudeStatDescriptive()
{

}
// ----- SETTERS // GETTERS

// ----- FONCTIONS

// ----- OPERATORS