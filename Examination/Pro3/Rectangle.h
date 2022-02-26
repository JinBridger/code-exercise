// Rectagle.h
#include <iostream>

class Rectangle {
public:
    // Constructor
    Rectangle(int, int);
    Rectangle() {};

    // Set functions
    void setWidth(int);
    void setLength(int);

    // Get functions
    int getWidth();
    int getLength();

    int area();
    void print();
private:
    int width, length;
};

using namespace std;

Rectangle::Rectangle(int newWidth, int newLength):
    width(newWidth), length(newLength)
{

}
void Rectangle::setWidth(int newWidth) {
    width = newWidth;
}
void Rectangle::setLength(int newLength) {
    length = newLength;
}
int Rectangle::getWidth() {
    return width;
}
int Rectangle::getLength() {
    return length;
}
int Rectangle::area() {
    return length * width;
}
void Rectangle::print() {
    cout << length << ", " << width << ", " << area();
}