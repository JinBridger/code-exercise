#include <iostream>
using namespace std;

int main() {
    int num[11];
    cout << "Data items in original order" << endl;
    for(int i = 1; i <= 10; ++ i)
        cin >> num[i];
    for(int i = 1; i <= 10; ++ i) {
        for(int j = 2; j <= 10; ++ j) {
            if(num[j] < num[j - 1]) 
                swap(num[j], num[j - 1]);
        }
    }
    cout << "Data items in ascending order" << endl;
    for(int i = 1; i <= 10; ++ i)
        cout << num[i] << " ";
    return 0;
}