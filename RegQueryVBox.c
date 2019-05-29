#include <stdio.h>
#include <stdlib.h>

#define REG_QUERY "REG QUERY HKLM\\SYSTEM\\CurrentControlSet\\Control\\VirtualDeviceDrivers"

int main() {
    int i = system(REG_QUERY);
    if (i == 0) {
        printf("virtualbox detected");
    } else {
        printf("no virtualbox detected");
    }

    return 0;
}

