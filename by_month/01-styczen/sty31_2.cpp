/*
 * main.cpp
 *
 *  Created on: Jan 31, 2016
 *      Author: lewiatan
 */

#include <algorithm>
#include <vector>
#include <iostream>
#include <string>
using namespace std;

template <typename T>
void DisplayContents(const T& Input)
{
    for (auto iElement = Input.cbegin();
         iElement != Input.cend();
         ++iElement) {
        cout << *iElement << ' ';
    }
    cout << endl;
}

int main()
{
    vector<int> inty;
    inty.push_back(1);
    inty.push_back(5);
    inty.push_back(-1);
    inty.push_back(3);
    inty.push_back(10);

    DisplayContents(inty);
    cout << "====================" << endl;
    sort(inty.begin(), inty.end(),
            [](const int& a, const int& b){ return (a > b);});
    DisplayContents(inty);

    for_each(inty.begin(),
             inty.end(),
             [](int& a){a += 1;});
    DisplayContents(inty);

    return 0;
}
