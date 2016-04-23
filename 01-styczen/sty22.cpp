/*
 * main.cpp
 *
 *  Created on: Jan 22, 2016
 *      Author: lewiatan
 */

#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

template <typename numberType>
struct IsMultiple
{
    numberType Divisor;

    IsMultiple(const numberType& divisor)
    {
        Divisor = divisor;
    }

    bool operator()(const numberType& element) const
    {
        return ((element % Divisor) == 0);
    }
};

int main()
{
    vector<int> vecIntegers;
    cout << "Obiekt vector zawiera nastepujace wartosci przykladowe: ";

    for (int nCount = 25; nCount < 32; ++nCount) {
        vecIntegers.push_back(nCount);
        cout << nCount << ' ';
    }
    cout << endl << "Podaj dzielnik (>0): ";
    int divisor = 2;
    cin >> divisor;
    auto iElement = find_if(vecIntegers.begin(),
                            vecIntegers.end(),
                            IsMultiple<int>(divisor));

    if (iElement != vecIntegers.end()) {
        cout << "Pierwszy element obiektu vector, ktory jest wielokrotnoscia "
             << divisor << " to: " << *iElement << endl;
    }
    return 0;
}
