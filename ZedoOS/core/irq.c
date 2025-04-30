#include "irq.h"
#include "isr.h"
#include "screen.h"

void irq_handler(uint8_t irq, uint32_t esp) {
    printk("IRQ: Hardware interrupt %d occurred\n", irq);
    // أكواد معالجة المقاطعات العتادية هنا
}

void irq_install() {
    // تثبيت المقاطعات العتادية
    // ربط المقاطعات مع الـ ISR المناسبة
}
