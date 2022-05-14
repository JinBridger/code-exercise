/*
 * @Date: 2022-04-29 16:48:37
 * @LastEditors: JinBridge
 * @LastEditTime: 2022-04-29 18:04:34
 * @FilePath: \Code_exercise\Assignment\CppProgramII\Lab3\Ex6.cpp
 */
#include <iostream>
#include <string>

class Shape {
public:
    Shape(std::string name = "Untitled Shape") : id(name) {}
    ~Shape() {}

    virtual std::string getID() { return id; }
    virtual double area() = 0;
    virtual void print() = 0;

protected:
    std::string id;
};
class Rectangle : public Shape {
public:
    Rectangle(double lTopX, double lTopY, double rBtmX, double rBtmY,
        std::string name = "Untitled Rectangle")
        : Shape(name),
        ltTopX(lTopX),
        ltTopY(lTopY),
        rtBtmX(rBtmX),
        rtBtmY(rBtmY) {}
    ~Rectangle() {}

    double area() override {
        return (rtBtmX - ltTopX) * (ltTopY - rtBtmY);
    }
    void print() override {
        std::cout << std::endl;
        std::cout << "Name:\t" << getID() << std::endl;
        std::cout << "Width:\t" << (rtBtmX - ltTopX) << std::endl;
        std::cout << "Height:\t" << (ltTopY - rtBtmY) << std::endl;
        std::cout << "Area:\t" << area() << std::endl;
        std::cout << std::endl;
    }
protected:
    double ltTopX;
    double ltTopY;
    double rtBtmX;
    double rtBtmY;
};
class Circle : public Shape {
public:
    Circle(double r, double cX, double cY,
        std::string name = "Untitled Circle")
        : Shape(name),
        radius(r),
        centerX(cX),
        centerY(cY) {}
    ~Circle() {}

    double area() override {
        return radius * radius * 3.1415926;
    }
    void print() override {
        std::cout << std::endl;
        std::cout << "Name:\t" << getID() << std::endl;
        std::cout << "Radius:\t" << radius << std::endl;
        std::cout << "Center:\t" << "(" << centerX << ", " << centerY << ")" << std::endl;
        std::cout << "Area:\t" << area() << std::endl;
        std::cout << std::endl;
    }
private:
    double radius;
    double centerX;
    double centerY;

};
class Triangle : public Shape {
public:
    Triangle(double p1X, double p1Y,
        double p2X, double p2Y,
        double p3X, double p3Y,
        std::string name = "Untitled Triangle")
        : Shape(name), pt1X(p1X), pt1Y(p1Y),
        pt2X(p2X), pt2Y(p2Y),
        pt3X(p3X), pt3Y(p3Y) {}
    ~Triangle() {}

    double area() override {
        double vec1X = pt2X - pt1X;
        double vec1Y = pt2Y - pt1Y;
        double vec2X = pt3X - pt1X;
        double vec2Y = pt3Y - pt1Y;
        // Using vector to calc area
        return 0.5 * abs(vec1X * vec2Y - vec2X * vec1Y);
    }
    void print() override {
        std::cout << std::endl;
        std::cout << "Name:\t" << getID() << std::endl;
        std::cout << "Point 1:\t" << "(" << pt1X << ", " << pt1Y << ")" << std::endl;
        std::cout << "Point 2:\t" << "(" << pt2X << ", " << pt2Y << ")" << std::endl;
        std::cout << "Point 3:\t" << "(" << pt3X << ", " << pt3Y << ")" << std::endl;
        std::cout << "Area:\t" << area() << std::endl;
        std::cout << std::endl;
    }
private:
    double pt1X, pt1Y;
    double pt2X, pt2Y;
    double pt3X, pt3Y;
};
class Square : public Rectangle {
public:
    Square(double lTopX, double lTopY, double rBtmX, double rBtmY,
        std::string name = "Untitled Square")
        : Rectangle(lTopX, lTopY, rBtmX, rBtmY, name),
        sideLength(rBtmX - lTopX) {}
    Square(double lTopX, double lTopY, double sideLen, std::string name = "Untitled Square")
        : Rectangle(lTopX, lTopY, lTopX + sideLen, lTopY - sideLen, name),
        sideLength(sideLen) {}

    ~Square() {}

    Circle incircle() {
        return Circle(sideLength / 2, ltTopX + sideLength / 2, ltTopY - sideLength / 2, "Incircle of " + getID());
    }
    double area() override {
        return sideLength * sideLength;
    }
    void print() override {
        std::cout << std::endl;
        std::cout << "Name:\t" << getID() << std::endl;
        std::cout << "Side:\t" << sideLength << std::endl;
        std::cout << "Area:\t" << area() << std::endl;
        std::cout << std::endl;
    }
private:
    double sideLength;

};
int main() {

    Rectangle rec(2, 3, 4, 1);
    Square sqr(1, 2, 3);
    Circle cir(1, 1, 1);
    Triangle tri(1, 1, 2, 2, 1, 2);

    rec.print();
    sqr.print();
    cir.print();
    tri.print();

    return 0;
}
