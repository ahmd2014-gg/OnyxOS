// window.c
#include "graphics.h"
#include "window.h"

void draw_window(uint16_t x, uint16_t y, uint16_t w, uint16_t h, const char* title) {
    fill_rect(x, y, w, h, 0x17);               // خلفية النافذة
    draw_rect(x, y, w, h, 0x00);               // الحدود
    fill_rect(x, y, w, 10, 0x01);              // الشريط العلوي
    // هنا لاحقاً: دالة لرسم النص title
}
