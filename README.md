# anti-analysis

demo of anti-analysis techniques (can be used by malware)

anti-debugging:
- DebuggerCheck - checks for invasive debuggers
- FindWindow - checks for active debugger windows
- Self-debugging - debug the current process using a child process; debuggers cannot attach unless in kernel-mode

anti-VM:
- RegQueryVBox - queries the registry for vbox entries
