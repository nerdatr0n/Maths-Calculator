#pragma once

#include <windows.h>   // Include all the windows headers.
#include <windowsx.h>  // Include useful macros.






void ReadFromDialogBoxes(HWND _hwnd, float _fLine1[4], float _fLine2[4], float _fLine3[4])
{
	// For line 1
	_fLine1[0] = ReadFromEditBox(_hwnd, IDC_EDIT1);
	_fLine1[1] = ReadFromEditBox(_hwnd, IDC_EDIT4);
	_fLine1[2] = ReadFromEditBox(_hwnd, IDC_EDIT2);
	_fLine1[3] = ReadFromEditBox(_hwnd, IDC_EDIT3);

	// For line 2
	_fLine2[0] = ReadFromEditBox(_hwnd, IDC_EDIT5);
	_fLine2[1] = ReadFromEditBox(_hwnd, IDC_EDIT8);
	_fLine2[2] = ReadFromEditBox(_hwnd, IDC_EDIT6);
	_fLine2[3] = ReadFromEditBox(_hwnd, IDC_EDIT7);
	
	// For line 3
	_fLine3[0] = ReadFromEditBox(_hwnd, IDC_EDIT9);
	_fLine3[1] = ReadFromEditBox(_hwnd, IDC_EDIT12);
	_fLine3[2] = ReadFromEditBox(_hwnd, IDC_EDIT10);
	_fLine3[3] = ReadFromEditBox(_hwnd, IDC_EDIT11);

}
	

void WriteToDialogBoxes(HWND _hwnd, float _fLine1[4], float _fLine2[4], float _fLine3[4])
{
	// For line 1
	WriteToEditBox(_hwnd, IDC_EDIT1, _fLine1[0]);
	WriteToEditBox(_hwnd, IDC_EDIT4, _fLine1[1]);
	WriteToEditBox(_hwnd, IDC_EDIT2, _fLine1[2]);
	WriteToEditBox(_hwnd, IDC_EDIT3, _fLine1[3]);

	// For line 2
	WriteToEditBox(_hwnd, IDC_EDIT5, _fLine2[0]);
	WriteToEditBox(_hwnd, IDC_EDIT8, _fLine2[1]);
	WriteToEditBox(_hwnd, IDC_EDIT6, _fLine2[2]);
	WriteToEditBox(_hwnd, IDC_EDIT7, _fLine2[3]);

	// For line 3
	WriteToEditBox(_hwnd, IDC_EDIT9, _fLine3[0]);
	WriteToEditBox(_hwnd, IDC_EDIT12, _fLine3[1]);
	WriteToEditBox(_hwnd, IDC_EDIT10, _fLine3[2]);
	WriteToEditBox(_hwnd, IDC_EDIT11, _fLine3[3]);

}