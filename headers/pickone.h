class pickOne{
    static void sig_handler(int signo){
        exit(0);
    }

    static void detect(){
        if(ptrace(PTRACE_TRACEME, 0, NULL, NULL) == -1) {
            puts("Debugger detected!");
            exit(0);
        }else{
            return;
        }
    }

protected:
    static void breakpoint(){
        printf("Breakpoint hit at: %p\n", breakpoint);
        __asm__("int $3");
    }

protected:
    void ascii_table(){
        char output[defaults::max];

        for(int i = 0x20; i <= 0x7f; i++){
            output[0] = i;
            printf("Hex value:   %x\n", i);
            printf("Ascii value: %c\n", output[0]);
            puts("");
        }
    }

    void aslr(){
        system("echo 2 | sudo tee /proc/sys/kernel/randomize_va_space");
    }

    void no_aslr(){
        system("echo 0 | sudo tee /proc/sys/kernel/randomize_va_space");
    }

    void no_time(){
        signal(SIGINT, sig_handler);

        for(;;){
            system("date -s '06 JUL 2018 12:00:00'");
            usleep(30000);
        }
    }

    void version(){
        utsname versionData;

        uname(&versionData);
        printf("System:  %s\n", versionData.sysname);
        printf("Distro:  %s\n", versionData.nodename);
        printf("Release: %s\n", versionData.release);
        printf("Version: %s\n", versionData.version);
        printf("Machine: %s\n", versionData.machine);
    }

    void trace(){
        if(ptrace(PTRACE_TRACEME, 0, NULL, NULL) == -1) {
            puts("Debugger detected!");
        }else{
            puts("No debugger detected");
        }
    }

    void background(){
        detect();
        __asm__("int $3");
    }

    void crash(){
        __asm__("push $0xff");
    }
};
