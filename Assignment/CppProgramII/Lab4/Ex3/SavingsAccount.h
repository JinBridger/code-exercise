#pragma once

#include "Account.h"

class SavingsAccount : public Account {
public: 
    SavingsAccount(const double &, const double &);
    ~SavingsAccount() {}

    double calculateInterest() const;
private:
    double interestRate;
};