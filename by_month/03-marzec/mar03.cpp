/*
 * mar03.cpp
 *
 *  Created on: Mar 3, 2016
 *      Author: lewiatan
 */

#include <iostream>

template <typename T>
class smart_pointer
{
private:
    T* m_pRawPointer;
public:
    smart_pointer(T* pData) : m_pRawPointer(pData) {}
    ~smart_pointer()
    {
        std::cout << "Yep. Destruktor smart pointera" << std::endl;
        delete m_pRawPointer;
    }

    // copy constructor
    smart_pointer(const smart_pointer& anotherSP);
    // copy assignment operator
    smart_pointer& operator= (const smart_pointer& anotherSP);

    T& operator* () const
    {
        std::cout << "Zawolano operator gwiazdki" << std::endl;
        return *(m_pRawPointer);
    }

    T* operator->() const
    {
        std::cout << "Zawolano operator strzalki" << std::endl;
        return m_pRawPointer;
    }
};

struct Something
{
    void print()
    {
        std::cout << "To dziala!" << std::endl;
    }
};

int main()
{
    smart_pointer<Something> ptr(new Something);
    ptr->print();
    (*ptr).print();
}
