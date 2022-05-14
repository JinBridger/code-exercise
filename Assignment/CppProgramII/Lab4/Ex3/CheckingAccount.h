#pragma once

#include "Account.h"

class CheckingAccount : public Account {
public:
    CheckingAccount(const double &, const double &);
    ~CheckingAccount() {}

    bool debit(const double &) override;
    void credit(const double &) override;
private:
    double transactionFee;
};