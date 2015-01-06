#include "stdafx.h"
#include "Point.h"
class Line:public Shape
{
private:
public:
	Line(Point newStart, Point newEnd, int newWeight, COLORREF newColor);
	Line(int=0, int=0, int=0,int= 0,int newWeight=1, COLORREF newColor=0);
	Line(Line &l);
	~Line(void);
	
	Line &operator=(Line &);
	void Paint(CDC *dc);
};