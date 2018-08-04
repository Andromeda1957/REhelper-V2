// Copyright 2018 <Andromeda>

#ifndef CODE___REHELP_HEADERS_OPTIONS_H_
#define CODE___REHELP_HEADERS_OPTIONS_H_

struct REhelp : public defaults {
    REhelp();
    void pick1(const char *option);
    void pick2(const char *option, const char *input);
    void pick3(const char *option, const char *input, const char *value_str);
};

#endif  // CODE___REHELP_HEADERS_OPTIONS_H_
