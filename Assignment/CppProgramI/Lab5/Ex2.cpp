#include <iostream>
using namespace std;

int isPerfectNumber(int n) {
	int divSum = 0;
	for(int i = 1; i < n; i++) {
		if(n % i == 0)
			divSum += i;
	}
	if(divSum == n)
		return 1;
	return 0;
}
int main() {
	cout << "Perfect numbers between 1 and 1000:\n";
	for(int i = 1; i <= 1000; i++) {
		if(isPerfectNumber(i)) {
			cout << i << " = 1";
			for(int j = 2; j < i; j++) {
				if(i % j == 0)
					cout << " + " << j;
			}
			cout << endl;
		}
	}
	return 0;
}