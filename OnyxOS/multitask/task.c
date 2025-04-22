#include "task.h"
#include "memory.h"
#include "context.h"

Task* task_list[MAX_TASKS];
static uint32_t task_counter = 0;

void task_create(uint32_t* entry_point, uint32_t stack_size) {
    if (task_counter >= MAX_TASKS) {
        return;  // لا يمكن إضافة مهام إضافية
    }
    
    Task* new_task = (Task*)malloc(sizeof(Task));
    new_task->stack_size = stack_size;
    new_task->stack_base = (uint32_t*)malloc(stack_size);
    new_task->stack_pointer = new_task->stack_base + stack_size / sizeof(uint32_t);

    // ضبط الستاك (التوجيه إلى دالة الإدخال/الخروج)
    new_task->task_id = task_counter++;
    new_task->status = 0;  // مهمة جاهزة

    // إعداد الستاك للانتقال إلى entry_point عند بدء المهمة
    *(new_task->stack_pointer) = (uint32_t)entry_point;

    // إضافة المهمة إلى قائمة المهام
    task_list[new_task->task_id] = new_task;
}

void task_switch(Task* current_task, Task* next_task) {
    save_context(current_task); // حفظ السياق للمهمة الحالية
    load_context(next_task);    // تحميل السياق للمهمة التالية
}
