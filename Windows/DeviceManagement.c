#include "USBGuard.h"

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

int DisableUSBDevices() {
	
}