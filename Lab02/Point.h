#pragma once

#include <string>
#include <iostream>


class Point
{
private:
	double x_;
	double y_;

public:
	Point() : x_(0.0), y_(0.0) {
		std::cout << "0-param constructor\n";
	}

	Point(double x, double y) : x_(x), y_(y) {
		std::cout << "2-param constructor\n";
	}

	Point(const Point& point) {
		std::cout << "Copy constructor\n";
		this->x_ = point.x_;
		this->y_ = point.y_;
	}

	Point& operator=(const Point& point) {
		std::cout << "Copy assignment operator\n";
		this->x_ = point.x_;
		this->y_ = point.y_;
		return *this;
	}

	Point(Point&& point) noexcept {
		std::cout << "Move constructor\n";
		this->x_ = std::move(point.x_);
		this->y_ = std::move(point.y_);
	}

	void set_xy(double x, double y) {
		this->x_ = x;
		this->y_ = y;
	}

	std::string toString() {
		return "{ x: " + std::to_string(x_)
			+ ", y: " + std::to_string(y_)
		+ " }";
	}

};
