#include "context.h"

// دالة لحفظ السياق (السجل الحالي)
void save_context(Task* task) {
    __asm__ __volatile__(
        "mov %%esp, %0\n"
        : "=r"(task->stack_pointer)  // حفظ قيمة الـ ESP
    );
}

// دالة لتحميل السياق (استرجاع السجل)
void load_context(Task* task) {
    __asm__ __volatile__(
        "mov %0, %%esp\n"
        : : "r"(task->stack_pointer)  // تحميل قيمة الـ ESP
    );
}
