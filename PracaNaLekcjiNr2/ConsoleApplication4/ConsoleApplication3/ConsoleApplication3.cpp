#include <iostream>
#include <string>
#include <utility> 
#include "szyfr.h"
#include"decypher.h"
using namespace std;
int main()
{
    while (1) {
        cout << "\nczy wyczyscic ekran? \n1-tak\ninny znak-nie";
        char wybor;
        cin >> wybor;
        if (wybor == '1')
        {
            system("CLS");
        }
        szyfr a;
        decypher b;
        cout << "wybierz operacje:";
        cout << "\n1-Szyfr podstawieniowy";
        cout << "\n2-Szyfr przestawieniowy";
        cout << "\n3-Szyfr podstawieniowy i szyfr przestawieniowy";
        cout << "\n4-generator kluczy";
        cout << "\n5-Odszyfruj teskt\n";
        cin >> wybor;
        string wiadomosc;
        cout << "\npodaj tekst: \n";
        cin.ignore();
        getline(cin,wiadomosc);
        switch (wybor)
        {
        case '1':
            cout<<a.podstawianie(wiadomosc);
            break;
        case '2':
            cout<<a.przestawiania(wiadomosc);
            break;
        case '3':
            cout<<a.poloczenie(wiadomosc);
            break;
        case '5':
            for (int i = 0; i < 26; i++){
                cout << b.cof_skracanie(i, wiadomosc) << "\n";
            }
            break;
        case '4':
            a.generator_kluczy();
            break;
        }
    }
}