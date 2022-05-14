#pragma once

#include "Shape.h"

class TwoDimensionalShape : public Shape {
public:
    TwoDimensionalShape(const std::string &);
    virtual ~TwoDimensionalShape() {}

    virtual double getArea() const = 0;    
private:
};