#include "heap.h"
#include "memory.h"

#define HEAP_START 0x100000
#define HEAP_SIZE  0x100000

static uint32_t heap_end = HEAP_START;

// دالة تخصيص الذاكرة (malloc)
void* malloc(uint32_t size) {
    if (heap_end + size > HEAP_START + HEAP_SIZE) {
        return NULL;  // لا توجد مساحة كافية
    }
    void* ptr = (void*)heap_end;
    heap_end += size;
    return ptr;
}

// دالة تحرير الذاكرة (free)
void free(void* ptr) {
    // في هذا النموذج البسيط، لا يوجد جمع للقمامة (Garbage Collection) 
    // لذا لا يمكننا تحرير الذاكرة هنا بشكل دقيق
}
