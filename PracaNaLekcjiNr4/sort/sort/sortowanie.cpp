#include<iostream>
#include<vector>
#include<stdlib.h>
#include<algorithm>
#include"sortowanie.h"
using namespace std;
sortowanie::sortowanie(){
	srand(time(NULL));
	for (int i = 0; i < 20000; i++)
	{
		liczby_wylosowane.push_back(rand() % 1000);
	}
	//wyswietlanie();
}
void sortowanie::gen() {
	srand(time(NULL));
	for (int i = 0; i < liczby_wylosowane.size()-1; i++)
	{
		liczby_wylosowane[i] = rand() % 1000;
	}
	//wyswietlanie();
}
void sortowanie::sortowanie_std() {
	sort(liczby_wylosowane.begin(), liczby_wylosowane.end());
	//wyswietlanie();
}
void sortowanie::quick_sort(int left,int right) {
	int i = (left + right) / 2;
	int piwot = liczby_wylosowane[i];
	liczby_wylosowane[i] = liczby_wylosowane[right];
	int j = left;
	for ( i = left; i < right; i++)
	{
		if (liczby_wylosowane[i] < piwot)
		{
			swap(liczby_wylosowane[i], liczby_wylosowane[j]);
			j++;
		}
	}
	liczby_wylosowane[right] = liczby_wylosowane[j];
	liczby_wylosowane[j] = piwot;
	if (left<j-1)
	{
		quick_sort(left, j-1);
	}

	if( j + 1<right) {
		quick_sort(j+1, right);
	}
}
void sortowanie::przez_wybor(){
	for (int j = 0; j< liczby_wylosowane.size()-1; j++)
	{
		int naj = j;
		for (int  i = j+1; i < liczby_wylosowane.size(); i++)
		{
			if (liczby_wylosowane[i] < liczby_wylosowane[naj])
			{
				naj = i;
			}
		}
		int temp;
		temp=liczby_wylosowane[j];
		liczby_wylosowane[j] = liczby_wylosowane[naj];
		liczby_wylosowane[naj] = temp;
	}
	//wyswietlanie();
}
void sortowanie::wyswietlanie(){
	cout << "\n----------------------------------------------------";
	for (int i = 0; i < liczby_wylosowane.size(); i++)
	{
		cout << "\n" << "liczba nr " << i + 1 << ": " << liczby_wylosowane[i];
	}
	cout << "\n----------------------------------------------------";
}
void sortowanie::babelkowy(){
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
	//wyswietlanie();
}
void sortowanie::wstawianie(){
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
	//wyswietlanie();
}