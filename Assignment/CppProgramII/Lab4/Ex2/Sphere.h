#pragma once

#include "ThreeDimensionalShape.h"

class Sphere : public ThreeDimensionalShape {
public:
    Sphere(const std::string &, const double &);
    ~Sphere() {}

    double getVolume() const override;
    double getArea() const override;
private:
    double radius;
};