#include <iostream>
#include <algorithm>
#include <vector>

int main()
{
    using namespace std;
    vector<int> vecIntegers;

    for (int SampleVal = -9; SampleVal < 10; ++SampleVal) {
        vecIntegers.push_back(SampleVal);
    }
    cout << "Enter number to find in collection: ";
    int NumToFind = 0;
    cin >> NumToFind;

    auto iElementFound = find(vecIntegers.cbegin(),
                              vecIntegers.cend(),
                              NumToFind);

    if (iElementFound != vecIntegers.cend())
        cout << "Result: Value " << *iElementFound << " found!" << endl;
    else
        cout << "Result: No element contains this value!" << endl;


    auto iEvenNumer = find_if(iElementFound,
                              vecIntegers.cend(),
                              [](int element) { return ((element % 2) == 0);});

    if (iEvenNumer!= vecIntegers.cend())
    {
        cout << "Number '" << *iEvenNumer << "' found at position ["
                << distance(vecIntegers.cbegin(), iEvenNumer) << "]!" << endl;
    }
    return 0;
}
