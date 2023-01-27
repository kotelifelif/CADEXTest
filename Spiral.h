#pragma once
#include "Figure.h"

class Spiral : public Figure
{
public:
	Spiral(const double radius, const double slope, const Point center = Point{0, 0, 0});
	virtual Point get_point(const double parameter) override;
	virtual Vector get_first_derivative(const double parameter) override;
	double get_radius();
	double get_slope();
private:
	double radius;
	double slope;
	Point center;
};

