#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

char c;
int ans = 20;
int chs[10][10];

int jud() {
    for(int i = 1; i<= 4; i++) {
        for(int j = 1; j <= 4; j++) {
            if(chs[j][i] != chs[1][1])
                return 0;
        }
    }
    return 1;
}
void flip(int x, int y) {
    chs[x][y] = !chs[x][y];
    chs[x + 1][y] = !chs[x + 1][y];
    chs[x - 1][y] = !chs[x - 1][y];
    chs[x][y + 1] = !chs[x][y + 1];
    chs[x][y - 1] = !chs[x][y - 1];
    return;
}
void dfs(int x, int y, int stp) {
    if(x == 4 && y == 4) {
        if(jud()) ans = min(ans, stp);
        else {
            flip(x, y);
            if(jud()) ans = min(ans, stp + 1);
        }
        return ;
    }
    if(x == 4 && y != 4) dfs(1, y + 1, stp);
    else dfs(x + 1, y, stp);
    flip(x, y);
    if(x == 4 && y != 4) dfs(1, y + 1, stp + 1);
    else dfs(x + 1, y, stp + 1);
    flip(x, y);
    return ;
}
int main(){
    for(int i = 1; i <= 4; i++) {
        for(int j = 1; j <= 4; j++) {
            c = '0';
            while(c != 'b' && c != 'w') c = getchar();
            chs[j][i] = (c == 'b')?1:0;
        }
    }
    dfs(1, 1, 0);
    if(ans == 20) {
        printf("Impossible");
        return 0;
    }
    printf("%d", ans);
    return 0;
}