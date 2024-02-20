// filename: account_t.cpp
// main for the account 
// Uses account objects 
// ---------------------------------------

#include "Account.h"
#include <iostream>


int main(){
    Account current1, current2, current3;
    Account *ptr; 
    current1.init("Zivai Chembwa", 93029382, 300.00);
    current1.display();

    current2 = current1;
    current2.display();
    
    std::cout << std::endl;
    std::cout << "current1 address: " << &current1 << "\n"
            << "current2 address: " << &current2 << std::endl;

    ptr = &current2;
    ptr->deposit(250.00);
    ptr->display();

    //use pointers with classes



    return 0;
}