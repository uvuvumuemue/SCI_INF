#include "decypher.h"
#include<iostream>
#include<string>
decypher::decypher()
{
  

}
string decypher::cofnij(int cyfra,string wiadomosc) {
    if (cyfra == 0) {
        return cof_przes(wiadomosc);
    }
    return cof_skracanie(cyfra,wiadomosc);
}
//string decypher::odszyfrowanie_eulera(string a) {
//    cout << "\npodaj wartosc n: ";
//    cin >> n;
//    cout << "\npodaj wartosc e: ";
//    cin >> e;
//
//    for (int i = 0; i < a.length(); i++)
//    {
//        cout<< unsigned long long((pow(unsigned long long(a[i]), e))) % n <<":test\n";
//        a[i] = unsigned long long((pow(unsigned long long (a[i]),e))) % n;
//    }
//    return a;
//}
string decypher::cof_przes(string wiadomosc) {
    string szyfr(wiadomosc.length(), '.');
    for (int i = 0; i < wiadomosc.length(); i++) {
        if (i % 2 == 0) {
            szyfr[i] = wiadomosc[i + 1];
        }
        else if (i % 2 == 1) {
            szyfr[i] = wiadomosc[i - 1];
        }
    }
    if (wiadomosc.length() % 2 == 1) {
        szyfr[wiadomosc.length() - 1] = wiadomosc[wiadomosc.length() - 1];
    }
    a = szyfr;
    return a;
}
string decypher::cof_skracanie(int cyfra,string wiadomosc) {
    for (int i = 0; i < wiadomosc.length(); i++) {
        if (wiadomosc[i] > 123 || wiadomosc[i] < 96) {
            wiadomosc[i] = wiadomosc[i];
        }
        else if (wiadomosc[i] - cyfra < 97) {
            wiadomosc[i] = wiadomosc[i] - cyfra + 26;
        }
        else {
            wiadomosc[i] = wiadomosc[i] - cyfra;
        }
    }
    a=wiadomosc;
    return a;
}