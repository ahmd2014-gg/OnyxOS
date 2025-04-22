#include "stack.h"

#define STACK_SIZE 0x8000  // 32KB من الذاكرة للـ stack

typedef struct {
    uint32_t* stack_pointer;
} Process;

extern void switch_to_user_mode(uint32_t* stack_pointer);

// دالة لتهيئة الـ stack
void init_stack(Process* process) {
    process->stack_pointer = (uint32_t*)malloc(STACK_SIZE);
    // تهيئة الـ stack بالقيم الافتراضية
    for (int i = 0; i < STACK_SIZE / sizeof(uint32_t); i++) {
        process->stack_pointer[i] = 0;
    }
}

// دالة للانتقال إلى وضع المستخدم مع تهيئة الـ stack
void switch_stack(Process* process) {
    switch_to_user_mode(process->stack_pointer);
}
