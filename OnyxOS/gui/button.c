// button.c
#include "graphics.h"
#include "button.h"

void draw_button(uint16_t x, uint16_t y, uint16_t w, uint16_t h, const char* label) {
    fill_rect(x, y, w, h, 0x2F);  // زر
    draw_rect(x, y, w, h, 0x00);  // حدود
    // لاحقًا: دالة ترسم label في منتصف الزر
}
