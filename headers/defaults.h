struct defaults{
    static int max;

    static void quit(){
        exit(0);
    }
};

int defaults::max = 0xff;