#include "Sphere.h"

Sphere::Sphere(const std::string &n, const double &r) : ThreeDimensionalShape(n), radius(r) {

}

double Sphere::getVolume() const {
    return 3.1415926 * 4 / 3 * radius * radius;
}

double Sphere::getArea() const {
    return 3.1415926 * 4 * radius * radius;
}