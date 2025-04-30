#include "idt.h"
#include "utils.h"

// تعريف جدول المقاطعات
IDTEntry idt[256];
IDTPtr idt_ptr;

extern void idt_load();

// دالة لتهيئة جدول المقاطعات
void init_idt() {
    idt_ptr.limit = sizeof(IDTEntry) * 256 - 1;
    idt_ptr.base = (uint32_t)&idt;

    // تهيئة جدول المقاطعات
    for (int i = 0; i < 256; i++) {
        set_idt_gate(i, (uint32_t)0);  // وضع قيمة افتراضية غير مُعالجة للمقاطعات
    }

    // تحميل جدول المقاطعات
    load_idt();
}

// دالة لإعداد نقطة معالجة المقاطعة
void set_idt_gate(int n, uint32_t handler) {
    idt[n].base_low = handler & 0xFFFF;
    idt[n].base_high = (handler >> 16) & 0xFFFF;
    idt[n].selector = 0x08;  // تحديد محول البيانات (مثال: SEG_KERNEL_CODE)
    idt[n].always0 = 0;
    idt[n].flags = 0x8E;  // Type = 14 (interrupt gate)
}

// دالة لتحميل IDT
void load_idt() {
    __asm__ __volatile__ ("lidt %0" : : "m" (idt_ptr));
}
