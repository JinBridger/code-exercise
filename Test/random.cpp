#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("D:\\Code_exercise\\Test\\Data\\data.in", "w", stdout);
    srand((int)time(0));
    int t = rand() % 3 + 1;
    while (t--) {
        int n = rand() % 4 + 1;
        int W = rand() % 9 + 1;
        int H = rand() % 9 + 1;
        printf("%d %d %d\n", n, W, H);
        for(int i = 1; i <= n; i++) {
            int x_ = rand() % 9 + 1;
            int y_ = rand() % 9 + 1;
            int c_ = rand() % 9 + 1;
            printf("%d %d %d\n",x_,y_,c_);
        }
    }
    return 0;
}