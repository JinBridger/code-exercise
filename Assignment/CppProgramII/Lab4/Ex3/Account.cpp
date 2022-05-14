#include <iostream>
#include "Account.h"

Account::Account(const double &b) {
    if(b >= 0)
        balance = b;
    else
        std::cout << "ERROR: TRYING TO INITIALIZE A NEGATIVE ACCOUNT!" << std::endl;        
}

bool Account::debit(const double &amount) {
    if(amount <= balance) {
        balance -= amount;
        return true;
    } else {
        std::cout << "Debit amount exceeded account balance." << std::endl;
        return false;
    }
}

void Account::credit(const double &amount) {
    balance += amount;
}

double Account::getBalance() const {
    return balance;
}