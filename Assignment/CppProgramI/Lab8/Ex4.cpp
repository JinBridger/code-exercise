#include <iostream>
using namespace std;

bool paren_check(char *expr) {
    int stk = 0;
    for(char *ptr = expr; *ptr != '\0'; ++ptr) {
        if(*ptr == '(')
            stk ++;
        if(*ptr == ')')
            stk --;
        if(stk < 0)
            return false;
    }
    if(stk != 0)
        return false;
    return true;
}
int main(){
    char strExpr[100];
    cout << "Please input the expression: " << endl;
    cin >> strExpr;
    cout << "The result is: " << paren_check(strExpr);
    return 0;
}