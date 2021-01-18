#pragma once
#include "point.h"


class Triangle
{
public:
	Triangle();
	Triangle(Point& p1, Point& p2, Point& p3);
	~Triangle();

public:
	bool isValid() { return m_isValid; }
	void print() const;

private:
	Point m_p1;
	Point m_p2;
	Point m_p3;
	bool  m_isValid;
};


