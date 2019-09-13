// SelfDebugging.c
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <windows.h>

int successfulDebugging = -1;

// Method for parent to spawn and debug child process
void spawnAndDebugChild() {
    HANDLE hProcess = NULL;
    PROCESS_INFORMATION pi;
    STARTUPINFO si;
    ZeroMemory(&pi, sizeof(PROCESS_INFORMATION));
    ZeroMemory(&si, sizeof(STARTUPINFO));

    GetStartupInfo(&si);
    char commandArgs[1024];
    sprintf(commandArgs,"%s %d",GetCommandLine(), (int) GetCurrentProcessId());

    CreateProcess(NULL, commandArgs, NULL, NULL, FALSE,
        DEBUG_PROCESS, NULL, NULL, &si, &pi);
}

// Parent program
void executeParentProgram() {
    spawnAndDebugChild();
    DEBUG_EVENT DbgEvent;

    while(1) {
        WaitForDebugEvent(&DbgEvent, INFINITE);

        if (DbgEvent.dwDebugEventCode == EXIT_PROCESS_DEBUG_EVENT) {
            ExitProcess(-1);
        } else if (DbgEvent.dwDebugEventCode == OUTPUT_DEBUG_STRING_EVENT) {
            printf("this is the malicious payload");
            ExitProcess(0);
        }

        ContinueDebugEvent(DbgEvent.dwProcessId, DbgEvent.dwThreadId, DBG_CONTINUE);
    }
}

// Method for child to debug parent
void *debugParent (void *pid_void_ptr) {
    DWORD *pid_ptr = (DWORD *)pid_void_ptr;
    successfulDebugging = DebugActiveProcess(*pid_ptr);

    DEBUG_EVENT DbgEvent;

    while(1) {
        WaitForDebugEvent(&DbgEvent, INFINITE);
        ContinueDebugEvent(DbgEvent.dwProcessId, DbgEvent.dwThreadId, DBG_CONTINUE);
    }
}

// Child program
void executeChildProgram(DWORD pid) {
    pthread_t debugParentThread;
    pthread_create(&debugParentThread, NULL, debugParent, &pid);

    // Update debugging status for parent thread
    while (successfulDebugging == -1) {
        if (successfulDebugging == 0) {
            ExitProcess(-1);
        } else {
            OutputDebugString("success");
        }
    }

    pthread_join(debugParentThread, NULL);
}

void main(int argc, char *argv[]) {
    if (argc > 1) {
        executeChildProgram((DWORD) atoi(argv[1]));
    } else {
        executeParentProgram();
    }
}
