#include <sdk/os/mem.hpp>
extern "C" {
    void *memcpy(void *dest, const void *src, int n) { return Mem_Memcpy(dest, src, n); }
    void *memset(void *s, int c, int n) { return Mem_Memset(s, c, n); }
}