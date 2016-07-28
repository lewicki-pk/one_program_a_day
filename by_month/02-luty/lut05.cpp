/*
 * lut05.cpp
 *
 *  Created on: Feb 5, 2016
 *      Author: lewiatan
 */

#include <algorithm>
#include <vector>
#include <list>
#include <iostream>
using namespace std;

template <typename T>
void DisplayContents (const T& Input)
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
    vector<int> vecIntegers;
    for (int n = -9; n < 10; ++n) {
        vecIntegers.push_back(n);
    }

    vecIntegers.push_back(9);
    vecIntegers.push_back(9);

    list<int> listIntegers;
    for (int n = -4; n < 5; ++n) {
        listIntegers.push_back(n);
    }

    cout << "The contents of the sample vector are: " << endl;
    DisplayContents(vecIntegers);

    cout << "The contents of the sample list are: " << endl;
    DisplayContents(listIntegers);

    cout << "search() for the contents of list in vector: " << endl;
    auto iRange = search(vecIntegers.cbegin(),
                         vecIntegers.cend(),
                         listIntegers.cbegin(),
                         listIntegers.cend());
    if (iRange != vecIntegers.cend()) {
        cout << "Sequence in list found in vector at position "
             << distance(vecIntegers.cbegin(), iRange) << endl;
    }

    cout << "Searching {9,9,9} in vector using search_n(): " << endl;
    auto iPartialRange = search_n(vecIntegers.cbegin(),
                                  vecIntegers.cend(),
                                  3,
                                  9);

    if (iPartialRange != vecIntegers.end()) {
        cout << "Sequence {9,9,9} found in vector at position: "
             << distance(vecIntegers.cbegin(), iPartialRange);
    }
    return 0;
}
