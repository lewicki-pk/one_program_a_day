/*
 * main.cpp
 *
 *  Created on: Jan 29, 2016
 *      Author: lewiatan
 */

#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

int main()
{
    vector<int> vecNums;
    vecNums.push_back(25);
    vecNums.push_back(101);
    vecNums.push_back(-10);
    vecNums.push_back(200);

    auto iEvenNum = find_if( vecNums.cbegin(),
                             vecNums.cend(),
                             [](const int& Num){return ((Num % 2) == 0);});

    if (iEvenNum != vecNums.end())
        cout << "First even number in collection is :" << *iEvenNum << endl;

    auto iEvenNum2 = find_if( ++iEvenNum,
                             vecNums.cend(),
                             [](const int& Num){return ((Num % 2) == 0);});

    if (iEvenNum2 != vecNums.end())
        cout << "First even number in collection is :" << *iEvenNum2 << endl;
    return 0;
}
