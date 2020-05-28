#include "plansza.h"
#include "gra.h"
#include "ai.h"
#include <iostream>
using namespace std;

int main()
{
    std::cout << "Hello World!\n"; 
	//Plansza nowa_gra(4);


	/*
	nowa_gra.setVal(0, 0, O_VAL);
	nowa_gra.setVal(0, 1, NIC);
	nowa_gra.setVal(0, 2, O_VAL);
	nowa_gra.setVal(1, 0, X_VAL);
	nowa_gra.setVal(1, 1, O_VAL);
	nowa_gra.setVal(1, 2, X_VAL);
	nowa_gra.setVal(1, 3, X_VAL);
	nowa_gra.setVal(2, 2, O_VAL);
	nowa_gra.setVal(2, 0, O_VAL);
	nowa_gra.setVal(2, 1, NIC);
	nowa_gra.setVal(2, 2, X_VAL);
	nowa_gra.setVal(3, 3, O_VAL);

	nowa_gra.print();
	
	cout<<"\n\n"<<nowa_gra.czyWygrana();
	*/

	Gra nowa_gra(menuRozmiar(), menuDowygrania());
	/*
	nowa_gra._plansza.setVal(0, 0, X_VAL);
	nowa_gra._plansza.setVal(0, 1, O_VAL);
	nowa_gra._plansza.setVal(1, 0, X_VAL);
	nowa_gra._plansza.setVal(1, 1, X_VAL);
	nowa_gra._plansza.setVal(2, 0, O_VAL);
	nowa_gra._plansza.setVal(2, 1, O_VAL);
	nowa_gra._plansza.setVal(1, 3, X_VAL);
	nowa_gra._plansza.setVal(3, 0, O_VAL);
	nowa_gra._plansza.setVal(2, 2, O_VAL);	
	*/
	nowa_gra.start_gry();
	nowa_gra.run();



	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
