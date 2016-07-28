/*
 * 03sty.cpp
 *
 *  Created on: Jan 3, 2016
 *      Author: lewiatan
 */

#include <list>
#include <iostream>

using namespace std;

template <typename T>
void displayContent(const T& input)
{
    for (auto iElement = input.cbegin();
            iElement != input.cend();
            ++iElement)
    {
        cout << *iElement << ' ';
    }
    cout << endl;
}

bool sortujMalejaco(const int& lhs, const int& rhs)
{
    if (lhs > rhs)
        return true;
    else
        return false;
}

int main(int argc, char* argv[])
{
    list <int> lista;

    lista.push_back(4);
    lista.push_back(5);
    lista.push_front(1);
    lista.push_front(3);
    lista.push_front(2);

    cout << "Niezmieniona lista: ";
    displayContent(lista);

    auto pierwszy = lista.begin();
    auto ostatni = lista.end();
    cout << "pierwszy wskazuje na \"" << *pierwszy << "\" a ostatni na \"" << *ostatni << "\"" << endl;
    lista.reverse();
    cout << "Zmieniona lista: ";
    displayContent(lista);

    cout << "pierwszy wskazuje na \"" << *pierwszy << "\" a ostatni na \"" << *ostatni << "\"" << endl;

    // Copy constructor
    list<int> kopiaListy(lista);
    cout << "Kopia listy: ";
    displayContent(kopiaListy);

    // Sort
    lista.sort();
    cout << "Posortowana lista:";
    displayContent(lista);

    kopiaListy.sort(sortujMalejaco);
    cout << "Posortowana kopia listy:";
    displayContent(kopiaListy);


}
