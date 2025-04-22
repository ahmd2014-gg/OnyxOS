#include "panic.h"
#include "screen.h"

void panic(const char* message) {
    // طباعة رسالة الخطأ على الشاشة
    printk("Kernel Panic: %s\n", message);

    // إيقاف النظام
    while (1) {
        __asm__ __volatile__("hlt");
    }
}
