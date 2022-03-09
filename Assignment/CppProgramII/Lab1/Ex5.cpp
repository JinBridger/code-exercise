/*
 * @Author: JinBridge
 * @Date: 2022-03-09 15:44:43
 * @LastEditors: JinBridge
 * @LastEditTime: 2022-03-09 16:16:19
 * Copyright (c) 2022 by JinBridge, All Rights Reserved. 
 */
#include <iostream>

class integerSet {
   public:
    integerSet(int* a, int aSize) {
        for(int i = 0; i < aSize; ++i)
            isExist[a[i]] = 1;
    }
    integerSet() {
        int tempNum;
        while(true) {
            std::cout << "Enter an element (-1 to end): ";
            std::cin >> tempNum;
            if(tempNum == -1) {
                std::cout << "Entry complete" << std::endl;
                break;
            }
            isExist[tempNum] = 1;
        }
    }

    integerSet unionOfSets(integerSet s) {
        for(int i = 0; i <= 100; ++i)
            if(isExist[i])
                s.isExist[i] = 1;
        return s;
    }
    integerSet intersectionOfSets(integerSet s) {
        for(int i = 0; i <= 100; ++i)
            if((!isExist[i]) || (!s.isExist[i]))
                s.isExist[i] = 0;
        return s;
    }
    
    integerSet& insertElements(int i) {
        isExist[i] = 1;
        return *this;
    }
    integerSet& deleteElements(int i) {
        isExist[i] = 0;
        return *this;
    }
    
    void printSet() {
        bool isEmpty = 1;
        std::cout << "{\t";
        for(int i = 0; i <= 100; ++i) {
            if(isExist[i]) {
                isEmpty = 0;
                std::cout << i << "\t";
            }
        }
        if(isEmpty)
            std::cout << "---\t";
        std::cout << "}" << std::endl;
    }

    bool isEqualTo(const integerSet& s) {
        for(int i = 0; i <= 100; ++i)
            if(isExist[i] != s.isExist[i])
                return false;
        return true;
    }
   private:
    bool isExist[101] = {0};
};
int main() {
    std::cout << "Enter set A:" << std::endl;
    integerSet A = integerSet();
    std::cout << std::endl;

    integerSet B = integerSet();
    std::cout << std::endl;

    std::cout << "Union of A and B is: " << std::endl;
    A.unionOfSets(B).printSet();
    std::cout << "Intersection of A and B is: " << std::endl;
    A.intersectionOfSets(B).printSet();
    if(!A.isEqualTo(B))
        std::cout << "Set A is not equal to set B" << std::endl;
    
    std::cout << std::endl;
    std::cout << "Inserting 77 into set A...\nSet A is now:" << std::endl;
    A.insertElements(77).printSet();

    std::cout << "Deleting 77 from set A...\nSet A is now:" << std::endl;
    A.deleteElements(77).printSet();
    
    return 0;
}