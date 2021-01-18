#include <iostream>
#include "point.h"

using namespace std;

Point::Point()
{
	m_x = 0;
	m_y = 0;
}

Point::Point(int x, int y)
{
	m_x = x;
	m_y = y;
}

Point::~Point()
{
}

void Point::print() const
{
	cout << "(x,y)=(" << m_x << "," << m_y << ")" << endl;
}

void Point::movePoint(int dx, int dy)
{
	m_x += dx;
	m_y += dy;
}
