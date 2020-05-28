#pragma once
#include "plansza.h"
#include "ai.h"
#include <iostream>

const bool PLAYING = 1;
const bool EXIT = 0;



class Gra
{
	Ai graczAI;
	bool czyMultiplayer;
	char czyja_kolej;
	
	bool gameState;
	Gracz X;
	Gracz O;
	   
public:
	Plansza _plansza;
	Gra();
	Gra(int wymiar_planszy, int dowygranej);	
	void start_gry();
	void koniec_gry();
	void zmiana_gracza();
	void playerMove(Gracz gracz);
	void aiMove(Gracz gracz);
	void run();
};

char menuZnaku();
bool menuMultiplayer();
int menuRozmiar();
int menuDowygrania();