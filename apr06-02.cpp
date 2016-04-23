#include <iostream>
#include <string>
using namespace std;

int main()
{
    cout << "Enter a line: " << endl;
    char CStyleStr[10] = {0};
    cin.get(CStyleStr, 9);
    cout << "Cstyle string equals: " << CStyleStr << endl;

    return 0;
}
