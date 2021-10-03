#include <bits/stdc++.h>
using namespace std;

const int MAXN = 3e4 + 100;
int t, fa[MAXN], d[MAXN], size[MAXN];
char opt;

int get(int x) {
    if(fa[x] == x) return x;
    int root = get(fa[x]);
    d[x] += d[fa[x]];
    return fa[x] = root;
}
void merge(int x, int y) {
    x = get(x);
    y = get(y);
    fa[x] = y;
    d[x] = size[y];
    size[y] += size[x];
}
int main(){
    scanf("%d",&t);
    for(int i = 1; i <= 30000; i++) {
        fa[i] = i;
        size[i] = 1;
    }
    for(int i = 1; i <= t; i++) {
        int a, b;
        cin >> opt;
        scanf("%d%d", &a, &b);
        if(opt == 'M') {
            merge(a, b);
        } else {
            if(get(a) == get(b)) {
                printf("%d\n",abs(d[a] - d[b]) - 1);
            } else printf("-1\n");
        }
    }
    return 0;
}