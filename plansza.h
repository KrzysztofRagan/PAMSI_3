#pragma once
#include <iostream>

const char X_VAL = 'X';
const char O_VAL = 'O';
const char NIC = ' ';
const char TIE_VAL = 'r';
const bool AI = 1;
const bool CZLOWIEK = 0;


class Plansza
{
	int _wymiar;
	int _dowygranej = 3;//domyślnie 3 do wygranej
	char** tablica;

public:
	Plansza();
	Plansza(int wymiar);  //konstruktory
	Plansza(int wymiar, int dowygranej);
	void init(int wymiar);
	void init(int wymiar, int dowygranej);
	void clear();
	void print();
	char getVal(int x, int y);
	void setVal(int x, int y, char val);
	char czyWygrana();
	int getSize();

};


struct Gracz
{
	

public:
	bool _czyAI;
	char _znak;
	Gracz();
	void czyAI(bool czy);
	bool czyAI();
};