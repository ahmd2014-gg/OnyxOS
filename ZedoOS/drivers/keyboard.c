#include "keyboard.h"
#include "screen.h"
#include "isr.h"

// دالة تهيئة لوحة المفاتيح
void keyboard_init() {
    // قم بتثبيت معالج المقاطعة للمفتاح
    register_interrupt_handler(33, keyboard_handler);  // مقاطعة 33 هي للمفتاح
}

// دالة معالجة المقاطعة عند الضغط على مفتاح
void keyboard_handler() {
    uint8_t scancode = get_scancode();
    printk("Scancode received: 0x%x\n", scancode);

    // يمكنك إضافة معالجة إضافية مثل تحويل الرموز إلى أحرف هنا
}

// دالة للحصول على رمز المفتاح
uint8_t get_scancode() {
    // قراءة من منفذ لوحة المفاتيح (عادة 0x60)
    return inb(0x60);
}
