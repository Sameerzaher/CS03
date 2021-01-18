#pragma once

class Point
{
public:
	Point();
	Point(int x, int y);
	~Point();

public:
	void print()const;
	void movePoint(int dx, int dy);
	int getX() { return m_x; }
	int getY() { return m_y; }


private:
	int m_x;
	int m_y;
};

