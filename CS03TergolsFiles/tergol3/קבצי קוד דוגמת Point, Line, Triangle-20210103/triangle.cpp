#include "triangle.h"


Triangle::Triangle()
{
}

Triangle::Triangle(Point & p1, Point & p2, Point & p3)
{
	double firstSlope = (p2.getX() != p1.getX()) ? (p2.getY() - p1.getY()) / (p2.getX() - p1.getX()) : 0;
	double secondSlope = (p2.getX() != p3.getX()) ? (p2.getY() - p3.getY()) / (p2.getX() - p3.getX()) : 0;

	m_isValid = firstSlope != secondSlope;
	if (m_isValid)
	{
		m_p1 = p1;
		m_p2 = p2;
		m_p3 = p3;
	}
}

Triangle::~Triangle()
{
}

void Triangle::print() const
{
	m_p1.print();
	m_p2.print();
	m_p3.print();
}
