#include "gdt.h"

// تعريف جدول GDT
GDTEntry gdt[GDT_NUM_ENTRIES];
GDTPtr gdt_ptr;

extern void gdt_load();

// تهيئة GDT
void init_gdt() {
    gdt_ptr.limit = (sizeof(GDTEntry) * GDT_NUM_ENTRIES) - 1;
    gdt_ptr.base = (uint32_t)&gdt;

    // وضع مدخلات جدول GDT
    set_gdt_gate(0, 0, 0, 0, 0);            // المدخل 0 غير صالح
    set_gdt_gate(1, 0, 0xFFFFFFFF, 0x9A, 0xCF); // المدخل 1 - الكود
    set_gdt_gate(2, 0, 0xFFFFFFFF, 0x92, 0xCF); // المدخل 2 - البيانات
    set_gdt_gate(3, 0, 0, 0, 0);              // المدخل 3 غير صالح

    // تحميل جدول GDT
    gdt_load();
}

// دالة لإعداد مدخل GDT
void set_gdt_gate(int num, uint32_t base, uint32_t limit, uint8_t access, uint8_t granularity) {
    gdt[num].limit_low = (limit & 0xFFFF);
    gdt[num].base_low = (base & 0xFFFF);
    gdt[num].base_middle = (base >> 16) & 0xFF;
    gdt[num].access = access;
    gdt[num].granularity = (limit >> 16) & 0x0F;
    gdt[num].granularity |= granularity & 0xF0;
    gdt[num].base_high = (base >> 24) & 0xFF;
}
