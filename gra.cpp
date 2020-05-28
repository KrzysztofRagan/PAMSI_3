#include "gra.h"
#include "plansza.h"


using namespace std;




Gra::Gra()
{
	gameState = EXIT;
}

Gra::Gra(int wymiar_planszy, int dowygranej)
{
	_plansza.init(wymiar_planszy, dowygranej);
	gameState = EXIT;
}


void Gra::start_gry()
{
	O._znak = O_VAL;
	X._znak = X_VAL;
	gameState = PLAYING;
	czyMultiplayer = menuMultiplayer();
	czyja_kolej = O_VAL;
	
	if (czyMultiplayer)
	{
		O.czyAI(CZLOWIEK);
		X.czyAI(CZLOWIEK);
	}
	else
	{
		if (menuZnaku() == 'o')
		{
			O.czyAI(CZLOWIEK);
			X.czyAI(AI);
			graczAI.init(X_VAL);
		}
		else
		{
			O.czyAI(AI);
			graczAI.init(O_VAL);
			X.czyAI(CZLOWIEK);
		}
	}
}

void Gra::zmiana_gracza()
{
	if (czyja_kolej == O_VAL)czyja_kolej = X_VAL;
	else czyja_kolej = O_VAL;
}

void Gra::playerMove(Gracz gracz)
{
	int x, y;
	while (true)
	{
		cout << "Gdzie chcesz postawic znak? wspolrzedna x: ";
		cin >> x;
		cout << " wspolrzedna y: ";
		cin >> y;
		if (_plansza.getVal(x, y) == NIC)
		{
			_plansza.setVal(x, y, gracz._znak);
			break;
		}
		else
		{
			cout << "Pole zajete, wybierz ponownie.\n";
		}
	}
}

void Gra::aiMove(Gracz gracz)
{
	graczAI.performMove(_plansza);
}

void Gra::koniec_gry()
{
	gameState = false;
}

void Gra::run()
{
	while (gameState)
	{
		_plansza.print();
		if (czyja_kolej == X_VAL)
		{
			cout << "Kolej gracza X!\n";
		}
		else
		{
			cout << "Kolej gracza O!\n";
		}
		//czyj ruch?
		switch (czyja_kolej)
		{
		case X_VAL:
		{
			if (X.czyAI())this->aiMove(X);
			else playerMove(X);		
			break;
		}
		case O_VAL:
		{
			if (O.czyAI())this->aiMove(O);
			else playerMove(O);
			break;
		}
		default:
			break;
		}
		//sprawdz czy ktoś wygrał
		if (_plansza.czyWygrana() != NIC)
		{
			_plansza.print();
			gameState = false;
			switch (_plansza.czyWygrana())
			{
			case TIE_VAL:
			{
				cout << "REMIS!\n";
				break;
			}
			default:
				cout << "WYGRAL GRACZ " << _plansza.czyWygrana() << "!\n";
				break;
			}		
		}
		else
		{
			zmiana_gracza();
			cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
		}
	}
}

bool menuMultiplayer()
{
	bool odp=false,rv;
	char decyzja;
	while (odp == false)
	{
		cout << "Czy chcesz grac na dwoch graczy? t/n:";
		cin >> decyzja;
		cout << "\n";
		switch (decyzja)
		{
		case 't':
			rv = true;
			odp = true;
			break;
		case 'n':
			rv = false;
			odp = true;
			break;
		default:
			cout << "zla odpowiedz :(\n";
			odp = false;
			break;
		}
	}
	switch (rv)
	{
	case true:
		cout << "\nGRA MULTIPLAYER\n";
		break;
	case false:
		cout << "\nGRA vs AI\n";
		break;
	}
	return rv;
}

int menuRozmiar()
{
	int rozmiar;
	cout << "\nWprowadz rozmiar planszy: ";
	cin >> rozmiar;
	return rozmiar;
}

int menuDowygrania()
{
	int rv;
	cout << "\nIle znakow w linii do wygranej? :";
	cin >> rv;
	return rv;
}

char menuZnaku()
{
	bool odp=false;
	char rv, decyzja;
	while (odp == false)
	{
		cout << "Ktorym znakiem chcesz grac? x/o:";
		cin >> decyzja;
		cout << "\n";
		switch (decyzja)
		{
		case 'o':
			rv = decyzja;
			odp = true;
			break;
		case 'x':
			rv = decyzja;
			odp = true;
			break;
		default:
			cout << "zla odpowiedz :(\n";
			odp = false;
			break;
		}
	}
	switch (rv)
	{
	case 'x':
		cout << "\nGrasz jako X\n";
		break;
	case 'o':
		cout << "\nGrasz jako O\n";
		break;
	}
	return rv;
}