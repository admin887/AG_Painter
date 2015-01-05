#include "stdafx.h"
#include "ISelectable.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif

class Shape : public ISelectable
{
private:
	bool m_isSelected; //False
public:
	virtual void Paint(CDC *dc)=0 ;
	virtual bool getIsSelected();
	virtual void setIsSelected(bool) ;


};