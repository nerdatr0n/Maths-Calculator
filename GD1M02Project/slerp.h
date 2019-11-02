//
// Bachelor of Software Engineering
// Media Design School
// Auckland
// New Zealand
//
// (c) 2018 Media Design School
//
// File Name	: slerp.h
// Description	: Slerp calculator functions
// Author		: Benjamin Zaher and David Haverland
// Mail			: benjamin.zah8502@mediadesign.school.nz and david.hav8466@mediadesign.school.nz
//

#pragma once

#include <windows.h>   // Include all the windows headers.
#include <windowsx.h>  // Include useful macros.



//int leadings[3] = { 7,8,9 };


void ReadFromDialogBoxes(HWND _hwnd, float _fLine1[4], float _fLine2[4], float _fLineR[4], float _fMatrix1[4][4], float& _fScalar)
{
	// For line 1
	_fLine1[0] = ReadFromEditBox(_hwnd, IDC_EDIT1);
	_fLine1[1] = ReadFromEditBox(_hwnd, IDC_EDIT2);
	_fLine1[2] = ReadFromEditBox(_hwnd, IDC_EDIT3);
	_fLine1[3] = ReadFromEditBox(_hwnd, IDC_EDIT4);

	// For line 2
	_fLine2[0] = ReadFromEditBox(_hwnd, IDC_EDIT5);
	_fLine2[1] = ReadFromEditBox(_hwnd, IDC_EDIT6);
	_fLine2[2] = ReadFromEditBox(_hwnd, IDC_EDIT7);
	_fLine2[3] = ReadFromEditBox(_hwnd, IDC_EDIT8);

	// For scalar
	_fScalar = ReadFromEditBox(_hwnd, IDC_EDIT9);

	// For line 3
	_fLineR[0] = ReadFromEditBox(_hwnd, IDC_EDIT10);
	_fLineR[1] = ReadFromEditBox(_hwnd, IDC_EDIT11);
	_fLineR[2] = ReadFromEditBox(_hwnd, IDC_EDIT12);
	_fLineR[3] = ReadFromEditBox(_hwnd, IDC_EDIT13);


	// For Matrix R
	_fMatrix1[0][0] = ReadFromEditBox(_hwnd, IDC_EDIT34);
	_fMatrix1[1][0] = ReadFromEditBox(_hwnd, IDC_EDIT35);
	_fMatrix1[2][0] = ReadFromEditBox(_hwnd, IDC_EDIT36);
	_fMatrix1[3][0] = ReadFromEditBox(_hwnd, IDC_EDIT37);

	_fMatrix1[0][1] = ReadFromEditBox(_hwnd, IDC_EDIT38);
	_fMatrix1[1][1] = ReadFromEditBox(_hwnd, IDC_EDIT39);
	_fMatrix1[2][1] = ReadFromEditBox(_hwnd, IDC_EDIT40);
	_fMatrix1[3][1] = ReadFromEditBox(_hwnd, IDC_EDIT41);

	_fMatrix1[0][2] = ReadFromEditBox(_hwnd, IDC_EDIT42);
	_fMatrix1[1][2] = ReadFromEditBox(_hwnd, IDC_EDIT43);
	_fMatrix1[2][2] = ReadFromEditBox(_hwnd, IDC_EDIT44);
	_fMatrix1[3][2] = ReadFromEditBox(_hwnd, IDC_EDIT45);

	_fMatrix1[0][3] = ReadFromEditBox(_hwnd, IDC_EDIT46);
	_fMatrix1[1][3] = ReadFromEditBox(_hwnd, IDC_EDIT47);
	_fMatrix1[2][3] = ReadFromEditBox(_hwnd, IDC_EDIT48);
	_fMatrix1[3][3] = ReadFromEditBox(_hwnd, IDC_EDIT49);
}


void WriteToDialogBoxes(HWND _hwnd, float _fLine1[4], float _fLine2[4], float _fLineR[4], float _fMatrix1[4][4], float& _fScalar)
{
	// For line 1
	WriteToEditBox(_hwnd, IDC_EDIT1, _fLine1[0]);
	WriteToEditBox(_hwnd, IDC_EDIT2, _fLine1[1]);
	WriteToEditBox(_hwnd, IDC_EDIT3, _fLine1[2]);
	WriteToEditBox(_hwnd, IDC_EDIT4, _fLine1[3]);

	// For line 2
	WriteToEditBox(_hwnd, IDC_EDIT5, _fLine2[0]);
	WriteToEditBox(_hwnd, IDC_EDIT6, _fLine2[1]);
	WriteToEditBox(_hwnd, IDC_EDIT7, _fLine2[2]);
	WriteToEditBox(_hwnd, IDC_EDIT8, _fLine2[3]);

	// For scalar
	WriteToEditBox(_hwnd, IDC_EDIT9, _fScalar);

	// For line 3
	WriteToEditBox(_hwnd, IDC_EDIT10, _fLineR[0]);
	WriteToEditBox(_hwnd, IDC_EDIT11, _fLineR[1]);
	WriteToEditBox(_hwnd, IDC_EDIT12, _fLineR[2]);
	WriteToEditBox(_hwnd, IDC_EDIT13, _fLineR[3]);


	// For Matrix R
	if (_fMatrix1 != nullptr)
	{
		WriteToEditBox(_hwnd, IDC_EDIT34, _fMatrix1[0][0]);
		WriteToEditBox(_hwnd, IDC_EDIT35, _fMatrix1[0][1]);
		WriteToEditBox(_hwnd, IDC_EDIT36, _fMatrix1[0][2]);
		WriteToEditBox(_hwnd, IDC_EDIT37, _fMatrix1[0][3]);

		WriteToEditBox(_hwnd, IDC_EDIT38, _fMatrix1[1][0]);
		WriteToEditBox(_hwnd, IDC_EDIT39, _fMatrix1[1][1]);
		WriteToEditBox(_hwnd, IDC_EDIT40, _fMatrix1[1][2]);
		WriteToEditBox(_hwnd, IDC_EDIT41, _fMatrix1[1][3]);

		WriteToEditBox(_hwnd, IDC_EDIT42, _fMatrix1[2][0]);
		WriteToEditBox(_hwnd, IDC_EDIT43, _fMatrix1[2][1]);
		WriteToEditBox(_hwnd, IDC_EDIT44, _fMatrix1[2][2]);
		WriteToEditBox(_hwnd, IDC_EDIT45, _fMatrix1[2][3]);

		WriteToEditBox(_hwnd, IDC_EDIT46, _fMatrix1[3][0]);
		WriteToEditBox(_hwnd, IDC_EDIT47, _fMatrix1[3][1]);
		WriteToEditBox(_hwnd, IDC_EDIT48, _fMatrix1[3][2]);
		WriteToEditBox(_hwnd, IDC_EDIT49, _fMatrix1[3][3]);

	}

}

