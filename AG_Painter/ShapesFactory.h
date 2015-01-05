#include "stdafx.h"
#include "IShape.h"
class ShapesFactory
{
private:
	ShapesFactory();
public:
	~ShapesFactory();
	ShapesFactory getInstance();
	IShape CreateShape(char* Type);
};