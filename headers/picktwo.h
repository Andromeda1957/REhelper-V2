// Copyright 2018 <Andromeda>

#ifndef CODE___REHELP_HEADERS_PICKTWO_H_
#define CODE___REHELP_HEADERS_PICKTWO_H_

class pickTwo {
    char proc[defaults::max] = "/proc/";
    int length_decode(const char *user_input);
    void print_file(const char *proc);

 public:
    pickTwo();

 public:
    void reverse(const char *user_input);
    void magic(const char *user_input);
    void dump_stack(const char *user_input);
    void dump_status(const char *user_input);
    void dump_io(const char *user_input);
    void dump_maps(const char *user_input);
    void dump_limits(const char *user_input);
    void dump_clone(const char *user_input);
    void add(const char *user_input);
    void mult(const char *user_input);
    void xors(const char *user_input);
    void base64encode(const char *user_input);
    void base64decode(const char *user_input);
    void getmd5(const char *user_input);
    void getsha1(const char *user_input);
    void getsha256(const char *user_input);
    void getsha384(const char *user_input);
    void getsha512(const char *user_input);
};

#endif  // CODE___REHELP_HEADERS_PICKTWO_H_
