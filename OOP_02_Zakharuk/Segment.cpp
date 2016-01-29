#include <iostream>
#include <cmath>
#include "Segment.h"

using namespace std;

int Segment::_freeID = 0;

Segment::Segment(const double x1, const double y1, const double x2, const double y2) : _a(x1, y1), _b(x2, y2), _myId(_freeID++)
{
#ifndef NDEBUG
	cout << "New Segment " << *this << endl;
#endif
	return;
}

Segment::Segment(const Point &start, const Point &end) : _a(start), _b(end), _myId(_freeID++)
{
#ifndef NDEBUG
	cout << "New Segment " << *this << endl;
#endif
	return;
}

Segment::Segment(const Segment& s) : _a(s._a), _b(s._b), _myId(_freeID++)
{
#ifndef NDEBUG
	cout << "New copy Segment " << *this << endl;
#endif
	return;
}

Segment::~Segment()
{
#ifndef NDEBUG
	cout << "Destroying Segment " << *this << endl;
#endif
	return;
}

Segment& Segment::operator=(const Segment& s)
{
#ifndef NDEBUG
	cout << *this << " = " << s << endl;
#endif
	if (this == &s) return *this;
	_a = s._a;
	_b = s._b;
	return *this;
}

const Point& Segment::start() const
{
	return _a;
}

const Point& Segment::end() const
{
	return _b;
}

Point &Segment::start()
{
	return _a;
}

Point &Segment::end()
{
	return _b;
}

const double &Segment::startX() const
{
	return _a.x();
}

const double &Segment::startY() const
{
	return _a.y();
}

const double &Segment::endX() const
{
	return _b.x();
}

const double &Segment::endY() const
{
	return _b.y();
}

double &Segment::startX()
{
	return _a.x();
}

double &Segment::startY()
{
	return _a.y();
}

double &Segment::endX()
{
	return _b.x();
}

double &Segment::endY()
{
	return _b.y();
}

double Segment::length() const
{
#ifndef NDEBUG
	cout << "Length of " << *this << endl;
#endif
	double x = _a.x() - _b.x();
	double y = _a.y() - _b.y();
	return sqrt(x*x + y*y);
}

// returns true if the point P lies on the same line as the segment Seg
bool isOnLine(const Segment& seg, const Point& p)
{
#ifndef NDEBUG
	cout << "Checking if " << p << " is on " << seg << endl;
#endif
	// if the point is one of the ends of the segment
	if (p == seg.start() || p == seg.end()) return true;
	// if the segment is vertical
	if ((seg.start().x() == seg.end().x()) && seg.start().x() == p.x()) return true;
	// if the segment is horizontal
	if ((seg.start().y() == seg.end().y()) && seg.start().y() == p.y()) return true;
	const double TOL = 0.001;
	double k = (seg.end().y() - seg.start().y()) / (seg.end().x() - seg.start().x());
	double eq = k*(p.x() - seg.start().x()) + seg.start().y();
	if (p.y() <= eq + TOL && p.y() >= eq - TOL) return true;
	return false;
}

double Segment::distance(const Point& p) const
{
#ifndef NDEBUG
	cout << "Distance between " << p << " and " << *this << endl;
#endif
	// if the segment is actually a point
	if (_a == _b)
	{
		double x = p.x() - _a.x();
		double y = p.y() - _a.y();
		return sqrt(x*x + y*y);
	}
	if (isOnLine(*this, p)) 
	{
#ifndef NDEBUG
		cout << p << " is on " << *this << endl;
#endif
		return 0; 
	}
	double top = abs( (_a.y() - _b.y())*p.x() - (_a.x() - _b.x())*p.y() + (_b.x()*_a.y() - _a.x()*_b.y()) );
	return top / length();
}

const int Segment::getID() const
{
	return _myId;
}

ostream& operator<<(ostream & os, const Segment & seg)
{
	os << "S" << seg.getID() << "[" << seg.start() << " -> " << seg.end() << "]";
	return os;
}