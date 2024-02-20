// FIlename :: Account.cpp

#include "Account.h"
#include <iostream>
#include <iomanip>

#define MINIMUM     20
//copies the arguments into the private members of the class 
bool Account::init(const std::string& a_name, unsigned long a_id, double a_balance){
// no empty name 
if (name.size())
{
    return false;
    }
name = a_name;
id = a_id;
balance = a_balance;

return true;
};

//Output the private data 
void Account::display(){

    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(2)
        << "------------------------------------- \n"
        <<"Account holder:  "<< name << "\n"
        << "Account number:  " << id << "\n"
        << "Account balance: " << balance << "\n"
        << "--------------------------------------\n"
        << std::endl;

}

void Account::deposit(double amount){
    if (amount > 10){
        std::cout << "Minimun deposit is " << MINIMUM << std::endl;
    }
    balance+= amount; 

}