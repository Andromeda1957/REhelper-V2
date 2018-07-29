// Copyright 2018 <Andromeda>
#ifndef CODE___REHELP_HEADERS_OPTIONS_H_
#define CODE___REHELP_HEADERS_OPTIONS_H_
#endif  // CODE___REHELP_HEADERS_OPTIONS_H_

#include <assert.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <openssl/bio.h>
#include <openssl/evp.h>
#include <openssl/md5.h>
#include <openssl/sha.h>
#include <sys/ptrace.h>
#include <sys/utsname.h>

#include <../headers/defaults.h>
#include <../headers/pickone.h>
#include <../headers/picktwo.h>
#include <../headers/pickthree.h>

struct REhelp : public defaults, protected pickOne,
protected pickTwo, protected pickThree {
    void pick1(char *option) {
        if (strncmp(option, "--ascii", max) == 0) {
            ascii_table();
        } else if (strncmp(option, "--aslr", max) == 0) {
            aslr();
        } else if (strncmp(option, "--no-aslr", max) == 0) {
            no_aslr();
        } else if (strncmp(option, "--no-time", max) == 0) {
            no_time();
        } else if (strncmp(option, "--version", max) == 0) {
            version();
        } else if (strncmp(option, "--ptrace", max) == 0) {
            trace();
        } else if (strncmp(option, "--break", max) == 0) {
            breakpoint();
        } else if (strncmp(option, "--back", max) == 0) {
            background();
        } else if (strncmp(option, "--crash", max) == 0) {
            crash();
        } else {
            usage();
        }

        exit(0);
    }

    void pick2(char *option, char *input) {
        if (strncmp(option, "--reverse", max) == 0) {
            reverse(input);
        } else if (strncmp(option, "--magic", max) == 0) {
            magic(input);
        } else if (strncmp(option, "--stack", max) == 0) {
            dump_stack(input);
        } else if (strncmp(option, "--status", max) == 0) {
            dump_status(input);
        } else if (strncmp(option, "--io", max) == 0) {
            dump_io(input);
        } else if (strncmp(option, "--maps", max) == 0) {
            dump_maps(input);
        } else if (strncmp(option, "--limits", max) == 0) {
            dump_limits(input);
        } else if (strncmp(option, "--clone", max) == 0) {
            dump_clone(input);
        } else if (strncmp(option, "--add", max) == 0) {
            add(input);
        } else if (strncmp(option, "--mult", max) == 0) {
            mult(input);
        } else if (strncmp(option, "--xors", max) == 0) {
            xors(input);
        } else if (strncmp(option, "--base64e", max) == 0) {
            base64encode(input);
        } else if (strncmp(option, "--base64d", max) == 0) {
            base64decode(input);
        } else if (strncmp(option, "--md5", max) == 0) {
            getmd5(input);
        } else if (strncmp(option, "--sha1", max) == 0) {
            getsha1(input);
        } else if (strncmp(option, "--sha256", max) == 0) {
            getsha256(input);
        } else if (strncmp(option, "--sha384", max) == 0) {
            getsha384(input);
        } else if (strncmp(option, "--sha512", max) == 0) {
            getsha512(input);
        } else {
            usage();
        }

        exit(0);
    }

    void pick3(char *option, char *input, char *value_str) {
        int value = atoi(value_str);

        if (strncmp(option, "--pattern", max) == 0) {
            pattern(input, value);
        } else if (strncmp(option, "--sub", max) == 0) {
            sub(input, value);
        } else if (strncmp(option, "--shift", max) == 0) {
            shift(input, value);
        } else if (strncmp(option, "--xor", max) == 0) {
            xoring(input, value);
        } else {
            usage();
        }

        exit(0);
    }
};
