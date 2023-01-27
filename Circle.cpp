#include "Circle.h"
#include <cmath>

Circle::Circle(const double radius, const Point center) : 
    radius(radius), center(center)
{
}

Point Circle::get_point(const double parameter)
{
    Point point;
    point.x = radius * std::cos(parameter) + center.x;
    point.y = radius * std::cos(parameter) + center.y;
    point.z = center.z;
    return point;
}

Vector Circle::get_first_derivative(const double parameter)
{
    Vector vec;
    vec.x = -radius * std::sin(parameter);
    vec.y =  radius * std::cos(parameter);
    vec.z = 0;
    return vec;
}

double Circle::get_radius()
{
    return radius;
}
