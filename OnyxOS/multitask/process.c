#include "process.h"
#include "task.h"

// دالة لإنشاء عملية جديدة
void process_create(uint32_t* entry_point, uint32_t stack_size) {
    task_create(entry_point, stack_size);
    // يمكنك إضافة أي معالجة إضافية تخص إدارة العمليات هنا مثل تحديد الأولوية أو الحالة
}

// دالة لإيقاف عملية (قتل أو إلغاء مهمة)
void process_terminate(uint32_t task_id) {
    if (task_id < MAX_TASKS && task_list[task_id] != NULL) {
        free(task_list[task_id]->stack_base);
        free(task_list[task_id]);
        task_list[task_id] = NULL;
    }
}
