#include "plansza.h"

using namespace std;




Gracz::Gracz()
{
}

bool Gracz::czyAI()
{
	return _czyAI;
}

void Gracz::czyAI(bool czy)
{
	if (czy == AI)_czyAI = AI;
	else _czyAI = CZLOWIEK;
}


Plansza::Plansza()
{
}

Plansza::Plansza(int wymiar)
{
	_wymiar = wymiar;
	// tablica na wskazniki
	tablica = new char *[wymiar];
	// generowanie poszczegolnych wymiarów
	for (int i = 0; i < wymiar; i++)
		tablica[i] = new char[wymiar];

	for (int i = 0; i < wymiar; ++i)
	{
		for (int j = 0; j < wymiar; ++j)
		{
			tablica[i][j] = NIC;
		}
	}
}

Plansza::Plansza(int wymiar, int dowygranej)
{
	
	if (wymiar < dowygranej)
	{
		cout << "Rozmiar planszy jest mniejszy niż ilość elementów określających wygraną" << endl;
	}
	else {
		_wymiar = wymiar;
		_dowygranej = dowygranej;

		// tablica na wskazniki
		tablica = new char* [wymiar];
		// generowanie poszczegolnych wymiarów
		for (int i = 0; i < wymiar; i++)
			tablica[i] = new char[wymiar];

		for (int i = 0; i < wymiar; ++i)
		{
			for (int j = 0; j < wymiar; ++j)
			{
				tablica[i][j] = NIC;
			}
		}
	}
}

void Plansza::init(int wymiar)
{
	_wymiar = wymiar;
	// tablica na wskazniki
	tablica = new char *[wymiar];
	// generowanie poszczegolnych wymiarów
	for (int i = 0; i < wymiar; i++)
		tablica[i] = new char[wymiar];

	for (int i = 0; i < wymiar; ++i)
	{
		for (int j = 0; j < wymiar; ++j)
		{
			tablica[i][j] = NIC;
		}
	}
}

void Plansza::init(int wymiar, int dowygranej)
{
	
	if (wymiar < dowygranej)
	{
		cout << "Rozmiar planszy jest mniejszy niz ilosc elementow okreslajacych wygrana" << endl;
	}
	else {
		_wymiar = wymiar;
		_dowygranej = dowygranej;

		// tablica na wskazniki
		tablica = new char* [wymiar];
		// generowanie poszczegolnych wymiarów
		for (int i = 0; i < wymiar; i++)
			tablica[i] = new char[wymiar];

		for (int i = 0; i < wymiar; ++i)
		{
			for (int j = 0; j < wymiar; ++j)
			{
				tablica[i][j] = NIC;
			}
		}
	}
}
 
int Plansza::getSize()
{
	return _wymiar;
}

void Plansza::setVal(int x, int y, char val)
{
	while (true)
	{
		if (tablica[x][y] == NIC)
		{
			tablica[x][y] = val;
			break;
		}
		else if (val == NIC)
		{
			tablica[x][y] = val;
			break;
		}
	}
}

char Plansza::getVal(int x, int y)
{
	return tablica[x][y];
}

void Plansza::clear()
{
	for (int i = 0; i < _wymiar; ++i)
	{
		for (int j = 0; j < _wymiar; ++j)
		{
			this->setVal(i, j, NIC);
		}		
	}
}

void Plansza::print()
{
	cout << "\n\n\n\n\nAKTUALNY STAN GRY:\n";

		for (int i = 0; i < _wymiar; ++i)
		{
			for (int j = 0; j < _wymiar; ++j)
			{
				cout << "| " << this->getVal(i, j) << " ";
			}			
			cout << "|\n";
			if (i < _wymiar - 1)
			{
				for(int k=0;k<_wymiar;++k)cout << " ---";
				cout << "\n";				
			}
		}
		
}
//TO DO: NAPRAWIĆ ZLICZANIE W RZĘDZIE!!!!
//ZROBIONE
char Plansza::czyWygrana()
{
	bool wygrana=false;
	char poprzednie,teraz;
	int licznik = 0;

	//sprawdź w wierszach
	for (int i = 0; i < _wymiar; ++i)
	{
		for (int j = 0; j < _wymiar; ++j)
		{

			teraz = this->getVal(i, j);
			if (licznik == 0)
			{
				licznik++;
			}
			else 
			{
				if (poprzednie == teraz && teraz != NIC)licznik++;
				else licznik = 1;
			}
			poprzednie = teraz;
			if (licznik == _dowygranej)
			{
				wygrana = true;
			}
			if (wygrana)
			{
				return teraz;
			}
		}
		
		licznik = 0;
	}

	//sprawdz w kolumnach

	for (int i = 0; i < _wymiar; ++i)
	{
		for (int j = 0; j < _wymiar; ++j)
		{

			teraz = this->getVal(j, i);
			if (licznik == 0)
			{
				licznik++;
			}
			else
			{
				if (poprzednie == teraz && teraz != NIC)licznik++;
				else licznik = 1;
			}
			poprzednie = teraz;
			if (licznik == _dowygranej)
			{
				wygrana = true;
			}
			if (wygrana)
			{
				return teraz;
			}
		}
		
		licznik = 0;
	}
	 //po przekatnych
	//jesli _wymiar==_dowygranej to tylko dwie przekatne do sprawdzenia
	//od lewej góry

	
	
	//glowna przekatna
	
	for (int i = 0; i < _wymiar; ++i)
	{
		teraz = this->getVal(i, i);
		if (licznik == 0)
		{
			licznik++;
		}
		else
		{
			if (poprzednie == teraz && teraz != NIC)licznik++;
			else licznik = 1;
		}
		poprzednie = teraz;
		if (licznik == _dowygranej)
		{
			wygrana = true;
		}
		if (wygrana)
		{
			return teraz;
		}
	}

	int roznica = _wymiar - _dowygranej;
	//lewo nad główną
	for (int i = 1; i <= roznica ; ++i)
	{
		for (int j = 0; j < _wymiar - i; ++j)
		{
			teraz = this->getVal(j, i+j);
			if (licznik == 0)
			{
				licznik++;
			}
			else
			{
				if (poprzednie == teraz && teraz != NIC)licznik++;
				else licznik = 1;
			}
			poprzednie = teraz;
			if (licznik == _dowygranej)
			{
				wygrana = true;
			}
			if (wygrana)
			{
				return teraz;
			}
		}
		licznik = 0;
	}

	//lewo pod główną
			
	for (int i = 1; i <= roznica; ++i)
	{
		for (int j = 0; j < _wymiar-i; ++j)
		{

			teraz = this->getVal(i+j, j);
			if (licznik == 0)
			{
				licznik++;
			}
			else
			{
				if (poprzednie == teraz && teraz != NIC)licznik++;
				else licznik = 1;
			}
			poprzednie = teraz;
			if (licznik == _dowygranej)
			{
				wygrana = true;
			}
			if (wygrana)
			{
				return teraz;
			}
		}
		licznik = 0;
	}
	


	//od prawej góry

	//glowna przekatna
	licznik = 0;
	for (int i = 0; i < _wymiar; ++i)
	{
		teraz = this->getVal(i, _wymiar-i-1);
		if (licznik == 0)
		{
			licznik++;
		}
		else
		{
			if (poprzednie == teraz && teraz != NIC)licznik++;
			else licznik = 1;
		}
		poprzednie = teraz;
		if (licznik == _dowygranej)
		{
			wygrana = true;
		}
		if (wygrana)
		{
			return teraz;
		}
	}

	//prawo nad główną
	for (int i = 1; i <= roznica; ++i)
	{
		for (int j = 0; j < _wymiar - i; ++j)
		{
			teraz = this->getVal(j, _wymiar-i-1 - j);
			if (licznik == 0)
			{
				licznik++;
			}
			else
			{
				if (poprzednie == teraz && teraz != NIC)licznik++;
				else licznik = 1;
			}
			poprzednie = teraz;
			if (licznik == _dowygranej)
			{
				wygrana = true;
			}
			if (wygrana)
			{
				return teraz;
			}
		}
		licznik = 0;
	}


	//prawo pod glowna
	for (int i = 1; i <= roznica; ++i)
	{
		for (int j = 0; j < _wymiar-i; ++j)
		{

			teraz = this->getVal(_wymiar - i - 1 - j, j);
			if (licznik == 0)
			{
				licznik++;
			}
			else
			{
				if (poprzednie == teraz && teraz != NIC)licznik++;
				else licznik = 1;
			}
			poprzednie = teraz;
			if (licznik == _dowygranej)
			{
				wygrana = true;
			}
			if (wygrana)
			{
				return teraz;
			}
		}
		licznik = 0;
	}


	//czy remis
	for (int i = 0; i < _wymiar; ++i)
	{
		for (int j = 0; j < _wymiar; ++j)
		{
			if (this->getVal(i, j) == NIC)return NIC;
		}
	}
	return TIE_VAL;
}