/*
 * @Author: JinBridge
 * @Date: 2022-04-06 19:53:06
 * @LastEditors: JinBridge
 * @LastEditTime: 2022-04-15 20:34:46
 * Copyright (c) 2022 by JinBridge, All Rights Reserved.
 */
#include <iostream>

class String {
    friend std::ostream& operator<<(std::ostream&, const String&);
    friend String operator+(const String&, const String&);

   public:
    String(const char* const s = "") {
        for (length = 0; s[length] != '\0'; ++length)
            ;
        sPtr = new char[length + 1];
        for (int i = 0; i <= length; ++i)
            sPtr[i] = s[i];
    }
    String(const String& s) {
        length = s.length;
        sPtr = new char[s.length + 1];
        for (int i = 0; i <= length; ++i)
            sPtr[i] = s.sPtr[i];
    }
    ~String() { delete[] sPtr; }

    const String& operator=(const String& s) {
        length = s.length;
        delete[] sPtr;
        sPtr = new char[s.length + 1];
        for (int i = 0; i <= length; ++i)
            sPtr[i] = s.sPtr[i];
        return *this;
    }

   private:
    char* sPtr;
    int length;
};
std::ostream& operator<<(std::ostream& os, const String& s) {
    char* c = s.sPtr;
    while (*c != '\0') {
        os << *c;
        ++c;
    }
    return os;
}
String operator+(const String& a, const String& b) {
    char* resStr = new char[a.length + b.length + 1];
    int i = 0;
    for (int j = 0; j < a.length; ++j, ++i)
        resStr[i] = a.sPtr[j];
    for (int j = 0; j < b.length; ++j, ++i)
        resStr[i] = b.sPtr[j];
    resStr[a.length + b.length] = '\0';
    String res = String(resStr);
    delete[] resStr;
    return res;
}

int main() {
    String string1, string2("The date is");
    String string3(" August 1, 1993");
    // test overloaded operators
    std::cout << "string1 = string2 + string3\n";
    string1 = string2 + string3;  // tests overloaded = and + operator
    std::cout << "\"" << string1 << "\" = \"" << string2 << "\" + \"" << string3
         << "\"" << std::endl;
    return 0;

    return 0;
}