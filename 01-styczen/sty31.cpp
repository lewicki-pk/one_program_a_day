/*
 * main.cpp
 *
 *  Created on: Jan 31, 2016
 *      Author: lewiatan
 */

#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

int excercise1()
{
    vector<int> vecIntegers;
    cout << "The vector of integers contains values:" << endl;

    for (int i = 25; i < 32; ++i) {
        vecIntegers.push_back(i);
        cout << i << ' ';
    }
    cout << endl << "Podaj dzielnik: ";
    int Dzielnik = 2;
    cin >> Dzielnik;

    vector<int>::const_iterator iElement;
    iElement = find_if(vecIntegers.cbegin(),
                       vecIntegers.cend(),
                       [Dzielnik](int dividend){return ((dividend % Dzielnik) == 0);});

    if (iElement != vecIntegers.cend()) {
        cout << "Pierwszy element podzielny przez " << Dzielnik << " to "
             << *iElement << endl;
    }

    return 0;
}

int excercise2()
{
    vector<int> vecIntegers;
    cout << "The vector of integers contains values:" << endl;

    for (int i = 25; i < 32; ++i) {
        vecIntegers.push_back(i);
        cout << i << ' ';
    }
    cout << endl << "Podaj dzielnik: ";
    int Dzielnik = 2;
    cin >> Dzielnik;
    int wartosc = 0;

    vector<int>::const_iterator iElement;
    iElement = find_if(vecIntegers.cbegin(),
                       vecIntegers.cend(),
                       [Dzielnik, wartosc](int dividend) mutable
                           {cout << "Wartosc: " << (wartosc++) + 1 << endl;
                            return ((dividend % Dzielnik) == 0);});

    if (iElement != vecIntegers.cend()) {
        cout << "Pierwszy element podzielny przez " << Dzielnik << " to "
             << *iElement << endl;
    }

    cout << "Wartosc na koncu: " << wartosc << endl;

    return 0;

}
void printVector(vector<int>& vec) {
    for (size_t i = 0; i < vec.size(); ++i) {
        cout << vec[i] << ' ';
    }
    cout << endl;
}

int excercise3()
{
    vector<int> vecMultiplicand, vecMultiplier;

    for (int i1 = 0; i1 < 10; ++i1) {
        vecMultiplicand.push_back(i1);
    }

    for (int i2 = 100; i2 < 110; ++i2) {
        vecMultiplier.push_back(i2);
    }

    vector<int> vecResult;

    vecResult.resize(10);

    transform(vecMultiplicand.begin(),
              vecMultiplicand.end(),
              vecMultiplier.begin(),
              vecResult.begin(),
              [](int a, int b){return a * b; });
    cout << "Pierwszy wektor: " << endl;
    printVector(vecMultiplicand);

    cout << "Drugi wektor: " << endl;
    printVector(vecMultiplier);

    cout << "Wektor z wynikami mnozenia: " << endl;
    printVector(vecResult);

    return 0;
}

int main()
{
    excercise3();
}
