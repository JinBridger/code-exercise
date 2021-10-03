#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e6 + 100;
int t, n, ans, fa[MAXN], X[MAXN];
struct g{
    int i ,j ,e;
} gp[MAXN];

int get(int x) {
    if(x == fa[x]) return x;
    return fa[x] = get(fa[x]);
}
void merge(int x, int y) {
    x = get(x);
    y = get(y);
    fa[x] = y;
    return ;
}
int cmp(g a, g b) {
    return a.e > b.e;
}
int main() {
    // freopen("D:\\Code_exercise\\Luogu\\Data\\P1955.in","r",stdin);
    // freopen("D:\\Code_exercise\\Luogu\\Data\\P1955.out","w",stdout);
    scanf("%d",&t);
    for(int i = 1; i <= t; i++) {
        scanf("%d", &n);
        for(int j = 1; j <= 2 * n; j++)
            fa[j] = j;
        ans = 1;
        for(int j = 1; j <= n; j++) {
            scanf("%d%d%d", &gp[j].i, &gp[j].j, &gp[j].e);
            X[j * 2 - 1] = gp[j].i;
            X[j * 2] = gp[j].j;
        }
        sort(gp + 1, gp + 1 + n, cmp);
        sort(X + 1, X + 1 + 2 * n);
        X[0] = unique(X + 1, X + 1 + 2 * n) - X - 1;
        for(int j = 1; j <= n; j++) {
            int x = lower_bound(X + 1, X + 1 + 2 * n, gp[j].i) - X - 1;
            int y = lower_bound(X + 1, X + 1 + 2 * n, gp[j].j) - X - 1;
            if(gp[j].e) {
                merge(x, y);
            } else {
                if(get(x) == get(y)) ans = 0;
            }
        }
        (ans)?(printf("YES\n")):(printf("NO\n"));
    }
    return 0;
}