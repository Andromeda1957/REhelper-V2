#include <../headers/options.h>

int main(int argc, char **argv){
    REhelp options;

    switch(argc){
        case 2:
            options.pick1(argv[1]);
        case 3:
            options.pick2(argv[1], argv[2]);
        case 4:
            options.pick3(argv[1], argv[2], argv[3]);
        default:
            options.usage();
        }

    return 0;
}
