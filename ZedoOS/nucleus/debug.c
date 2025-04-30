#include "debug.h"
#include "screen.h"

void printk(const char* format, ...) {
    va_list args;
    va_start(args, format);
    char buffer[256];
    vsprintf(buffer, format, args);
    va_end(args);
    print_string(buffer);
}

void print_string(const char* str) {
    while (*str) {
        __asm__ __volatile__("int $0x10" : : "a"(0x0E00 | (*str & 0xFF)));
        str++;
    }
}
