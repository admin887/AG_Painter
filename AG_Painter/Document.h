#include "stdafx.h"
#include "Drawer.h"
#include "NullShape.h"
#include "ToolNull.h"
#include "ShapesGarage.h"
#pragma once;
class Document
{
private:
	Tool *m_curTool;
	Shape *m_currShape;
	ShapesGarage *sg;
public:
	Document(Tool *newCurTool=new ToolNull(), Shape *newShape=new NullShape());
	virtual ~Document(void);
	Tool &getCurrTool();
	void setCurrTool(Tool &newCurTool);

	Shape &getCurrentShape();
	void setCurrentShape(Shape &newShape);

	Document &operator=(Document &newDocument);

	ShapesGarage* getShapeGarade();
	void setShapeGarade(ShapesGarage &newsg);
	Document(Document &newDocument);
};