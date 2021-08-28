/*实现了Hello::print()*/
#include <iostream>

#include "static/hello.h"

void Hello::print()
{
    std::cout << "Hello Shared Library!" << std::endl;
}