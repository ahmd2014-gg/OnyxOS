#include "usyscall.h"
#include "syscall.h"

// دالة لكتابة البيانات إلى الملف (أو الشاشة)
int syscall_write(int fd, const char* buf, int len) {
    // يتم تنفيذ نداء النظام لكتابة البيانات
    return syscall(SYSCALL_WRITE, fd, buf, len);
}

// دالة لفتح ملف
int syscall_open(const char* filename, int mode) {
    return syscall(SYSCALL_OPEN, (int)filename, mode, 0);  // نداء النظام لفتح الملف
}

// دالة لقراءة من ملف
int syscall_read(int fd, char* buf, int len) {
    return syscall(SYSCALL_READ, fd, buf, len);  // نداء النظام لقراءة البيانات
}

// دالة لإغلاق ملف
int syscall_close(int fd) {
    return syscall(SYSCALL_CLOSE, fd, 0, 0);  // نداء النظام لإغلاق الملف
}

// دالة لإنهاء العملية
void syscall_exit(int status) {
    syscall(SYSCALL_EXIT, status, 0, 0);  // نداء النظام لإنهاء العملية
}

// دالة لتنفيذ نداء النظام
int syscall(int syscall_num, int arg1, int arg2, int arg3) {
    int result;
    __asm__ __volatile__(
        "int $0x80"
        : "=a"(result)
        : "0"(syscall_num), "b"(arg1), "c"(arg2), "d"(arg3)
    );
    return result;
}
