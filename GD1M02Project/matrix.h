//
// Bachelor of Software Engineering
// Media Design School
// Auckland
// New Zealand
//
// (c) 2018 Media Design School
//
// File Name	: matrix.h
// Description	: Functions for matrix
// Author		: Benjamin Zaher and David Haverland
// Mail			: benjamin.zah8502@mediadesign.school.nz and david.hav8466@mediadesign.school.nz
//

#pragma once

#include <windows.h>   // Include all the windows headers.
#include <windowsx.h>  // Include useful macros.

/*
int row = 0;
int col = 0;
for (row = 0; row < 4; row++)
{
	for (col = 0; col < 4; col++)
	{
		// Checking if row is equal to column  
		if (row == col)
		{
			s_fMatrixA[row][col] = 1;
		}

		else
		{
			s_fMatrixA[row][col] = 0;
		}

	}

}*/




void ReadFromDialogBoxes(HWND _hwnd, float _fMatrixA[4][4], float _fMatrixB[4][4], float _fMatrixR[4][4]) {
	// for Matrix A
	_fMatrixA[0][0] = ReadFromEditBox(_hwnd, IDC_EDIT_A11);
	_fMatrixA[1][0] = ReadFromEditBox(_hwnd, IDC_EDIT_A21);
	_fMatrixA[2][0] = ReadFromEditBox(_hwnd, IDC_EDIT_A31);
	_fMatrixA[3][0] = ReadFromEditBox(_hwnd, IDC_EDIT_A41);
	
	_fMatrixA[0][1] = ReadFromEditBox(_hwnd, IDC_EDIT_A12);
	_fMatrixA[1][1] = ReadFromEditBox(_hwnd, IDC_EDIT_A22);
	_fMatrixA[2][1] = ReadFromEditBox(_hwnd, IDC_EDIT_A32);
	_fMatrixA[3][1] = ReadFromEditBox(_hwnd, IDC_EDIT_A42);

	_fMatrixA[0][2] = ReadFromEditBox(_hwnd, IDC_EDIT_A13);
	_fMatrixA[1][2] = ReadFromEditBox(_hwnd, IDC_EDIT_A23);
	_fMatrixA[2][2] = ReadFromEditBox(_hwnd, IDC_EDIT_A33);
	_fMatrixA[3][2] = ReadFromEditBox(_hwnd, IDC_EDIT_A43);

	_fMatrixA[0][3] = ReadFromEditBox(_hwnd, IDC_EDIT_A14);
	_fMatrixA[1][3] = ReadFromEditBox(_hwnd, IDC_EDIT_A24);
	_fMatrixA[2][3] = ReadFromEditBox(_hwnd, IDC_EDIT_A34);
	_fMatrixA[3][3] = ReadFromEditBox(_hwnd, IDC_EDIT_A44);


	// for Matrix B
	_fMatrixB[0][0] = ReadFromEditBox(_hwnd, IDC_EDIT_B11);
	_fMatrixB[1][0] = ReadFromEditBox(_hwnd, IDC_EDIT_B21);
	_fMatrixB[2][0] = ReadFromEditBox(_hwnd, IDC_EDIT_B31);
	_fMatrixB[3][0] = ReadFromEditBox(_hwnd, IDC_EDIT_B41);
	
	_fMatrixB[0][1] = ReadFromEditBox(_hwnd, IDC_EDIT_B12);
	_fMatrixB[1][1] = ReadFromEditBox(_hwnd, IDC_EDIT_B22);
	_fMatrixB[2][1] = ReadFromEditBox(_hwnd, IDC_EDIT_B32);
	_fMatrixB[3][1] = ReadFromEditBox(_hwnd, IDC_EDIT_B42);
	
	_fMatrixB[0][2] = ReadFromEditBox(_hwnd, IDC_EDIT_B13);
	_fMatrixB[1][2] = ReadFromEditBox(_hwnd, IDC_EDIT_B23);
	_fMatrixB[2][2] = ReadFromEditBox(_hwnd, IDC_EDIT_B33);
	_fMatrixB[3][2] = ReadFromEditBox(_hwnd, IDC_EDIT_B43);
	
	_fMatrixB[0][3] = ReadFromEditBox(_hwnd, IDC_EDIT_B14);
	_fMatrixB[1][3] = ReadFromEditBox(_hwnd, IDC_EDIT_B24);
	_fMatrixB[2][3] = ReadFromEditBox(_hwnd, IDC_EDIT_B34);
	_fMatrixB[3][3] = ReadFromEditBox(_hwnd, IDC_EDIT_B44);


	// for Matrix R
	_fMatrixR[0][0] = ReadFromEditBox(_hwnd, IDC_EDIT_R11);
	_fMatrixR[1][0] = ReadFromEditBox(_hwnd, IDC_EDIT_R21);
	_fMatrixR[2][0] = ReadFromEditBox(_hwnd, IDC_EDIT_R31);
	_fMatrixR[3][0] = ReadFromEditBox(_hwnd, IDC_EDIT_R41);

	_fMatrixR[0][1] = ReadFromEditBox(_hwnd, IDC_EDIT_R12);
	_fMatrixR[1][1] = ReadFromEditBox(_hwnd, IDC_EDIT_R22);
	_fMatrixR[2][1] = ReadFromEditBox(_hwnd, IDC_EDIT_R32);
	_fMatrixR[3][1] = ReadFromEditBox(_hwnd, IDC_EDIT_R42);

	_fMatrixR[0][2] = ReadFromEditBox(_hwnd, IDC_EDIT_R13);
	_fMatrixR[1][2] = ReadFromEditBox(_hwnd, IDC_EDIT_R23);
	_fMatrixR[2][2] = ReadFromEditBox(_hwnd, IDC_EDIT_R33);
	_fMatrixR[3][2] = ReadFromEditBox(_hwnd, IDC_EDIT_R43);

	_fMatrixR[0][3] = ReadFromEditBox(_hwnd, IDC_EDIT_R14);
	_fMatrixR[1][3] = ReadFromEditBox(_hwnd, IDC_EDIT_R24);
	_fMatrixR[2][3] = ReadFromEditBox(_hwnd, IDC_EDIT_R34);
	_fMatrixR[3][3] = ReadFromEditBox(_hwnd, IDC_EDIT_R44);
	
}


void WriteToDialogBoxes(HWND _hwnd, float _fMatrixA[4][4], float _fMatrixB[4][4], float _fMatrixR[4][4]) {
	// for Matrix A
	WriteToEditBox(_hwnd, IDC_EDIT_A11, _fMatrixA[0][0]);
	WriteToEditBox(_hwnd, IDC_EDIT_A21, _fMatrixA[1][0]);
	WriteToEditBox(_hwnd, IDC_EDIT_A31, _fMatrixA[2][0]);
	WriteToEditBox(_hwnd, IDC_EDIT_A41, _fMatrixA[3][0]);

	WriteToEditBox(_hwnd, IDC_EDIT_A12, _fMatrixA[0][1]);
	WriteToEditBox(_hwnd, IDC_EDIT_A22, _fMatrixA[1][1]);
	WriteToEditBox(_hwnd, IDC_EDIT_A32, _fMatrixA[2][1]);
	WriteToEditBox(_hwnd, IDC_EDIT_A42, _fMatrixA[3][1]);

	WriteToEditBox(_hwnd, IDC_EDIT_A13, _fMatrixA[0][2]);
	WriteToEditBox(_hwnd, IDC_EDIT_A23, _fMatrixA[1][2]);
	WriteToEditBox(_hwnd, IDC_EDIT_A33, _fMatrixA[2][2]);
	WriteToEditBox(_hwnd, IDC_EDIT_A43, _fMatrixA[3][2]);

	WriteToEditBox(_hwnd, IDC_EDIT_A14, _fMatrixA[0][3]);
	WriteToEditBox(_hwnd, IDC_EDIT_A24, _fMatrixA[1][3]);
	WriteToEditBox(_hwnd, IDC_EDIT_A34, _fMatrixA[2][3]);
	WriteToEditBox(_hwnd, IDC_EDIT_A44, _fMatrixA[3][3]);


	// for Matrix B
	WriteToEditBox(_hwnd, IDC_EDIT_B11, _fMatrixB[0][0]);
	WriteToEditBox(_hwnd, IDC_EDIT_B21, _fMatrixB[1][0]);
	WriteToEditBox(_hwnd, IDC_EDIT_B31, _fMatrixB[2][0]);
	WriteToEditBox(_hwnd, IDC_EDIT_B41, _fMatrixB[3][0]);

	WriteToEditBox(_hwnd, IDC_EDIT_B12, _fMatrixB[0][1]);
	WriteToEditBox(_hwnd, IDC_EDIT_B22, _fMatrixB[1][1]);
	WriteToEditBox(_hwnd, IDC_EDIT_B32, _fMatrixB[2][1]);
	WriteToEditBox(_hwnd, IDC_EDIT_B42, _fMatrixB[3][1]);

	WriteToEditBox(_hwnd, IDC_EDIT_B13, _fMatrixB[0][2]);
	WriteToEditBox(_hwnd, IDC_EDIT_B23, _fMatrixB[1][2]);
	WriteToEditBox(_hwnd, IDC_EDIT_B33, _fMatrixB[2][2]);
	WriteToEditBox(_hwnd, IDC_EDIT_B43, _fMatrixB[3][2]);

	WriteToEditBox(_hwnd, IDC_EDIT_B14, _fMatrixB[0][3]);
	WriteToEditBox(_hwnd, IDC_EDIT_B24, _fMatrixB[1][3]);
	WriteToEditBox(_hwnd, IDC_EDIT_B34, _fMatrixB[2][3]);
	WriteToEditBox(_hwnd, IDC_EDIT_B44, _fMatrixB[3][3]);


	// for Matrix R
	WriteToEditBox(_hwnd, IDC_EDIT_R11, _fMatrixR[0][0]);
	WriteToEditBox(_hwnd, IDC_EDIT_R21, _fMatrixR[1][0]);
	WriteToEditBox(_hwnd, IDC_EDIT_R31, _fMatrixR[2][0]);
	WriteToEditBox(_hwnd, IDC_EDIT_R41, _fMatrixR[3][0]);

	WriteToEditBox(_hwnd, IDC_EDIT_R12, _fMatrixR[0][1]);
	WriteToEditBox(_hwnd, IDC_EDIT_R22, _fMatrixR[1][1]);
	WriteToEditBox(_hwnd, IDC_EDIT_R32, _fMatrixR[2][1]);
	WriteToEditBox(_hwnd, IDC_EDIT_R42, _fMatrixR[3][1]);

	WriteToEditBox(_hwnd, IDC_EDIT_R13, _fMatrixR[0][2]);
	WriteToEditBox(_hwnd, IDC_EDIT_R23, _fMatrixR[1][2]);
	WriteToEditBox(_hwnd, IDC_EDIT_R33, _fMatrixR[2][2]);
	WriteToEditBox(_hwnd, IDC_EDIT_R43, _fMatrixR[3][2]);

	WriteToEditBox(_hwnd, IDC_EDIT_R14, _fMatrixR[0][3]);
	WriteToEditBox(_hwnd, IDC_EDIT_R24, _fMatrixR[1][3]);
	WriteToEditBox(_hwnd, IDC_EDIT_R34, _fMatrixR[2][3]);
	WriteToEditBox(_hwnd, IDC_EDIT_R44, _fMatrixR[3][3]);

}