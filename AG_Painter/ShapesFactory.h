#include "stdafx.h"
#include "Shape.h"
class ShapesFactory
{
private:
	ShapesFactory();
public:
	~ShapesFactory();
	ShapesFactory getInstance();
	Shape CreateShape(char* Type);
};