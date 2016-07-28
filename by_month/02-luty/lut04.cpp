/*
 * 04lut.cpp
 *
 *  Created on: Feb 4, 2016
 *      Author: lewiatan
 */

#include <algorithm>
#include <vector>
#include <iostream>

template <typename elementType>
bool IsEven (const elementType& number)
{
    return ((number % 2) == 0);
}

int main()
{
    using namespace std;
    vector<int> vecIntegers;

    cout << "Populating a vector<int> with values from -9 to 9" << endl;
    for (int n = -9; n < 10; ++n) {
        vecIntegers.push_back(n);
    }

    size_t nNumZeroes = count(vecIntegers.cbegin(),
                              vecIntegers.cend(),
                              0);
    cout << "Number of instances of '0': " <<
            nNumZeroes << endl << endl;

    size_t nNumDivisible = count_if(vecIntegers.cbegin(),
                                    vecIntegers.cend(),
                                    IsEven<int>);
    cout << "Number ov even elements: " << nNumDivisible
            << endl << "Number of odd elements: "
            << vecIntegers.size() - nNumDivisible << endl;

    return 0;
}
