#pragma once
#include "Figure.h"

class Ellipse : public Figure
{
public:
	Ellipse(const double major_axis, const double minor_axis, const Point center = Point{ 0, 0, 0 });
	virtual Point get_point(const double parameter) override;
	virtual Vector get_first_derivative(const double parameter) override;
	double get_major_axis();
	double get_minor_axis();
private:
	double major_axis;
	double minor_axis;
	Point center;
};

