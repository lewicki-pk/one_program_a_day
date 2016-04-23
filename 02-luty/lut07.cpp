/*
 * lut07.cpp
 *
 *  Created on: Feb 7, 2016
 *      Author: lewiatan
 */

#include <algorithm>
#include <vector>
#include <iostream>
#include <list>

// uzycie funkcji fill() i fill_n()
void excercise1()
{
    using namespace std;
    vector<int> vecIntegers(3);

    fill(vecIntegers.begin(), vecIntegers.end(), 9);

    vecIntegers.resize(6);

    fill_n(vecIntegers.begin() + 3, 3, -9);

    cout << "Zawartosc wektora to: " << endl;
    for (size_t n = 0; n < vecIntegers.size(); ++n) {
        cout << "Element[" << n << "] = " << vecIntegers.at(n) << endl;
    }

}

// uzycie funkcji generate() oraz generate_n()
void excercise2()
{
    using namespace std;

    srand(time(0));

    vector<int> vecIntegers(10);
    generate(vecIntegers.begin(), vecIntegers.end(), rand);

    cout << "Elementy w wektorze o rozmiarze " << vecIntegers.size()
         << " przypisane przy uzyciu f. 'generate()' to: " << endl << "{";

    for (size_t n = 0; n < vecIntegers.size(); ++n) {
        cout << vecIntegers[n] << ", ";
    }

    cout << "}" << endl;

    list<int> listIntegers(10);
    generate_n(listIntegers.begin(), 5, rand);

    cout << "Elementy w liscie o rozmiarze " << listIntegers.size()
         << " przypisane przy uzyciu f. 'generate_n()' to: " << endl << "{";
    for (auto it = listIntegers.cbegin();
         it != listIntegers.cend();
         ++it) {
        cout << *it << ' ';
    }
}

int main()
{
    std::cout << "Excercise 1: " << std::endl;
    excercise1();
    std::cout << "Excercise 2: " << std::endl;
    excercise2();
}
