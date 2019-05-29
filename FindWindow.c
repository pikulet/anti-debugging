#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

int main() {
    while(1) {
        HANDLE hOlly = FindWindow(TEXT("OLLYDBG"), NULL);

        if(hOlly) {
            printf("OllyDbg is open!");
            ExitProcess(0); 
        }
    }
}

