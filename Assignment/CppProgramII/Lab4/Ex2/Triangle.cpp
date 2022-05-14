#include <cmath>
#include "Triangle.h"

Triangle::Triangle(const std::string &n, const double &d1, const double &d2, const double &d3) :
    TwoDimensionalShape(n), side1(d1), side2(d2), side3(d3) {

}

double Triangle::getArea() const {
    double s = (side1 + side2 + side3) / 2;
    double ret = sqrt(s * (s - side1) * (s - side2) * (s - side3));

    return ret;
}