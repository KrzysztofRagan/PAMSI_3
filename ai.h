#pragma once
#include "plansza.h"




struct AiMove
{
	AiMove();
	AiMove(int Score);
	int x;
	int y;
	int score;

};

class Ai
{
private:
	Gracz _aiPlayer;
	Gracz _humanPlayer;
public:
	AiMove getBestMove(Plansza& plansza,Gracz gracz);
	void init(char aiPlayer);
	void performMove(Plansza &plansza);
};