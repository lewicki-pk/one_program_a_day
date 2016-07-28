/*
 * mar28-02.cpp
 *
 *  Created on: Mar 28, 2016
 *      Author: lewiatan
 */

#include <memory>
#include <iostream>
using namespace std;

class Fish
{
public:
    Fish()
    {
        cout << "Fish: Constructed!" << endl;
    }

    ~Fish()
    {
        cout << "Fish: Destructed!" << endl;
    }

    void Swim() const
    {
        cout << "Fish swims in water" << endl;
    }
};

void MakeFishSwim (const unique_ptr<Fish>& inFish)
{
    inFish->Swim();
}

int main()
{
    unique_ptr<Fish> smartFish(new Fish);

    smartFish->Swim();
    MakeFishSwim(smartFish);

    unique_ptr<Fish> copySmartFish;
    // copySmartFish = smartFish;

    return 0;
}
