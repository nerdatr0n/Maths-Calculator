#pragma once


#pragma once

#include <windows.h>   // Include all the windows headers.
#include <windowsx.h>  // Include useful macros.


void ReadFromDialogBoxes(HWND _hwnd, float _fQuaternionA[4], float _fQuaternionB[4], float _fQuaternionR[4], float _fScalar)
{
	// For quaternion A
	_fQuaternionA[0] = ReadFromEditBox(_hwnd, IDC_EDIT1);
	_fQuaternionA[1] = ReadFromEditBox(_hwnd, IDC_EDIT2);
	_fQuaternionA[2] = ReadFromEditBox(_hwnd, IDC_EDIT3);
	_fQuaternionA[3] = ReadFromEditBox(_hwnd, IDC_EDIT4);

	// For quaternion B
	_fQuaternionB[0] = ReadFromEditBox(_hwnd, IDC_EDIT5);
	_fQuaternionB[1] = ReadFromEditBox(_hwnd, IDC_EDIT6);
	_fQuaternionB[2] = ReadFromEditBox(_hwnd, IDC_EDIT7);
	_fQuaternionB[3] = ReadFromEditBox(_hwnd, IDC_EDIT8);

	// For T
	_fScalar = ReadFromEditBox(_hwnd, IDC_EDIT9);

	// For quaternion resultant
	_fQuaternionR[0] = ReadFromEditBox(_hwnd, IDC_EDIT10);
	_fQuaternionR[1] = ReadFromEditBox(_hwnd, IDC_EDIT11);
	_fQuaternionR[2] = ReadFromEditBox(_hwnd, IDC_EDIT12);
	_fQuaternionR[3] = ReadFromEditBox(_hwnd, IDC_EDIT13);



}


void WriteToDialogBoxes(HWND _hwnd, float _fQuaternionA[4], float _fQuaternionB[4], float _fQuaternionR[4], float _fScalar)
{
	// For quaternion A
	WriteToEditBox(_hwnd, IDC_EDIT1, _fQuaternionA[0]);
	WriteToEditBox(_hwnd, IDC_EDIT2, _fQuaternionA[1]);
	WriteToEditBox(_hwnd, IDC_EDIT3, _fQuaternionA[2]);
	WriteToEditBox(_hwnd, IDC_EDIT4, _fQuaternionA[3]);

	// For quaternion B
	WriteToEditBox(_hwnd, IDC_EDIT5, _fQuaternionB[0]);
	WriteToEditBox(_hwnd, IDC_EDIT6, _fQuaternionB[1]);
	WriteToEditBox(_hwnd, IDC_EDIT7, _fQuaternionB[2]);
	WriteToEditBox(_hwnd, IDC_EDIT8, _fQuaternionB[3]);

	// For T
	WriteToEditBox(_hwnd, IDC_EDIT9, _fScalar);

	// For quaternion resultant
	WriteToEditBox(_hwnd, IDC_EDIT10, _fQuaternionR[0]);
	WriteToEditBox(_hwnd, IDC_EDIT11, _fQuaternionR[1]);
	WriteToEditBox(_hwnd, IDC_EDIT12, _fQuaternionR[2]);
	WriteToEditBox(_hwnd, IDC_EDIT13, _fQuaternionR[3]);


}