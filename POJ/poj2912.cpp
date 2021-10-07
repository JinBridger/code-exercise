#include <cstdio>
#include <iostream>
using namespace std;

#define a(x) x * 3 - 2
#define b(x) x * 3 - 1
#define c(x) x * 3

const int MAXN = 2000;
int N, M, fa[MAXN], jud_num, jud, jud_line;
struct g {
    int x, y;
    char opt;
} dat[MAXN];

int get(int p) {
    if (fa[p] == p)
        return p;
    return fa[p] = get(fa[p]);
}
void merge(int x, int y) {
    fa[get(x)] = fa[get(y)];
    return;
}
void x_win_y(int x, int y) {
    merge(a(x), b(y));
    merge(b(x), c(y));
    merge(c(x), a(y));
}
void x_equal_y(int x, int y) {
    merge(a(x), a(y));
    merge(b(x), b(y));
    merge(c(x), c(y));
}
int check(int p) {
    if (get(a(p)) == get(b(p)) || get(b(p)) == get(c(p)) ||
        get(c(p)) == get(a(p))) {
        return 0;
    }
    return 1;
}
void deal(int p) {
    for (int i = 1; i <= N * 3 + 10; i++)
        fa[i] = i;
    for (int i = 1; i <= M; i++) {
        if (dat[i].x == p || dat[i].y == p)
            continue;
        switch (dat[i].opt) {
            case '<':
                x_win_y(dat[i].y, dat[i].x);
                break;
            case '>':
                x_win_y(dat[i].x, dat[i].y);
                break;
            case '=':
                x_equal_y(dat[i].x, dat[i].y);
                break;
            default:
                printf("NEVER HERE!");
                break;
        }
        if (!check(dat[i].x) || !check(dat[i].y)) { // 如果有问题，那么这个必不可能为裁判，并且问题出现最晚的一行即为答案
            jud_line = max(jud_line, i);
            return ;
        }
    }
    jud_num++;
    jud = p - 1;
}
int main() {
    while (scanf("%d%d", &N, &M) != EOF) {
        jud_num = 0;
        jud_line = 0;
        for (int i = 1; i <= M; i++) {
            scanf("%d", &dat[i].x);
            dat[i].opt = getchar();
            scanf("%d", &dat[i].y);
            dat[i].x++;
            dat[i].y++;
        }
        for (int i = 1; i <= N; i++)
            deal(i);
        switch (jud_num) {
            case 0:
                printf("Impossible\n");
                break;
            case 1:
                printf("Player %d can be determined to be the judge after %d lines\n", jud, jud_line);
                break;
            default:
                printf("Can not determine\n");
                break;
        }
    }
    return 0;
}