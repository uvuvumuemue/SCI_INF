#include <iostream>
#include<vector>
#include<chrono>
#include <fstream>
#include"sortowanie.h"
using namespace std;
int main() {
    ofstream plik;
    plik.open("czasy.txt");
    for (int i = 0; i < 3; i++) {
        sortowanie Liczby;
        cout << "\n1-bombelkowe\n2-wstawieniowe\n3-wybor\n4-sortowanie std\n5-quick sort\n";
        auto start = chrono::steady_clock::now();
        Liczby.babelkowy();
        auto end = chrono::steady_clock::now();
        std::chrono::duration<double> elapsed_seconds = end - start;
        std::cout << "elapsed time: " << elapsed_seconds.count() << "s\n";
        plik << "babelkowe " << elapsed_seconds.count() << "s" << endl;
        Liczby.gen();
        start = chrono::steady_clock::now();
        Liczby.wstawianie();
        end = chrono::steady_clock::now();
        elapsed_seconds = end - start;
        std::cout << "elapsed time: " << elapsed_seconds.count() << "s\n";
        plik << "wstawieniowe " << elapsed_seconds.count() << "s" << endl;
        Liczby.gen();
        start = chrono::steady_clock::now();
        Liczby.przez_wybor();
        end = chrono::steady_clock::now();
        elapsed_seconds = end - start;
        std::cout << "elapsed time: " << elapsed_seconds.count() << "s\n";
        plik << "wybor " << elapsed_seconds.count() << "s" << endl;
        Liczby.gen();
        start = chrono::steady_clock::now();
        Liczby.sortowanie_std();
        end = chrono::steady_clock::now();
        elapsed_seconds = end - start;
        std::cout << "elapsed time: " << elapsed_seconds.count() << "s\n";
        plik << "std " << elapsed_seconds.count() << "s" << endl;
        Liczby.gen();
        start = chrono::steady_clock::now();
        Liczby.quick_sort(0, Liczby.liczby_wylosowane.size() - 1);
        end = chrono::steady_clock::now();
        elapsed_seconds = end - start;
        std::cout << "elapsed time: " << elapsed_seconds.count() << "s\n";
        plik << "quick " << elapsed_seconds.count() << "s" << endl;
        plik << endl;
    }
    plik.close();
}