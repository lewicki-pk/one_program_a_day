/*
 * apr04.cpp
 *
 *  Created on: Apr 4, 2016
 *      Author: lewiatan
 */

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    cout << "Hey - default!" << endl;

    cout << setw(120);
    cout << "Hey - right aligned!" << endl;

    cout << setw(120) << setfill('*');
    cout << "Hey - right aligned!" << endl;

    cout << "Hey - back to default" << endl;

    return 0;
}
