/*
 * main.cpp
 *
 *  Created on: Jan 8, 2016
 *      Author: lewiatan
 */

#include <map>
#include <iostream>
#include <string>

template <typename T>
void DisplayContents(const T& input)
{
    for (auto iElement = input.cbegin() ;
         iElement != input.cend() ;
         ++iElement) {
        std::cout << iElement->first << " -> " << iElement->second << std::endl;
    }
    std::cout << std::endl;
}

void excercise1()
{
    std::map<int, std::string> mapIntToString;

    mapIntToString.insert(std::make_pair(3, "trzy"));
    mapIntToString.insert(std::make_pair(45, "Czterdziesci piec"));
    mapIntToString.insert(std::make_pair(-1, "Minus jeden"));
    mapIntToString.insert(std::make_pair(1000, "Tysiac"));

    std::cout << "Obiekt map zawiera " << mapIntToString.size();
    std::cout << " par(e/y) klucz-wartosc. Elementy w obiekcie map to: " << std::endl;

    DisplayContents(mapIntToString);

    while (true)
    {
        std::cout << "Podaj klucz:" << std::endl;
        int klucz = 0;
        std::cin >> klucz;

        auto iPairFound = mapIntToString.find(klucz);
        if (iPairFound != mapIntToString.end()) {
            std::cout << "Klucz " << iPairFound->first << " prowadzi do wartosci: "
                    << iPairFound->second << std::endl;
        } else
            std::cout << "Sorki, ale para o kluczu " << klucz << " nie istnieje..." << std::endl;
    }

}

void excercise2()
{
    std::multimap<int, std::string> multimapIntToString;

    multimapIntToString.insert(std::make_pair(3, "trzy"));
    multimapIntToString.insert(std::make_pair(3, "Trzy"));
    multimapIntToString.insert(std::make_pair(3, "Drei"));
    multimapIntToString.insert(std::make_pair(45, "Czterdziesci piec"));
    multimapIntToString.insert(std::make_pair(-1, "Minus jeden"));
    multimapIntToString.insert(std::make_pair(1000, "Tysiac"));

    std::cout << "Obiekt map zawiera " << multimapIntToString.size();
    std::cout << " par(e/y) klucz-wartosc. Elementy w obiekcie map to: " << std::endl;

    DisplayContents(multimapIntToString);

    while (true)
    {
        std::cout << "Podaj klucz:" << std::endl;
        int klucz = 0;
        std::cin >> klucz;

        auto iPairFound = multimapIntToString.find(klucz);
        if (iPairFound != multimapIntToString.end()) {
            size_t iloscPar = multimapIntToString.count(klucz);
            for (size_t i = 0; i < iloscPar; ++i)
            {
                std::cout << "Klucz " << iPairFound->first << " prowadzi do wartosci: "
                        << iPairFound->second << std::endl;

                ++iPairFound;
            }
        } else
            std::cout << "Sorki, ale para o kluczu " << klucz << " nie istnieje..." << std::endl;
    }

}

void excercise3()
{
    std::multimap<int, std::string> multimapIntToString;

    multimapIntToString.insert(std::make_pair(3, "trzy"));
    multimapIntToString.insert(std::make_pair(3, "Trzy"));
    multimapIntToString.insert(std::make_pair(3, "Drei"));
    multimapIntToString.insert(std::make_pair(45, "Czterdziesci piec"));
    multimapIntToString.insert(std::make_pair(-1, "Minus jeden"));
    multimapIntToString.insert(std::make_pair(1000, "Tysiac"));
    multimapIntToString.insert(std::make_pair(1000, "Tysiac"));

    std::cout << "Obiekt map zawiera " << multimapIntToString.size();
    std::cout << " par(e/y) klucz-wartosc. Elementy w obiekcie map to: " << std::endl;

    DisplayContents(multimapIntToString);

    while (true)
    {
        std::cout << "Podaj klucz:" << std::endl;
        int klucz = 0;
        std::cin >> klucz;

        auto iPairFound = multimapIntToString.find(klucz);
        if (iPairFound != multimapIntToString.end()) {
            //multimapIntToString.erase(iPairFound, iPairFound++);
            multimapIntToString.erase(multimapIntToString.lower_bound(klucz), multimapIntToString.upper_bound(klucz));
        } else
            std::cout << "Sorki, ale para o kluczu " << klucz << " nie istnieje..." << std::endl;

        DisplayContents(multimapIntToString);
    }

}

int main()
{
    excercise3();

    return 0;
}

