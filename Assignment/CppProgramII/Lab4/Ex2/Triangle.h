#pragma once

#include "TwoDimensionalShape.h"

class Triangle : public TwoDimensionalShape {
public:
    Triangle(const std::string &, const double &, const double &, const double &);
    ~Triangle() {}

    double getArea() const override;
private:
    double side1, side2, side3;
};