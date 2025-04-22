#include "syscall.h"
#include "screen.h"

void syscall_handler(uint32_t syscall_number, uint32_t param1, uint32_t param2) {
    switch (syscall_number) {
        case 1:
            printk("Syscall 1 received with param1: %d, param2: %d\n", param1, param2);
            break;
        // إضافة المزيد من الحالات حسب الحاجة
        default:
            printk("Unknown syscall: %d\n", syscall_number);
            break;
    }
}
