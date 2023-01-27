#include "Spiral.h"
#include <cmath>

Spiral::Spiral(const double radius, const double slope, const Point center) : 
    radius(radius), slope(slope), center(center)
{
}

Point Spiral::get_point(const double parameter)
{
    Point point;
    point.x = radius * std::cos(parameter) + center.x;
    point.y = radius * std::sin(parameter) + center.y;
    point.z = slope * parameter + center.z;
    return point;
}

Vector Spiral::get_first_derivative(const double parameter)
{
    Vector vec;
    vec.x = -radius * std::sin(parameter);
    vec.y = radius * std::cos(parameter);
    vec.z = slope;
    return vec;
}

double Spiral::get_radius()
{
    return radius;
}

double Spiral::get_slope()
{
    return slope;
}
