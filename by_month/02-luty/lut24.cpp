/*
 * lut24.cpp
 *
 *  Created on: Feb 24, 2016
 *      Author: lewiatan
 */

#include <vector>
#include <iostream>
#include <bitset>

int excercise1()
{
    using namespace std;

    vector<bool> vecBoolFlags(3);
    vecBoolFlags[0] = true;
    vecBoolFlags[1] = true;
    vecBoolFlags[2] = false;

    vecBoolFlags.push_back(true);

    cout << "The contents of the vector are: " << endl;
    for (size_t i = 0; i < vecBoolFlags.size(); ++i) {
        cout << vecBoolFlags[i] << ' ';
    }
    cout << endl;

    vecBoolFlags.flip();

    cout << "The contents of the vector after flipping are: " << endl;
    for (size_t i = 0; i < vecBoolFlags.size(); ++i) {
        cout << vecBoolFlags[i] << ' ';
    }
    cout << endl;

    return 0;
}

int main()
{
    using namespace std;

    bitset<4> bsA, bsB;
    bitset<5> result;
    cout << "Write one bitset (4 bits):" << endl;
    cin >> bsA;
    cout << "Write second bitset (4 bits):" << endl;
    cin >> bsB;

//    bool flag = false;
//    for (int i = 0; i < result.size(); ++i) {
//        result[i] = (bsA[i] ^ bsB[i]);
//        if (flag)
//            result[i] = result[i] ^ 1;
//        if ((flag && (bsA[i] || bsB[i])) ||
//            (bsA[i] && bsB[i])) {
//            flag = true;
//        } else {
//            flag = false;
//        }
//    }
    result = bsA.to_ullong() + bsB.to_ullong();

    cout << "And the resul is: " << result;
}
