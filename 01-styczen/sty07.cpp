/*
 * main.cpp
 *
 *  Created on: Jan 7, 2016
 *      Author: lewiatan
 */


#include <map>
#include <iostream>
#include <string>

template <typename KeyType>
struct ReverseSort
{
    bool operator ()(const KeyType& left, const KeyType& right)
    {
        return (left > right);
    }
};

void excercise1()
{
    std::map<int, std::string> mapIntToString1;
    std::multimap<int, std::string> mmapIntToString1;

    std::map<int, std::string> mapIntToString2(mapIntToString1);

    std::map<int, std::string> mapIntTostring3(mapIntToString1.begin(), mapIntToString1.end());

    std::map<int, std::string, ReverseSort<int>> mapIntToString4(mapIntToString1.begin(), mapIntToString1.end());
}

template <typename T>
void DisplayContents(const T& input)
{
    for (auto iElement = input.cbegin()
        ; iElement != input.cend()
        ; ++iElement) {
        std::cout << iElement->first << "->" << iElement->second << std::endl;
    }
    std::cout << std::endl;
}

void excercise2()
{
    std::map<int, std::string> mapIntToString;

    mapIntToString.insert(std::map<int, std::string>::value_type(3, "Trzy"));

    mapIntToString.insert(std::make_pair(-1,"Minus jeden"));

    mapIntToString.insert(std::pair<int, std::string>(1000, "Tysiac"));

    mapIntToString[100000000] = "Milion";

    std::cout << "Obiekt map zawiera " << mapIntToString.size();
    std::cout << " par(e/y) klucz-wartosc. Elementy w obiekcie map to:" << std::endl;
    DisplayContents(mapIntToString);

    std::multimap<int, std::string> mmapIntToString(mapIntToString.cbegin(), mapIntToString.cend());

    mmapIntToString.insert(std::make_pair(1000, "Tysiac"));
    mmapIntToString.insert(std::make_pair(1000, "Tysiac"));

    std::cout << "Obiekt multimap zawiera " << mmapIntToString.size();
    std::cout << " par(e/y) klucz-wartosc. Elementy w obiekcie multimap to:" << std::endl;
    DisplayContents(mmapIntToString);

    std::cout << "Liczba par w obiekcie multimap o kluczu 1000: "
            << mmapIntToString.count(1000) << std::endl;

}

int main()
{
    excercise1();
    excercise2();
    return 0;
}
