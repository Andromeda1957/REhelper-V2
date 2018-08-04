// Copyright 2018 <Andromeda>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <defaults.h>
#include <pickone.h>
#include <picktwo.h>
#include <pickthree.h>
#include <options.h>

REhelp::REhelp() {}

// Public methods

void REhelp::pick1(const char *option) {
    pickOne pick;

    if (strncmp(option, "--ascii", max) == 0) {
        pick.ascii_table();
    } else if (strncmp(option, "--aslr", max) == 0) {
        pick.aslr();
    } else if (strncmp(option, "--no-aslr", max) == 0) {
        pick.no_aslr();
    } else if (strncmp(option, "--no-time", max) == 0) {
        pick.no_time();
    } else if (strncmp(option, "--version", max) == 0) {
        pick.version();
    } else if (strncmp(option, "--ptrace", max) == 0) {
        pick.trace();
    } else if (strncmp(option, "--break", max) == 0) {
        pick.breakpoint();
    } else if (strncmp(option, "--back", max) == 0) {
        pick.background();
    } else if (strncmp(option, "--crash", max) == 0) {
        pick.crash();
    } else {
        usage();
    }
}

void REhelp::pick2(const char *option, const char *input) {
    pickTwo pick;

    if (strncmp(option, "--reverse", max) == 0) {
        pick.reverse(input);
    } else if (strncmp(option, "--magic", max) == 0) {
        pick.magic(input);
    } else if (strncmp(option, "--stack", max) == 0) {
        pick.dump_stack(input);
    } else if (strncmp(option, "--status", max) == 0) {
        pick.dump_status(input);
    } else if (strncmp(option, "--io", max) == 0) {
        pick.dump_io(input);
    } else if (strncmp(option, "--maps", max) == 0) {
        pick.dump_maps(input);
    } else if (strncmp(option, "--limits", max) == 0) {
        pick.dump_limits(input);
    } else if (strncmp(option, "--clone", max) == 0) {
        pick.dump_clone(input);
    } else if (strncmp(option, "--add", max) == 0) {
        pick.add(input);
    } else if (strncmp(option, "--mult", max) == 0) {
        pick.mult(input);
    } else if (strncmp(option, "--xors", max) == 0) {
        pick.xors(input);
    } else if (strncmp(option, "--base64e", max) == 0) {
        pick.base64encode(input);
    } else if (strncmp(option, "--base64d", max) == 0) {
        pick.base64decode(input);
    } else if (strncmp(option, "--md5", max) == 0) {
        pick.getmd5(input);
    } else if (strncmp(option, "--sha1", max) == 0) {
        pick.getsha1(input);
    } else if (strncmp(option, "--sha256", max) == 0) {
        pick.getsha256(input);
    } else if (strncmp(option, "--sha384", max) == 0) {
        pick.getsha384(input);
    } else if (strncmp(option, "--sha512", max) == 0) {
        pick.getsha512(input);
    } else {
        usage();
    }
}

void REhelp::pick3(const char *option, const char *input,
const char *value_str) {
    const int value = atoi(value_str);

    pickThree pick;

    if (strncmp(option, "--pattern", max) == 0) {
        pick.pattern(input, value);
    } else if (strncmp(option, "--sub", max) == 0) {
        pick.sub(input, value);
    } else if (strncmp(option, "--shift", max) == 0) {
        pick.shift(input, value);
    } else if (strncmp(option, "--xor", max) == 0) {
        pick.xoring(input, value);
    } else {
        usage();
    }
}
