#if !defined(AFX_WALLS_H__DAE76EC1_EED1_403D_87D6_32F6DA47F8C8__INCLUDED_)
#define AFX_WALLS_H__DAE76EC1_EED1_403D_87D6_32F6DA47F8C8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Machine generated IDispatch wrapper class(es) created by Microsoft Visual C++

// NOTE: Do not modify the contents of this file.  If this class is regenerated by
//  Microsoft Visual C++, your modifications will be overwritten.


// Dispatch interfaces referenced by this interface
class CWall;

/////////////////////////////////////////////////////////////////////////////
// CWalls wrapper class

class CWalls : public COleDispatchDriver
{
public:
	CWalls() {}		// Calls COleDispatchDriver default constructor
	CWalls(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	CWalls(const CWalls& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

// Attributes
public:

// Operations
public:
	CWall GetBottom();
	CWall GetLeft();
	BOOL GetVisible();
	void SetVisible(BOOL bNewValue);
	unsigned long GetBackColor();
	void SetBackColor(unsigned long newValue);
	CWall GetBack();
	CWall GetRight();
	void SetSize(long nNewValue);
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_WALLS_H__DAE76EC1_EED1_403D_87D6_32F6DA47F8C8__INCLUDED_)