#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std;

const int MAXN = 1e6;
int n, ans, bef, cur_x;
int x1[MAXN], y1[MAXN], x2[MAXN], y2[MAXN];
int Y[MAXN];
struct line {
    // y1 < y2
    int x, y1, y2, val;
} l[MAXN];
struct node {
    int l, r, cov, len;
} tree[MAXN];

void add_line(int x1_, int y1_, int x2_, int y2_, int i) {
    Y[2 * i] = y1_;
    Y[2 * i - 1] = y2_;

    l[i * 2 - 1].x = x1_;
    l[i * 2 - 1].y1 = y1_;
    l[i * 2 - 1].y2 = y2_;
    l[i * 2 - 1].val = 1;

    l[i * 2].x = x2_;
    l[i * 2].y1 = y1_;
    l[i * 2].y2 = y2_;
    l[i * 2].val = -1;
}
int cmp(line a, line b) {
    if(a.x == b.x) {
        return a.val > b.val;
    } else {
        return a.x < b.x;
    }
}
void build(int p, int l, int r) {
    tree[p].cov = tree[p].len = 0;
    tree[p].l = l;
    tree[p].r = r;
    if(l == r) {
        return ;
    }
    int mid = (l + r) / 2;
    build(p << 1, l, mid);
    build(p << 1 | 1, mid + 1, r);
    return ;    
}
void upd(int p) {
    if(tree[p].cov) {
        tree[p].len = (Y[tree[p].r + 1] - Y[tree[p].l]);
    } else {
        tree[p].len = tree[p << 1].len + tree[p << 1 | 1].len;
    }
    return ;
}
void change(int p, int l, int r, int v) {
    if(Y[tree[p].r + 1] <= l || r <= Y[tree[p].l]) {
        return ;
    }
    if(l <= Y[tree[p].l] && Y[tree[p].r + 1] <= r) {
        tree[p].cov += v;
        upd(p);
        return ;
    }
    change(p << 1, l, r, v);
    change(p << 1 | 1, l, r, v);
    upd(p);
    return ;
}
int main() {
    // freopen("D:\\Code_exercise\\POJ\\Data\\poj1177.in", "r", stdin);
    scanf("%d", &n);
    if(n == 0) {
        printf("0\n");
        return 0;
    }
    for (int i = 1; i <= n; i++) {
        // 1 -> 左下角 ; 2 -> 右上角
        scanf("%d%d%d%d", &x1[i], &y1[i], &x2[i], &y2[i]);
        add_line(x1[i], y1[i], x2[i], y2[i], i);
    }
    sort(Y + 1, Y + 1 + 2 * n);    
    Y[0] = unique(Y + 1, Y + 1 + 2*n) - Y - 1;
    sort(l + 1, l + 1 + 2 * n, cmp);
    build(1, 1, Y[0] - 1);
    for(int i = 1; i <= 2 * n; i++) {
        change(1, l[i].y1, l[i].y2, l[i].val);
        ans += (tree[1].len > bef)?(tree[1].len - bef):(- tree[1].len + bef);
        bef = tree[1].len;
    }
    bef = 0;
    /**/
    for (int i = 1; i <= n; i++) {
        // 1 -> 左下角 ; 2 -> 右上角
        add_line(y1[i], x1[i], y2[i], x2[i], i);
    }
    sort(Y + 1, Y + 1 + 2 * n);    
    Y[0] = unique(Y + 1, Y + 1 + 2*n) - Y - 1;
    sort(l + 1, l + 1 + 2 * n, cmp);
    build(1, 1, Y[0] - 1);
    for(int i = 1; i <= 2 * n; i++) {
        change(1, l[i].y1, l[i].y2, l[i].val);
        ans += (tree[1].len > bef)?(tree[1].len - bef):(- tree[1].len + bef);
        bef = tree[1].len;
    }
    printf("%d\n", ans);
    return 0;
}
/*
7
-15 0 5 10
-5 8 20 25
15 -4 24 14
0 -6 16 4
2 15 10 22
30 10 36 20
34 0 40 16
*/