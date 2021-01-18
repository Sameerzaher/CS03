#include "Line.h"

Line::Line()
{
}

Line::Line(Point & p1, Point & p2)
{
	m_slope = (p2.getX() != p1.getX()) ? (p2.getY() - p1.getY()) / (p2.getX() - p1.getX()) : 0;
	m_offset = p1.getY() - m_slope * p1.getX();
}

Line::~Line()
{
}

bool Line::isPointOnLine(Point & p)
{
	return p.getY() == m_slope * p.getX() + m_offset;
}
