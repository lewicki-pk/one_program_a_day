/*
 * main.cpp
 *
 *  Created on: Jan 28, 2016
 *      Author: lewiatan
 */

#include <algorithm>
#include <iostream>
#include <vector>
#include <list>

using namespace std;

int main()
{
    vector<int> vecIntegers;

    for (int i = 0; i < 10; ++i) {
        vecIntegers.push_back(i);
    }

    list<char> listChars;
    for (char c = 'a'; c < 'k'; ++c) {
        listChars.push_back(c);
    }

    cout << "Displaying vector of integers using a lambda: " << endl;

    for_each(vecIntegers.begin(),
             vecIntegers.end(),
             [](int& element){ cout << element << ' '; }); // lambda

    cout << endl << endl;
    cout << "Displaying list of characters using a lambda: " << endl;

    for_each(listChars.begin(),
             listChars.end(),
             [](char& element){cout << element << ' ';});

    cout << endl;

    return 0;
}
