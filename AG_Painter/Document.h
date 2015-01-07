#include "stdafx.h"
#include "Drawer.h"
#pragma once;
class Document
{
private:
	Drawer *m_drawer;
	Shape *currShape;
public:
	Document(Drawer *,Shape *);
	Document(Document &);
	~Document();
	Document &operator=(Document &newDocument);
	Drawer &getDrawer();
	void setDrawer(Drawer &newDrawer);

	Shape &getCurrentShape();
	void setCurrentShape(Shape &newShape);

	
};