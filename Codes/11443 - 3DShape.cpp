#include <iostream>
#include <string>
#include <cmath>
#include "function.h"
using namespace std;

oj::Sphere::Sphere(double r, double p)
{
    radius = r;
    pi = p;
    if(r <= 0 || p <= 0)
    {
        setVolume(0);
        return;
    }
    double vol;
    vol = (4.0 / 3.0) * p * pow(r, 3);
    setVolume(vol);
}

oj::Cone::Cone(double r, double h, double p)
{
    radius = r;
    height = h;
    pi = p;
    if(r <= 0 || h <= 0 || p <= 0)
    {
        setVolume(0);
        return;
    }
    double vol;
    vol = (1.0 / 3.0) * p * pow(r, 2) * h;
    setVolume(vol);
}

oj::Cuboid::Cuboid(double l, double w, double h)
{
    length = l;
    width = w;
    height = h;
    if(l <= 0 || w <= 0 || h <= 0)
    {
        setVolume(0);
        return;
    }
    double vol;
    vol = l * w * h;
    setVolume(vol);
}

oj::Cube::Cube(double r) : oj::Cuboid::Cuboid(r, r, r) {}
