/*
 * main.cpp
 *
 *  Created on: Jan 13, 2016
 *      Author: lewiatan
 * Description: Dostarczenie predykatu sortowania do obiektow  map i multimap
 */


#include <map>
#include <algorithm>
#include <string>
#include <iostream>

template <typename T>
void DisplayContents(const T& input)
{
    for (auto iElement = input.cbegin()
          ; iElement != input.cend()
          ; ++iElement)
    {
        std::cout << iElement->first << " - > " << iElement->second << std::endl;
    }
    std::cout << std::endl;
}

struct PredIgnoreCase
{
    bool operator() (const std::string& str1, const std::string& str2) const
    {
        std::string str1NoCase(str1), str2NoCase(str2);
        std::transform(str1.begin(), str1.end(), str1NoCase.begin(), tolower);
        std::transform(str2.begin(), str2.end(), str2NoCase.begin(), tolower);

        return (str1NoCase < str2NoCase);
    };
};

int main()
{
    std::map<std::string, std::string, PredIgnoreCase>
       dirCaseInsensitive;

    dirCaseInsensitive.insert(std::make_pair("Jan", "2345764"));
    dirCaseInsensitive.insert(std::make_pair("JAN", "2345764"));
    dirCaseInsensitive.insert(std::make_pair("Sandra", "42367236"));
    dirCaseInsensitive.insert(std::make_pair("Jacek", "32435348"));


    std::cout << "Wyswietlenie zawartosci obiektu map, ktory nie rozroznia wielkosci znakow " << std::endl;
    DisplayContents(dirCaseInsensitive);

    std::map<std::string, std::string>
        dirCaseSensitive (dirCaseInsensitive.begin(), dirCaseInsensitive.end());

    std::cout << "Wyswietlenie zawartosci obiektu map, ktory rozroznia wielkosc znakow " << std::endl;
    DisplayContents(dirCaseSensitive);

    std::cout << "Prosze podac imie do wyszukania:" << std::endl;
    std::cout << ">";
    std::string nameInput;
    std::cin >> nameInput;

    auto iPairInNoCaseDir = dirCaseInsensitive.find(nameInput);
    if (iPairInNoCaseDir != dirCaseInsensitive.end()) {
        std::cout << "numer telefonu osoby " << iPairInNoCaseDir->first << " w ksiazce telefonicznej, ktora nie"
                << " rozroznia wielkosci znakow to:" << iPairInNoCaseDir->second << std::endl;
    } else {
        std::cout << "Numer telefonu osoby " << nameInput << " nie zostal znaleziony w ksiazce telefonicznej" << std::endl;
    }

    auto iPairInCaseDir = dirCaseSensitive.find(nameInput);
    if (iPairInCaseDir != dirCaseSensitive.end()) {
        std::cout << "numer telefonu osoby " << iPairInCaseDir->first << " w ksiazce telefonicznej, ktora"
                << " rozroznia wielkosci znakow to:" << iPairInCaseDir->second << std::endl;
    } else {
        std::cout << "Numer telefonu osoby " << nameInput << " nie zostal znaleziony w ksiazce telefonicznej" << std::endl;
    }

    return 0;
}
