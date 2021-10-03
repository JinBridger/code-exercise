#include <cstdio>
#include <ctime>
#include <cstdlib>
using namespace std;

int main() {
    freopen("D:\\Code_exercise\\Test\\Data\\data.in", "w", stdout);
    srand((int)time(0));
    for(int i = 1; i <= 4; i++) {
        for(int j = 1; j <= 4; j++) {
            printf("%c",(rand() % 2)?'b':'w');
        }
        printf("\n");
    }
    return 0;
}