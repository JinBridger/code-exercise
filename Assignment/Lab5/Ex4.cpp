#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int flip() {
	return rand() % 2;
}
int main() {
	srand(time(0));
	int n, head = 0, tail = 0;
	cout << "Please input tosses of the coin: ";
	cin >> n;
	for(int i = 1; i <= n; i++) {
		if(flip()) head ++;
		else tail ++;
	}
	cout << "Head: " << head << "\t" << (double)(head)/n * 100 << "%" << endl;
	cout << "Tail: " << tail << "\t" << (double)(tail)/n * 100 << "%" << endl;
	return 0;
}