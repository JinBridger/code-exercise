#include <iostream>
using namespace std;

int main(){
    int count = 0;
    cout << "Side1\tSide2\tSide3" << endl;
    for(int side1 = 1; side1 <= 500; side1 ++) {
        for(int side2 = side1; side2 <= 500; side2 ++) {
            for(int side3 = side2; side3 <= 500; side3 ++) {
                if(side1 * side1 + side2 * side2 == side3 * side3) {
                    cout << side3 << "\t" << side2 << "\t" << side3 << endl;
                    count ++;
                }
            }
        }
    }
    cout << "A total of " << count << " triples were found." << endl;
    return 0;
}