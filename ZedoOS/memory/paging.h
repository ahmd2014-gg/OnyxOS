#ifndef PAGING_H
#define PAGING_H

#include <stdint.h>

#define PAGE_SIZE 4096
#define NUM_PAGES 1024

typedef struct {
    uint32_t present   : 1;
    uint32_t rw        : 1;
    uint32_t user      : 1;
    uint32_t accessed  : 1;
    uint32_t dirty     : 1;
    uint32_t reserved  : 7;
    uint32_t frame     : 20;
} __attribute__((packed)) PageTableEntry;

typedef struct {
    PageTableEntry pages[NUM_PAGES];
} __attribute__((packed)) PageTable;

typedef struct {
    uint32_t physical_address;
    uint32_t page_table_addr;
} __attribute__((packed)) PageDirectory;

void init_paging();
void enable_paging();

#endif
