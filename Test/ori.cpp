/*
POJ 2482 Stars in your window
竖向扫描线，从左往右扫
*/
#include <algorithm>
#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

const int MAXN = 1e7;
int n, W, H, ans;
int x[MAXN], y[MAXN], c[MAXN];
int Y[MAXN];
struct line {
    int y1, y2, x, val;
} l[MAXN * 2];
struct node {
    int l, r, val, tag;
} tree[MAXN * 4];

int cmp(line a, line b) {
    if(a.x != b.x)
        return a.x < b.x;
    else
        return a.val < b.val;
}
void add_line(int x_, int y_, int c_, int i) {
    // 确保 y2 < y1
    // 确保 l[i].x < l[i << 1].x
    Y[i << 1] = y[i];
    Y[i * 2 - 1] = y[i] - H;

    l[i * 2 - 1].y1 = y_;
    l[i * 2 - 1].y2 = y_ - H;
    l[i * 2 - 1].x = x_ - W;
    l[i * 2 - 1].val = c_;

    l[i << 1].y1 = y_;
    l[i << 1].y2 = y_ - H;
    l[i << 1].x = x_;
    l[i << 1].val = -c_;
}
void build(int p, int l, int r) { // 建树
    tree[p].l = l;
    tree[p].r = r;
    tree[p].val = 0;
    tree[p].tag = 0;
    if (l == r)
        return;
    int mid = (l + r) / 2;
    build(p << 1, l, mid);
    build(p << 1 | 1, mid + 1, r);
    return;
}
void spread(int p) { // 下传延迟标记
    if (tree[p].tag) {
        tree[p << 1].val += tree[p].tag;
        tree[p << 1 | 1].val += tree[p].tag;
        tree[p << 1].tag += tree[p].tag;
        tree[p << 1 | 1].tag += tree[p].tag;
        tree[p].tag = 0;
    }
}
void change(int p, int l, int r, int v) { // 更改数值并更新
    spread(p);
    if (Y[tree[p].r + 1] <= l || r <= Y[tree[p].l]) {
        return;
    }
    if (l <= Y[tree[p].l] && Y[tree[p].r + 1] <= r) {
        tree[p].val += v;
        tree[p].tag += v;
        return;
    }
    change(p << 1, l, r, v);
    change(p << 1 | 1, l, r, v);
    tree[p].val = max(tree[p << 1].val, tree[p << 1 | 1].val);
    return;
}
void debugger() {
    printf("i\tx\ty1\ty2\tval\n");
    for (int i = 1; i <= 2 * n; i++) {
        printf("%d\t%d\t%d\t%d\t%d\n", i, l[i].x, l[i].y1, l[i].y2, l[i].val);
    }
}
int main() {
    freopen("D:\\Code_exercise\\Test\\Data\\data.in", "r", stdin);
    freopen("D:\\Code_exercise\\Test\\Data\\data.out", "w", stdout);
    while (scanf("%d%d%d", &n, &W, &H) != EOF) {
        ans = 0;
        memset(Y, 0, sizeof(Y));

        for (int i = 1; i <= n; i++) {
            scanf("%d%d%d", &x[i], &y[i], &c[i]);
            add_line(x[i], y[i], c[i], i);
        }
        sort(Y + 1, Y + 1 + 2 * n);  
        Y[0] = unique(Y + 1, Y + 1 + 2 * n) - Y - 1; // 进行离散化
        build(1, 1, Y[0] - 1);  // 建树，每个节点代表的区间为 l ~ r + 1
        sort(l + 1, l + 1 + n * 2, cmp);  // 按横坐标从左到右对竖边进行排序
        /*
        for(int i = 1; i <= Y[0]; i++) {
            printf("%d\t", i);
        } printf("\n");
        
        for(int i = 1; i <= Y[0]; i++) {
            printf("%d\t", Y[i]);
        }
        printf("\n%d",Y[0]);
        // debugger();
        
        for (int i = 1; i <= 5; i++) {
            printf("%d\t%d\n", tree[i].l,tree[i].r + 1);
        }*/
        for (int i = 1; i <= 2 * n; i++) {
            change(1, l[i].y2, l[i].y1, l[i].val); // 进行扫描
            // printf("%d\n", tree[1].val);
            // for(int j = 1; j <= 6; j ++) printf("%d\t", tree[j].val);
            // printf("\n");
            ans = max(ans, tree[1].val); // 对答案进行更新
        }
        printf("%d\n", ans); 
        
    }
    return 0;
}
/*
3 5 4
1 2 3
2 3 2
6 3 1
*/