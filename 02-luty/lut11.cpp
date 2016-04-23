/*
 * lut11.cpp
 *
 *  Created on: Feb 11, 2016
 *      Author: lewiatan
 */
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>

struct Predykat
{
    bool operator()(const std::string& lhs,
                    const std::string& rhs)
    {
        std::string lhs_l;
        lhs_l.resize(lhs.size());
        std::string rhs_l;
        rhs_l.resize(rhs.size());
        std::transform(lhs.begin(), lhs.end(), lhs_l.begin(), tolower);
        std::transform(rhs.begin(), rhs.end(), rhs_l.begin(), tolower);

        return (lhs_l < rhs_l);
    }
};


using namespace std;
int main()
{
    vector<string> wektor;
    wektor.push_back("Piotr");
    wektor.push_back("PAULA");
    wektor.push_back("paula");
    wektor.push_back("Paula");

    for (auto it = wektor.begin();
            it != wektor.end();
            ++it) {
        cout << *it << endl;
    }

    cout << "===" << endl;

    sort(wektor.begin(), wektor.end(), Predykat());
    for (auto it = wektor.begin();
            it != wektor.end();
            ++it) {
        cout << *it << endl;
    }
    cout << "===" << endl;

    sort(wektor.begin(), wektor.end());
    for (auto it = wektor.begin();
            it != wektor.end();
            ++it) {
        cout << *it << endl;
    }
}
