/*
 * lut18.cpp
 *
 *  Created on: Feb 18, 2016
 *      Author: lewiatan
 */

#include <queue>
#include <list>

int main()
{
    std::queue<int> qInts;

    std::queue<double> qDoubles;

    std::queue<int, std::list<double>> qDoubleList;

    std::queue<int> qCopy(qInts);
}
