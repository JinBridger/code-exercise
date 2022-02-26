#include <iostream>
#include <algorithm>
using namespace std;

int sortnum(int num) {
    int digits[10] = {0};
    int digitNum = 0;
    int ans = 0;
    while(num) {
        digits[++digitNum] = num % 10;
        num /= 10;
    }
    sort(digits + 1, digits + 1 + digitNum);
    for(int i = digitNum; i >= 1; --i) {
        ans *= 10;
        ans += digits[i];
    }
    return ans;
}
int main() {
    int num;
    cin >> num;
    cout << sortnum(num);
    return 0;
}