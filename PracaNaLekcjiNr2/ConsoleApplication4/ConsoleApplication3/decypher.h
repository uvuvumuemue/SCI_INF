#pragma once
#include <string>
using namespace std;
class decypher
{
private:
	string a;
	int cyfra,n, e;
	string cof_przes(string wiadomosc);
public:
	string cof_skracanie(int cyfra, string wiadomosc);
	/*string odszyfrowanie_eulera(string wiadomosc);*/
	string cofnij(int cyfra,string wiadomosc);
	decypher();
};

