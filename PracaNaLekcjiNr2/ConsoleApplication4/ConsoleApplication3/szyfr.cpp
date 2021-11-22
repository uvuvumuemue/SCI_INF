#include<iostream>
#include <utility> 
#include<time.h>
#include <math.h>
#include"szyfr.h"
using namespace std;
szyfr::szyfr()
{
}
int szyfr :: eu() {
    return (p -1) * ( q - 1);
}
void szyfr::liczby_wzglednie_pierwsze() {
    int ax, bx, temp;
    for (int i = 2; i <= eu(); i++)
    {
        ax = i; bx = eu();
        while (bx)
        {
            temp = bx;
            bx = ax % bx;
            ax = temp;
        }
        if (ax == 1) cout << i << " "<<"\n";
    }
}
int szyfr::wyznaczenie_d() {
    for (int i = 0; i < eu(); i++)
    {
        d = i;
        if ((d * e) % eu() == 1)
        {
            return d;
            break;
        }
    }
}
void szyfr::generator_kluczy() {
    srand(time(0));
    p = liczby_pierwsze[rand() % 5];
    q = liczby_pierwsze[rand() % 5];
    n = p * q;
    eu();
    cout << "\nwpisz 1 z podanych liczb aby nadac waartosc dla e: \n";
    liczby_wzglednie_pierwsze();
    cin >> e;
    wyznaczenie_d();
    klucz_publiczny.first = n;
    klucz_publiczny.second = e;
    klucz_prywatny.first = n;
    klucz_prywatny.second = d;
    cout << "klucz prywatny:   n:" << klucz_prywatny.first << "       d:" << klucz_prywatny.second << "\n";
    cout << "klucz publiczny:  n:" << klucz_publiczny.first << "       e:" << klucz_publiczny.second << "\n";
}
//string szyfr::euler(string a) {
//    generator_kluczy();
//    cout << "klucz publiczny n:" << klucz_publiczny.first << "  e:" << klucz_publiczny.second<<"\n";
//    for (int  i = 0; i < a.size(); i++){
//        cout<< unsigned long long((pow(unsigned long long(a[i]), d))) % n<<":test\n";
//        a[i]=unsigned long long((pow(unsigned long long (a[i]),d)))%n;
//    }
//    return a;
//}
string szyfr::przestawiania(string a) {
    string kod(a.length(), '.');
    for (int i = 0; i < a.length(); i++) {
        if (i % 2 == 0) {
            kod[i + 1] = a[i];
        }
        else if (i % 2 == 1) {
            kod[i - 1] = a[i];
        }
    }
    if (a.length() % 2 == 1) {
        kod[a.length() - 1] = a[a.length() - 1];
    }
    return kod;
}
string szyfr::podstawianie(string a) {
    cout << "\no ile cyfr ma przestawiac(maks 26): ";
    wiadomosc = a;
    int cyfra;
    cin >> cyfra;
    while (cyfra > 26 || cyfra < 0) {
        cout << "\npodaj wartosc mniejsza od 26 a zarazem wieksza od 0";
        cin >> cyfra;
    }
    for (int i = 0; i < a.length(); i++) {
        if (a[i] + cyfra > 122) {
            wiadomosc[i] = ((a[i] + cyfra) % 123) + 97;
        }
        else if (a[i] > 122 || a[i] < 97) {
            wiadomosc[i] = a[i];
        }
        else {
            wiadomosc[i] = a[i] + cyfra;
        }
    }
    return wiadomosc;
}
string szyfr :: poloczenie(string a) {
     return przestawiania(podstawianie(a));
     
}
