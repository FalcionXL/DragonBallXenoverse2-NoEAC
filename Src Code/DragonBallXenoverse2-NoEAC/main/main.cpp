#include <Windows.h>
#include <iostream>
using namespace std;
#pragma warning(disable : 6031 6387);

bool BypassEAC() 
{
	ReplaceFileA((LPCSTR)"R:\\Program Files (x86)\\Steam\\steamapps\\common\\DB Xenoverse 2\\START.exe", (LPCSTR)"R:\\Program Files(x86)\\Steam\\steamapps\\common\\DB Xenoverse 2\\START_Original.exe", 0, REPLACEFILE_IGNORE_MERGE_ERRORS, 0, 0); //Ignoring Merge Errors :D
	DeleteFileA((LPCSTR)"R:\\Program Files (x86)\\Steam\\steamapps\\common\\DB Xenoverse 2\\START.exe"); //If u have Another Volume Letter, Please Change This!!!
	return true;
}
void LaunchDBX2WithoutEAC() 
{
	cout << "Launching DBX 2 Without EAC..." << endl;
	STARTUPINFO si;
	PROCESS_INFORMATION pi;
	// set the size of the structures
	ZeroMemory(&si, sizeof(si));
	si.cb = sizeof(si);
	ZeroMemory(&pi, sizeof(pi));

	// start the program up
	CreateProcessW((LPCWSTR)L"R:\\Program Files (x86)\\Steam\\steamapps\\common\\DB Xenoverse 2\\bin\\DBXV2.exe",   // the path
		0,        // Command line
		NULL,           // Process handle not inheritable
		NULL,           // Thread handle not inheritable
		FALSE,          // Set handle inheritance to FALSE
		0,              // No creation flags
		NULL,           // Use parent's environment block
		NULL,           // Use parent's starting directory 
		&si,            // Pointer to STARTUPINFO structure
		&pi             // Pointer to PROCESS_INFORMATION structure (removed extra parentheses)
	);
	// Close process and thread handles. 
	CloseHandle(pi.hProcess);
	CloseHandle(pi.hThread);
}

int main() 
{
	if (BypassEAC() != true) 
	{
		cout << "File is Totally Renamed \n";
		Sleep(5000);
	}
	else
	{
		cout << "File is Renamed or Deleted..." << endl;
		Sleep(10000);
		getchar();
		LaunchDBX2WithoutEAC();
	}
	HMODULE module = LoadLibraryA((LPCSTR)"ntdll.dll");
	FARPROC process = GetProcAddress(module, "NtOpenProcess");
	cout << "Address of NtOpenProcess: 0x" << process << std::hex << endl;
	Sleep(2100);
	return 0;
}