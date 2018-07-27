class pickThree{
private:
    static void pattern(char *string, int value){
        for(int i = 0; i < value; i++){
            printf("%s", string);
        }

        printf("\n");
        defaults::quit();
    }

    static void sub(char *string, int value){
        int length = strnlen(string, defaults::max) - 1;

        for(int i = 0; i <= length; i++){
            value = value - string[i];
        }

        printf("Decimal value: %d", value);
        printf("\n");
        printf("Hex value:     %x", value);
        printf("\n");
        defaults::quit();
    }

    static void shift(char *string, int shift){
        int length = strnlen(string, defaults::max) - 1;
        char rightshifted[defaults::max];
        char leftshifted[defaults::max];

        leftshifted[length + 1] = '\0';
        rightshifted[length + 1] = '\0';
        printf("Shifted right: ");

        for(int i = 0; i <= length; i++){
            rightshifted[i] = string[i] >> shift;
            printf("%x", rightshifted[i]);
        }

        printf("\n");
        printf("Shifted left:  ");

        for(int e = 0; e <= length; e++){
            leftshifted[e] = string[e] << shift;
            printf("%x", leftshifted[e]);
        }

        printf("\n");
        defaults::quit();
    }

    static void xoring(char *string, int xors){
        int length = strnlen(string, defaults::max) - 1;
        char xored[defaults::max];

        printf("Hex value: ");

        for(int i = 0; i <= length; i++){
            xored[i] = string[i] ^ xors;
            printf("%x", xored[i]);
        }

        xored[length + 1] = '\0';
        printf("\n");
        printf("String:    ");
        printf("%s\n", xored);
        defaults::quit();
    }

public:
    static void options(char *option, char *string, int value){
        if(strncmp(option, "--pattern", defaults::max) == 0){
            pattern(string, value);
        }else if(strncmp(option, "--sub", defaults::max) == 0){
            sub(string, value);
        }else if(strncmp(option, "--shift", defaults::max) == 0){
            shift(string, value);
        }else if(strncmp(option, "--xor", defaults::max) == 0){\
            xoring(string, value);
        }else{
            return;
        }
    }
};