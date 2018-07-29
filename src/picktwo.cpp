// Copyright 2018 <Andromeda>

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/bio.h>
#include <openssl/evp.h>
#include <openssl/md5.h>
#include <openssl/sha.h>

#include <../headers/defaults.h>
#include <../headers/picktwo.h>

pickTwo::pickTwo() {}

// Private methods

int pickTwo::length_decode(char *user_input) {
    int equals;
    const int length = strnlen(user_input, defaults::max);

    if (user_input[length - 1] == '=' && user_input[length - 2] == '=')
        equals = 2;
    else if (user_input[length - 1] == '=')
        equals = 1;
    else
        equals = 0;

    return (length * 3) / 4 - equals;
}

void pickTwo::print_file(char *proc) {
    constexpr int size = 6400;
    char *filecontent = new char[size];
    FILE *file = fopen(proc, "r");

    if (!file) {
        puts("No such process");
        return;
    }

    fread(filecontent, 1, size, file);
    filecontent[size] = '\0';

    if (filecontent[size] == 0x00) {
        puts(filecontent);
        delete[] filecontent;
    } else {
        delete[] filecontent;
        exit(0);
    }
}

// Public methods

void pickTwo::reverse(char *user_input) {
    const int length = strnlen(user_input, defaults::max) - 1;
    char *output = new char[defaults::max];

    for (int i = 0; i <= length; i++)
        output[i] = user_input[length - i];

    puts(output);
    delete[] output;
}

void pickTwo::magic(char *user_input) {
    FILE *file = fopen(user_input, "rb");
    char *filecontent = new char[sizeof(file)];

    if (!file) {
        puts("File not found");
        return;
    }

    fscanf(file, "%s", filecontent);

    if (filecontent[0] != 0x7f) {
        puts("Not an ELF file");
        return;
    } else if (filecontent[1] != 0x45) {
        puts("Not an ELF file");
        return;
    } else if (filecontent[2] != 0x4c) {
        puts("Not an ELF file");
        return;
    } else if (filecontent[3] != 0x46) {
        puts("Not an ELF file");
        return;
    }

    printf("ELF magic: ");

    for (int i = 0; i <= 6; i++)
        printf("%02x ", filecontent[i]);

    puts("");
    delete[] filecontent;
}

void pickTwo::dump_stack(char *user_input) {
    strncat(proc, user_input, defaults::max - strnlen(proc, defaults::max));
    strncat(proc, "/stack", defaults::max - strnlen(proc, defaults::max));
    print_file(proc);
}

void pickTwo::dump_status(char *user_input) {
    strncat(proc, user_input, defaults::max - strnlen(proc, defaults::max));
    strncat(proc, "/status", defaults::max - strnlen(proc, defaults::max));
    print_file(proc);
}

void pickTwo::dump_io(char *user_input) {
    strncat(proc, user_input, defaults::max - strnlen(proc, defaults::max));
    strncat(proc, "/io", defaults::max - strnlen(proc, defaults::max));
    print_file(proc);
}

void pickTwo::dump_maps(char *user_input) {
    strncat(proc, user_input, defaults::max - strnlen(proc, defaults::max));
    strncat(proc, "/maps", defaults::max - strnlen(proc, defaults::max));
    print_file(proc);
}

void pickTwo::dump_limits(char *user_input) {
    strncat(proc, user_input, defaults::max - strnlen(proc, defaults::max));
    strncat(proc, "/limits", defaults::max - strnlen(proc, defaults::max));
    print_file(proc);
}

void pickTwo::dump_clone(char *user_input) {
    int outfile;
    char *filecontent;
    FILE *file = fopen(proc, "r");
    FILE *cloned = fopen("cloned", "r");
    FILE *out = fopen("cloned", "w");

    strncat(proc, user_input, defaults::max - strnlen(proc, defaults::max));
    strncat(proc, "/exe", defaults::max - strnlen(proc, defaults::max));

    if (!file) {
        puts("No such process");
        return;
    }

    if (cloned) {
        puts("File 'cloned' already exists");
        return;
    }

    if (!out) {
        puts("Cannot write to file");
        return;
    }

    outfile = fgetc(file);

    while (outfile != EOF) {
        fputc(outfile, out);
        outfile = fgetc(file);
    }

    system("chmod +x cloned");
    puts("Created file named cloned");
}

void pickTwo::add(char *user_input) {
    int total = 0;
    const int length = strnlen(user_input, defaults::max) - 1;

    for (int i = 0; i <= length; i++)
        total = total + user_input[i];

    printf("Decimal value: %d", total);
    puts("");
    printf("Hex value:     0x%x", total);
    puts("");
}

void pickTwo::mult(char *user_input) {
    int total = 1;
    const int length = strnlen(user_input, defaults::max) - 1;

    for (int i = 0; i <= length; i++)
        total = total * user_input[i];

    printf("Decimal value: %d", total);
    puts("");
    printf("Hex value:     0x%x", total);
    puts("");
}

void pickTwo::xors(char *user_input) {
    int xors;
    const int length = strnlen(user_input, defaults::max);
    char *xored = new char[length];

    xored[length + 1] = '\0';

    for (int i = 0; i <= 256; i++) {
        printf("Hex value %d: 0x", i);

        for (int e = 0; e <= length - 1; e++) {
            xors = user_input[e] ^ i;
            xored[e] = xors;
            printf("%x", xored[e]);
        }

        puts("");
        printf("String    %d: ", i);
        puts(xored);
    }

    delete[] xored;
}

void pickTwo::base64encode(char *user_input) {
    BIO *base64 = BIO_new(BIO_f_base64());
    BIO *input = BIO_new_fp(stdout, BIO_NOCLOSE);

    BIO_push(base64, input);
    BIO_write(base64, user_input, strnlen(user_input, defaults::max));
    BIO_flush(base64);
    BIO_free_all(base64);
}

void pickTwo::base64decode(char *user_input) {
    int length;
    const int decode_length = length_decode(user_input);
    char *output = new char[decode_length + 1];
    BIO *base64 = BIO_new(BIO_f_base64());
    BIO *input = BIO_new_mem_buf(user_input, -1);

    output[decode_length] = '\0';
    input = BIO_push(base64, input);
    BIO_set_flags(input, BIO_FLAGS_BASE64_NO_NL);
    length = BIO_read(input, output, strnlen(user_input, defaults::max));

    if (length != decode_length) {
        puts("not base64");
        exit(0);
    }

    assert(length == decode_length);
    BIO_free_all(input);
    puts(output);
    delete[] output;
}

void pickTwo::getmd5(char *user_input) {
    const int length = strnlen(user_input, defaults::max);
    unsigned char hash[MD5_DIGEST_LENGTH];
    MD5_CTX ctx;

    MD5_Init(&ctx);
    MD5_Update(&ctx, user_input, length);
    MD5_Final(hash, &ctx);
    puts("");

    for (int i = 0; i < 16; i++)
        printf("%02x", (unsigned int)hash[i]);

    puts("");
}
void pickTwo::getsha1(char *user_input) {
    const int length = strnlen(user_input, defaults::max);
    unsigned char hash[SHA_DIGEST_LENGTH];
    SHA_CTX ctx;

    SHA1_Init(&ctx);
    SHA1_Update(&ctx, user_input, length);
    SHA1_Final(hash, &ctx);
    puts("");

    for (int i = 0; i < 20; i++)
        printf("%02x", (unsigned int)hash[i]);

    puts("");;
}

void pickTwo::getsha256(char *user_input) {
    const int length = strnlen(user_input, defaults::max);
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_CTX ctx;

    SHA256_Init(&ctx);
    SHA256_Update(&ctx, user_input, length);
    SHA256_Final(hash, &ctx);
    puts("");

    for (int i = 0; i < 32; i++)
        printf("%02x", (unsigned int)hash[i]);

    puts("");
}

void pickTwo::getsha384(char *user_input) {
    const int length = strnlen(user_input, defaults::max);
    unsigned char hash[SHA384_DIGEST_LENGTH];
    SHA512_CTX ctx;

    SHA384_Init(&ctx);
    SHA384_Update(&ctx, user_input, length);
    SHA384_Final(hash, &ctx);
    puts("");

    for (int i = 0; i < 48; i++)
        printf("%02x", (unsigned int)hash[i]);

    puts("");
}

void pickTwo::getsha512(char *user_input) {
    const int length = strnlen(user_input, defaults::max);
    unsigned char hash[SHA512_DIGEST_LENGTH];
    SHA512_CTX ctx;

    SHA512_Init(&ctx);
    SHA512_Update(&ctx, user_input, length);
    SHA512_Final(hash, &ctx);
    puts("");

    for (int i = 0; i < 64; i++)
        printf("%02x", (unsigned int)hash[i]);

    puts("");
}
