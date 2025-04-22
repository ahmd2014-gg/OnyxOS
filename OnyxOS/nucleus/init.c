#include "init.h"
#include "memory.h"
#include "gdt.h"
#include "idt.h"
#include "drivers.h"

void init_system() {
    // تهيئة إدارة الذاكرة
    init_memory();

    // تهيئة جدول المقاطعات
    init_idt();

    // تهيئة جدول الـ GDT
    init_gdt();

    // تهيئة المحركات والملحقات الأخرى
    init_drivers();

    // طباعة رسالة تهيئة ناجحة
    printk("System Initialized Successfully!\n");
}
