/*
 * lut07-3.cpp
 *
 *  Created on: Feb 7, 2016
 *      Author: lewiatan
 */

#include <algorithm>
#include <string>
#include <vector>
#include <deque>
#include <iostream>
#include <functional>

int main()
{
    std::string Sample("This iS a tESt StrInG!");
    std::cout << "Przykladowy ciag to: " << Sample << std::endl;

    std::string strLowerCaseCopy;
    strLowerCaseCopy.resize(Sample.size());

    std::transform(Sample.begin(),
                   Sample.end(),
                   strLowerCaseCopy.begin(),
                   tolower);

    std::cout << "Wynik dzialania f. 'transform()' przy wykorzystaniu 'tolower' to: "
              << std::endl << "\"" << strLowerCaseCopy << "\"" << "\n\n";

    std::vector<int> vecIntegers1, vecIntegers2;
    for (int n = 0; n < 10; ++n) {
        vecIntegers1.push_back(n);
        vecIntegers2.push_back(10 - n);
    }

    std::deque<int> dqResult(vecIntegers1.size());

    std::transform(vecIntegers1.cbegin(),
                   vecIntegers1.cend(),
                   vecIntegers2.cbegin(),
                   dqResult.begin(),
                   std::plus<int>());

    std::cout << "Wynik f. 'transform()' wykorzystujacej funkcje dwuargumentowa 'plus':"
              << std::endl << std::endl
              << "Index  Vector1  +  Vector2  =  Result (in Deque)" << std::endl;
    for (size_t n = 0; n < vecIntegers1.size(); ++n) {
        std::cout << " [" << n << "]      " << vecIntegers1.at(n) << "     +     "
                  << vecIntegers2.at(n) << "     =    "
                  << dqResult.at(n) << std::endl;
    }
    return 0;
}
