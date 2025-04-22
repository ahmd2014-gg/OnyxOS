#include "timer_driver.h"
#include "screen.h"

// العداد الذي يزيد مع كل "تيك"
uint32_t tick = 0;

void timer_handler(uint32_t esp) {
    tick++;
    if (tick % 100 == 0) {
        printk("Tick count: %d\n", tick);
    }
}

// إعداد مؤقت النظام
void init_timer(uint32_t frequency) {
    uint32_t divisor = 1193180 / frequency;  // حساب القسمة لعدد التايمر
    outb(0x43, 0x36);  // إعدادات وضع التايمر
    outb(0x40, (uint8_t)(divisor & 0xFF));  // إرسال الأقل
    outb(0x40, (uint8_t)((divisor >> 8) & 0xFF));  // إرسال الأعلى
}
