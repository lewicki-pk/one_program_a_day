/*
 * main.cpp
 *
 *  Created on: Jan 14, 2016
 *      Author: lewiatan
 */

#include <unordered_map>
#include <iostream>
#include <string>

using namespace std;

template <typename T1, typename T2>
void DisplayUnorderedMap(unordered_map<T1, T2>& input)
{
    cout << "Liczba par, size() = " << input.size() << endl;
    cout << "Liczba kubelkow = " << input.bucket_count() << endl; // TODO tu jest piec, a nizej jest 11 - skad? stack overflow
    cout << "Maksymalna liczba kubelkow = " << input.max_bucket_count() << endl;
    cout << "Wspolczynnik wypelnienia: " << input.load_factor() << endl;
    cout << "Maksymalny wspolczynnik wypelnienia: " << input.max_load_factor() << endl;
    cout << "Zawartosc nieposortowanego obiektu map: " << endl;

    for (auto iElement = input.cbegin() ;
         iElement != input.cend() ;
         ++iElement)
        cout << iElement->first << " -> " << iElement->second << endl;
    cout << endl;
}

int main()
{
    unordered_map<int, string> umapIntToString;
    umapIntToString.insert(make_pair(1, "Jeden"));
    umapIntToString.insert(make_pair(45, "Czterdziesci piec"));

    DisplayUnorderedMap<int, string>(umapIntToString);

    cout << "Wstawienie jeszcze jednego elementu" << endl;
    umapIntToString.insert(make_pair(300, "Trzysta"));
    umapIntToString.insert(make_pair(1001, "Tysiac jeden"));
    umapIntToString.insert(make_pair(-2, "Minus dwa"));
    umapIntToString.insert(make_pair(-1000, "Minus tysiac"));
    umapIntToString.insert(make_pair(100, "Sto"));
    umapIntToString.insert(make_pair(12, "Dwanascie"));
    umapIntToString.insert(make_pair(-100, "Minus stoo"));
    DisplayUnorderedMap<int, string>(umapIntToString);

    while (true) {
        cout << "Podaj szukany klucz" << endl << ">";
        int Key = 0;
        cin >> Key;

        auto iElementFound = umapIntToString.find(Key);
        if (iElementFound != umapIntToString.end()) {
            cout << "Znaleziono! Klucz " << iElementFound->first << " prowadzi do wartosci "
                    << iElementFound->second << endl;
        } else {
            cout << "Klucz nie ma odpowiadajacej mu wartosci w obiekcie map!" << endl;
        }
    }
    return 0;
}
