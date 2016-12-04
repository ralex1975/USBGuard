#include "USBGuard.h"

#define USBSTOR_BASE L"SYSTEM\\CurrentControlSet\\Services\\USBSTOR"
#define USBSTOR_ENUM L"SYSTEM\\CurrentControlSet\\Services\\USBSTOR\\Enum"

void PrintDevices()
{
   HKEY hTestKey;

   if( RegOpenKeyEx( HKEY_LOCAL_MACHINE,
        TEXT("SYSTEM\\CurrentControlSet\\Enum\\USB"),
        0,
        KEY_READ,
        &hTestKey) == ERROR_SUCCESS
      )
   {
      QueryKey(hTestKey);
   }
   
   RegCloseKey(hTestKey);
}

int SetRegistryValue(DWORD value, wchar_t * path, int path_size, wchar_t * variable, int var_size) {

	HKEY key;

	wchar_t PATH_V[path_size];
	wcsncpy(PATH_V, path, path_size);

	wchar_t VAR_V[var_size];
	wcsncpy(VAR_V, variable, var_size);

	//wprintf(L"%s\n", PATH_V);

    if (RegOpenKeyExW(HKEY_LOCAL_MACHINE, (LPCWSTR)PATH_V, 0, KEY_SET_VALUE | KEY_WOW64_64KEY, &key) == ERROR_SUCCESS)
    {
        printf("[+] Key location open successful \n");
        if (RegSetValueExW(key, VAR_V, 0, REG_DWORD, (LPBYTE)&value, sizeof(DWORD)) == ERROR_SUCCESS)
        {
            printf("[+] Key changed in registry \n");
        }
        else{
            printf("[-] Key not changed in registry \n");
            printf("[-] Error %u ", (unsigned int)GetLastError());
        }
        RegCloseKey(key);
    }
    else 
    {
        printf("[-] Unsuccessful in opening key  \n");
        printf("[-] Please run with Admin privilages to edit registry values \n");
        printf("[-] Error: %u ", (unsigned int)GetLastError());
    }

    return 0;
}

int DisableUSBDevices() {
	DWORD number = 0x00000004; 

	SetRegistryValue(number, USBSTOR_BASE, 44, L"Start", 5);

	return 0;
    
}

int EnableUSBDevices() {
	DWORD number = 0x00000003;

	SetRegistryValue(number, USBSTOR_BASE, 44, L"Start", 5);

	return 0;
}