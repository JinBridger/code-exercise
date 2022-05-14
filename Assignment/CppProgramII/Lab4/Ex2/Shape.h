#pragma once

#include <string>

class Shape {
public:
    Shape(const std::string &);
    virtual ~Shape() {}

    std::string getName() const;
    void setName(const std::string &);
private:
    std::string name;
};