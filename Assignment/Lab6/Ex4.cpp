#include <iostream>
#include <string>
using namespace std;

template <typename T> 
int TwoSmallest(T a, T b, T c, T &s1, T &s2) {
	if (a > b) swap(a, b);
	if (b > c) swap(b, c);
	if (a > b) swap(a, b);
	s1 = a;
	s2 = b;
	if(s1 == s2) return 1;
	else return 0;
}
template <typename T> 
void ShowTwoSmallest(int smallestnum, T s1, T s2) {
	cout << "The smallest number: " << s1 << endl;
	if(!smallestnum)
		cout << "The second smallest number: " << s2 << endl;
	cout << endl << endl;
}
void deal() {
	cout << "***********************" << endl;
	cout << "     1.  int" << endl;
	cout << "     2.  double" << endl;
	cout << "     3.  char" << endl;
	cout << "     4.  string" << endl;
	cout << "     0.  exit" << endl;
	cout << "***********************" << endl;
	cout << "Input choices: " ;
	int mode;
	cin >> mode;
	if(!mode) exit(0);
	if(mode == 1) {
		int a, b, c, s1, s2;
		cout << "Int1: ";  cin >> a;
		cout << "Int2: ";  cin >> b;
		cout << "Int3: ";  cin >> c;
		TwoSmallest(a, b, c, s1, s2);
		ShowTwoSmallest(TwoSmallest(a, b, c, s1, s2), s1, s2);
	}
	if(mode == 2) {
		double a, b, c, s1, s2;
		cout << "Double1: ";  cin >> a;
		cout << "Double2: ";  cin >> b;
		cout << "Double3: ";  cin >> c;
		TwoSmallest(a, b, c, s1, s2);
		ShowTwoSmallest(TwoSmallest(a, b, c, s1, s2), s1, s2);
	}
	if(mode == 3) {
		char a, b, c, s1, s2;
		cout << "Char1: ";  cin >> a;
		cout << "Char2: ";  cin >> b;
		cout << "Char3: ";  cin >> c;
		TwoSmallest(a, b, c, s1, s2);
		ShowTwoSmallest(TwoSmallest(a, b, c, s1, s2), s1, s2);
	}
	if(mode == 4) {
		string a, b, c, s1, s2;
		cout << "String1: ";  cin >> a;
		cout << "String2: ";  cin >> b;
		cout << "String3: ";  cin >> c;
		TwoSmallest(a, b, c, s1, s2);
		ShowTwoSmallest(TwoSmallest(a, b, c, s1, s2), s1, s2);
	}
	
}
int main() {
	while(1)
		deal();
	return 0;
}