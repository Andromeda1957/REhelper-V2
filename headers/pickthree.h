class pickThree{
protected:
    void pattern(char *string, int value){
        for(int i = 0; i < value; i++){
            printf("%s", string);
        }

        puts("");
    }

    void sub(char *string, int value){
        int length = strnlen(string, defaults::max) - 1;

        for(int i = 0; i <= length; i++){
            value = value - string[i];
        }

        printf("Decimal value: %d", value);
        puts("");
        printf("Hex value:     %x", value);
        puts("");
    }

    void shift(char *string, int shift){
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

        puts("");
        printf("Shifted left:  ");

        for(int e = 0; e <= length; e++){
            leftshifted[e] = string[e] << shift;
            printf("%x", leftshifted[e]);
        }

        puts("");
    }

    void xoring(char *string, int xors){
        int length = strnlen(string, defaults::max) - 1;
        char xored[defaults::max];

        printf("Hex value: ");

        for(int i = 0; i <= length; i++){
            xored[i] = string[i] ^ xors;
            printf("%x", xored[i]);
        }

        xored[length + 1] = '\0';
        puts("");
        printf("String:    ");
        puts(xored);
    }
};
