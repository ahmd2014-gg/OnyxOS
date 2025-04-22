#include "mem.h"

// دالة لنسخ الذاكرة
void* memcpy(void* dest, const void* src, size_t n) {
    unsigned char* d = dest;
    const unsigned char* s = src;
    while (n--) {
        *d++ = *s++;
    }
    return dest;
}

// دالة لملء الذاكرة
void* memset(void* dest, int val, size_t n) {
    unsigned char* d = dest;
    while (n--) {
        *d++ = (unsigned char)val;
    }
    return dest;
}

// دالة لمسح الذاكرة
void bzero(void* dest, size_t n) {
    memset(dest, 0, n);
}
