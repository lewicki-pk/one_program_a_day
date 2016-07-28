/*
 * lut07-4.cpp
 *
 *  Created on: Feb 7, 2016
 *      Author: lewiatan
 */

#include <algorithm>
#include <vector>
#include <list>
#include <iostream>
using namespace std;

template <typename T>
void DisplayContents(const T& Input)
{
    for (auto iElement = Input.cbegin();
            iElement != Input.cend();
            ++iElement) {
        cout << *iElement << ' ';
    }
    cout << "| Number of elements: " << Input.size() << endl;
}

int main()
{
    list<int> listIntegers;
    for (int n = 0; n < 10; ++n) {
        listIntegers.push_back(n);
    }

    cout << "Source (list) contains: " << endl;
    DisplayContents(listIntegers);

    vector<int> vecIntegers(listIntegers.size() * 2);

    auto iLastPos = copy(listIntegers.begin(),
                         listIntegers.end(),
                         vecIntegers.begin());

    copy_if(listIntegers.begin(), listIntegers.end(),
            iLastPos, [](int element){return ((element % 2) == 1);});

    cout << "Destination (vector) after copy and copy_if:" << endl;
    DisplayContents(vecIntegers);

    auto iNewEnd = remove(vecIntegers.begin(), vecIntegers.end(), 0);
    vecIntegers.erase(iNewEnd, vecIntegers.end());

    cout << "Destination (vector) after removing 0s: " << endl;
    DisplayContents(vecIntegers);

    iNewEnd = remove_if(vecIntegers.begin(), vecIntegers.end(),
            [](int element){return ((element % 2) == 1);});
    vecIntegers.erase(iNewEnd, vecIntegers.end());
    cout << "Destination (vector) after remove, remove_if, erase: " << endl;
    DisplayContents(vecIntegers);

    return 0;
}
