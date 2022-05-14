#pragma once

#include "TwoDimensionalShape.h"

class Circle : public TwoDimensionalShape {
public:
    Circle(const std::string &, const double &);
    ~Circle() {}

    double getArea() const override;
private:
    double radius;
};