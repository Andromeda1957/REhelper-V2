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

void usage(){
    printf("REhelper created by Andromeda\n");
    printf("Usage <option> <string> <number>\n\n");
    printf("General options:\n");
    printf("--ascii                         prints ascii table\n");
    printf("--reverse   <string>            reverses the string\n");
    printf("--pattern   <string> <number>   prints string the given ammount of times\n\n");
    printf("Binary options:\n");
    printf("--magic     <file>              prints magic bytes from ELF files\n\n");
    printf("Process options:\n");
    printf("--stack     <string>            give process pid to dump its stack\n");
    printf("--status    <string>            give process pid to dump its status\n");
    printf("--io        <string>            give process pid to dump its IO data\n");
    printf("--maps      <string>            give process pid to dump its mappings\n");
    printf("--limits    <string>            give process pid to dump its limits\n");
    printf("--clone     <string>            give process pid to dump its binary\n\n");
    printf("System options:\n");
    printf("--aslr                          turns on system ASLR\n");
    printf("--no-aslr                       turns off system ASLR\n");
    printf("--no-time                       makes time stop\n");
    printf("--version                       prints system information\n\n");
    printf("Logic options:\n");
    printf("--add       <string>            adds value of string together\n");
    printf("--sub       <string> <number>   subtracts value of string from a value\n");
    printf("--mult      <string>            multiplies value of string together\n");
    printf("--shift     <string> <number>   bit shifts a string by a value\n");
    printf("--xor       <string> <number>   xores a string by a value\n");
    printf("--xors      <string>            xores a string by all 256 values\n\n");
    printf("Encoding options:\n");
    printf("--base64e   <string>            encodes a string in base64\n");
    printf("--base64d   <string>            decodes a base64 string\n\n");
    printf("Hashing options:\n");
    printf("--md5       <string>            prints md5 of a string\n");
    printf("--sha1      <string>            prints sha1 of a string\n");
    printf("--sha256    <string>            prints sha256 of a string\n");
    printf("--sha384    <string>            prints sha384 of a string\n");
    printf("--sha512    <string>            prints sha512 of a string\n\n");
    printf("Debug options:\n");
    printf("--ptrace                        calls ptrace\n");
    printf("--break                         calls int3\n");
    printf("--back                          continue execution in background\n");
    printf("--crash                         cause segmentation fault\n");
}

int main(int argc, char **argv){
    int value;

    if(argc == 2){
        pickOne::options(argv[1]);
    }else if(argc == 3){
        pickTwo::options(argv[1], argv[2]);
    }else if(argc == 4){
        value = atoi(argv[3]);
        pickThree::options(argv[1], argv[2], value);
    }
        
    usage();
    return 0;
}
