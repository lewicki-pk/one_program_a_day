/*
 * lut22.cpp
 *
 *  Created on: Feb 22, 2016
 *      Author: lewiatan
 */

#include <string>
#include <queue>
#include <iostream>

class Person
{
public:
    Person(int age_, bool female_, std::string name_)
      : age(age_), isFemale(female_), name(name_)
    { }

    int age;
    bool isFemale;
    std::string name;

    bool operator<(const Person& rhs)
    {
        return this->age < rhs.age;
    }
};

struct porownaj {
    bool operator()(Person*& lhs, Person*& rhs)
    {
        return lhs->age < rhs->age;
    }
};

int main()
{
    std::priority_queue<Person*, std::deque<Person*>, porownaj> myQueue;
    myQueue.emplace(new Person(26, false, "Peter"));
    myQueue.emplace(new Person(28, true, "Paula"));
    myQueue.emplace(new Person(5, false, "baby"));
    myQueue.emplace(new Person(80, true, "grandma"));

    while (!myQueue.empty())
    {
        std::cout << "Person: " << myQueue.top()->name
                  << ", age: " << myQueue.top()->age
                  << " leaves myQueue!" << std::endl;
        delete myQueue.top();
        myQueue.pop();
    }
    return 0;
}
