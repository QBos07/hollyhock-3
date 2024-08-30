#pragma once

#include "elf.h"
#include "files.hpp"
#include <sdk/os/file.hpp>

class Apps {
public:
    typedef void (*EntryPoint)();
    
    struct AppInfo {
        char fileName[100];
        char path[200];
        char name[100];
        char description[100];
        char author[100];
        char version[100];
    };

    static constexpr char FILE_MASK[] = "*.hhk";

    static constexpr int MAX_APPS = 64;

    struct AppInfo g_apps[MAX_APPS];

    int g_numApps;

    void LoadAppInfo();
    EntryPoint RunApp(int i);

private:
    const Elf32_Ehdr *LoadELF(File f, const Elf32_Shdr **sectionHeaders);
    void LoadApp(const char *folder, wchar_t *fileName);
};
