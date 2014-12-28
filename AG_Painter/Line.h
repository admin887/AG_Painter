#include "stdafx.h"
#include "Point.h"
class Line:public Point
{
private:
	int m_X2;
	int m_Y2;
public:
	Line(int=0, int=0, int=0,int= 0);
	Line(Line &l);
	~Line(void);
	
	Line &operator=(const Line &);
	int getX2() const;
	int getY2() const;
	void setX2(int newX2);
	void setY2(int newY2);
	void Paint(CDC *dc);
};