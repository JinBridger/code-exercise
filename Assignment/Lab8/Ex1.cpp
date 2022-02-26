// ------- Below is Ex1.2 --------
void swap(int a, int b) {  // declare a local identifier temp
    int temp = a;
    a = b;
    b = temp;
}
void swap(int a, int b) {  // declare a local identifier temp*
    int *temp = &a;
    // 这函数没法写
}
void swap(int *a, int *b) {  // declare a local identifier temp
    int temp = *a;
    *a = *b;
    *b = temp;
}
void swap(int *a, int *b) {  // declare a local identifier temp*
    int *temp = a;
    a = b;
    b = temp;
}
void swap(int &a, int &b) {  // declare a local identifier temp
    int temp = a;
    a = b;
    b = temp;
}


// ------- Below is Ex1.3 --------
int getsum(int a, int b) {  // declare a local identifier temp, return temp
    int temp = a + b;
    return temp;
}
int* swap(int a, int b) {  // declare a local identifier temp, return the address of temp
    int temp = a;
    a = b;
    b = temp;
    int *ptr = &temp;
    return ptr;
}
void swap(int a, int b) {  // declare a local identifier temp*, return temp
    // 这函数也没法写
} 
void swap(int a, int b) {  // declare a local identifier temp*, return the content of temp
    // 这函数也没法写，真的
}
void swap(int a, int b) {  // declare a local identifier temp&, return temp
    // 这函数也是没法写，不信你试试
}