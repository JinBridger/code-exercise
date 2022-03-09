#include <iostream>
using namespace std;

int main(){
    int mat[3][5];
    cout << "Please input the matrix's data: " << endl;
    for(int i = 0; i <= 2; ++i)
        for(int j = 0; j <= 4; ++j)
            cin >> mat[i][j];
    cout << "The transposed matrix is: " << endl;
    for(int i = 0; i <= 4; ++i) {
        for(int j = 0; j <= 2; ++j) {
            cout << *(mat[j] + i) << " ";
        }
        cout << endl;
    }
    return 0;
}