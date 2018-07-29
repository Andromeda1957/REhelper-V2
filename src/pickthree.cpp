// Copyright 2018 <Andromeda>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <../headers/defaults.h>
#include <../headers/pickthree.h>

#include <vector>

pickThree::pickThree() {}

// Public methods

void pickThree::pattern(char *user_input, int value) {
    for (int i = 0; i < value; i++) {
        printf("%s", user_input);
    }

    puts("");
}

void pickThree::sub(char *user_input, int value) {
    const int length = strnlen(user_input, defaults::max) - 1;

    for (int i = 0; i <= length; i++) {
        value = value - user_input[i];
    }

    printf("Decimal value: %d", value);
    puts("");
    printf("Hex value:     0x%x", value);
    puts("");
}

void pickThree::shift(char *user_input, int shift) {
    const int length = strnlen(user_input, defaults::max) - 1;
    std::vector<char> rightshifted(defaults::max);
    std::vector<char> leftshifted(defaults::max);

    leftshifted[length + 1] = '\0';
    rightshifted[length + 1] = '\0';
    printf("Shifted right: 0x");

    for (int i = 0; i <= length; i++) {
        rightshifted[i] = user_input[i] >> shift;
        printf("%x", rightshifted[i]);
    }

    puts("");
    printf("Shifted left:  0x");

    for (int e = 0; e <= length; e++) {
        leftshifted[e] = user_input[e] << shift;
        printf("%x", leftshifted[e]);
    }

    puts("");
}

void pickThree::xoring(char *user_input, int xors) {
    const int length = strnlen(user_input, defaults::max) - 1;
    std::vector<char> xored(defaults::max);

    printf("Hex value: 0x");

    for (int i = 0; i <= length; i++) {
        xored[i] = user_input[i] ^ xors;
        printf("%x", xored[i]);
    }

    xored[length + 1] = '\0';
    puts("");
    printf("String:    ");
    printf("%s\n", xored);
}
