/*
 * mar27.cpp
 *
 *  Created on: Mar 27, 2016
 *      Author: lewiatan
 */

#include <iostream>
#include <string>

template <typename T>
class destructiveCopyPointer
{
private:
    T* pObject;
    std::string name = "default";
public:
    destructiveCopyPointer(T* pInput, std::string name):pObject(pInput), name(name)
    {
        std::cout << name << "constructor" << std::endl;
    }
    ~destructiveCopyPointer()
    {
        std::cout << name << "destructor" << std::endl;
        delete pObject;
    }

    destructiveCopyPointer(destructiveCopyPointer& source)
    {
        std::cout << name << "copy constructor" << std::endl;
        // Take ownership on copy
        pObject = source.pObject;

        // destroy source
        source.pObject = 0;
    }

    // copy assignment operator
    destructiveCopyPointer& operator= (destructiveCopyPointer& rhs)
    {
        std::cout << name << "assignment operator" << std::endl;
        if (pObject != rhs.pObject)
        {
            delete pObject;
            pObject = rhs.pObject;
            rhs.pObject = 0;
        }
    }
};

int main()
{
    destructiveCopyPointer<int> pNumber (new int, "number");
    destructiveCopyPointer<int> pCopy = pNumber;
    std::cout << "============" << std::endl;
    return 0;
}
