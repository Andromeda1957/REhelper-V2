// Copyright 2018 <Andromeda>

#ifndef CODE___REHELP_HEADERS_PICKONE_H_
#define CODE___REHELP_HEADERS_PICKONE_H_

class pickOne {
    static void sig_handler(int signo);

 private:
    void detect();

 public:
    pickOne();
    static void breakpoint();

 public:
    void ascii_table();
    void aslr();
    void no_aslr();
    void no_time();
    void version();
    void trace();
    void background();
    void crash();
};

#endif  // CODE___REHELP_HEADERS_PICKONE_H_
