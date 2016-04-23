/*
 * lut07-2.cpp
 *
 *  Created on: Feb 7, 2016
 *      Author: lewiatan
 */

#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

template <typename T>
struct DisplayElementKeepCount
{
    int Count;

    DisplayElementKeepCount() : Count(0) {}

    void operator()(const T& element)
    {
        ++Count;
        cout << element << ' ';
    }
};

int main()
{
    vector<int> vecIntegers;
    for (int n = 0; n < 10; ++n) {
        vecIntegers.push_back(n);
    }

    cout << "Wyswietlenie wektora integerow: " << endl;
    DisplayElementKeepCount<int> Functor =
            for_each(vecIntegers.begin(),
                     vecIntegers.end(),
                     DisplayElementKeepCount<int>());
    cout << endl;

    cout << "'" << Functor.Count << "' elementow zostalo wyswietlonych" << endl;

    string Sample("for_each  i  stringi!");
    cout << "String: " << Sample << ", dlugosc: " << Sample.length() << endl;

    cout << "Ciag (String) wyswietlony przy uzyciu lambdy:" << endl;
    int NumChars = 0;
    auto funktor2 = for_each(Sample.begin(),
                             Sample.end(),
                             [&NumChars](char c) {cout << c << ' '; ++NumChars;});
    cout << endl;
    cout << "'" << NumChars << "' znakow zostalo wyswietlonych." << endl;
    funktor2.operator ()('$');
    cout << endl;
    cout << "'" << NumChars << "' znakow zostalo wyswietlonych." << endl;

    return 0;
}
