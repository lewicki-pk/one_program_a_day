/*
 * lut10.cpp
 *
 *  Created on: Feb 10, 2016
 *      Author: lewiatan
 */

#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

bool IsEven(const int& nNumber)
{
    return ((nNumber % 2) == 0);
}

template <typename T>
void DisplayContents(const T& Input)
{
    cout << "|" ;
    for (auto iElement = Input.cbegin();
            iElement != Input.cend();
            ++iElement) {
        if (distance(Input.cbegin(), iElement) == 5) {
            cout << "|" ;
        }
        cout << *iElement << ' ';
    }
    cout << "||| Number of elements: " << Input.size() << endl;
}

int main()
{
    vector<int> vecIntegers;

    for (int n = 0; n < 10; ++n) {
        vecIntegers.push_back(n);
    }

    cout << "The initial contents: " << endl;
    DisplayContents(vecIntegers);

    vector<int> vecCopy(vecIntegers);

    cout << "The effect of using partition(): " << endl;
    partition(vecIntegers.begin(), vecIntegers.end(), IsEven);
    DisplayContents(vecIntegers);

    cout << "The effect of using stable_partition():" << endl;
    stable_partition(vecCopy.begin(), vecCopy.end(), IsEven);
    DisplayContents(vecCopy);

    return 0;
}
