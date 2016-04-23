/*
 * lut23.cpp
 *
 *  Created on: Feb 23, 2016
 *      Author: lewiatan
 */

#include <bitset>
#include <iostream>
#include <string>

int main()
{
    using namespace std;

    bitset<4> fourBits;
    cout << "Poczatkowo 'fourBits' zawiera: " << fourBits << endl;

    bitset<5> fiveBits("10101");
    cout << "Poczatkowo 'fiveBits' zawiera: " << fiveBits << endl;

    bitset<8> eightBits(255);
    cout << "Poczatkowo 'eightBits' zawiera: " << eightBits << endl;

    bitset<8> eightBitsCopy(eightBits);
    cout << "Poczatkowo 'eightBitsCopy' zawiera: " << eightBitsCopy << endl;

    return 0;
}
