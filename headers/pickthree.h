// Copyright 2018 <Andromeda>

#ifndef CODE___REHELP_HEADERS_PICKTHREE_H_
#define CODE___REHELP_HEADERS_PICKTHREE_H_

struct pickThree {
    pickThree();
    void pattern(const char *user_input, const int value);
    void sub(const char *user_input, const int value);
    void shift(const char *user_input, const int shift);
    void xoring(const char *user_input, const int xors);
};

#endif  // CODE___REHELP_HEADERS_PICKTHREE_H_
