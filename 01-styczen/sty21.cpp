/*
 * main.cpp
 *
 *  Created on: Jan 21, 2016
 *      Author: lewiatan
 */

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

template <typename elementType>
struct DisplayElementKeepCount
{
    int Count;

    DisplayElementKeepCount () : Count(0) {}

    void operator()(const elementType& element)
    {
        ++Count;
        cout << element << ' ';
    }
};

int main()
{
    vector<int> vecIntegers;
    for (int nCount = 0; nCount < 10; ++nCount) {
        vecIntegers.push_back(nCount);
    }

    cout << "Wyswietlanie obiektu vector przechowujacego liczby calkowite: " << endl;

    DisplayElementKeepCount<int> Result;
    Result = for_each(vecIntegers.begin(),
                      vecIntegers.end(),
                      DisplayElementKeepCount<int>());
    Result.operator ()(Result.Count);
    Result.operator ()(555);

    cout << endl;

    cout << "Wyswietlono " << Result.Count << " elementow!" << endl;
    return 0;
}
