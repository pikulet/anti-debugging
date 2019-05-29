#include <stdio.h>
#include <stdlib.h>

#define REG_QUERY "REG QUERY HKLM\\SOFTWARE\\Microsoft\\PowerShell\\1\\PowerShellEngine /s"

int main() {
    int i = system(REG_QUERY);
    printf("System returned: %d", i);

    return 0;
}
