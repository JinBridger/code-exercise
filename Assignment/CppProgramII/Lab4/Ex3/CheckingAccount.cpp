#include "CheckingAccount.h"

CheckingAccount::CheckingAccount(const double &b, const double &f) : Account(b), transactionFee(f) {

}

bool CheckingAccount::debit(const double &amount) {
    if(Account::debit(amount)) {
        balance -= transactionFee;
        return true;
    }
    return false;
}

void CheckingAccount::credit(const double &amount) {
    Account::credit(amount);
    balance -= transactionFee;
}