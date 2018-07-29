// Copyright 2018 <Andromeda>

#ifndef CODE___REHELP_HEADERS_OPTIONS_H_
#define CODE___REHELP_HEADERS_OPTIONS_H_

struct REhelp : public defaults, public pickOne,
public pickTwo, public pickThree {
    REhelp();
    void pick1(char *option);
    void pick2(char *option, char *input);
    void pick3(char *option, char *input, char *value_str);
};

#endif  // CODE___REHELP_HEADERS_OPTIONS_H_
