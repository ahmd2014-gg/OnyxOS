#include "init.h"
#include "scheduler.h"
#include "panic.h"

void kernel_main() {
    // تهيئة الأنظمة الفرعية مثل إدارة الذاكرة
    init_system();

    // بدء جدولة العمليات
    start_scheduler();

    // إذا وصلنا إلى هنا فهذا يعني أن النواة فشلت في بدء جدولة العمليات
    panic("Failed to start scheduler");
}
