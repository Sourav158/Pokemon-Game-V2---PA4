#include <iostream>
#ifndef INPUT_HANDDLING_H
#define INPUT_HANDDLING_H
using namespace std;

class Invalid_Input {
    public:
        Invalid_Input(string in_ptr) : msg_ptr(in_ptr) { }
        const string msg_ptr;
    private:
        Invalid_Input();
};

#endif
