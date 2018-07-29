// Copyright 2018 <Andromeda>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <../headers/defaults.h>
#include <../headers/pickone.h>
#include <../headers/picktwo.h>
#include <../headers/pickthree.h>
#include <../headers/options.h>

REhelp::REhelp(){}

void REhelp::pick1(char *option) {
    defaults de;
    pickOne pick;

    if (strncmp(option, "--ascii", de.max) == 0) {
        pick.ascii_table();
    } else if (strncmp(option, "--aslr", de.max) == 0) {
        pick.aslr();
    } else if (strncmp(option, "--no-aslr", de.max) == 0) {
        pick.no_aslr();
    } else if (strncmp(option, "--no-time", de.max) == 0) {
        pick.no_time();
    } else if (strncmp(option, "--version", de.max) == 0) {
        pick.version();
    } else if (strncmp(option, "--ptrace", de.max) == 0) {
        pick.trace();
    } else if (strncmp(option, "--break", de.max) == 0) {
        pick.breakpoint();
    } else if (strncmp(option, "--back", de.max) == 0) {
        pick.background();
    } else if (strncmp(option, "--crash", de.max) == 0) {
        pick.crash();
    } else {
        de.usage();
    }

    exit(0);
}

void REhelp::pick2(char *option, char *input) {
    defaults de;
    pickTwo pick;

    if (strncmp(option, "--reverse", de.max) == 0) {
        pick.reverse(input);
    } else if (strncmp(option, "--magic", de.max) == 0) {
        pick.magic(input);
    } else if (strncmp(option, "--stack", de.max) == 0) {
        pick.dump_stack(input);
    } else if (strncmp(option, "--status", de.max) == 0) {
        pick.dump_status(input);
    } else if (strncmp(option, "--io", de.max) == 0) {
        pick.dump_io(input);
    } else if (strncmp(option, "--maps", de.max) == 0) {
        pick.dump_maps(input);
    } else if (strncmp(option, "--limits", de.max) == 0) {
        pick.dump_limits(input);
    } else if (strncmp(option, "--clone", de.max) == 0) {
        pick.dump_clone(input);
    } else if (strncmp(option, "--add", de.max) == 0) {
        pick.add(input);
    } else if (strncmp(option, "--mult", de.max) == 0) {
        pick.mult(input);
    } else if (strncmp(option, "--xors", de.max) == 0) {
        pick.xors(input);
    } else if (strncmp(option, "--base64e", de.max) == 0) {
        pick.base64encode(input);
    } else if (strncmp(option, "--base64d", de.max) == 0) {
        pick.base64decode(input);
    } else if (strncmp(option, "--md5", de.max) == 0) {
        pick.getmd5(input);
    } else if (strncmp(option, "--sha1", de.max) == 0) {
        pick.getsha1(input);
    } else if (strncmp(option, "--sha256", de.max) == 0) {
        pick.getsha256(input);
    } else if (strncmp(option, "--sha384", de.max) == 0) {
        pick.getsha384(input);
    } else if (strncmp(option, "--sha512", de.max) == 0) {
        pick.getsha512(input);
    } else {
        de.usage();
    }

    exit(0);
}

void REhelp::pick3(char *option, char *input, char *value_str) {
    defaults de;
    pickThree pick;

    int value = atoi(value_str);

    if (strncmp(option, "--pattern", de.max) == 0) {
        pick.pattern(input, value);
    } else if (strncmp(option, "--sub", de.max) == 0) {
        pick.sub(input, value);
    } else if (strncmp(option, "--shift", de.max) == 0) {
        pick.shift(input, value);
    } else if (strncmp(option, "--xor", de.max) == 0) {
        pick.xoring(input, value);
    } else {
        de.usage();
    }

    exit(0);
}
