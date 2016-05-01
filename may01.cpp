#include <iostream>
#include <exception>
#include <string>
using namespace std;

class CustomException: public std::exception
{
    string Reason;
public:
    CustomException(const char * why) : Reason(why) {}
    virtual const char* what() const throw()
    {
        return Reason.c_str();
    }
};

double Divide(double Dividend, double Divisor)
{
    if (Divisor ==0)
        throw CustomException("CE: Dividiing by 0 is a crime");

    return (Dividend / Divisor);
}

int main()
{
    cout << "Enter dividend: ";
    double dividend = 0;
    cin >> dividend;
    cout << "Enter divisor: ";
    double divisor = 0;
    cin >> divisor;
    try
    {
        cout << "Result of division is: " << Divide(dividend, divisor) << endl;
    }
    catch (exception& e)
    {
        cout << e.what() << endl;
        cout << "Sorry, can't continue!" << endl;
    }

    return 0;
}
