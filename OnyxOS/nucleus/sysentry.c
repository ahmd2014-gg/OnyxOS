#include "sysentry.h"
#include "task.h"

void syscall_handler(uint32_t syscall_number, uint32_t param1, uint32_t param2) {
    switch (syscall_number) {
        case 0: // مثال على نداء نظام - إنشاء عملية جديدة
            create_task(param1);
            break;
        case 1: // مثال على نداء نظام - الحصول على معرف العملية
            get_task_id();
            break;
        // يمكن إضافة المزيد من الأوامر هنا
        default:
            printk("Unknown syscall: %d\n", syscall_number);
            break;
    }
}
