/*
 * 19sty.cpp
 *
 *  Created on: Jan 19, 2016
 *      Author: lewiatan
 */


#include <algorithm>
#include <iostream>
#include <vector>
#include <list>

using namespace std;

template <typename elementType>
struct DisplayElement
{
    void operator()(const elementType& element) const
    {
        cout << static_cast<int>(element) << ' ';
        //cout << element << ' ';
    }
};

void FuncDisplayElement(const int& element)
{
    cout << element << '-';
}
int main()
{
    vector<int> vecIntegers;

    for (int nCount = 0; nCount < 110; ++nCount) {
        vecIntegers.push_back(nCount);
    }

    list<char> listChars;

    for (char nChar = 'a'; nChar < 'k' + 10 ; ++nChar) {
        listChars.push_back(nChar);
    }

    cout << "Wyswietlanie liczb calkowitych" << endl;

/*
    for_each( vecIntegers.begin(),
              vecIntegers.end(),
              DisplayElement<int>());
*/
    for_each( vecIntegers.begin(),
              vecIntegers.end(),
              FuncDisplayElement);

    cout << endl << endl;

    cout << "Wyswietlanie literek" << endl;

/*
    for_each( listChars.begin(),
              listChars.end(),
              DisplayElement<char>());
*/
    for_each( listChars.begin(),
              listChars.end(),
              [](char& element){ cout << element << ' ';});

}
