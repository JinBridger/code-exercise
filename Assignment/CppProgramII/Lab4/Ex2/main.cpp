#include <vector>
#include <iostream>
#include <iomanip>
#include "Circle.h"
#include "Square.h"
#include "Triangle.h"
#include "Sphere.h"
#include "Cube.h"

void printAreaOrVolume(Shape *shapePtr) {
    if(TwoDimensionalShape *twd = dynamic_cast<TwoDimensionalShape*>(shapePtr)) {
        std::cout << "Type: 2D\tArea: " << twd->getArea() << std::endl;
    }
    if(ThreeDimensionalShape *thd = dynamic_cast<ThreeDimensionalShape*>(shapePtr)) {
        std::cout << "Type: 3D\tArea: " << thd->getArea()
                  << "\tVolume: " << thd->getVolume() << std::endl;
    }
}

int main() {
    std::cout << std::fixed << std::setprecision(3);
    Shape* vecShape[5];

    vecShape[0] = new Circle("Cir", 1.0);
    vecShape[1] = new Square("Squ", 1.0);
    vecShape[2] = new Triangle("Tri", 1, 1, 1);
    vecShape[3] = new Sphere("Sph", 1);
    vecShape[4] = new Cube("Cub", 1);
    
    
    for(int i = 0; i < 5; ++i)
        printAreaOrVolume(vecShape[i]);
    return 0;
}