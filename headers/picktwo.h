class pickTwo{
private:
    static void reverse(char *string){
        int length = strnlen(string, defaults::max) - 1;
        char output[defaults::max];

        for(int i = 0; i <= length; i++){
            output[i] = string[length - i];
        }

        printf("%s\n", output);
        defaults::quit();
    }

    static void magic(char *string){
        char *filecontent;
        FILE *file;

        file = fopen(string, "rb");

        if(!file){
            printf("File not found\n");
            return;
        }

        filecontent = (char *)malloc(sizeof(file));
        fscanf(file, "%s", filecontent);

        if(filecontent[0] != 0x7f){
            printf("Not an ELF file\n");
            return;
        }else if(filecontent[1] != 0x45){
            printf("Not an ELF file\n");
            return;
        }else if(filecontent[2] != 0x4c){
            printf("Not an ELF file\n");
            return;
        }else if(filecontent[3] != 0x46){
            printf("Not an ELF file\n");
            return;
        }

        printf("ELF magic: ");

        for(int i = 0; i <= 6; i++){
            printf("%02x ", filecontent[i]);
        }

        printf("\n");
        free(filecontent);
        filecontent = NULL;
        defaults::quit();
    }

    static void dump_stack(char *string){
        char *filecontent;
        char stack[defaults::max] = "/proc/";
        FILE *file;

        strncat(stack, string, defaults::max - strnlen(stack, defaults::max));
        strncat(stack, "/stack", defaults::max - strnlen(stack, defaults::max));
        file = fopen(stack, "r");

        if(!file){
            printf("No such process\n");
            return;
        }

        filecontent = (char *)malloc(sizeof(file));
        fread(filecontent, sizeof(file), 45, file);
        printf("%s", filecontent);
        free(filecontent);
        filecontent = NULL;
        defaults::quit();
    }

    static void dump_status(char *string){
        char *filecontent;
        char status[defaults::max] = "/proc/";
        FILE *file;

        strncat(status, string, defaults::max - strnlen(status, defaults::max));
        strncat(status, "/status", defaults::max - strnlen(status, defaults::max));
        file = fopen(status, "r");

        if(!file){
            printf("No such process\n");
            return;
        }

        filecontent = (char *)malloc(sizeof(file));
        fread(filecontent, sizeof(file), 20, file);
        printf("%s", filecontent);
        free(filecontent);
        filecontent = NULL;
        defaults::quit();
    }

    static void dump_io(char *string){
        char *filecontent;
        char io[defaults::max] = "/proc/";
        FILE *file;

        strncat(io, string, defaults::max - strnlen(io, defaults::max));
        strncat(io, "/io", defaults::max - strnlen(io, defaults::max));
        file = fopen(io, "r");

        if(!file){
            printf("No such process\n");
            return;
        }

        filecontent = (char *)malloc(sizeof(file));
        fread(filecontent, sizeof(file), 8, file);
        printf("%s", filecontent);
        free(filecontent);
        filecontent = NULL;
        defaults::quit();
    }

    static void dump_maps(char *string){
        char *filecontent;
        char maps[defaults::max] = "/proc/";
        FILE *file;

        strncat(maps, string, defaults::max - strnlen(maps, defaults::max));
        strncat(maps, "/maps", defaults::max - strnlen(maps, defaults::max));
        file = fopen(maps, "r");

        if(!file){
            printf("No such process\n");
            return;
        }

        filecontent = (char *)malloc(sizeof(file));
        fread(filecontent, sizeof(file), 400, file);
        printf("%s", filecontent);
        printf("\n");
        free(filecontent);
        filecontent = NULL;
        defaults::quit();
    }

    static void dump_limits(char *string){
        char *filecontent;
        char limits[defaults::max] = "/proc/";
        FILE *file;

        strncat(limits, string, defaults::max - strnlen(limits, defaults::max));
        strncat(limits, "/limits", defaults::max - strnlen(limits, defaults::max));
        file = fopen(limits, "r");

        if(!file){
            printf("No such process\n");
            return;
        }

        filecontent = (char *)malloc(sizeof(file));
        fread(filecontent, sizeof(file), 128, file);
        printf("%s", filecontent);
        printf("\n");
        free(filecontent);
        filecontent = NULL;
        defaults::quit();
    }

    static void dump_clone(char *string){
        int outfile;
        char *filecontent;
        char clone[defaults::max] = "/proc/";
        FILE *file;
        FILE *cloned;
        FILE *out;

        strncat(clone, string, defaults::max - strnlen(clone, defaults::max));
        strncat(clone, "/exe", defaults::max - strnlen(clone, defaults::max));
        file = fopen(clone, "r");
        cloned = fopen("cloned", "r");
        out = fopen("cloned", "w");

        if(!file){
            printf("No such process\n");
            return;
        }

        if(cloned){
            printf("File 'cloned' already exists\n");
            return;
        }

        if(!out){
            printf("Cannot write to file\n");
            return;
        }

        outfile = fgetc(file);

        while(outfile != EOF){
            fputc(outfile, out);
            outfile = fgetc(file);
        }

        system("chmod +x cloned");
        printf("Created file named cloned\n");
        defaults::quit();
        
    }

    static void add(char *string){
        int total = 0;
        int length = strnlen(string, defaults::max) - 1;

        for(int i = 0; i <= length; i++){
            total = total + string[i];
        }

        printf("Decimal value: %d", total);
        printf("\n");
        printf("Hex value:     %x", total);
        printf("\n");
        defaults::quit();
    }

    static void mult(char *string){
        int total = 1;
        int length = strnlen(string, defaults::max) - 1;

        for(int i = 0; i <= length; i++){
            total = total * string[i];
        }

        printf("Decimal value: %d", total);
        printf("\n");
        printf("Hex value:     %02x", total);
        printf("\n");
        defaults::quit();
    }

    static void xors(char *string){
        int xors;
        int length = strnlen(string, defaults::max) - 1;
        char xored[length];

        xored[length + 1] = '\0';

        for(int i = 0; i <= 256; i++){
            printf("Hex value %d: ", i);

            for(int e = 0; e <= length; e++){
                xors = string[e] ^ i;
                xored[e] = (char)(xors);
                printf("%x", xored[e]);
            }

            printf("\n");
            printf("String    %d: ", i);
            printf("%s\n", xored);
        }

        defaults::quit();
    }

    static void base64encode(char *string){
        BIO *base64;
        BIO *input;

        base64 = BIO_new(BIO_f_base64());
        input = BIO_new_fp(stdout, BIO_NOCLOSE);
        BIO_push(base64, input);
        BIO_write(base64, string, strnlen(string, defaults::max));
        BIO_flush(base64);
        BIO_free_all(base64);
        base64 = NULL;
        defaults::quit();
    }

    static int length_decode(char *string){ 
        int equals;
        int length = strnlen(string, defaults::max);

        if(string[length - 1] == '=' && string[length - 2] == '='){
            equals = 2;
        }else if(string[length - 1] == '='){
            equals = 1;
        }else{
            equals = 0;
        }

        return (length * 3) / 4 - equals;
    }

    static void base64decode(char *string){
        int length;
        int decode_length = length_decode(string);
        char *output;
        BIO *base64;
        BIO *input;

        output = (char *)malloc(decode_length + 1);
        output[decode_length] = '\0';
        input = BIO_new_mem_buf(string, -1);
        base64 = BIO_new(BIO_f_base64());
        input = BIO_push(base64, input);
        BIO_set_flags(input, BIO_FLAGS_BASE64_NO_NL); 
        length = BIO_read(input, output, strnlen(string, defaults::max));
        assert(length == decode_length); 
        BIO_free_all(input);
        input = NULL;
        printf("%s\n", output);
        defaults::quit();
    }

    static void getmd5(char *string){
        int length = strnlen(string, defaults::max);
        unsigned char hash[MD5_DIGEST_LENGTH];
        MD5_CTX ctx;

        MD5_Init(&ctx);
        MD5_Update(&ctx, string, length);
        MD5_Final(hash, &ctx);
        printf("\n");    

        for(int i = 0; i < 16; i++){
            printf("%02x", (unsigned int)hash[i]);
        }

        printf("\n");
        defaults::quit();
    }

    static void getsha1(char *string){
        int length = strnlen(string, defaults::max);
        unsigned char hash[SHA_DIGEST_LENGTH];
        SHA_CTX ctx;

        SHA1_Init(&ctx);
        SHA1_Update(&ctx, string, length);
        SHA1_Final(hash, &ctx);
        printf("\n");    

        for(int i = 0; i < 20; i++){
            printf("%02x", (unsigned int)hash[i]);
        }

        printf("\n");
        defaults::quit();    
    }

    static void getsha256(char *string){
        int length = strnlen(string, defaults::max);
        unsigned char hash[SHA256_DIGEST_LENGTH];
        SHA256_CTX ctx;

        SHA256_Init(&ctx);
        SHA256_Update(&ctx, string, length);
        SHA256_Final(hash, &ctx);
        printf("\n");    

        for(int i = 0; i < 32; i++){
            printf("%02x", (unsigned int)hash[i]);
        }

        printf("\n");
        defaults::quit();
    }

    static void getsha384(char *string){
        int length = strnlen(string, defaults::max);
        unsigned char hash[SHA384_DIGEST_LENGTH];
        SHA512_CTX ctx;

        SHA384_Init(&ctx);
        SHA384_Update(&ctx, string, length);
        SHA384_Final(hash, &ctx);
        printf("\n");    

        for(int i = 0; i < 48; i++){
            printf("%02x", (unsigned int)hash[i]);
        }

        printf("\n");
        defaults::quit();
    }

    static void getsha512(char *string){
        int length = strnlen(string, defaults::max);
        unsigned char hash[SHA512_DIGEST_LENGTH];
        SHA512_CTX ctx;

        SHA512_Init(&ctx);
        SHA512_Update(&ctx, string, length);
        SHA512_Final(hash, &ctx);
        printf("\n");    

        for(int i = 0; i < 64; i++){
            printf("%02x", (unsigned int)hash[i]);
        }

        printf("\n");
        defaults::quit();
    }

public:
    static void options(char *option, char *string){
        if(strncmp(option, "--reverse", defaults::max) == 0){
            reverse(string);
        }else if(strncmp(option, "--magic", defaults::max) == 0){
            magic(string);
        }else if(strncmp(option, "--stack", defaults::max) == 0){
            dump_stack(string);
        }else if(strncmp(option, "--status", defaults::max) == 0){
            dump_status(string);
        }else if(strncmp(option, "--io", defaults::max) == 0){
            dump_io(string);
        }else if(strncmp(option, "--maps", defaults::max) == 0){
            dump_maps(string);
        }else if(strncmp(option, "--limits", defaults::max) == 0){
            dump_limits(string);
        }else if(strncmp(option, "--clone", defaults::max) == 0){
            dump_clone(string);
        }else if(strncmp(option, "--add", defaults::max) == 0){
            add(string);
        }else if(strncmp(option, "--mult", defaults::max) == 0){
            mult(string);
        }else if(strncmp(option, "--xors", defaults::max) == 0){
            xors(string);
        }else if(strncmp(option, "--base64e", defaults::max) == 0){
            base64encode(string);
        }else if(strncmp(option, "--base64d", defaults::max) == 0){
            base64decode(string);
        }else if(strncmp(option, "--md5", defaults::max) == 0){
            getmd5(string);
        }else if(strncmp(option, "--sha1", defaults::max) == 0){
            getsha1(string);
        }else if(strncmp(option, "--sha256", defaults::max) == 0){
            getsha256(string);
        }else if(strncmp(option, "--sha384", defaults::max) == 0){
            getsha384(string);
        }else if(strncmp(option, "--sha512", defaults::max) == 0){
            getsha512(string);
        }else{
            return;
        }
    }
};