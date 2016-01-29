#include <iostream>

using namespace std;

#include "Point.h"

int Point::freeID = 0;
static int c_points = 0;

Point::Point(double x, double y) : _x(x), _y(y), pointID(freeID)
{
#ifndef NDEBUG
	cout << "Point Constructor ";
	cout << *this << endl;
#endif
	++freeID;
	++c_points;
	return;
}

Point::Point(const Point & p) : _x(p.x()), _y(p.y()), pointID(freeID)
{
#ifndef NDEBUG
	cout << "Point Constructor ";
	cout << *this << endl;
#endif
	++freeID;
	++c_points;
	return;
}

Point::~Point()
{
#ifndef NDEBUG
	cout << "Point Destructor ";
	cout << *this << endl;
#endif
	--c_points;
	return;
}

Point& Point::operator = (const Point& p)
{
	if (this == &p) return *this;
	_x = p._x;
	_y = p._y;
	return *this;
}

double& Point::x()
{
	return _x;
}

double& Point::y()
{
	return _y;
}

const double& Point::x() const
{
	return _x;
}

const double& Point::y() const
{
	return _y;
}

const int Point::getID() const
{
	return pointID;
}

int Point::amount()
{
	return c_points;
}

ostream& operator<<(ostream& os, const Point& p)
{
	os << "P" << p.getID() << "(" << p.x() << "; " << p.y() << ")";
	return os;
}

const Point operator+ (const Point & u, const Point & v)
{
	Point p(u.x() + v.x(), u.y() + v.y());
	return p;
}

Point& operator+=(Point & p, const Point& u)
{
	p.x() = p.x() + u.x();
	p.y() = p.y() + u.y();
	return p;
}

bool operator==(const Point & u, const Point &v)
{
#ifndef NDEBUG
	cout << "Comparing " << u << " and " << v << endl;
#endif
	if (u.x() == v.x() && u.y() == v.y()) return true;
	return false;
}

bool operator!=(const Point & u, const Point &v)
{
#ifndef NDEBUG
	cout << "Comparing " << u << " and " << v << endl;
#endif
	if (u.x() == v.x() && u.y() == v.y()) return false;
	return true;
}