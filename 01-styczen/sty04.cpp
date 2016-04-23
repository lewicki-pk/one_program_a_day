/*
 * 04sty.cpp
 *
 *  Created on: Jan 4, 2016
 *      Author: lewiatan
 */

#include <list>
#include <string>
#include <iostream>
using namespace std;

template <typename T>
void displayContents(T& input)
{
    for (auto iElement = input.cbegin();
         iElement != input.cend();
         ++iElement)
        cout << *iElement << endl;

    cout << endl;
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

bool sortOnPhoneNumber(const ContactItem& item1, const ContactItem& item2)
{
    return (item1.phoneNumber < item2.phoneNumber);
}

int main()
{
    list <ContactItem> contacts;
    contacts.push_back(ContactItem("Jack Welsch","+1 7889 879 879"));
    contacts.push_back(ContactItem("Bill Gates","+1 97 7897 8799 8"));
    contacts.push_back(ContactItem("Angela Merkel","+49 23456 5466"));
    contacts.push_back(ContactItem("Vladimir Putin","+7 6645 4564 797"));
    contacts.push_back(ContactItem("Manmohan Singh","+91 234 4564 789"));
    contacts.push_back(ContactItem("Barack Obama","+1 745 641 314"));

    cout << "lista w kolejnosci poczatkowej :" << endl;
    displayContents(contacts);

    contacts.sort();
    cout << "po posortowaniu w kolejnowsci alfabetycznej przy uzyciu operatora <" << endl;
    displayContents(contacts);

    contacts.sort(sortOnPhoneNumber);
    cout << "po posortowaniu wedlug numeru telefonu przy uzyciu predykatu :" << endl;
    displayContents(contacts);

    cout << "Po usunieciu Putina z listy" << endl;
    contacts.remove(ContactItem("Vladimir Putin", "43252342"));
    displayContents(contacts);
}







