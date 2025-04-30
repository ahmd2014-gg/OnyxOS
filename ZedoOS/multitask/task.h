#ifndef TASK_H
#define TASK_H

#include <stdint.h>

#define MAX_TASKS 64

typedef struct task {
    uint32_t* stack_pointer; // مؤشر الستاك
    uint32_t* stack_base;    // قاعدة الستاك
    uint32_t stack_size;     // حجم الستاك
    uint32_t task_id;        // معرف المهمة
    uint32_t status;         // حالة المهمة (جاهزة، قيد التنفيذ، إلخ)
} Task;

extern Task* task_list[MAX_TASKS];

void task_create(uint32_t* entry_point, uint32_t stack_size);
void task_switch(Task* current_task, Task* next_task);

#endif
