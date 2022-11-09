#include "../shared_ptr/simple_shared_ptr.h"
#include <iostream>

using namespace ptr;

void testCopy() {
    shared_ptr<int> sp(new int(5));
    {
        shared_ptr<int> sp2(sp);    
        std::cout << *sp2 << std::endl;
    }
    
    std::cout << *sp;
}

void testMove() {
    shared_ptr<int> sp(new int(5));
    {
        shared_ptr<int> sp2(std::move(sp));    
        std::cout << *sp2 << std::endl;
    }
    
    // std::cout << *sp; ask for candidate: why it'll crash?
}