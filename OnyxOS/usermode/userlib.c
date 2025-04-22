#include "userlib.h"
#include "usyscall.h"

// دالة لطباعة النصوص
void print(const char* str) {
    syscall_write(1, str, strlen(str));  // نداء النظام لكتابة النص
}

// دالة لفتح ملف
int open(const char* filename, int mode) {
    return syscall_open(filename, mode);  // نداء النظام لفتح الملف
}

// دالة لقراءة من ملف
int read(int file, char* buffer, int size) {
    return syscall_read(file, buffer, size);  // نداء النظام لقراءة البيانات من الملف
}

// دالة لإغلاق ملف
int close(int file) {
    return syscall_close(file);  // نداء النظام لإغلاق الملف
}

// دالة لإنهاء العملية
void exit(int status) {
    syscall_exit(status);  // نداء النظام لإنهاء العملية
}

// دالة لحساب طول النص
int strlen(const char* str) {
    int len = 0;
    while (str[len] != '\0') {
        len++;
    }
    return len;
}
