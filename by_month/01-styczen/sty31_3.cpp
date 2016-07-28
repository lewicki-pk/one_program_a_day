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

template <typename T>
void DisplayContents(const T& Input)
{
    for (auto iElement = Input.cbegin();
              iElement != Input.cend();
              ++iElement) {
        std::cout << *iElement << std::endl;
    }
}

int main()
{
    std::vector<std::string> vecNames;

    vecNames.push_back("jim");
    vecNames.push_back("Adam");
    vecNames.push_back("Jack");
    vecNames.push_back("Sam");
    vecNames.push_back("anna");
    vecNames.push_back("susan");
    vecNames.push_back("kamila");
    vecNames.push_back("Paula");

    std::cout << "The names in vector in order of insertion: " << std::endl;
    DisplayContents(vecNames);

    std::cout << "Names after sorting using default std::less<>: " << std::endl;
    std::sort(vecNames.begin(), vecNames.end());
    DisplayContents(vecNames);

    std::cout << "Names after sorting using predicate that ignores case: " << std::endl;
    std::sort(vecNames.begin(), vecNames.end(),
            [](const std::string& str1, const std::string& str2) -> bool
            {
                std::string str1LC, str2LC;
                str1LC.resize(str1.size());
                str2LC.resize(str2.size());
                std::transform(str1.begin(), str1.end(), str1LC.begin(), tolower);
                std::transform(str2.begin(), str2.end(), str2LC.begin(), tolower);
                return (str1LC < str2LC);
            }
    );
    DisplayContents(vecNames);

    return 0;
}
