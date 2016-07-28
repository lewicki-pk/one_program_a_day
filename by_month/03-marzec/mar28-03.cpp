/*
 * mar28-03.cpp
 *
 *  Created on: Mar 28, 2016
 *      Author: lewiatan
 */

#include <iostream>
#include <iomanip>

int main()
{
    std::cout << "Enter an integer: ";
    int Input = 0;
    std::cin >> Input;

    std::cout << "Integer in octal: " << std::oct << Input << std::endl;
    std::cout << "Integer in hexadecimal: " << std::hex << Input << std::endl;

    std::cout << "Integer in hex using base notation: ";
    std::cout << std::setiosflags(std::ios_base::hex |
                                  std::ios_base::showbase |
                                  std::ios_base::uppercase);
    std::cout << Input << std::endl;

    std::cout << "Integer after resetting I/O flags: ";
    std::cout << std::resetiosflags(std::ios_base::hex |
                                    std::ios_base::showbase |
                                    std::ios_base::uppercase);
    std::cout << Input << std::endl;

    return 0;
}
