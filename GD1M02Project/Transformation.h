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

void SetMatrixToIdentity(float _fMatrixR[4][4])
{
	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			if (i == j)
			{
				_fMatrixR[i][j] = 1;
			}
			else
			{
				_fMatrixR[i][j] = 0;
			}
		}
	}
}


void SetMatrixToMatrix(float _fMatrixA[4][4], float _fMatrixR[4][4])
{
	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			_fMatrixR[i][j] = _fMatrixA[i][j];
		}
	}
}

void MultiplyMatrix(float _fMatrixA[4][4], float _fMatrixB[4][4], float _fMatrixR[4][4])
{
	//Changed to float
	float fMatrixTemp[4][4];
	float fTemp = 0.0f;

	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			fTemp = 0;
			for (int k = 0; k < 4; ++k)
			{
				fTemp += _fMatrixA[i][k] * _fMatrixB[k][j];
			}
			fMatrixTemp[i][j] = fTemp;
		}
	}

	SetMatrixToMatrix(fMatrixTemp, _fMatrixR);
	//delete fMatrixTemp;
}

void SetMatrixToScale(float _fMatrixR[4][4], float _fScalefactor[3])
{
	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			_fMatrixR[i][j] = 0;
		}
	}
	_fMatrixR[0][0] = _fScalefactor[0];
	_fMatrixR[1][1] = _fScalefactor[1];
	_fMatrixR[2][2] = _fScalefactor[2];
	_fMatrixR[3][3] = 1;
}
void SetMatrixToTranslation(float _fMatrixR[4][4], float _fTranslation[3])
{
	SetMatrixToIdentity(_fMatrixR);

	_fMatrixR[0][3] = _fTranslation[0];
	_fMatrixR[1][3] = _fTranslation[1];
	_fMatrixR[2][3] = _fTranslation[2];
}
void SetMatrixToRotation(float _fMatrixR[4][4], int _xyz, float s_fAngle)
{
	SetMatrixToIdentity(_fMatrixR);

	switch (_xyz)
	{
	//x
	case 1:
		_fMatrixR[0][0] = 1;
		_fMatrixR[1][1] = cos(s_fAngle);
		_fMatrixR[1][2] = -sin(s_fAngle);
		_fMatrixR[2][1] = sin(s_fAngle);
		_fMatrixR[2][2] = cos(s_fAngle);

		break;

	//y
	case 2:
		_fMatrixR[0][0] = cos(s_fAngle);
		_fMatrixR[0][2] = sin(s_fAngle);
		_fMatrixR[1][1] = 1;
		_fMatrixR[2][0] = -sin(s_fAngle);
		_fMatrixR[2][2] = cos(s_fAngle);
		
		break;

	//z
	case 3:
		_fMatrixR[0][0] = cos(s_fAngle);
		_fMatrixR[0][1] = -sin(s_fAngle);
		_fMatrixR[1][0] = sin(s_fAngle);;
		_fMatrixR[1][1] = cos(s_fAngle);

		break;
	}
}
void SetMatrixToProjection(float _fMatrixR[4][4], float _projection[3],  float s_fDistance)
{
	SetMatrixToIdentity(_fMatrixR);

	float t_v = _projection[0] + _projection[1] + _projection[2] + (_projection[2] / s_fDistance);

	_fMatrixR[0][0] *= _projection[0];
	_fMatrixR[1][1] *= _projection[1];
	_fMatrixR[2][2] *= _projection[2];
	_fMatrixR[3][2] = t_v / s_fDistance;
	_fMatrixR[3][3] = 0;
}

void ReadFromDialogBoxes(HWND _hwnd, float _fLine1[3], float _fLine2[3], float& _fScalar1, float _fLine3[3], float& _fScalar2, float _fMatrixA[4][4] = NULL, float _fMatrixB[4][4] = NULL)
{
	 // for Scale Factor
	_fLine1[0] = ReadFromEditBox(_hwnd, IDC_EDIT1);
	_fLine1[1] = ReadFromEditBox(_hwnd, IDC_EDIT2);
	_fLine1[2] = ReadFromEditBox(_hwnd, IDC_EDIT3);

	// for Translation amount
	_fLine2[0] = ReadFromEditBox(_hwnd, IDC_EDIT4);
	_fLine2[1] = ReadFromEditBox(_hwnd, IDC_EDIT5);
	_fLine2[2] = ReadFromEditBox(_hwnd, IDC_EDIT6);

	// for Projection
	_fLine3[0] = ReadFromEditBox(_hwnd, IDC_EDIT29);
	_fLine3[1] = ReadFromEditBox(_hwnd, IDC_EDIT30);
	_fLine3[2] = ReadFromEditBox(_hwnd, IDC_EDIT31);
	
	_fScalar1 = ReadFromEditBox(_hwnd, IDC_EDIT13);
	
	
	_fScalar2 = ReadFromEditBox(_hwnd, IDC_EDIT15);


	//For Column major format
	if (_fMatrixA != NULL)
	{
		_fMatrixA[0][0] = ReadFromEditBox(_hwnd, IDC_EDIT47);
		_fMatrixA[0][1] = ReadFromEditBox(_hwnd, IDC_EDIT48);
		_fMatrixA[0][2] = ReadFromEditBox(_hwnd, IDC_EDIT49);
		_fMatrixA[0][3] = ReadFromEditBox(_hwnd, IDC_EDIT50);

		_fMatrixA[1][0] = ReadFromEditBox(_hwnd, IDC_EDIT51);
		_fMatrixA[1][1] = ReadFromEditBox(_hwnd, IDC_EDIT52);
		_fMatrixA[1][2] = ReadFromEditBox(_hwnd, IDC_EDIT53);
		_fMatrixA[1][3] = ReadFromEditBox(_hwnd, IDC_EDIT54);

		_fMatrixA[2][0] = ReadFromEditBox(_hwnd, IDC_EDIT55);
		_fMatrixA[2][1] = ReadFromEditBox(_hwnd, IDC_EDIT56);
		_fMatrixA[2][2] = ReadFromEditBox(_hwnd, IDC_EDIT57);
		_fMatrixA[2][3] = ReadFromEditBox(_hwnd, IDC_EDIT58);

		_fMatrixA[3][0] = ReadFromEditBox(_hwnd, IDC_EDIT59);
		_fMatrixA[3][1] = ReadFromEditBox(_hwnd, IDC_EDIT60);
		_fMatrixA[3][2] = ReadFromEditBox(_hwnd, IDC_EDIT61);
		_fMatrixA[3][3] = ReadFromEditBox(_hwnd, IDC_EDIT62);
	}


	// for Row-Major Format
	if (_fMatrixB != NULL)
	{
		_fMatrixB[0][0] = ReadFromEditBox(_hwnd, IDC_EDIT16);
		_fMatrixB[1][0] = ReadFromEditBox(_hwnd, IDC_EDIT18);
		_fMatrixB[2][0] = ReadFromEditBox(_hwnd, IDC_EDIT19);
		_fMatrixB[3][0] = ReadFromEditBox(_hwnd, IDC_EDIT20);
				
		_fMatrixB[0][1] = ReadFromEditBox(_hwnd, IDC_EDIT21);
		_fMatrixB[1][1] = ReadFromEditBox(_hwnd, IDC_EDIT22);
		_fMatrixB[2][1] = ReadFromEditBox(_hwnd, IDC_EDIT23);
		_fMatrixB[3][1] = ReadFromEditBox(_hwnd, IDC_EDIT8);
				
		_fMatrixB[0][2] = ReadFromEditBox(_hwnd, IDC_EDIT9);
		_fMatrixB[1][2] = ReadFromEditBox(_hwnd, IDC_EDIT10);
		_fMatrixB[2][2] = ReadFromEditBox(_hwnd, IDC_EDIT11);
		_fMatrixB[3][2] = ReadFromEditBox(_hwnd, IDC_EDIT12);
				
		_fMatrixB[0][3] = ReadFromEditBox(_hwnd, IDC_EDIT24);
		_fMatrixB[1][3] = ReadFromEditBox(_hwnd, IDC_EDIT25);
		_fMatrixB[2][3] = ReadFromEditBox(_hwnd, IDC_EDIT26);
		_fMatrixB[3][3] = ReadFromEditBox(_hwnd, IDC_EDIT27);
	}

			    

}


void WriteToDialogBoxes(HWND _hwnd, float _fLine1[3], float _fLine2[3], float _fScalar1, float _fLine3[3], float _fScalar2, float _fMatrixA[4][4], float _fMatrixB[4][4])
{

	

	// for Scale Factor
	WriteToEditBox(_hwnd, IDC_EDIT1, _fLine1[0]);
	WriteToEditBox(_hwnd, IDC_EDIT2, _fLine1[1]);
	WriteToEditBox(_hwnd, IDC_EDIT3, _fLine1[2]);
	
	// for Translation amount
	WriteToEditBox(_hwnd, IDC_EDIT4, _fLine2[0]);
	WriteToEditBox(_hwnd, IDC_EDIT5, _fLine2[1]);
	WriteToEditBox(_hwnd, IDC_EDIT6, _fLine2[2]);

	// for Projection amount
	WriteToEditBox(_hwnd, IDC_EDIT29, _fLine3[0]);
	WriteToEditBox(_hwnd, IDC_EDIT30, _fLine3[1]);
	WriteToEditBox(_hwnd, IDC_EDIT31, _fLine3[2]);
	
	// for Rotation amount	
	WriteToEditBox(_hwnd, IDC_EDIT13, _fScalar1);
	
	// for Projection
	WriteToEditBox(_hwnd, IDC_EDIT15, _fScalar2);

	
	
	
	
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
	WriteToEditBox(_hwnd, IDC_EDIT47, _fMatrixA[0][0]);
	WriteToEditBox(_hwnd, IDC_EDIT48, _fMatrixA[0][1]);
	WriteToEditBox(_hwnd, IDC_EDIT49, _fMatrixA[0][2]);
	WriteToEditBox(_hwnd, IDC_EDIT50, _fMatrixA[0][3]);

	WriteToEditBox(_hwnd, IDC_EDIT51, _fMatrixA[1][0]);
	WriteToEditBox(_hwnd, IDC_EDIT52, _fMatrixA[1][1]);
	WriteToEditBox(_hwnd, IDC_EDIT53, _fMatrixA[1][2]);
	WriteToEditBox(_hwnd, IDC_EDIT54, _fMatrixA[1][3]);

	WriteToEditBox(_hwnd, IDC_EDIT55, _fMatrixA[2][0]);
	WriteToEditBox(_hwnd, IDC_EDIT56, _fMatrixA[2][1]);
	WriteToEditBox(_hwnd, IDC_EDIT57, _fMatrixA[2][2]);
	WriteToEditBox(_hwnd, IDC_EDIT58, _fMatrixA[2][3]);

	WriteToEditBox(_hwnd, IDC_EDIT59, _fMatrixA[3][0]);
	WriteToEditBox(_hwnd, IDC_EDIT60, _fMatrixA[3][1]);
	WriteToEditBox(_hwnd, IDC_EDIT61, _fMatrixA[3][2]);
	WriteToEditBox(_hwnd, IDC_EDIT62, _fMatrixA[3][3]);


}