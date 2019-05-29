#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

int main() {
    while (1) {
        if (IsDebuggerPresent()) {
            printf("there is a debugger");
        }
    }

    return 0;
}

