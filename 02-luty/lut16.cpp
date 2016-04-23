/*
 * lut16.cpp
 *
 *  Created on: Feb 16, 2016
 *      Author: lewiatan
 */

#include <stack>
#include <vector>

int main()
{
    using namespace std;

    // A stack of integers
    stack<int> stackInts;

    // A stack of doubles
    stack<double> stackDoubles;

    // A stack of doubles contained in a vector
    stack<double, vector<double>> stackDoublesInVector;

    stack<int> ctackIntsCopy(stackInts);
}
