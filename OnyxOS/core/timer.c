#include "timer.h"
#include "screen.h"

uint32_t tick = 0;

void timer_handler(uint32_t esp) {
    tick++;
    printk("Tick: %d\n", tick);
}

void init_timer(uint32_t frequency) {
    uint32_t divisor = 1193180 / frequency;
    outb(0x43, 0x36);  // إعدادات التايمر
    outb(0x40, (uint8_t)(divisor & 0xFF));
    outb(0x40, (uint8_t)((divisor >> 8) & 0xFF));
}
