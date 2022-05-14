#include <iostream>
#include <iomanip>
#include <vector>
#include "SavingsAccount.h"
#include "CheckingAccount.h"

void handleSavingOrChecking(Account *aPtr) {
    if(SavingsAccount *sp = dynamic_cast<SavingsAccount*>(aPtr)) {
        sp->credit(sp->calculateInterest());
    }
}
int main() {
    Account* accPtr[5];

    accPtr[0] = new SavingsAccount(123, 0.0135);
    accPtr[1] = new SavingsAccount(1e8, 0.0125);
    accPtr[2] = new SavingsAccount(15674, 0.011);
    accPtr[3] = new CheckingAccount(123, 5);
    accPtr[4] = new CheckingAccount(1e8, 1000);

    std::cout << "Before: " << std::endl;

    for(int i = 0; i < 5; ++i)
        std::cout << "Balance is " << accPtr[i]->getBalance() << std::endl;

    for(int i = 0; i < 5; ++i)
        handleSavingOrChecking(accPtr[i]);

    std::cout << "After: " << std::endl;

    for(int i = 0; i < 5; ++i)
        std::cout << "Balance is " << accPtr[i]->getBalance() << std::endl;

    return 0;
}