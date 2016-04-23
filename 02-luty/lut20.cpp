/*
 * lut20.cpp
 *
 *  Created on: Feb 20, 2016
 *      Author: lewiatan
 */

#include <queue>
#include <iostream>

int main()
{
    using namespace std;

    priority_queue<int, vector<int>, greater<int>> pqIntegers;

    cout << "Inserting {10, 5, -1, 20} into the priority_queue." << endl;
    pqIntegers.push(10);
    pqIntegers.push(5);
    pqIntegers.push(-1);
    pqIntegers.push(20);

    priority_queue<double> pqDoubles;

    priority_queue<int, deque<int>, greater<int>> pqIntegers_inverse;

//    priority_queue<int> pqCopy(pqIntegers);


    cout << "Deleting the " << pqIntegers.size() << " elements" << endl;
    while (!pqIntegers.empty()) {
        cout << "Deleting topmost element: " << pqIntegers.top() << endl;
        pqIntegers.pop();
    }

    return 0;
}
