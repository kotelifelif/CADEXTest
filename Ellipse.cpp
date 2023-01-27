#include "Ellipse.h"
#include <cmath>

Ellipse::Ellipse(const double major_axis, const double minor_axis, const Point center) :
    major_axis(major_axis), minor_axis(minor_axis), center(center)
{
}

Point Ellipse::get_point(const double parameter)
{
    Point point;
    point.x = major_axis * std::cos(parameter) + center.x;
    point.y = minor_axis * std::sin(parameter) + center.y;
    point.z = center.z;
    return point;
}

Vector Ellipse::get_first_derivative(const double parameter)
{
    Vector vec;
    vec.x = -major_axis * std::sin(parameter);
    vec.y = minor_axis * std::cos(parameter);
    vec.z = 0;
    return vec;
}

double Ellipse::get_major_axis()
{
    return major_axis;
}

double Ellipse::get_minor_axis()
{
    return minor_axis;
}
