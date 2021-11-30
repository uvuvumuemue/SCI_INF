#include<iostream>
#include<vector>
#include<stdlib.h>
#include "sortowanie.h"
using namespace std;
void sortowanie::wyswietlanie() {
	cout << "\n----------------------------------------------------";
	for (int i = 0; i < liczby_wylosowane.size(); i++)
	{
		cout << "\n" << "liczba nr " << i + 1 << ": " << liczby_wylosowane[i];
	}
	cout << "\n----------------------------------------------------";
}
void sortowanie::generator() {
	srand(time(NULL));
	for (int i = 0; i < 100; i++)
	{
		liczby_wylosowane.push_back(rand() % 1001);
	}
	wyswietlanie();
}
void sortowanie::bombelkowy() {
	for (int i = 0; i < liczby_wylosowane.size() - 1; i++)
	{
		for (int i = 0; i < liczby_wylosowane.size() - 1; i++)
		{

			if (liczby_wylosowane[i] > liczby_wylosowane[i + 1]) {
				int temp = liczby_wylosowane[i];
				liczby_wylosowane[i] = liczby_wylosowane[i + 1];
				liczby_wylosowane[i + 1] = temp;
			}
		}
	}
	wyswietlanie();
}
void sortowanie::wstawianie() {

	for (int j = liczby_wylosowane.size() - 1; j >= 0; j--)
	{
		x = liczby_wylosowane[j];
		i = j + 1;
		while (i<liczby_wylosowane.size() && x>liczby_wylosowane[i])
		{
			liczby_wylosowane[i - 1] = liczby_wylosowane[i];
			i++;
		}
		liczby_wylosowane[i - 1] = x;
	}
	wyswietlanie();
}