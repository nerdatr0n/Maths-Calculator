//
// Bachelor of Software Engineering
// Media Design School
// Auckland
// New Zealand
//
// (c) 2018 Media Design School
//
// File Name	: 
// Description	: 
// Author		: Your Name
// Mail			: your.name@mediadesign.school.nz
//


#define WIN32_LEAN_AND_MEAN

#include <windows.h>   // Include all the windows headers.
#include <windowsx.h>  // Include useful macros.
#include <iostream>
#include <map>


#include "utils.h"
#include "resource.h"

#define WINDOW_CLASS_NAME L"WINCLASS1"

HMENU g_hMenu;
HWND g_hDlgMatrix, g_hDlgTransformation, g_hDlgGaussian, g_hDlgQuaternion, g_hDlgSLERP;

void GameLoop()
{
	//One frame of game logic occurs here...
}

LRESULT CALLBACK WindowProc(HWND _hwnd,
	UINT _msg,
	WPARAM _wparam,
	LPARAM _lparam)
{
	// This is the main message handler of the system.
	PAINTSTRUCT ps; // Used in WM_PAINT.
	HDC hdc;        // Handle to a device context.

					// What is the message?
	switch (_msg)
	{
	case WM_CREATE:
	{
		// Do initialization stuff here.

		// Return Success.
		return (0);
	}
	break;

	case WM_PAINT:
	{
		// Simply validate the window.
		hdc = BeginPaint(_hwnd, &ps);

		// You would do all your painting here...

		EndPaint(_hwnd, &ps);

		// Return Success.
		return (0);
	}
	break;

	case WM_COMMAND:
	{
		switch (LOWORD(_wparam))
		{
		case ID_EXIT:
		{
			PostQuitMessage(0);
			break;
		}
		case ID_CALCULATOR_MATRIX:
		{
			ShowWindow(g_hDlgMatrix, SW_SHOWNORMAL);
			break;
		}
		case ID_CALCULATOR_TRANSFORMATION:
		{
			ShowWindow(g_hDlgTransformation, SW_SHOWNORMAL);
			break;

		}
		//open the matrix dialog
		case ID_CALCULATOR_GAUSSIAN:
		{
			ShowWindow(g_hDlgGaussian, SW_SHOWNORMAL);
			break;
		}
		//open the gaussian dialog
		case ID_CALCULATOR_QUATERNION:
		{
			ShowWindow(g_hDlgQuaternion, SW_SHOWNORMAL);
			break;
		}
		//open the quaternion dialog
		case ID_CALCULATOR_SLERP:
		{
			ShowWindow(g_hDlgSLERP, SW_SHOWNORMAL);
			break;
		}
		default:
			break;
		}
		return(0);
	}
	break;

	case WM_DESTROY:
	{
		// Kill the application, this sends a WM_QUIT message.
		PostQuitMessage(0);

		// Return success.
		return (0);
	}
	break;

	default:break;
	} // End switch.

	  // Process any messages that we did not take care of...

	return (DefWindowProc(_hwnd, _msg, _wparam, _lparam));
}


BOOL CALLBACK MatrixDlgProc(HWND _hwnd,
	UINT _msg,
	WPARAM _wparam,
	LPARAM _lparam)
{
	//static float _value;
	static float _values[4][4];

	std::map<int, int> map;
	std::map<int, int>::iterator it;

	map[0] = IDC_EDIT_A11;
	map[1] = IDC_EDIT_A12;
	map[2] = IDC_EDIT_A13;
	map[3] = IDC_EDIT_A14;
	
	map[4] = IDC_EDIT_A21;
	map[5] = IDC_EDIT_A22;
	map[6] = IDC_EDIT_A23;
	map[7] = IDC_EDIT_A24;

	map[8] = IDC_EDIT_A31;
	map[9] = IDC_EDIT_A32;
	map[10] = IDC_EDIT_A33;
	map[11] = IDC_EDIT_A34;

	map[12] = IDC_EDIT_A41;
	map[13] = IDC_EDIT_A42;
	map[14] = IDC_EDIT_A43;
	map[15] = IDC_EDIT_A44;

	

	switch (_msg)
	{
	case WM_COMMAND:
	{
		switch (LOWORD(_wparam))
		{
		//INPUT BOXES

		//ROW 1
		case IDC_EDIT_A11:
		{
			_values[0][0] = ReadFromEditBox(_hwnd, IDC_EDIT_A11);
			break;
		}
		case IDC_EDIT_A12:
		{
			_values[0][1] = ReadFromEditBox(_hwnd, IDC_EDIT_A12);
			break;
		}
		case IDC_EDIT_A13:
		{
			_values[0][2] = ReadFromEditBox(_hwnd, IDC_EDIT_A13);
			break;
		}
		case IDC_EDIT_A14:
		{
			_values[0][3] = ReadFromEditBox(_hwnd, IDC_EDIT_A14);
			break;
		}

		//ROW 2

		case IDC_EDIT_A21:
		{
			_values[1][0] = ReadFromEditBox(_hwnd, IDC_EDIT_A21);
			break;
		}
		case IDC_EDIT_A22:
		{
			_values[1][1] = ReadFromEditBox(_hwnd, IDC_EDIT_A22);
			break;
		}
		case IDC_EDIT_A23:
		{
			_values[1][2] = ReadFromEditBox(_hwnd, IDC_EDIT_A23);
			break;
		}
		case IDC_EDIT_A24:
		{
			_values[1][3] = ReadFromEditBox(_hwnd, IDC_EDIT_A24);
			break;
		}


		//ROW 3

		case IDC_EDIT_A31:
		{
			_values[2][0] = ReadFromEditBox(_hwnd, IDC_EDIT_A31);
			break;
		}
		case IDC_EDIT_A32:
		{
			_values[2][1] = ReadFromEditBox(_hwnd, IDC_EDIT_A32);
			break;
		}
		case IDC_EDIT_A33:
		{
			_values[2][2] = ReadFromEditBox(_hwnd, IDC_EDIT_A33);
			break;
		}
		case IDC_EDIT_A34:
		{
			_values[2][3] = ReadFromEditBox(_hwnd, IDC_EDIT_A34);
			break;
		}


		//ROW 4

		case IDC_EDIT_A41:
		{
			_values[3][0] = ReadFromEditBox(_hwnd, IDC_EDIT_A41);
			break;
		}
		case IDC_EDIT_A42:
		{
			_values[3][1] = ReadFromEditBox(_hwnd, IDC_EDIT_A42);
			break;
		}
		case IDC_EDIT_A43:
		{
			_values[3][2] = ReadFromEditBox(_hwnd, IDC_EDIT_A43);
			break;
		}
		case IDC_EDIT_A44:
		{
			_values[3][3] = ReadFromEditBox(_hwnd, IDC_EDIT_A44);
			break;
		}

		//BUTTONS

		case IDOK4:
		{
			//Set identity matrix
			for (int i = 0; i < 4; ++i)
			{
				for (int j = 0; j < 4; ++j)
				{
					if(i == j)
						_values[i][j] = 1.0f;
					else
						_values[i][j] = 0.0f;
				}
			}
			
			for (int k = 0; k < 16; ++k)
			{
				it = map.find(k);
				if(k%5 == 0)
					WriteToEditBox(_hwnd, it->second, 1);
				else
					WriteToEditBox(_hwnd, it->second, 0);
			}

			break;
		}
		case IDOK9:
		{
			//Transposing the matrix

			//Create a temporary matrix
			int tempValues[4][4];

			//Create transposed matrix
			for (int i = 0; i < 4; ++i)
			{
				for (int j = 0; j < 4; ++j)
				{
					tempValues[i][j] = _values[j][i];
				}
			}

			//Move transposed matrix into main matrix
			for (int i = 0; i < 4; ++i)
			{
				for (int j = 0; j < 4; ++j)
				{
					_values[i][j] = tempValues[i][j];
				}
			}

			//Output matrix to text boxes
			int c1 = 0;
			int c2 = 0;

			for (int k = 0; k < 16; ++k)
			{
				it = map.find(k);
				WriteToEditBox(_hwnd, it->second, _values[c1][c2]);
				c2++;

				if (c2 == 4)
				{
					c1++;
					c2 = 0;
				}
			}

			break;
		}
		case IDCANCEL2:
		{
			//Easily understood variables
			float a = _values[0][0];
			float b = _values[0][1];
			float c = _values[0][2];
			float d = _values[0][3];

			float e = _values[1][0];
			float f = _values[1][1];
			float g = _values[1][2];
			float h = _values[1][3];

			float i = _values[2][0];
			float j = _values[2][1];
			float k = _values[2][2];
			float l = _values[2][3];

			float m = _values[3][0];
			float n = _values[3][1];
			float o = _values[3][2];
			float p = _values[3][3];

			float adjMatrix[4][4];

			adjMatrix[0][0] = (-h*k*n) + (g*l*n) + (h*j*o) - (f*l*o) - (g*j*p) + (f*k*p);
			adjMatrix[0][1] = d * k*n - c * l*n - d * j*o + b * l*o + c * j*p - b * k*p;
			adjMatrix[0][2] = -d*g*n + c*h*n + d*f*o - b*h*o - c*f*p + b*g*p;
			adjMatrix[0][3] = d * g*j - c * h*j - d * f*k + b * h*k + c * f*l - b * g*l;
			adjMatrix[1][0] = h * k*m - g * l*m - h * i*o + e * l*o + g * i*p - e * k*p;
			adjMatrix[1][1] = -d * k*m + c * l*m + d * i*o - a * l*o - c * i*p + a * k*p;
			adjMatrix[1][2] = d * g*m - c * h*m - d * e*o + a * h*o + c * e*p - a * g*p;
			adjMatrix[1][3] = -d * g*i + c * h*i + d * e*k - a * h*k - c * e*l + a * g*l;
			adjMatrix[2][0] = -h * j*m + f * l*m + h * i*n - e * l*n - f * i*p + e * j*p;
			adjMatrix[2][1] = d * j*m - b * l*m - d * i*n + a * l*n + b * i*p - a * j*p;
			adjMatrix[2][2] = -d * f*m + b * h*m + d * e*n - a * h*n - b * e*p + a * f*p;
			adjMatrix[2][3] = d * f*i - b * h*i - d * e*j + a * h*j + b * e*l - a * f*l;
			adjMatrix[3][0] = g * j*m - f * k*m - g * i*n + e * k*n + f * i*o - e * j*o;
			adjMatrix[3][1] = -c * j*m + b * k*m + c * i*n - a * k*n - b * i*o + a * j*o;
			adjMatrix[3][2] = c * f*m - b * g*m - c * e*n + a * g*n + b * e*o - a * f*o;
			adjMatrix[3][3] = -c * f*i + b * g*i + c * e*j - a * g*j - b * e*k + a * f*k;

			//Got adj, need to do inverse

			int s;
			s++;
			break;
		}
		case IDOK3:
		{
			//Setting up smaller matrices
			float values1[3][3];
			float values2[3][3];
			float values3[3][3];
			float values4[3][3];

			//Get matrix 1

			for (int i = 0; i < 3; ++i)
			{
				for (int j = 0; j < 3; ++j)
				{
					values1[i][j] = _values[i+1][j+1];
				}
			}

			//Get matrix 2
			for (int i = 0; i < 3; ++i)
			{
				for (int j = 0; j < 3; ++j)
				{
					if (j > 0)
					{
						values2[i][j] = _values[i + 1][j + 1];
					}
					else
					{
						values2[i][j] = _values[i+1][j];
					}
				}
			}

			//Get matrix 3
			for (int i = 0; i < 3; ++i)
			{
				for (int j = 0; j < 3; ++j)
				{
					if (j > 1)
					{
						values3[i][j] = _values[i + 1][j + 1];
					}
					else
					{
						values3[i][j] = _values[i + 1][j];
					}
				}
			}

			//Get matrix 4
			for (int i = 0; i < 3; ++i)
			{
				for (int j = 0; j < 3; ++j)
				{
					if (j > 2)
					{
						values4[i][j] = _values[i + 1][j + 1];
					}
					else
					{
						values4[i][j] = _values[i + 1][j];
					}
				}
			}
	

			

			//Get first determinant
			float det1 = _values[0][0] * (  (values1[0][0] * values1[1][1] * values1[2][2]) + 
				(values1[0][1] * values1[1][2] * values1[2][0]) +
				(values1[0][2] * values1[1][0] * values1[2][1]) -
				(values1[0][2] * values1[1][1] * values1[2][0]) -
				(values1[0][0] * values1[1][2] * values1[2][1]) -
				(values1[0][1] * values1[1][0] * values1[2][2]));

			//Get second determinant
			float det2 = -1* _values[0][1] * ((values2[0][0] * values2[1][1] * values2[2][2]) +
				(values2[0][1] * values2[1][2] * values2[2][0]) +
				(values2[0][2] * values2[1][0] * values2[2][1]) -
				(values2[0][2] * values2[1][1] * values2[2][0]) -
				(values2[0][0] * values2[1][2] * values2[2][1]) -
				(values2[0][1] * values2[1][0] * values2[2][2]));

			//Get third determinant
			float det3 = _values[0][2] * ((values3[0][0] * values3[1][1] * values3[2][2]) +
				(values3[0][1] * values3[1][2] * values3[2][0]) +
				(values3[0][2] * values3[1][0] * values3[2][1]) -
				(values3[0][2] * values3[1][1] * values3[2][0]) -
				(values3[0][0] * values3[1][2] * values3[2][1]) -
				(values3[0][1] * values3[1][0] * values3[2][2]));

			//Get fourth determinant
			float det4 = -1 * _values[0][3] * ((values4[0][0] * values4[1][1] * values4[2][2]) +
				(values4[0][1] * values4[1][2] * values4[2][0]) +
				(values4[0][2] * values4[1][0] * values4[2][1]) -
				(values4[0][2] * values4[1][1] * values4[2][0]) -
				(values4[0][0] * values4[1][2] * values4[2][1]) -
				(values4[0][1] * values4[1][0] * values4[2][2]));

			//Get the final determinant
			float finalDet = det1 + det2 + det3 + det4;

			//Output final determinant
			WriteToEditBox(_hwnd, IDC_EDIT_DetA, finalDet);

		}

		default:
			break;
		}
		return TRUE;
		break;
	}

	case WM_CLOSE:
	{
		MessageBox(_hwnd, ToWideString(_values[0][0]).c_str(), L"Value in A11", MB_OK);
		ShowWindow(_hwnd, SW_HIDE);
		return TRUE;
		break;
	}
	default:
		break;
	}
	return FALSE;
}

BOOL CALLBACK TransformationDlgProc(HWND _hwnd,
	UINT _msg,
	WPARAM _wparam,
	LPARAM _lparam)
{

	switch (_msg)
	{
	case WM_CLOSE:
	{
		ShowWindow(_hwnd, SW_HIDE);
		return TRUE;
		break;
	}
	default:
		break;
	}
	return FALSE;
}


BOOL CALLBACK GaussianDlgProc(HWND _hwnd,
	UINT _msg,
	WPARAM _wparam,
	LPARAM _lparam)
{

	switch (_msg)
	{
	case WM_CLOSE:
	{
		ShowWindow(_hwnd, SW_HIDE);
		return TRUE;
		break;
	}
	default:
		break;
	}
	return FALSE;
}


BOOL CALLBACK QuaternionDlgProc(HWND _hwnd,
	UINT _msg,
	WPARAM _wparam,
	LPARAM _lparam)
{

	switch (_msg)
	{
	case WM_CLOSE:
	{
		ShowWindow(_hwnd, SW_HIDE);
		return TRUE;
		break;
	}
	default:
		break;
	}
	return FALSE;
}

BOOL CALLBACK SLERPDlgProc(HWND _hwnd,
	UINT _msg,
	WPARAM _wparam,
	LPARAM _lparam)
{

	switch (_msg)
	{
	case WM_CLOSE:
	{
		ShowWindow(_hwnd, SW_HIDE);
		return TRUE;
		break;
	}
	default:
		break;
	}
	return FALSE;
}

int WINAPI WinMain(HINSTANCE _hInstance,
	HINSTANCE _hPrevInstance,
	LPSTR _lpCmdLine,
	int _nCmdShow)
{
	WNDCLASSEX winclass; // This will hold the class we create.
	HWND hwnd;           // Generic window handle.
	MSG msg;             // Generic message.

						 // First fill in the window class structure.
	winclass.cbSize = sizeof(WNDCLASSEX);
	winclass.style = CS_DBLCLKS | CS_OWNDC | CS_HREDRAW | CS_VREDRAW;
	winclass.lpfnWndProc = WindowProc;
	winclass.cbClsExtra = 0;
	winclass.cbWndExtra = 0;
	winclass.hInstance = _hInstance;
	winclass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	winclass.hCursor = LoadCursor(NULL, IDC_ARROW);
	winclass.hbrBackground =
		static_cast<HBRUSH>(GetStockObject(BLACK_BRUSH));
	winclass.lpszMenuName = NULL;
	winclass.lpszClassName = WINDOW_CLASS_NAME;
	winclass.hIconSm = LoadIcon(NULL, IDI_APPLICATION);

	// register the window class
	if (!RegisterClassEx(&winclass))
	{
		return (0);
	}

	//Laod the Menu
	g_hMenu = LoadMenu(_hInstance, MAKEINTRESOURCE(IDR_MENU1));

	// create the window
	hwnd = CreateWindowEx(NULL, // Extended style.
		WINDOW_CLASS_NAME,      // Class.
		L"Your Basic Window",   // Title.
		WS_OVERLAPPEDWINDOW | WS_VISIBLE,
		0, 0,                    // Initial x,y.
		400, 100,                // Initial width, height.
		NULL,                   // Handle to parent.
		g_hMenu,                   // Handle to menu.
		_hInstance,             // Instance of this application.
		NULL);                  // Extra creation parameters.

	if (!(hwnd))
	{
		return (0);
	}

	//Create the modeless dialog boxes for the calculators
	//Matrix Calculator
	g_hDlgMatrix = CreateDialog(_hInstance, MAKEINTRESOURCE(IDD_DialogMatrix), hwnd, (DLGPROC)MatrixDlgProc);
	g_hDlgTransformation = CreateDialog(_hInstance, MAKEINTRESOURCE(IDD_DialogTransformations), hwnd, (DLGPROC)TransformationDlgProc);
	g_hDlgGaussian = CreateDialog(_hInstance, MAKEINTRESOURCE(IDD_DialogGaussian), hwnd, (DLGPROC)GaussianDlgProc);
	g_hDlgQuaternion = CreateDialog(_hInstance, MAKEINTRESOURCE(IDD_DialogQuaternion), hwnd, (DLGPROC)QuaternionDlgProc);
	g_hDlgSLERP = CreateDialog(_hInstance, MAKEINTRESOURCE(IDD_DialogSLERP), hwnd, (DLGPROC)SLERPDlgProc);

	// Enter main event loop
	while (true)
	{
		// Test if there is a message in queue, if so get it.
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			// Test if this is a quit.
			if (msg.message == WM_QUIT)
			{
				break;
			}

			if ((g_hDlgMatrix == 0 && g_hDlgTransformation == 0 && g_hDlgGaussian == 0 && g_hDlgQuaternion == 0 && g_hDlgSLERP == 0) ||
				(!IsDialogMessage(g_hDlgMatrix, &msg) && !IsDialogMessage(g_hDlgTransformation, &msg) && !IsDialogMessage(g_hDlgGaussian, &msg) && !IsDialogMessage(g_hDlgQuaternion, &msg) && !IsDialogMessage(g_hDlgSLERP, &msg)))
			{
				// Translate any accelerator keys.
				TranslateMessage(&msg);
				// Send the message to the window proc.
				DispatchMessage(&msg);
			}
		}

		// Main game processing goes here.
		GameLoop(); //One frame of game logic occurs here...
	}

	// Return to Windows like this...
	return (static_cast<int>(msg.wParam));
}


