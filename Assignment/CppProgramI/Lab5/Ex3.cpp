#include <iostream>
using namespace std;

int isPrime(int n) {
	for(int i = 2; i < n; i++)
		if(n % i == 0)
			return 0;
	return 1;
}
int main() {
	int cnt = 0;
	cout << "The prime numbers from 1 to 10000 are:\n";
	for(int i = 2; i <= 10000; i++) {
		if(isPrime(i)) {
			cnt++;
			cout << i;
			(cnt % 10 == 0)?cout << "\n":cout <<"\t";
		}
	}
	cout << endl;
	cout << "Total of " << cnt << " prime numbers between 1 and 10000";
	return 0;
}