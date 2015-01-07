#include "stdafx.h"
#include "Drawer.h"
#include "NullShape.h"
#include "ToolNull.h"
#pragma once;
class Document
{
private:
	Tool *m_drawer;
	Shape *currShape;
public:
	Document(Tool *newDrawer=new ToolNull(), Shape *newShape=new NullShape()); 
	Tool &getDrawer();
	void setDrawer(Tool &newDrawer);

	Shape &getCurrentShape();
	void setCurrentShape(Shape &newShape);

	Document &operator=(Document &newDocument);
};