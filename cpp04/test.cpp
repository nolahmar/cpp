#include <iostream>
#include "test.hpp"

void Test::print_hello() const {
    std::cout << "Hello world" << std::endl;
}


int main() {
    ITest *t = new Test();
    t->print_hello();
    return 0;
}

