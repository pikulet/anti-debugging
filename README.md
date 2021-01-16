# :dagger: anti-analysis :dagger:

This is a collection of anti-analysis techniques and their corresponding API calls.

Anti-debugging:
- DebuggerCheck - checks for invasive debuggers
- FindWindow - checks for active debugger windows
- Self-debugging - debug the current process using a child process; debuggers cannot attach unless in kernel-mode

Anti-VM:
- RegQueryVBox - queries the registry for vbox entries

## :dolphin: Getting Started

If you want to learn more about these techniques, I recommend compiling the binaries and observing their behaviour under various debuggers. For instance, you can verify that these binaries cannot be debugged by user-mode debuggers like OllyDbg. You can also observe other parts of the malware like its EPROCESS -> DebugPort. For this task, you would need a kernel-mode debugger like WinDbg to debug your VM.
