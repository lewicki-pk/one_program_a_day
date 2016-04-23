/*
 * 10lut-2.cpp
 *
 *  Created on: Feb 10, 2016
 *      Author: lewiatan
 */

#include <algorithm>
#include <list>
#include <string>
#include <iostream>
using namespace std;

template <typename T>
void DisplayContents(const T& Input)
{
    for (auto iElement = Input.cbegin();
            iElement != Input.cend();
            ++iElement) {
        cout << *iElement << endl;
    }
}

int main()
{
    list<string> names;
    names.push_back("John Doe");
    names.push_back("Brad Pitt");
    names.push_back("Jack Nicholson");
    names.push_back("Sean Penn");
    names.push_back("Anna Hoover");

    cout << "The sorted contents of the list are: " << endl;
    names.sort();
    DisplayContents(names);

    cout << "The lowest index where \"Brad Pitt\" can be inserted is: ";
    auto iMinInsertPos = lower_bound(names.begin(), names.end(), "Brad Pitt");
    cout << distance(names.begin(), iMinInsertPos) << endl;

    cout << "The highest index where \"Brad Pitt\" can be inserted is: ";
    auto iMaxInsertPos = upper_bound(names.begin(), names.end(), "Brad Pitt");
    cout << distance(names.begin(), iMaxInsertPos) << endl;

    cout << "List after inserting Brad Pitt in sorted order: " << endl;
    names.insert(iMinInsertPos, "Brad Pitt");

    DisplayContents(names);
    return 0;
}
