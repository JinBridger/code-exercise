#include <iostream>
using namespace std;

int gcd(int a, int b) {
	if(a == 0) return b;
	else return gcd(b%a, a);
}
int main() {
	cout << "Please input two intergers: ";
	int n, m;
	cin >> n >> m;
	if(n > m) swap(n,m);
	cout << "The gcd of the two intergers is: " << gcd(n,m);
	return 0;
}