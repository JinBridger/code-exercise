#include <iostream>
using namespace std;

int answer, sheet[10][10]; // 0 代表空, 1 代表放置皇后

int isPlaceable(int line, int row) { // 检查能否放置皇后，返回1代表可以，0代表不可以
    for(int i = 1; i <= 8; ++ i) // 检查当前行与列有无皇后
        if(sheet[line][i] || sheet[i][row])
            return 0;
    for(int i = line, j = row; (1 <= i && i <= 8) && (1 <= j && j <= 8); ++i, ++j) // 检查右上对角线
        if(sheet[i][j])
            return 0;
    for(int i = line, j = row; (1 <= i && i <= 8) && (1 <= j && j <= 8); --i, ++j) // 检查左上对角线
        if(sheet[i][j])
            return 0;
    for(int i = line, j = row; (1 <= i && i <= 8) && (1 <= j && j <= 8); ++i, --j) // 检查右下对角线
        if(sheet[i][j])
            return 0;
    for(int i = line, j = row; (1 <= i && i <= 8) && (1 <= j && j <= 8); --i, --j) // 检查左下对角线
        if(sheet[i][j])
            return 0;
    return 1;
}
void searchSolution(int line, int row) { // 从第一行开始搜索，每一行只能放一个皇后
    if(line == 8) { // 如果当前已是最后一行，则该方案可行
        answer ++;
        return;
    }
    sheet[line][row] = 1; // 在当前位置放置皇后
    for(int i = 1 ; i <= 8; ++ i) {
        if(isPlaceable(line + 1, i)) { // 查找下一行有无可以放置皇后的地方，如果这个位置可以放置皇后
            searchSolution(line + 1, i); // 尝试在这里放
        }
    }
    sheet[line][row] = 0; // 收回放置的皇后
    return ;
}
int main() {
    for(int i = 1; i <= 8; ++ i)
        for(int j = 1; j <= 8; ++j)
            sheet[i][j] = 0;
    for(int i = 1; i <= 8; ++ i) 
        searchSolution(1, i);
    cout << "There is " << answer << " Solutions.";
    return 0;
}