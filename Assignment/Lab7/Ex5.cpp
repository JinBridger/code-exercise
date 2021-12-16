#include <iostream>
using namespace std;

int answer, sheet[10][10]; // 0 -> empty, 1 -> queen

int isPlaceable(int line, int row) {
    for(int i = 1; i <= 8; ++ i) // check current line and row
        if(sheet[line][i] || sheet[i][row])
            return 0;
    for(int i = line, j = row; (1 <= i && i <= 8) && (1 <= j && j <= 8); ++i, ++j) // go rightup
        if(sheet[i][j])
            return 0;
    for(int i = line, j = row; (1 <= i && i <= 8) && (1 <= j && j <= 8); --i, ++j) // go leftup
        if(sheet[i][j])
            return 0;
    for(int i = line, j = row; (1 <= i && i <= 8) && (1 <= j && j <= 8); ++i, --j) // go rightdown
        if(sheet[i][j])
            return 0;
    for(int i = line, j = row; (1 <= i && i <= 8) && (1 <= j && j <= 8); --i, --j) // go leftdown
        if(sheet[i][j])
            return 0;
    return 1;
}
void searchSolution(int line, int row) {
    if(line == 8) {
        answer ++;
        return;
    }
    sheet[line][row] = 1;
    for(int i = 1 ; i <= 8; ++ i) {
        if(isPlaceable(line + 1, i)) {
            searchSolution(line + 1, i);
        }
    }
    sheet[line][row] = 0;
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