#include "scheduler.h"
#include "task.h"

static task_t* current_task = NULL;

void start_scheduler() {
    // أولاً، نستدعي المهمة الأولى (أو العملية الرئيسية)
    current_task = get_first_task();
    
    // بدء جدولة العمليات
    while (1) {
        if (current_task != NULL) {
            // تنفيذ المهمة الحالية
            switch_task(current_task);
            current_task = current_task->next;
        }
    }
}

void switch_task(task_t* task) {
    // هنا يتم تبديل السياق بين العمليات (السياق = حالة السجل)
    // في الأنظمة الحقيقية قد نستخدم تعليمات مثل "task_switch"
    printk("Switching to task: %d\n", task->task_id);
}
