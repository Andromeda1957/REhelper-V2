// Copyright 2018 <Andromeda>

#include <defaults.h>
#include <pickone.h>
#include <picktwo.h>
#include <pickthree.h>
#include <options.h>

int main(int argc, char **argv) {
    REhelp options;

    switch (argc) {
        case 2:
            options.pick1(argv[1]);
            return 0;
        case 3:
            options.pick2(argv[1], argv[2]);
            return 0;
        case 4:
            options.pick3(argv[1], argv[2], argv[3]);
            return 0;
        default:
            options.usage();
        }

    return 1;
}
