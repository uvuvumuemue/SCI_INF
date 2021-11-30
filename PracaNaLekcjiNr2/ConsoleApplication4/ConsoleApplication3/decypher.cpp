#include "decypher.h"
#include<iostream>
#include<string>
decypher::decypher()
{


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
string decypher::cof_skracanie(int cyfra,string wiadomosc){
        if (wiadomosc[cyfra] + cyfra > 122) {
            wiadomosc[cyfra] = ((wiadomosc[cyfra] + cyfra) % 123) + 97;
        }
        else if (a[cyfra] > 122 || a[cyfra] < 97) {
            wiadomosc[cyfra] = wiadomosc[cyfra];
        }
        else {
            wiadomosc[cyfra] = wiadomosc[cyfra] + cyfra;
        }
    return wiadomosc;
}
//string decypher::cof_skracanie(int cyfra, string wiadomosc) {
//    for (int i = 0; i < wiadomosc.length(); i++) {
//        if (wiadomosc[i] > 123 || wiadomosc[i] < 96) {
//            wiadomosc[i] = wiadomosc[i];
//        }
//        else if (wiadomosc[i] - cyfra < 97) {
//            wiadomosc[i] = wiadomosc[i] - cyfra + 26;
//        }
//        else {
//            wiadomosc[i] = wiadomosc[i] - cyfra;
//        }
//    }
//    a = wiadomosc;
//    return a;
//}