#pragma once
#include "point.h"


class Line
{
public:
	Line();
	Line(Point& p1, Point& p2);
	~Line();

public:
	bool isPointOnLine(Point& p);


private:
	double m_slope;
	int	   m_offset;
};

