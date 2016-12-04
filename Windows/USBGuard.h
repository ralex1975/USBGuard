#include <windows.h>
#include <stdio.h>
#include <tchar.h>

#include <ctype.h>
#include <stdlib.h>

// wchar_t type
#include <wchar.h>




// -----------------------------------------------------------------
// DeviceManagement.c Functions
// -----------------------------------------------------------------

void PrintDevices();		// Print all stored USB devices

int DisableUSBDevices();	// Disable all USB Devices

int EnableUSBDevices();		// Enable all USB Devices

// -----------------------------------------------------------------
// Tools
// -----------------------------------------------------------------

BOOL IsElevated(); 			// Checks if the program is elevated - Privilages.c

void QueryKey(HKEY hKey); 	// Query the registry key for all subitems - EnumRegistry.c

const char * GetLastErrorAsString(); 	// Return the last error as a string