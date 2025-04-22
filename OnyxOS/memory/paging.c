#include "paging.h"
#include "memory.h"

PageTable* kernel_page_table;
PageDirectory* kernel_page_directory;

extern void load_page_directory(uint32_t);

// دالة لتهيئة الصفحات
void init_paging() {
    kernel_page_table = (PageTable*)malloc(sizeof(PageTable));
    kernel_page_directory = (PageDirectory*)malloc(sizeof(PageDirectory));

    // تهيئة جدول الصفحات
    for (int i = 0; i < NUM_PAGES; i++) {
        kernel_page_table->pages[i].present = 0;
        kernel_page_table->pages[i].rw = 1;
        kernel_page_table->pages[i].user = 0;
        kernel_page_table->pages[i].frame = 0;
    }

    // ربط جدول الصفحات مع جدول الصفحات الرئيسي
    kernel_page_directory->physical_address = (uint32_t)kernel_page_table;
    kernel_page_directory->page_table_addr = (uint32_t)kernel_page_table;

    // تحميل جدول الصفحات
    load_page_directory((uint32_t)kernel_page_directory);
}

// دالة لتفعيل الـ paging
void enable_paging() {
    __asm__ __volatile__("mov %0, %%cr3" : : "r"(kernel_page_directory));  // تحميل جدول الصفحات في السجل CR3
    uint32_t cr0;
    __asm__ __volatile__("mov %%cr0, %0" : "=r"(cr0));
    cr0 |= 0x80000000;  // تفعيل الـ paging
    __asm__ __volatile__("mov %0, %%cr0" : : "r"(cr0));
}
