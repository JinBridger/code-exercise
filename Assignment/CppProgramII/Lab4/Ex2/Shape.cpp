#include "Shape.h"

Shape::Shape(const std::string &n) : name(n) {

}

std::string Shape::getName() const {
    return name;
}

void Shape::setName(const std::string &n) {
    name = n;
}