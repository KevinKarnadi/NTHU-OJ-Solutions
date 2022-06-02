#include <iostream>
#include <string>
#include <cmath>
#include "function.h"
using namespace std;

oj::Triangle::Triangle(double edge1, double edge2, double edge3)
{
    this->edge1 = edge1;
    this->edge2 = edge2;
    this->edge3 = edge3;
    if(edge1 + edge2 <= edge3 || edge2 + edge3 <= edge1 || edge1 + edge3 <= edge2 ||
       edge1 <= 0 || edge2 <= 0 || edge3 <= 0)
    {
        this->setArea(0);
        this->setPerimeter(0);
        return;
    }

    double area, s;
    s = (edge1 + edge2 + edge3) / 2;
    area = sqrt(s * (s-edge1) * (s-edge2) * (s-edge3));
    this->setArea(area);

    double perimeter;
    perimeter = edge1 + edge2 + edge3;
    this->setPerimeter(perimeter);
}

oj::Rectangle::Rectangle(double width, double height)
{
    this->width = width;
    this->height = height;
    if(width <= 0 || height <= 0)
    {
        this->setArea(0);
        this->setPerimeter(0);
        return;
    }

    double area;
    area = width * height;
    this->setArea(area);

    double perimeter;
    perimeter = (width + height) * 2;
    this->setPerimeter(perimeter);
}

oj::Circle::Circle(double radius, double pi)
{
    this->radius = radius;
    this->pi = pi;
    if(radius <= 0 || pi <= 0)
    {
        this->setArea(0);
        this->setPerimeter(0);
        return;
    }

    double area;
    area = pi * pow(radius, 2);
    this->setArea(area);

    double perimeter;
    perimeter = 2 * pi * radius;
    this->setPerimeter(perimeter);
}
