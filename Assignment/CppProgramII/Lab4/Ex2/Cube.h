#pragma once

#include "ThreeDimensionalShape.h"

class Cube : public ThreeDimensionalShape {
public:
    Cube(const std::string &, const double &);
    ~Cube() {}

    double getVolume() const override;
    double getArea() const override;
private:
    double side;
};