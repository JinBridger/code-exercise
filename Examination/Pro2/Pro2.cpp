#include <iostream>
using namespace std;

int countInversion(int arr[], int arrLen) {
    int ans = 0;
    
    for(int i = 1; i < arrLen; ++i)
        for(int j = i; j <= arrLen; ++j)
            if(arr[j] < arr[i])
                ans ++;
    return ans;
}
int main(){
    int arrayDat[100][100];
    int rowNum, colNum;
    cout << "Please input the number of rows: ";
    cin >> rowNum;
    cout << "Please input the number of columns: ";
    cin >> colNum;
    cout << "Please input the array: " << endl;
    
    for(int i = 0; i < rowNum; ++i)
        for(int j = 1; j <= colNum; ++j)
            cin >> arrayDat[i][j];
    
    for(int i = 0; i < rowNum; ++i)
        cout << "The inversion number in row-" << i << " is " << countInversion(arrayDat[i], colNum) << "." << endl;
    return 0;
}