#include <iostream>

using namespace std;

#include "Point.h"
#include "Segment.h"

int main()
{	
	Point p1(1.0, 2.1);
	Point p2(p1);
	Segment s1(0, 0, 10, 11);
	Segment s2(p1, p2);
	Segment s1_copy(s1);
	Segment s2_copy;
	Point p3(2.0, 3.4);
	Segment s3(p3, p3);
	cout << endl << "s1: " << s1 << "; " << "s2: " << s2 << "; " << "s1_copy: " << s1_copy << "; " << "s2_copy: " << s2_copy << endl << endl;
	s1_copy = s2_copy = s2;
	cout << endl << "s1: " << s1 << "; " << "s2: " << s2 << "; " << "s1_copy: " << s1_copy << "; " << "s2_copy: " << s2_copy << endl << endl;
	cout << "Length of s1: " << s1.length() << endl << endl;
	cout << "From p1 to s1: " << s1.distance(p1) << endl << endl;
	cout << "From p1 to s2_copy: " << s2_copy.distance(p1) << endl << endl;
	cout << "From p1 to s3: " << s3.distance(p1) << endl << endl;

	Point p22(2, 2);
	Point p52(5, 2);
	Point p25(2, 5);
	Point p65(6, 5);
	Point p810(8, 10);

	Segment ver(p22, p25);
	Segment hor(p22, p52);
	Segment slope(p65, p810);
	Segment point(p810, p810);

	Point onHor(4, 2);
	Point onVerAway(2, 10);
	Point onSlope(7, 7.5);
	Point onSlopeAway(20, 40);
	Point onSlopeBelow(2, -5);

	cout << endl << endl << "From hor to its start : " << endl << hor.distance(p22) << endl << endl;
	cout << "onHor : " << endl << hor.distance(onHor) << endl << endl;
	cout << "onVerAway: " << endl << ver.distance(onVerAway) << endl << endl;
	cout << "onSlope : " << endl << slope.distance(onSlope) << endl << endl;
	cout << "onSlopeAway : " << endl << slope.distance(onSlopeAway) << endl << endl;
	cout << "onSlopeBelow : " << endl << slope.distance(onSlopeBelow) << endl << endl;

	system("pause");
	return 0;
}