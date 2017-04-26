#include<iostream>
#include<Windows.h>

using namespace std;
int main()
{
	int newValue = 40000;
	HWND hwnd = FindWindowA(NULL,"Command & Conquer(tm) 3: Kane's Wrath");
	if (hwnd == NULL)
	{
		cout << "ERROR : Cannot find window." << endl;
		Sleep(3000);
		exit(-1);
	}
	else
	{
		DWORD procID;
		GetWindowThreadProcessId(hwnd, &procID);
		HANDLE handle = OpenProcess(PROCESS_ALL_ACCESS,FALSE,procID);

		if (procID = NULL)
		{
			cout << "ERROR : Cannot obtain process." << endl;
			Sleep(3000);
			exit(-1);
		}
		else
		{
			cout << "HACKING_SUCCESSFUL" << endl;
			while(true)
			{
				if (GetAsyncKeyState(0x47))
				{
					WriteProcessMemory(handle, (LPVOID)0x1D0D8F68, &newValue, sizeof(newValue), 0);
					WriteProcessMemory(handle, (LPVOID)0x10FC72FC, &newValue, sizeof(newValue), 0);
					cout <<"Now Money = "<< newValue << endl;

					newValue+=2000;
				}
				if (GetAsyncKeyState(0x4A))
				{
					WriteProcessMemory(handle, (LPVOID)0x1D0D8F68, &newValue, sizeof(newValue), 0);
					WriteProcessMemory(handle, (LPVOID)0x10FC72FC, &newValue, sizeof(newValue), 0);
					cout << "Now Money = " << newValue << endl;
					newValue -= 2000;
				}
				Sleep(1);
			}
		}
	}
	return 0;
}