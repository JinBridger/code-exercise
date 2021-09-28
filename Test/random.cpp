#include <cstdio>
#include <ctime>
#include <cstdlib>
using namespace std;

int main() {
    freopen("D:\\Code_exercise\\Test\\Data\\data.in", "w", stdout);
    srand((int)time(0));
    int n = rand() % 4 + 1;
    printf("%d\n", n);
    for(int i = 1; i <= n; i++) {
        int x1 = rand() % 5;
        int y1 = rand() % 5;
        int x2 = rand() % 5 + 1 + x1;
        int y2 = rand() % 5 + 1 + y2;
        printf("%d %d %d %d\n",x1,y1,x2,y2);
    }
    return 0;
}