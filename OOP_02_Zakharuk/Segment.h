//*******************************************

//Every segment posesses its unique ID.

//In debug mode both constructor and destructor

//report the ID and the coordinates

//of a segment created or resp. deleted

//Developed by Zakharuk

//at Jan 21, 2016

//Version 1.0

//*******************************************

#include <iostream>
#include "Point.h"

using namespace std;

class Segment

{

private:

	static int _freeID;

	const int _myId;

	// start
	Point _a;

	// end
	Point _b;

public:

	Segment(const double x1 = 0, const double y1 = 0,

		const double x2 = 1, const double y2 = 0);

	Segment(const Point &start, const Point &end);

	Segment(const Segment&);

	~Segment();

	Segment& operator=(const Segment&);

	const Point& start() const;

	const Point& end() const;

	Point &Segment::start();

	Point &Segment::end();

	const double &Segment::startX() const;

	const double &Segment::startY() const;

	const double &Segment::endX() const;

	const double &Segment::endY() const;

	double &Segment::startX();

	double &Segment::startY();

	double &Segment::endX();

	double &Segment::endY();

	// The length of the segment

	double length() const;

	// Calculate the distacne from the segment to a point

	double distance(const Point&) const;

	// Selector ID

	const int getID() const;

};



ostream& operator<<(ostream &, const Segment &);