#include "ai.h"

#include<vector>
using namespace std;



AiMove::AiMove()
{
}

AiMove::AiMove(int Score)
{
	score = Score;
}


void Ai::init(char aiPlayer)
{
	_aiPlayer._znak = aiPlayer;
	if (aiPlayer == X_VAL)_humanPlayer._znak = O_VAL;
	else _humanPlayer._znak = X_VAL;
	_aiPlayer._czyAI = true;
	_humanPlayer._czyAI = false;
}

void Ai::performMove(Plansza& plansza)
{
	AiMove best_move = getBestMove(plansza, _aiPlayer);
	plansza.setVal(best_move.x, best_move.y, _aiPlayer._znak);
}

AiMove Ai::getBestMove(Plansza & plansza, Gracz gracz)
{
	//base case, sprawdzamy czy zwycieztwo
	char rv = plansza.czyWygrana();
	if (rv == _aiPlayer._znak)
	{
		return AiMove(10);
	}
	else if(rv == _humanPlayer._znak)
	{
		return AiMove(-10);
	}
	else if (rv == TIE_VAL)
	{
		return AiMove(0);
	}

	//wektor z ruchami
	vector<AiMove>moves;

	for (int y = 0; y < plansza.getSize(); ++y)
	{
		for (int x = 0; x < plansza.getSize(); ++x)
		{
			if (plansza.getVal(x, y) == NIC)
			{
				AiMove move;
				move.x = x;
				move.y = y;
				plansza.setVal(x, y, gracz._znak);
				if (gracz.czyAI())
				{
					move.score = getBestMove(plansza, _humanPlayer).score;
				}
				else
				{
					move.score = getBestMove(plansza, _aiPlayer).score;
				}
				moves.push_back(move);
				plansza.setVal(x, y, NIC);
			}
		}
	}

	//indeks najlepszego ruchu w wektorze
	int BestMove = 0;

	//sprawdzamy ktory ruch najlepszy (zalezy od gracza, ai chce najwyzszy wynik a czlowiek najnizszy)
	if(gracz.czyAI())
	{
		int BestScore = -1000000;
		for (int i = 0; i < moves.size(); ++i)
		{
			if (moves[i].score > BestScore)
			{
				BestMove = i;
				BestScore = moves[i].score;
			}
		}

	}
	else
	{
		int BestScore = 1000000;
		for (int i = 0; i < moves.size(); ++i)
		{
			if (moves[i].score < BestScore)
			{
				BestMove = i;
				BestScore = moves[i].score;
			}
		}
	}
	//cout << "Dzialam dalej\n";
	return moves[BestMove];
}