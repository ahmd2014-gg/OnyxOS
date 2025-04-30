#ifndef IDT_H
#define IDT_H

#include <stdint.h>

// تعريف هيكل IDT Entry
typedef struct {
    uint16_t base_low;
    uint16_t selector;
    uint8_t  always0;
    uint8_t  flags;
    uint16_t base_high;
} __attribute__((packed)) IDTEntry;

// تعريف هيكل IDT Pointer
typedef struct {
    uint16_t limit;
    uint32_t base;
} __attribute__((packed)) IDTPtr;

extern IDTEntry idt[256];    // جدول المقاطعات
extern IDTPtr idt_ptr;       // المؤشر إلى جدول المقاطعات

void init_idt();
void set_idt_gate(int n, uint32_t handler);
void load_idt();

#endif
