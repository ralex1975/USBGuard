# USBGuard

### Overview

Personal computer USB port management, not intended for scale. The approach is a little different on every platform.

### Windows

The windows version disables system USB ports/devices using the registry values stored in 

```
HKEY_LOCAL_MACHINE\\SYSTEM\\CurrentControlSet\\Enum\\USB

HKEY_LOCAL_MACHINE\\SYSTEM\\CurrentControlSet\\Enum\\USBSTOR
```

A usefull reference for the technique is the Microsoft documentation:

1. [USB Device Registry Entries](https://msdn.microsoft.com/en-us/library/windows/hardware/jj649944(v=vs.85).aspx)

2. [USB Device Descriptors](https://msdn.microsoft.com/en-us/library/windows/hardware/ff539283(v=vs.85).aspx)

<b> Not finished yet, right now you can only fully enable or fully disable USB ports, no inbetween. </b>

### Linux

Coming soon.
