/*
 * main.cpp
 *
 *  Created on: Jan 25, 2016
 *      Author: lewiatan
 */

#include <vector>
#include <iostream>
#include <algorithm>

template <typename elementType>
class Multiply
{
public:
    elementType operator()(const elementType& elem1,
            const elementType& elem2) {
        return (elem1 * elem2);
    }
};

int main()
{
    using namespace std;

    vector<int> vecMultiplicand, vecMultiplier;

    for (int nCount = 0; nCount < 10; ++nCount) {
        vecMultiplicand.push_back(nCount);
    }

    for (int nCount2 = 100; nCount2 < 110; ++nCount2) {
        vecMultiplier.push_back(nCount2);
    }

    vector<int> vecResult;

    vecResult.resize(10);
    transform(vecMultiplicand.begin(),
              vecMultiplicand.end(),
              vecMultiplier.begin(),
              vecMultiplier.end(),
              Multiply<int>());

    cout << "The contents of the first vector are: " << endl;
    for (size_t nIndex1 = 0; nIndex1 < vecMultiplicand.size(); ++nIndex1) {
        cout << vecMultiplicand[nIndex1] << ' ';
    }
    cout << endl;

    cout << "The contents of the second vector are: " << endl;
    for (size_t nIndex2 = 0; nIndex2 < vecMultiplier.size(); ++nIndex2) {
        cout << vecMultiplier[nIndex2] << ' ';
    }
    cout << endl;

    cout << "The result of multiplication is: " << endl;
    for (size_t nIndex = 0; nIndex << vecResult.size(); ++nIndex) {
        cout << vecResult[nIndex] << ' ';
    }
    cout << endl;

    return 0;

}
