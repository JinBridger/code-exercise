#pragma once

#include "TwoDimensionalShape.h"

class Square : public TwoDimensionalShape {
public:
    Square(const std::string &, const double &);
    ~Square() {}

    double getArea() const override;
private:
    double side;
};