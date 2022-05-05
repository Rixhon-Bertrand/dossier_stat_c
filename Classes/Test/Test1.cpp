#include <stdlib.h>
#include <iostream>
using namespace std;
// #include <time.h>
// #include <string.h>
// #include <fstream> 
#include "Echantillon.h"
// #include "DataSource.h"
// #include "Liste.h"
// #include "ListeTriee.h"
// #include "Data1D.h"
// #include "DataSourceSerieContinue.h"
// #include "DataSourceSerieDiscrete.h"
// #include "Iterateur.h"



int  Menu();
void Essai1();
void Essai2();
void Essai3();
void Essai4();
void Essai5();

int main(int argc,char* argv[])
{
  int choix;
  bool fini = false;
  
  while(!fini)
  {
    if (argc == 2) { choix = atoi(argv[1]); fini = true; }
    else choix = Menu();
    switch(choix)
    {
      case 1 : Essai1(); break;
      case 2 : Essai2(); break;
      case 3 : Essai3(); break;
      case 4 : Essai4(); break;
      case 5 : Essai5(); break;
      default : 
      cout << endl << "Vous avez quittez l'application" << endl;
      fini = true ; break;
    }
  }

  return 0;
}

int Menu()
{
  cout << endl;
  cout << "----------------------------------------------------------------------------" << endl;
  cout << "--- JEU DE TEST ------------------------------------------------------------" << endl;
  cout << "----------------------------------------------------------------------------" << endl;
  cout << " 1. Test MultiC" << endl;
  cout << " 2. Test MultiD" << endl;
  cout << " 3. Test MultiD Error" << endl;
  cout << " 4. Test MultiC Error" << endl;
  cout << " 5. Test " << endl;
  cout << " 0. Quitter" << endl << endl;

  int ch;
  cout << "  Choix : ";
  cin >> ch; // Faites pas le biess !
  cin.ignore();
  return ch;
}

/***********************************************************************************************/
// A FAIRE : test de la classe Data1D avec le test des liste et liste triées 
void Essai1()
{

  // Echantillon TestEchantC("MultiC.dat",2);

  // cout << endl << "Test colonne inexistante" << endl << endl;

  // 

  Echantillon TestEchantC("MultiC.dat",1);
  // cout << endl << "Test pas de colonne" << endl << endl;


}

void Essai2()
{

    // Echantillon TestEchantD("DonneesNbEnf.txt");

    Echantillon TestEchantD("MultiD.dat",2);
}

void Essai3()
{ 
  Echantillon TestEchantC("MultiC.dat",24);
}

void Essai4()
{
  Echantillon TestEchantD("MultiD.dat",25);
}

void Essai5()
{
 
}