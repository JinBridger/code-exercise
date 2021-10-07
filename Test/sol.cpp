#include <cstdio>
#include <string.h>
#include <iostream>
#define MAXN 510
using namespace std;

int ranker[MAXN],
    pre[MAXN];  //***rank数组存储当前节点与父亲节点的关系!注意不是与根节点的关系!!!

int find(int x) {  //**递归路径压缩
    if (pre[x] != x) {
        int px = find(pre[x]);
        ranker[x] = (ranker[x] + ranker[pre[x]]) %
                  3;  //***回溯时改变rank[x]的值,这个公式我们可以由枚举得出
        pre[x] = px;  //***将 x 的父亲节点变为根节点,即 x 节点直接指向根节点
    }
    return pre[x];
}

int jion(int x, int y, int d) {
    int px = find(x);
    int py = find(y);
    if (px ==
        py) {  //***若 x, y 都已经加入并查集,即相对关系已经确定,递归压缩路径后
               //x, y 的根节点即为他们的父节点, 我们可以由rank得到 x,
               //y的关系,因为我们加入并查集的 x,
               //y的关系都是真确的,所以如果d值与我们由rank得到的关系不同,那么其为假话
        if ((ranker[y] - ranker[x] + 3) % 3 !=
            d) {  //***x, y的关系我们可以由枚举得出
            return 1;
        }
    } else {
        pre[py] = px;
        ranker[py] =
            (ranker[x] - ranker[y] + d + 3) %
            3;  //***得到合并后px与py的关系,此处的公式也是可以通过枚举得出的
    }
    return 0;
}

int main() {
    freopen("D:\\Code_exercise\\Test\\Data\\data.in", "r", stdin);
    int n, m;
    while (~scanf("%d%d", &n, &m)) {
        int x[MAXN * 4], y[MAXN * 4], d;
        char ch[MAXN * 4];
        for (int i = 1; i <= m; i++) {
            scanf("%d%c%d", &x[i], &ch[i], &y[i]);
        }
        int tot = 0, flag = 1, gg = 0, jj = 0;  //***tot统计裁判个数
        for (int i = 0; i < n; i++) {  //***枚举，假设i为裁判，若无矛盾即可行
            flag = 1;
            for (int j = 0; j < n; j++) {  //**初始化
                ranker[j] = 0;
                pre[j] = j;
            }
            for (int j = 1; j <= m; j++) {  //**建立关系并查集
                if (x[j] == i ||
                    y[j] == i) {  //***裁判可以任意出手势，把裁判放在并查集外面
                    continue;
                }
                if (ch[j] == '=') {
                    d = 0;
                } else if (ch[j] == '>') {
                    d = 1;
                } else {
                    d = 2;
                }
                if (jion(x[j], y[j], d)) {  //**判断是否有矛盾
                    gg = max(j, gg);        //**维护出现矛盾最大行数
                    flag = 0;
                    break;
                }
            }
            if (flag) {  //**没出现矛盾，即当前节点可以是裁判
                tot++;
                jj = i;  //**记录裁判节点号
            }
        }
        if (!tot) {
            printf("Impossible\n");
        } else if (tot > 1) {
            printf("Can not determine\n");
        } else {
            printf(
                "Player %d can be determined to be the judge after %d lines\n",
                jj, gg);
        }
    }
    return 0;
}