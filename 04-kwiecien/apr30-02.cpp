#include <iostream>
using namespace std;

struct StructA
{
    StructA() {cout << "Constructed a struct A" << endl;}
    ~StructA() {cout << "Destructed a struct A" << endl;}
};

struct StructB
{
    StructB() {cout << "Constructed a struct B" << endl;}
    ~StructB() {cout << "Destructed a struct B" << endl;}
};

struct StructC
{
    StructC() {cout << "Constructed a struct C" << endl;}
    ~StructC() {cout << "Destructed a struct C" << endl;}
};

struct StructD
{
    StructD() {cout << "Constructed a struct D" << endl;}
    ~StructD() {cout << "Destructed a struct D" << endl;}
};

void FuncB() // throws
{
    cout << "In func B" << endl;
    StructC objC;
    StructD objD;
    cout << "About to throw up!" << endl;
    throw "Throwing for the heck of it";
}

void FuncA()
{
    try
    {
        cout << "In func A" << endl;
        StructA objA;
        StructB objB;
        FuncB();
        cout << "FuncA: returning to caller" << endl;
    }
    catch (const char* exp)
    {
        cout << "FuncA: Caught exception, it says: " << exp << endl;
        cout << "FuncA: Handled it here, will not throw to caller" << endl;
        // throw; // uncomment to throw to main()
    }
}

int main()
{
    cout << "main(): Started execution" << endl;
    try
    {
        FuncA();
    }
    catch (const char* e)
    {
        cout << "Exception: " << e << endl;
    }
    cout << "main(): exiting gracefully" << endl;
    return 0;
}
