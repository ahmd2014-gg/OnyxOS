#include "scheduler.h"
#include "task.h"

// المؤشر للمهمة الحالية
static Task* current_task = NULL;

// دالة جدولة المهام
void scheduler() {
    Task* next_task = NULL;
    
    // البحث عن المهمة التالية (التنقل بين المهام الجاهزة)
    for (int i = 0; i < MAX_TASKS; i++) {
        if (task_list[i] != NULL && task_list[i]->status == 0) {  // البحث عن مهمة جاهزة
            next_task = task_list[i];
            break;
        }
    }
    
    if (next_task != NULL) {
        if (current_task != next_task) {
            task_switch(current_task, next_task);  // التبديل بين المهام
            current_task = next_task;
        }
    }
}
