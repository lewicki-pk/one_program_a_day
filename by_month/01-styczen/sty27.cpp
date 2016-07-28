/*
 * main.cpp
 *
 *  Created on: Jan 27, 2016
 *      Author: lewiatan
 */

// Write a unary function that can be used
// with std::for_each to display the double
// of the input parameter.
#include <iostream>
#include <vector>
#include <algorithm>

template <typename T>
void displayDouble(T& input)
{
    T result = input * 2;
    std::cout << result << std::endl;
}

template <typename Y>
bool sortAscending(const Y& lewy, const Y& prawy)
{
    return (lewy > prawy);
}

int main()
{
    double dblInput = 3.21;
    displayDouble<double>(dblInput);

    int intInput = 45;
    displayDouble<int>(intInput);

    std::vector<int> wektor;
    wektor.push_back(1);
    wektor.push_back(2);
    wektor.push_back(3);
    wektor.push_back(4);
    wektor.push_back(5);

    std::for_each(wektor.begin(), wektor.end(), displayDouble<int>);
    std::sort(wektor.begin(), wektor.end(), sortAscending<int>);
    std::for_each(wektor.begin(), wektor.end(), displayDouble<int>);

    return 0;
}
