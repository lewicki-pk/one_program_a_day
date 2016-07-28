/*
 * main.cpp
 *
 *  Created on: Jan 5, 2016
 *      Author: lewiatan
 */

#include <iostream>
#include <cstdlib>
#include <list>
#include <vector>
#include <string>

int main()
{
    std::vector<std::string> mojWektor = {"jeden", "dwa", "trzy", "cztery", "piec"};
    std::list<std::string> listaStringow(++mojWektor.begin(), --mojWektor.end());

    for (auto it = listaStringow.cbegin();
            it != listaStringow.cend();
            ++it) {
        std::cout << *it << ' ';
    }
    std::cout << std::endl;

    std::list<int> mojaLista;
    int liczba;
    do {
        std::cout << "Podaj liczbe" << std::endl;
        std::string txt;
        std::cin >> txt;
        liczba = atoi(txt.c_str());
        if ((liczba != 0) or (txt == "0"))
        {
            mojaLista.push_front(liczba);
        } else {
            break;
        }
    } while (true);
    std::cout << "Lista zawiera " << mojaLista.size() << " elementy(ow):" << std::endl;
    for (auto it = mojaLista.cbegin();
            it != mojaLista.cend();
            ++it) {
        std::cout << *it << ' ';
    }
    std::cout << std::endl;
    return 0;
}
