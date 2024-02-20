// FILENAME: Account.h
// defining the Account class 

#ifndef __ACCOUNT__H
#define __ACCOUNT__H


#include <iostream>
#include <string>

class Account {
    private:                /// sheltered members 
        std::string         name;
        unsigned long       id;
        double              balance;
    
    public:  // public interface 
        bool init(const std::string&, unsigned long, double);
        void display();
        void deposit(double amount);


};

#endif //end __ACCOUNT__H 