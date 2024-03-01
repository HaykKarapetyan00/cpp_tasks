#ifndef SHAPE_H
#define SHAPE_H

#include <QObject>

class Shape {
public:
    virtual double calculateArea() const = 0;
};

class Circle : public Shape {
private:
    double radius;

public:
    Circle(double r) : radius(r) {if(r < 0){throw std::invalid_argument("must be positive: ");}}

    double calculateArea() const override {
        return 3.14 * radius * radius;
    }
};

class Rectangle : public Shape {
private:
    double length;
    double width;

public:
    Rectangle(double l, double w) : length(l), width(w) {if(l < 0 || w < 0){throw std::invalid_argument("length and width should be positive: ");}}

    double calculateArea() const override {
        return length * width;
    }
};

#endif // SHAPE_H
