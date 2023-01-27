#pragma once

struct Point {
	double x;
	double y;
	double z;
};

struct Vector {
	double x;
	double y;
	double z;
};

class Figure
{
public:
	virtual Point get_point(const double parameter) = 0;
	virtual Vector get_first_derivative(const double parameter) = 0;
};

