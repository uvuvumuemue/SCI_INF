#pragma once
#include <string>
#include <utility> 
using namespace std;
class szyfr
{
private:
	pair <int, int> klucz_publiczny;
	pair <int, int> klucz_prywatny;
	string wiadomosc;
	int liczby_pierwsze[5]= {2,3 ,5 ,7 ,11 };
	int rng[2] = {0,0};
	int e=0, p=0, q=0, d=0;
	unsigned long long n;
	void liczby_wzglednie_pierwsze();
	int eu();
	int wyznaczenie_d();
public:
	szyfr();
	string przestawiania(string wiadomosc);
	string podstawianie(string wiadomosc);
	string poloczenie(string wiadomosc);
	void generator_kluczy();
	/*string euler(string wiadomosc);*/
};