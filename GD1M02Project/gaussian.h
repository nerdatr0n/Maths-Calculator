//
// Bachelor of Software Engineering
// Media Design School
// Auckland
// New Zealand
//
// (c) 2018 Media Design School
//
// File Name	: gaussian.h
// Description	: Gaussian calculator functions
// Author		: Benjamin Zaher and David Haverland
// Mail			: benjamin.zah8502@mediadesign.school.nz and david.hav8466@mediadesign.school.nz
//

#pragma once

#include <windows.h>   // Include all the windows headers.
#include <windowsx.h>  // Include useful macros.



int leadings[3] = { 7,8,9 };


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

bool checkRowEchelon(HWND _hwnd, float _fLine1[4], float _fLine2[4], float _fLine3[4])
{
	bool result = true;

	float* toggle;

	bool l10 = true;
	bool l20 = true;
	bool l30 = true;

	leadings[0] = 7;
	leadings[1] = 8;
	leadings[2] = 9;

	ReadFromDialogBoxes(_hwnd, _fLine1, _fLine2, _fLine3);

	//A matrix is in row - echelon form when the following conditions are met.

	//If there is a row of all zeros, then it is at the bottom of the matrix.
	//The first non - zero element of any row is a one. That element is called the leading one.
	//The leading one of any row is to the right of the leading one of the previous row.

	//Property 1
	for (int j = 0; j < 4; ++j)
		if (_fLine1[j] != 0)
			l10 = false;

	for (int j = 0; j < 4; ++j)
		if (_fLine2[j] != 0)
			l20 = false;

	for (int j = 0; j < 4; ++j)
		if (_fLine3[j] != 0)
			l30 = false;
	


	if (l10 && !(l20 && l30))
		result = false;

	if (l20 && !l30)
		result = false;


	//Property 2
	for (int k = 0; k < 3; ++k)
	{
		switch (k)
		{
		case 0:
			toggle = _fLine1;
			break;
		case 1:
			toggle = _fLine2;
			break;
		case 2:
			toggle = _fLine3;
			break;
		}

		int i = 0;
		while (i < 4)
		{
			if (toggle[i] != 1 && toggle[i] != 0)
			{
				result = false;
				i += 4;
			}
			else if (toggle[i] == 1)
			{
				leadings[k] = i;
				i += 4;
			}
			i++;
		}
	}

	//Property 3
	for (int o = 0; o < 2; ++o)
	{
		if (leadings[o] >= leadings[o + 1])
		{
			result = false;
		}
	}

	return(result);
}

bool checkReducedRowEchelon(HWND _hwnd, float _fLine1[4], float _fLine2[4], float _fLine3[4])
{
	//The leading entry in each row must be the only non-zero number in its column.

	bool result = checkRowEchelon(_hwnd, _fLine1, _fLine2, _fLine3);

	//Property 4
	if (leadings[0] != 7)
		if (_fLine2[leadings[0]] != 0 || _fLine3[leadings[0]] != 0)
			result = false;

	if (leadings[1] != 8)
		if (_fLine1[leadings[1]] != 0 || _fLine3[leadings[1]] != 0)
			result = false;

	if (leadings[2] != 9)
		if (_fLine1[leadings[2]] != 0 || _fLine2[leadings[2]] != 0)
			result = false;


	return(result);
}