#include <iostream>
using namespace std;

int main() {
	int n; char opt;
	cout << "Please input the length of the side: ";
	cin >> n;
	cout << "Please input the character: ";
	cin >> opt;
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			cout << opt;
		}
		cout << endl;
	}
	return 0;
}