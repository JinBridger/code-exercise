#pragma once

class Account {
public:
    Account(const double &);
    virtual ~Account() {}

    double getBalance() const;
    virtual bool debit(const double &);
    virtual void credit(const double &);
protected:
    double balance;
};