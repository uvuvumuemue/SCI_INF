#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;
string cof_skracanie(string wiadomosc, int cyfra) {
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
    return wiadomosc;
}
string przestawiania(string wiadomosc) {
    string szyfr(wiadomosc.length(), '.');
    for (int i = 0; i < wiadomosc.length(); i++) {
        if (i % 2 == 0) {
            szyfr[i + 1] = wiadomosc[i];
        }
        else if (i % 2 == 1) {
            szyfr[i - 1] = wiadomosc[i];
        }
    }
    if (wiadomosc.length() % 2 == 1 ) {
        szyfr[wiadomosc.length() - 1] = wiadomosc[wiadomosc.length() - 1];
    }
    return szyfr;
}
string podstawianie(string wiadomosc) {
    cout << "\no ile cyfr ma przestawiac(maks 26): ";
    int cyfra;
    cin >> cyfra;
    while (cyfra > 26 || cyfra<0) {
        cout << "\npodaj wartosc mniejsza od 26 a zarazem wieksza od 0";
        cin >> cyfra;
    }
    for (int i = 0; i < wiadomosc.length(); i++) {
        if (wiadomosc[i] + cyfra > 122) {
            wiadomosc[i] = ((wiadomosc[i] + cyfra) % 123) + 97;
        }
        else if (wiadomosc[i] > 122 || wiadomosc[i] < 97){
            wiadomosc[i] = wiadomosc[i];
        }
        else {
            wiadomosc[i] = wiadomosc[i] + cyfra;
        }
    }
    return wiadomosc;
}
string poloczenie(string wiadomosc) {
    wiadomosc = przestawiania(wiadomosc);
    return podstawianie(wiadomosc);
}
string cof_przes(string wiadomosc) {
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
    return szyfr;
}
string cofnij(string wiadomosc,int cyfra){
    if (cyfra == 0) {
        return cof_przes(wiadomosc);
    }
    string odszyfrowanie = cof_skracanie(wiadomosc, cyfra) + "     " + cof_przes(cof_skracanie(wiadomosc, cyfra)); ;
    return odszyfrowanie;
}
int main()
{
    while (1) {
        cout << "\nczy wyczyscc ekran? \n1-tak\ninny znak-nie";
        char wybor;
        cin >> wybor;
        if (wybor == '1')
        {
            system("CLS");
        }
        cout << "\nnapisz cos: ";
        string wiadomosc;
        cin.ignore();
        getline(cin, wiadomosc);
        cout << "wybierz operacje:";
        cout << "\n1-Szyfr podstawieniowy";
        cout << "\n2-Szyfr przestawieniowy";
        cout << "\n3-Szyfr podstawieniowy i szyfr przestawieniowy";
        cout << "\n4-Odszyfruj teskt\n";
        cin >> wybor;
        switch (wybor)
        {
        case '1' :
            cout << podstawianie(wiadomosc);
            break;
        case '2':
            cout << przestawiania(wiadomosc);
            break;
        case '3':
            cout << poloczenie(wiadomosc);
            break;
        case '4':
            for (int i = 0; i < 26; i++)
            {
                cout << cofnij(wiadomosc, i);
                cout << endl;
            }
            break;
        }
    }
}

