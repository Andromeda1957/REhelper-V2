// Copyright 2018 <Andromeda>
struct defaults{
    static const int max = 0xff;

    static void usage(){
        puts("REhelper created by Andromeda");
        puts("Usage <option> <string> <number>\n");
        puts("General options:");
        puts("--ascii                         prints ascii table");
        puts("--reverse   <string>            reverses the string");
        puts("--pattern   <string> <number>   "
            "prints string the given ammount of times\n");
        puts("Binary options:");
        puts("--magic     <file>              "
                "prints magic bytes from ELF files\n");
        puts("Process options:");
        puts("--stack     <string>            "
                    "give process pid to dump its stack");
        puts("--status    <string>            "
                    "give process pid to dump its status");
        puts("--io        <string>            "
                    "give process pid to dump its IO data");
        puts("--maps      <string>            "
                    "give process pid to dump its mappings");
        puts("--limits    <string>            "
                    "give process pid to dump its limits");
        puts("--clone     <string>            "
                    "give process pid to dump its binary\n");
        puts("System options:");
        puts("--aslr                          turns on system ASLR");
        puts("--no-aslr                       turns off system ASLR");
        puts("--no-time                       makes time stop");
        puts("--version                       prints system information\n");
        puts("Logic options:");
        puts("--add       <string>            adds value of string together");
        puts("--sub       <string> <number>   "
           "subtracts value of string from a value");
        puts("--mult      <string>            "
                    "multiplies value of string together");
        puts("--shift     <string> <number>   "
           "bit shifts a string by a value");
        puts("--xor       <string> <number>   "
            "xores a string by a value");
        puts("--xors      <string>            "
                    "xores a string by all 256 values\n");
        puts("Encoding options:");
        puts("--base64e   <string>            encodes a string in base64");
        puts("--base64d   <string>            decodes a base64 string\n");
        puts("Hashing options:");
        puts("--md5       <string>            prints md5 of a string");
        puts("--sha1      <string>            prints sha1 of a string");
        puts("--sha256    <string>            prints sha256 of a string");
        puts("--sha384    <string>            prints sha384 of a string");
        puts("--sha512    <string>            prints sha512 of a string\n");
        puts("Debug options:");
        puts("--ptrace                        calls ptrace");
        puts("--break                         calls int3");
        puts("--back                          "
            "continue execution in background");
        puts("--crash                         cause segmentation fault\n");
        exit(0);
    }
};
