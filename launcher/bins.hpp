#pragma once

class Bins {
public:
    struct AppInfo {
        char fileName[100];
        char path[200];
        char name[100];
        char description[100];
        char author[100];
        char version[100];
    };

    typedef void (*EntryPoint)();

    static constexpr char FILE_MASK[] = "*.bin";

    static constexpr int MAX_APPS = 64;

    struct AppInfo g_apps[MAX_APPS];
    int g_numApps;

    void LoadAppInfo();
    EntryPoint RunApp(int i);

private:
    void LoadApp(const char *folder, wchar_t *fileName);
};
