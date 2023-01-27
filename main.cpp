#include "Figure.h"
#include "Circle.h"
#include "Ellipse.h"
#include "Spiral.h"

#include <iostream>
#include <vector>
#include <random>
#include <algorithm>

using namespace std;

vector<Figure*> generate_figures(const size_t figures_number) {
	vector<Figure*> figures;
	figures.reserve(figures_number);

	Figure* figure;

	random_device device;
	mt19937 generator(device());
	uniform_int_distribution<mt19937::result_type> distribution(1, 3);
	uniform_int_distribution<mt19937::result_type> distribution_radius(1, 100);

	size_t number = 0;
	size_t radius = 0;
	size_t major_axis = 0;
	size_t minor_axis = 0;
	size_t slope = 0;
	for (size_t i = 0; i < figures_number; ++i) {
		number = distribution(generator);
		switch (number) {
		case 1:
			radius = distribution_radius(generator);
			figure = new Circle(radius);
			figures.push_back(figure);
			break;
		case 2:
			major_axis = distribution_radius(generator);
			minor_axis = distribution_radius(generator);
			figure = new Ellipse(major_axis, minor_axis);
			figures.push_back(figure);
			break;
		case 3:
			radius = distribution_radius(generator);
			slope = distribution_radius(generator);
			figure = new Spiral(radius, slope);
			figures.push_back(figure);
			break;
		}
	}

	return figures;
}

void print_figures(const vector<Figure*>& figures, const double parameter) {
	Point point;
	for (size_t i = 0; i < figures.size(); ++i) {
		point = figures[i]->get_point(parameter);
		cout << "Point: x =  " << point.x << " y = " << point.y << " z = " << point.z << endl;
	}
}

vector<Circle*> generate_circles(const vector<Figure*>& figures) {
	vector<Circle*> circles;
	for (size_t i = 0; i < figures.size(); ++i) {
		if (dynamic_cast<Circle*>(figures[i]) != nullptr) {
			circles.push_back(dynamic_cast<Circle*>(figures[i]));
		}
	}
	return circles;
}

double count_sum(vector<Circle*>& circles) {
	double sum = 0;
	for (size_t i = 0; i < circles.size(); ++i) {
		sum += circles[i]->get_radius();
	}
	return sum;
}

int main() {
	size_t figures_number;
	cin >> figures_number;
	
	vector<Figure*> figures = generate_figures(figures_number);

	const double PI = 3.14;
	const double parameter = PI / 4;
	print_figures(figures, parameter);


	vector<Circle*> circles = generate_circles(figures);

	sort(circles.begin(), circles.end(), [](Circle* first, Circle* second) {
		return first->get_radius() < second->get_radius();
		});

	double sum = count_sum(circles);
	cout << "Sum = " << sum << endl;

	for (size_t i = 0; i < figures.size(); ++i) {
		delete figures[i];
	}
}