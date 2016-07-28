/*
 * lut08-2.cpp
 *
 *  Created on: Feb 8, 2016
 *      Author: lewiatan
 */

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

template <typename T>
void DisplayContents(const T& Input)
{
    for (auto iElement = Input.cbegin();
            iElement != Input.cend();
            ++iElement) {
        cout << *iElement << endl;
    }
//    cout << "| Number of elements: " << Input.size() << endl;
}

int main()
{
    vector<string> vecNames;
    vecNames.push_back("John Doe");
    vecNames.push_back("Jack Nicholson");
    vecNames.push_back("Sean Penn");
    vecNames.push_back("Anna Hoover");

    vecNames.push_back("Jack Nicholson");

    cout << "The initial contents of the vector are: " << endl;
    DisplayContents(vecNames);

    cout << "The sorted vector contains names in the order:" << endl;
    sort(vecNames.begin(), vecNames.end());
    DisplayContents(vecNames);

    cout << "Searching for 'John Doe' using binary_search:" << endl;
    bool isFound = binary_search(vecNames.begin(), vecNames.end(), "John Doe");

    if (isFound)
        cout << "Result found!" << endl;
    else
        cout << "Not found!" << endl;

    auto iNewEnd = unique(vecNames.begin(), vecNames.end());
    vecNames.erase(iNewEnd, vecNames.end());

    cout << "The contents of the vector after using 'unique':" << endl;
    DisplayContents(vecNames);

    return 0;
}
