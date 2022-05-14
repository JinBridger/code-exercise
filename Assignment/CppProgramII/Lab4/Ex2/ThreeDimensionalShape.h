#pragma once

#include "Shape.h"

class ThreeDimensionalShape : public Shape {
public:
    ThreeDimensionalShape(const std::string &);
    virtual ~ThreeDimensionalShape() {}

    virtual double getVolume() const = 0;
    virtual double getArea() const = 0;    
private:
};