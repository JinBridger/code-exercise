#include "Square.h"

Square::Square(const std::string &n, const double &s) : TwoDimensionalShape(n), side(s) {

}

double Square::getArea() const {
    return side * side;
}