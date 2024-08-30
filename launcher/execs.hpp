#pragma once

class Execs {
public:
    struct ExecInfo {
        char fileName[9];
        //char path[200];
        char name[100];
        char description[100];
        char author[100];
        char version[100];
        char *fp; //this is the address of the first byte.
    };

    typedef void (*EntryPoint)();

    static constexpr int MAX_EXECS = 64;

    struct ExecInfo g_execs[MAX_EXECS];
    int g_numExecs;

    void LoadExecInfo();
    EntryPoint RunExec(int i);
};
