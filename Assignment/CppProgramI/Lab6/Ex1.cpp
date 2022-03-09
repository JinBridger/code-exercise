#include <iostream>
using namespace std;

int pow(int base, int exponent) {
	if(exponent == 1) return base;
	else return base*pow(base, exponent - 1);
}
int main() {
	int n, m;
	cout << "Enter a base and an exponent: ";
	cin >> n >> m;
	cout << n << " rasied to the " << m << " is " << pow(n,m);
	return 0;
}