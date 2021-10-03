#include <stdio.h>
#include <iostream>
using namespace std;
const int INF = 999999;
int a[10][10], ans;
char b[5][5];
int judge() {
    int x = a[0][0];
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            if (x != a[i][j])
                return 0;
    return 1;
}
void flip(int x, int y) {
    a[x][y] = !a[x][y];
    if (x - 1 >= 0)
        a[x - 1][y] = !a[x - 1][y];
    if (x + 1 < 4)
        a[x + 1][y] = !a[x + 1][y];
    if (y - 1 >= 0)
        a[x][y - 1] = !a[x][y - 1];
    if (y + 1 < 4)
        a[x][y + 1] = !a[x][y + 1];
}
void dfs(int x, int y, int t) {
    if (judge() == 1) {
        ans = min(t, ans);
        return;
    }
    if (x >= 4 || y >= 4)
        return;
    int newx = (x + 1) % 4;
    int newy = y + (x + 1) / 4;
    dfs(newx, newy, t);
    flip(x, y);
    dfs(newx, newy, t + 1);
    flip(x, y);
    return;
}
int main() {
    freopen("D:\\Code_exercise\\Test\\Data\\data.in", "r", stdin);
    freopen("D:\\Code_exercise\\Test\\Data\\data.ans", "w", stdout);
    ans = INF;
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++) {
            cin >> b[i][j];
            if (b[i][j] == 'b')
                a[i][j] = 0;
            else if (b[i][j] == 'w')
                a[i][j] = 1;
        }
    dfs(0, 0, 0);
    if (ans == INF)
        cout << "Impossible";
    else
        cout << ans;
    return 0;
}