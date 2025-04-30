#ifndef GDT_H
#define GDT_H

#include <stdint.h>

#define GDT_NUM_ENTRIES 6

// تعريف هيكل GDT Entry
typedef struct {
    uint16_t limit_low;
    uint16_t base_low;
    uint8_t  base_middle;
    uint8_t  access;
    uint8_t  granularity;
    uint8_t  base_high;
} __attribute__((packed)) GDTEntry;

// تعريف هيكل GDT Pointer
typedef struct {
    uint16_t limit;
    uint32_t base;
} __attribute__((packed)) GDTPtr;

extern GDTEntry gdt[GDT_NUM_ENTRIES];
extern GDTPtr gdt_ptr;

void init_gdt();
void set_gdt_gate(int num, uint32_t base, uint32_t limit, uint8_t access, uint8_t granularity);

#endif
