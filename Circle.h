#pragma once
#include "Figure.h"

class Circle : public Figure
{
public:
	Circle(const double radius, const Point center = Point{ 0, 0, 0 });
	virtual Point get_point(const double parameter) override;
	virtual Vector get_first_derivative(const double parameter) override;
	double get_radius();
private:
	double radius;
	Point center;
};

