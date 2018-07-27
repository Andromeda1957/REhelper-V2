class pickOne{
private:
    static void ascii_table(){
        char output[defaults::max];

        for(int i = 0x20; i <= 0x7f; i++){
            output[0] = i;
            printf("Hex value:   %x\n", i);
            printf("Ascii value: %c\n", output[0]);
            printf("\n");
        }

        defaults::quit();
    }

    static void aslr(){
        system("echo 2 | sudo tee /proc/sys/kernel/randomize_va_space");
        defaults::quit();
    }

    static void no_aslr(){
        system("echo 0 | sudo tee /proc/sys/kernel/randomize_va_space");
        defaults::quit();
    }

    static void sig_handler(int signo){
        defaults::quit();
    }

    static void no_time(){
        signal(SIGINT, sig_handler);

        for(;;){
            system("date -s '06 JUL 2018 12:00:00'");
            usleep(30000);
        }

        defaults::quit();
    }

    static void version(){
        struct utsname versionData;

        uname(&versionData);
        printf("System:  %s\n", versionData.sysname);
        printf("Distro:  %s\n", versionData.nodename);
        printf("Release: %s\n", versionData.release);
        printf("Version: %s\n", versionData.version);
        printf("Machine: %s\n", versionData.machine);
        defaults::quit();
    }

    static void trace(){
        if(ptrace(PTRACE_TRACEME, 0, NULL, NULL) == -1) {
            printf("Debugger detected!\n");
        }else{
            printf("No debugger detected\n");
        }

        defaults::quit();
    }

    static void breakpoint(){
        printf("Breakpoint hit at: %p\n", breakpoint);
        __asm__("int $3");
    }

    static void detect(){
        if(ptrace(PTRACE_TRACEME, 0, NULL, NULL) == -1) {
            printf("Debugger detected!\n");
            defaults::quit();
        }else{
            return;
        }
    }

    static void background(){
        detect();
        __asm__("int $3");
    }

    static void crash(){
        __asm__("push $0xff");
    }


public:
    static void options(char *option){
        if(strncmp(option, "--ascii", defaults::max) == 0){
            ascii_table();
        }else if(strncmp(option, "--aslr", defaults::max) == 0){
            aslr();
        }else if(strncmp(option, "--no-aslr", defaults::max) == 0){
            no_aslr();
        }else if(strncmp(option, "--no-time", defaults::max) == 0){
            no_time();
        }else if(strncmp(option, "--version", defaults::max) == 0){
            version();
        }else if(strncmp(option, "--ptrace", defaults::max) == 0){
            trace();
        }else if(strncmp(option, "--break", defaults::max) == 0){
            breakpoint();
        }else if(strncmp(option, "--back", defaults::max) == 0){
            background();
        }else if(strncmp(option, "--crash", defaults::max) == 0){
            crash();
        }else{
            return;
        }
    }
};