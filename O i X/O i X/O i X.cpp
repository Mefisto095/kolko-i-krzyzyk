
#include <iostream>
using namespace std;
int main()
{
	char wygrywa;
	int licznik = 1;
	int adres;
	char symbol;
	char pole[9];
	for (int i = 0; i < 9; i++)
	{
		pole[i] = ' ';
	}

	do {
		(licznik % 2 == 0) ? symbol = 'O' : symbol = 'X';
#pragma region rysowanie
		cout << licznik << " Ruch " << symbol << endl;
		cout << pole[0] << '|' << pole[1] << '|' << pole[2] << endl;
		cout << '-' << '+' << '-' << '+' << '-' << endl;
		cout << pole[3] << '|' << pole[4] << '|' << pole[5] << endl;
		cout << '-' << '+' << '-' << '+' << '-' << endl;
		cout << pole[6] << '|' << pole[7] << '|' << pole[8] << endl;
#pragma endregion
#pragma region wygrana
		if (pole[0] == pole[2] && pole[0] == pole[1] && pole[0] != ' ')
		{
			wygrywa = pole[0];
			break;
		}
		if (pole[3] == pole[5] && pole[3] == pole[4] && pole[3] != ' ')
		{
			wygrywa = pole[3];
			break;
		}
		if (pole[6] == pole[8] && pole[6] == pole[7] && pole[6] != ' ')
		{
			wygrywa = pole[6];
			break;
		}
		if (pole[0] == pole[6] && pole[0] == pole[3] && pole[0] != ' ')
		{
			wygrywa = pole[0];
			break;
		}
		if (pole[1] == pole[7] && pole[1] == pole[4] && pole[1] != ' ')
		{
			wygrywa = pole[1];
			break;
		}
		if (pole[2] == pole[8] && pole[2] == pole[5] && pole[2] != ' ')
		{
			wygrywa = pole[2];
			break;
		}
		if (pole[0] == pole[8] && pole[0] == pole[4] && pole[0] != ' ')
		{
			wygrywa = pole[0];
			break;
		}
		if (pole[2] == pole[6] && pole[2] == pole[4] && pole[2] != ' ')
		{
			wygrywa = pole[2];
			break;
		}
#pragma endregion

		cout << "wybierz pole" << endl;
	nie:
		cin >> adres;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Wprowadz poprawne dane." << endl;
			goto nie;
		}
#pragma region antyzapis


		if (pole[adres] == ' ')
		{
			pole[adres] = symbol;
			licznik++;
		}
		else
		{
			
			cout << "To pole jest zajete, wprowadz poprawne dane." << endl;
			goto nie;
		}

#pragma endregion
	} while (true);
	cout << "Wygrywa " << wygrywa << '!' << endl;
}

