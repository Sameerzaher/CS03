#include <iostream>
//#include "point.h"
#include "Triangle.h"
#include "Line.h"

using namespace std;


int main(void)
{
	Point p1(0, 3);
	Point p2(1, 1);
	Point p3(0, -1);

	p1.print();
	p2.print();
	p3.print();

	Line line1(p1, p2);
	Line line2(p2, p3);

	if (line1.isPointOnLine(p3))
		cout << "p3 is on the line!" << endl;
	else
		cout << "p3 is not on the line!" << endl;

	if (line2.isPointOnLine(p2))
		cout << "p2 is on the line!" << endl;
	else
		cout << "p2 is not on the line!" << endl;

	Triangle tri(p1, p2, p3);
	if (tri.isValid())
	{
		cout << "Valid triangle.." << endl;
		tri.print();
	}
	else
		cout << "Invalid triangle.." << endl;

	p3.movePoint(2, 0);
	Triangle tri2(p1, p2, p3);
	if (tri2.isValid())
	{
		cout << "Valid triangle.." << endl;
		tri2.print();
	}
	else
		cout << "Invalid triangle.." << endl;

	cin.get();

}