#include "SavingsAccount.h"

SavingsAccount::SavingsAccount(const double &b, const double &r) : Account(b), interestRate(r) {

}

double SavingsAccount::calculateInterest() const {
    return balance * interestRate;
}