#pragma once

#include "clUILibCommon.h"
#include "CGridColumnTrait.h"

BEGIN_CUTLEADER_NAMESPACE()

//------------------------------------------------------------------------
//! CGridColumnTraitText provides customization of cell text and background
//------------------------------------------------------------------------
class ClUILib_Export CGridColumnTraitText : public CGridColumnTrait
{
public:
	CGridColumnTraitText();
	virtual void OnCustomDraw(CGridListCtrlEx& owner, NMLVCUSTOMDRAW* pLVCD, LRESULT* pResult);	
	virtual bool OnSortRows(CGridListCtrlEx& owner, int nCol, bool bAscending);

	bool UpdateTextColor(COLORREF& textColor);
	bool UpdateBackColor(COLORREF& backColor);

	void SetSortFormatNumber(bool bValue);

	virtual int CompareCellValues(LPCTSTR pszLeftValue, LPCTSTR pszRightValue, bool bAscending);

protected:
	CFont*	m_pOldFont;		//!< Backup of the original font while drawing with this font
	COLORREF m_TextColor;	//!< Text color to use for this column
	COLORREF m_BackColor;	//!< Background color to use for this column
	bool m_SortFormatNumber;//!< Column contains integers

	virtual void Accept(CGridColumnTraitVisitor& visitor);
	virtual int GetCellFontHeight(CGridListCtrlEx& owner);
	virtual CRect GetCellEditRect(CGridListCtrlEx& owner, int nRow, int nCol);
};

END_CUTLEADER_NAMESPACE()
