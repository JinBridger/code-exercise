#include <iostream>
#include <cstdio>
using namespace std;

void toCapital(char *s) {
    for(int i = 0; s[i] != '\0'; ++i)
        if(s[i] <= 'z' && s[i] >= 'a')
            s[i] -= 'a' - 'A';
    return;
}
int main(){
    cout << "Please input two strings: " << endl;
    char s1[100], s2[100];
    gets(s1);
    gets(s2);
    toCapital(s1);
    toCapital(s2);
    char *ptr1 = s1, *ptr2 = s2;
    while(*ptr1 != '\0')
        ptr1++;
    ptr1--;
    *ptr1++ = ',';
    *ptr1++ = ' ';
    while (*ptr2 != '\0') {
      *ptr1 = *ptr2;
      ptr2 ++;
      ptr1 ++;  
    }
    *ptr1 = *ptr2;
    cout << "Output: " << endl;
    cout << s1;
    return 0;
}