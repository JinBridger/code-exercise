#include "Circle.h"

Circle::Circle(const std::string &n, const double &r) : TwoDimensionalShape(n), radius(r) {

}

double Circle::getArea() const {
    return 3.1415926 * radius * radius;
}