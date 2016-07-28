/*
 * main.cpp
 *
 *  Created on: Jan 5, 2016
 *      Author: lewiatan
 */

#include <set>
#include <cstdlib>
#include <string>
#include <iostream>

template <typename T>
struct sortujMalejaco
{
    bool operator()(const T& lhs, const T& rhs) const
    {
        return (lhs > rhs);
    }
};
using namespace std;

int main()
{
    set<int> setRosnaco;
    set<int, sortujMalejaco<int>> setMalejaco;

    string input;
    int liczba;
    while (true) {
        cout << "podaj liczbe" << endl;
        cin >> input;
        liczba = atoi(input.c_str());
        if ((liczba != 0) or (input == "0")) {
            setRosnaco.insert(liczba);
            setMalejaco.insert(liczba);
        } else {
            break;
        }
    }

    cout << "Lista posortowana rosnaco:" << endl;
    for (auto element : setRosnaco)
    {
        cout << element << ' ';
    }
    cout << endl << "Lista posortowana malejaco:" << endl;
    for (auto element : setMalejaco)
    {
        cout << element << ' ';
    }
    cout << endl;
//    sortujMalejaco<int> obiekt;
//    opLess<int> operatorLess;
//    cout << obiekt(1,2);
//    cout << obiekt(2,1);
//    cout << "operatorLess" << endl << operatorLess(1,2) << operatorLess(2,1);
}
