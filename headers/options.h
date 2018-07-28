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

struct REhelp : public defaults, protected pickOne, protected pickTwo, protected pickThree{
    void pick1(char *option){
        if(strncmp(option, "--ascii", max) == 0){
            ascii_table();
        }else if(strncmp(option, "--aslr", max) == 0){
            aslr();
        }else if(strncmp(option, "--no-aslr", max) == 0){
            no_aslr();
        }else if(strncmp(option, "--no-time", max) == 0){
            no_time();
        }else if(strncmp(option, "--version", max) == 0){
            version();
        }else if(strncmp(option, "--ptrace", max) == 0){
            trace();
        }else if(strncmp(option, "--break", max) == 0){
            breakpoint();
        }else if(strncmp(option, "--back", max) == 0){
            background();
        }else if(strncmp(option, "--crash", max) == 0){
            crash();
        }else{
            usage();
        }

        exit(0);
    }

    void pick2(char *option, char *string){
        if(strncmp(option, "--reverse", max) == 0){
            reverse(string);
        }else if(strncmp(option, "--magic", max) == 0){
            magic(string);
        }else if(strncmp(option, "--stack", max) == 0){
            dump_stack(string);
        }else if(strncmp(option, "--status", max) == 0){
            dump_status(string);
        }else if(strncmp(option, "--io", max) == 0){
            dump_io(string);
        }else if(strncmp(option, "--maps", max) == 0){
            dump_maps(string);
        }else if(strncmp(option, "--limits", max) == 0){
            dump_limits(string);
        }else if(strncmp(option, "--clone", max) == 0){
            dump_clone(string);
        }else if(strncmp(option, "--add", max) == 0){
            add(string);
        }else if(strncmp(option, "--mult", max) == 0){
            mult(string);
        }else if(strncmp(option, "--xors", max) == 0){
            xors(string);
        }else if(strncmp(option, "--base64e", max) == 0){
            base64encode(string);
        }else if(strncmp(option, "--base64d", max) == 0){
            base64decode(string);
        }else if(strncmp(option, "--md5", max) == 0){
            getmd5(string);
        }else if(strncmp(option, "--sha1", max) == 0){
            getsha1(string);
        }else if(strncmp(option, "--sha256", max) == 0){
            getsha256(string);
        }else if(strncmp(option, "--sha384", max) == 0){
            getsha384(string);
        }else if(strncmp(option, "--sha512", max) == 0){
            getsha512(string);
        }else{
            usage();
        }

        exit(0);
    }

    void pick3(char *option, char *string, char *value_str){
        int value = atoi(value_str);

        if(strncmp(option, "--pattern", max) == 0){
            pattern(string, value);
        }else if(strncmp(option, "--sub", max) == 0){
            sub(string, value);
        }else if(strncmp(option, "--shift", max) == 0){
            shift(string, value);
        }else if(strncmp(option, "--xor", max) == 0){
            xoring(string, value);
        }else{
            usage();
        }

        exit(0);
    }
};
