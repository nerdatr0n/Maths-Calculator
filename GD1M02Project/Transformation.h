//
// Bachelor of Software Engineering
// Media Design School
// Auckland
// New Zealand
//
// (c) 2018 Media Design School
//
// File Name	: transformation.h
// Description	: Functions for transformation
// Author		: Benjamin Zaher and David Haverland
// Mail			: benjamin.zah8502@mediadesign.school.nz and david.hav8466@mediadesign.school.nz
//

#pragma once

#include <windows.h>   // Include all the windows headers.
#include <windowsx.h>  // Include useful macros.






void ReadFromDialogBoxes(HWND _hwnd, float _fLine1[3], float _fLine2[3], float _fLine3[3], float& _fScalar1, float _fLine4[3], float& _fScalar2)
{
	// for Scale Factor
	_fLine1[0] = ReadFromEditBox(_hwnd, IDC_EDIT1);
	_fLine1[1] = ReadFromEditBox(_hwnd, IDC_EDIT2);
	_fLine1[2] = ReadFromEditBox(_hwnd, IDC_EDIT3);

	// for Translation amount
	_fLine2[0] = ReadFromEditBox(_hwnd, IDC_EDIT4);
	_fLine2[1] = ReadFromEditBox(_hwnd, IDC_EDIT5);
	_fLine2[2] = ReadFromEditBox(_hwnd, IDC_EDIT6);

	// for Rotation amount
	_fLine2[0] = ReadFromEditBox(_hwnd, IDC_EDIT7);
	_fLine2[1] = ReadFromEditBox(_hwnd, IDC_EDIT28);
	_fLine2[2] = ReadFromEditBox(_hwnd, IDC_EDIT30);

	_fScalar1 = ReadFromEditBox(_hwnd, IDC_EDIT13);

	// for Projection
	_fLine2[0] = ReadFromEditBox(_hwnd, IDC_EDIT14);
	_fLine2[1] = ReadFromEditBox(_hwnd, IDC_EDIT29);
	_fLine2[2] = ReadFromEditBox(_hwnd, IDC_EDIT31);

	_fScalar1 = ReadFromEditBox(_hwnd, IDC_EDIT15);

}


void WriteToDialogBoxes(HWND _hwnd, float _fLine1[3], float _fLine2[3], float _fLine3[3], float& _fScalar1, float _fLine4[3], float& _fScalar2, float _fMatrixA[4][4], float _fMatrixB[4][4])
{
	// for Scale Factor
	WriteToEditBox(_hwnd, IDC_EDIT1, _fLine1[0]);
	WriteToEditBox(_hwnd, IDC_EDIT2, _fLine1[1]);
	WriteToEditBox(_hwnd, IDC_EDIT3, _fLine1[2]);

	// for Translation amount
	WriteToEditBox(_hwnd, IDC_EDIT4, _fLine2[0]);
	WriteToEditBox(_hwnd, IDC_EDIT5, _fLine2[1]);
	WriteToEditBox(_hwnd, IDC_EDIT6, _fLine2[2]);

	// for Rotation amount
	WriteToEditBox(_hwnd, IDC_EDIT7, _fLine2[0]);
	WriteToEditBox(_hwnd, IDC_EDIT28, _fLine2[1]);
	WriteToEditBox(_hwnd, IDC_EDIT30, _fLine2[2]);

	WriteToEditBox(_hwnd, IDC_EDIT13, _fScalar1);

	// for Projection
	WriteToEditBox(_hwnd, IDC_EDIT14, _fLine2[0]);
	WriteToEditBox(_hwnd, IDC_EDIT29, _fLine2[1]);
	WriteToEditBox(_hwnd, IDC_EDIT31, _fLine2[2]);

	WriteToEditBox(_hwnd, IDC_EDIT15, _fScalar1);


	// for Row-Major Format
	WriteToEditBox(_hwnd, IDC_EDIT16, _fMatrixA[0][0]);
	WriteToEditBox(_hwnd, IDC_EDIT18, _fMatrixA[1][0]);
	WriteToEditBox(_hwnd, IDC_EDIT19, _fMatrixA[2][0]);
	WriteToEditBox(_hwnd, IDC_EDIT20, _fMatrixA[3][0]);

	WriteToEditBox(_hwnd, IDC_EDIT21, _fMatrixA[0][1]);
	WriteToEditBox(_hwnd, IDC_EDIT22, _fMatrixA[1][1]);
	WriteToEditBox(_hwnd, IDC_EDIT23, _fMatrixA[2][1]);
	WriteToEditBox(_hwnd, IDC_EDIT8, _fMatrixA[3][1]);

	WriteToEditBox(_hwnd, IDC_EDIT9, _fMatrixA[0][2]);
	WriteToEditBox(_hwnd, IDC_EDIT10, _fMatrixA[1][2]);
	WriteToEditBox(_hwnd, IDC_EDIT11, _fMatrixA[2][2]);
	WriteToEditBox(_hwnd, IDC_EDIT12, _fMatrixA[3][2]);

	WriteToEditBox(_hwnd, IDC_EDIT24, _fMatrixA[0][3]);
	WriteToEditBox(_hwnd, IDC_EDIT25, _fMatrixA[1][3]);
	WriteToEditBox(_hwnd, IDC_EDIT26, _fMatrixA[2][3]);
	WriteToEditBox(_hwnd, IDC_EDIT27, _fMatrixA[3][3]);



	// for Column-Major Format
	WriteToEditBox(_hwnd, IDC_EDIT47, _fMatrixB[0][0]);
	WriteToEditBox(_hwnd, IDC_EDIT48, _fMatrixB[1][0]);
	WriteToEditBox(_hwnd, IDC_EDIT49, _fMatrixB[2][0]);
	WriteToEditBox(_hwnd, IDC_EDIT50, _fMatrixB[3][0]);

	WriteToEditBox(_hwnd, IDC_EDIT51, _fMatrixB[0][1]);
	WriteToEditBox(_hwnd, IDC_EDIT52, _fMatrixB[1][1]);
	WriteToEditBox(_hwnd, IDC_EDIT53, _fMatrixB[2][1]);
	WriteToEditBox(_hwnd, IDC_EDIT54, _fMatrixB[3][1]);

	WriteToEditBox(_hwnd, IDC_EDIT55, _fMatrixB[0][2]);
	WriteToEditBox(_hwnd, IDC_EDIT56, _fMatrixB[1][2]);
	WriteToEditBox(_hwnd, IDC_EDIT57, _fMatrixB[2][2]);
	WriteToEditBox(_hwnd, IDC_EDIT58, _fMatrixB[3][2]);

	WriteToEditBox(_hwnd, IDC_EDIT59, _fMatrixB[0][3]);
	WriteToEditBox(_hwnd, IDC_EDIT60, _fMatrixB[1][3]);
	WriteToEditBox(_hwnd, IDC_EDIT61, _fMatrixB[2][3]);
	WriteToEditBox(_hwnd, IDC_EDIT62, _fMatrixB[3][3]);


}