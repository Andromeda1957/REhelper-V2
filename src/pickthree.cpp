// Copyright 2018 <Andromeda>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <../headers/defaults.h>
#include <../headers/pickthree.h>

pickThree::pickThree(){}

void pickThree::pattern(char *user_input, int value) {
    for (int i = 0; i < value; i++) {
        printf("%s", user_input);
    }

    puts("");
}

void pickThree::sub(char *user_input, int value) {
    int length = strnlen(user_input, defaults::max) - 1;

    for (int i = 0; i <= length; i++) {
        value = value - user_input[i];
    }

    printf("Decimal value: %d", value);
    puts("");
    printf("Hex value:     0x%x", value);
    puts("");
}

void pickThree::shift(char *user_input, int shift) {
    int length = strnlen(user_input, defaults::max) - 1;
    char *rightshifted = new char[defaults::max];
    char *leftshifted = new char[defaults::max];

    leftshifted[length + 1] = '\0';
    rightshifted[length + 1] = '\0';
    printf("Shifted right: ");

    for (int i = 0; i <= length; i++) {
        rightshifted[i] = user_input[i] >> shift;
        printf("%x", rightshifted[i]);
    }

    puts("");
    printf("Shifted left:  ");

    for (int e = 0; e <= length; e++) {
        leftshifted[e] = user_input[e] << shift;
        printf("%x", leftshifted[e]);
    }

    puts("");
    delete rightshifted;
    delete leftshifted;
}

void pickThree::xoring(char *user_input, int xors) {
    int length = strnlen(user_input, defaults::max) - 1;
    char *xored = new char[defaults::max];

    printf("Hex value: ");

    for (int i = 0; i <= length; i++) {
        xored[i] = user_input[i] ^ xors;
        printf("0x%x", xored[i]);
    }

    xored[length + 1] = '\0';
    puts("");
    printf("String:    ");
    puts(xored);
    delete xored;
}
