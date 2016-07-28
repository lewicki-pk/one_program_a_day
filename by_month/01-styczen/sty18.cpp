/*
 * main.cpp
 *
 *  Created on: Jan 18, 2016
 *      Author: lewiatan
 */

#include <map>
#include <string>
#include <iostream>

struct wordProperty {
    std::string strWord;
    bool bIsFromLatin;

    wordProperty(std::string str, bool bl)
    : strWord(str), bIsFromLatin(bl) { }
};

struct predykat
{
    bool operator()(const wordProperty& lewy, const wordProperty& prawy) const
    {
        return (lewy.strWord < prawy.strWord);
    }
};

int main()
{
    std::multimap<wordProperty, std::string, predykat> mojaMapa;
    mojaMapa.insert(std::make_pair(wordProperty("slowo", false), "SLOWO"));
    mojaMapa.insert(std::make_pair(wordProperty("inne", true), "INNE"));
    mojaMapa.insert(std::make_pair(wordProperty("jakies", false), "JAKIES"));
    mojaMapa.insert(std::make_pair(wordProperty("aaaa", true), "AAAA"));
    mojaMapa.insert(std::make_pair(wordProperty("bbbb", false), "BBBB"));
    mojaMapa.insert(std::make_pair(wordProperty("bbbb", false), "BBBB"));

    for (auto it : mojaMapa)
    {
        std::cout << it.first.strWord << " z bool:" << it.first.bIsFromLatin << " <-> " << it.second << std::endl;
    }
}
