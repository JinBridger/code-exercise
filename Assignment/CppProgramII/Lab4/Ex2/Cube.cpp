#include "Cube.h"

Cube::Cube(const std::string &n, const double &s) : ThreeDimensionalShape(n), side(s) {

}

double Cube::getVolume() const {
    return side * side * side;
}

double Cube::getArea() const {
    return 6 * side * side;
}