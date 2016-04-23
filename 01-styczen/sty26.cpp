/*
 * main.cpp
 *
 *  Created on: Jan 26, 2016
 *      Author: lewiatan
 */

#include <algorithm>
#include <string>
#include <vector>
#include <iostream>

class CompareStringNoCase
{
public:
    bool operator()(const std::string& str1, const std::string& str2)
    {
        std::string str1LowerCase;

        str1LowerCase.resize(str1.size());

        std::transform(str1.begin(), str1.end(), str1LowerCase.begin(),
                  tolower);

        std::string str2LowerCase;

        str2LowerCase.resize(str2.size());

        std::transform(str2.begin(), str2.end(), str2LowerCase.begin(),
                  tolower);

        return (str1LowerCase < str2LowerCase);
    }
};

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
    vector<string> vecNames;

    vecNames.push_back("jim");
    vecNames.push_back("Adam");
    vecNames.push_back("Jack");
    vecNames.push_back("Sam");
    vecNames.push_back("anna");
    vecNames.push_back("susan");

    cout << "The names in vector in order of insertion: " << endl;
    DisplayContents(vecNames);

    cout << "Names after sorting using default std::less<>: " << endl;
    sort(vecNames.begin(), vecNames.end());
    DisplayContents(vecNames);

    cout << "Names after sorting using predicate that ignores case: " << endl;
    sort(vecNames.begin(), vecNames.end(), CompareStringNoCase());
    DisplayContents(vecNames);

    return 0;
}
