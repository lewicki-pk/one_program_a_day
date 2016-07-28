/*
 * main.cpp
 *
 *  Created on: Jan 6, 2016
 *      Author: lewiatan
 */

#include <set>
#include <string>
#include <iostream>

template <typename T>
void displayContents(T& input)
{
    for (auto iElement = input.cbegin();
         iElement != input.cend();
         ++iElement)
    {
        std::cout << iElement->word << " <-> " << iElement->translation << std::endl;
    }

    std::cout << std::endl;
}

struct Container
{
    std::string word;
    std::string translation;
    bool operator==(const Container& compare) const
    {
        return (compare.word == this->word);
    }

    bool operator<(const Container& compare) const
    {
        return (this->word < compare.word);
    }
};

using namespace std;
void excercise2()
{
    set<Container> slownik;
    while (true)
    {
        Container input;
        cout << "Podaj slowo" << endl;
        cin >> input.word;
        if (input.word == "konieccc")
            break;
        cout << "Podaj tlumaczenie" << endl;
        cin >> input.translation;
        if (input.translation == "konieccc")
            break;
        slownik.insert(input);
    }

    displayContents(slownik);
}

void excercise3()
{
    set<string> example;
   do {
       string input;
       cout << "Podaj slowo" << endl;
       cin >> input;
       pair<set<string>::iterator, bool> para = example.insert(input);
       cout << "Dodano? " << para.second << endl;
   } while (true);
}
struct ContactItem
{
    string contactsName;
    string phoneNumber;
    string strDisplayRepresentation;

    ContactItem (const string& name, const string& number)
    {
        contactsName = name;
        phoneNumber = number;
        strDisplayRepresentation = name + ": " + number;
    }

    bool operator==(const ContactItem& itemToCompare) const
    {
        return (itemToCompare.contactsName == this->contactsName);
    }

    bool operator<(const ContactItem& itemToCompare) const
    {
        return (this->contactsName < itemToCompare.contactsName);
    }

    operator const char*() const
    {
        return strDisplayRepresentation.c_str();
    }
};

template <typename T>
struct predykat
{
    bool operator()(const T& item1, const T& item2) const
    {
        return (item1.phoneNumber < item2.phoneNumber);
    }

};

void excercise1()
{
    set<ContactItem, predykat<ContactItem>> contacts;
    contacts.insert(ContactItem("Jack Welsch","+1 7889 879 879"));
    contacts.insert(ContactItem("Bill Gates","+1 97 7897 8799 8"));
    contacts.insert(ContactItem("Angela Merkel","+49 23456 5466"));
    contacts.insert(ContactItem("Vladimir Putin","+7 6645 4564 797"));
    contacts.insert(ContactItem("Manmohan Singh","+91 234 4564 789"));
    contacts.insert(ContactItem("Barack Obama","+1 745 641 314"));

    cout << "lista w kolejnosci poczatkowej :" << endl;
    for (auto it = contacts.begin(); it != contacts.end(); ++it) {
        cout << *it << endl;
    }
}

int main()
{
    excercise1();

}
