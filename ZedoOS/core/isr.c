#include "isr.h"
#include "screen.h"

void isr_handler(uint8_t interrupt, uint32_t esp) {
    printk("ISR: Interrupt %d occurred\n", interrupt);
}

void isr_install() {
    // تثبيت روتينات الخدمة للمقاطعات
    // هنا يمكن ربط المقاطعات مع الدوال المناسبة
}
