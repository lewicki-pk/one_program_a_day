/*
 * lut12.cpp
 *
 *  Created on: Feb 12, 2016
 *      Author: lewiatan
 */

#include <algorithm>
#include <iostream>
#include <vector>
#include <list>

int main()
{
    std::list<int> list;
    list.push_back(1);
    list.push_back(4);
    list.push_back(3);
    list.push_back(8);
    list.push_back(5);

    std::vector<int> wektor(list.size());

    std::copy(list.begin(), list.end(), wektor.begin());

    for (auto it = wektor.begin();
            it != wektor.end();
            ++it) {
        std::cout << *it << std::endl;
    }
}
