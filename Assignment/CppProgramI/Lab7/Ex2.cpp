#include <cstdlib>
#include <iostream>
#include <string>
#include <ctime>
using namespace std;

int main() {
    srand(time(0));

    int sum[20], count;
    string prob[20] = {"", "", "2.778%", "5.556%", "8.333%", "11.111%",
                       "13.889%", "16.667%", "13.889%", "11.111%",
                       "8.333%", "5.556%", "2.778%"};
    
    for(int i = 2; i <= 12; ++ i)
        sum[i] = 0;
    cout << "Please input the times: ";
    cin >> count;
    for(int i = 1; i <= count; ++ i)
        sum[(rand() % 6 + 1) + (rand() % 6 + 1)] ++;
    
    cout << "Sum\tTotal\tExpect\tActual" << endl;
    for(int i = 2; i <= 12; ++ i) {
        cout << i << "\t" << sum[i] << "\t" << prob[i] << "\t" << ((double)sum[i]) / count * 100 << "%" << endl;
    }
    return 0;
}