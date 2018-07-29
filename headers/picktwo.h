// Copyright 2018 <Andromeda>

#ifndef CODE___REHELP_HEADERS_PICKTWO_H_
#define CODE___REHELP_HEADERS_PICKTWO_H_

class pickTwo {
 public:
    pickTwo();
    static int length_decode(char *user_input);
    static void print_file(char *proc);

 public:
    void reverse(char *user_input);
    void magic(char *user_input);
    void dump_stack(char *user_input);
    void dump_status(char *user_input);
    void dump_io(char *user_input);
    void dump_maps(char *user_input);
    void dump_limits(char *user_input);
    void dump_clone(char *user_input);
    void add(char *user_input);
    void mult(char *user_input);
    void xors(char *user_input);
    void base64encode(char *user_input);
    void base64decode(char *user_input);
    void getmd5(char *user_input);
    void getsha1(char *user_input);
    void getsha256(char *user_input);
    void getsha384(char *user_input);
    void getsha512(char *user_input);
};

#endif  // CODE___REHELP_HEADERS_PICKTWO_H_
