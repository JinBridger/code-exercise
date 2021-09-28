#include <bits/stdc++.h>
using namespace std;

int main(){
    for(int T = 1; T <= 10000; T++) {
        system("D:\\Code_exercise\\Test\\Bin\\random.exe");
        double st = clock();
        system("D:\\Code_exercise\\Test\\Bin\\sol.exe");
        double ed = clock();
        system("D:\\Code_exercise\\Test\\Bin\\ori.exe");
        if(system("fc D:\\Code_exercise\\Test\\Data\\data.out D:\\Code_exercise\\Test\\Data\\data.ans")) {
            puts("Wrong Answer");
            system("pause");
            return 0;
        } else {
            printf("Accepted, Test Case #%d, Time: %.0lfms\n", T, ed-st);
        }
    }
    return 0;
}