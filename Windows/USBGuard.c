#include "USBGuard.h"

void quit() /* write error message and quit */
{
    fprintf(stderr, "memory exhausted\n");
    exit(1);
}

int main()
{
    int max = 20;
    char* name = (char*) malloc(max); /* allocate buffer */
    if (name == 0) quit();

    if (!IsElevated()) {
        printf("Exiting: USBGuard requires elevated privilages to edit registry values.\n");
        return 1;
    }

    printf(
        "\n Welcome to USBGuard!\n\n"

        "1) Disable all USB ports - Safest\n"
        "2) Whitelist certain devices - Compromise\n"
        "3) Enable all USB ports - Least Safe\n"
        "\nPlease choose a task: ");

    while (1) { /* skip leading whitespace */
        int c = getchar();
        if (c == EOF) break; /* end of file */
        if (!isspace(c)) {
             ungetc(c, stdin);
             break;
        }
    }

    int i = 0;
    while (1) {
        int c = getchar();
        if (isspace(c) || c == EOF) { /* at end, add terminating zero */
            name[i] = 0;
            break;
        }
        name[i] = c;
        if (i == max - 1) { /* buffer full */
            max += max;
            name = (char*) realloc(name, max); /* get a new and larger buffer */
            if (name == 0) quit();
        }
        i++;
    }

    // Handle options
    switch( atoi(name) ) {
        case 1:
            printf("\n%s\n", "[*] Disabling all usb ports...");
            DisableUSBDevices();
            break;
        case 2:
            printf("\n%s\n", "[*] Entering whitelist utility...");
            PrintDevices();
            break;
        case 3:
            printf("\n%s\n", "[*] Enabling all usb ports...");
            EnableUSBDevices();
            break;
        default:
            printf("\n%s\n", "[*] Could not interpret the provided option.");
            break;
    }

    // Release memory
    free(name); 


    return 0;
}