// Machine generated IDispatch wrapper class(es) created by Microsoft Visual C++

// NOTE: Do not modify the contents of this file.  If this class is regenerated by
//  Microsoft Visual C++, your modifications will be overwritten.


// Dispatch interfaces referenced by this interface
class CTeeFilter;

/////////////////////////////////////////////////////////////////////////////
// CFilterItems wrapper class

class CFilterItems : public COleDispatchDriver
{
public:
	CFilterItems() {}		// Calls COleDispatchDriver default constructor
	CFilterItems(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	CFilterItems(const CFilterItems& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

// Attributes
public:

// Operations
public:
	long Add(long FilterClass);
	void LoadImage(LPCTSTR FileName);
	CTeeFilter GetItem(long Index);
	void AssignImage(long ImageHandle);
};
