// graphics.c
#include "graphics.h"

#define VIDEO_MEMORY ((uint8_t*)0xA0000)
#define WIDTH 320

void put_pixel(uint16_t x, uint16_t y, uint8_t color) {
    if (x < 320 && y < 200)
        VIDEO_MEMORY[y * WIDTH + x] = color;
}

void draw_rect(uint16_t x, uint16_t y, uint16_t w, uint16_t h, uint8_t color) {
    for (uint16_t i = 0; i < w; i++) {
        put_pixel(x + i, y, color);
        put_pixel(x + i, y + h - 1, color);
    }
    for (uint16_t i = 0; i < h; i++) {
        put_pixel(x, y + i, color);
        put_pixel(x + w - 1, y + i, color);
    }
}

void fill_rect(uint16_t x, uint16_t y, uint16_t w, uint16_t h, uint8_t color) {
    for (uint16_t i = 0; i < h; i++) {
        for (uint16_t j = 0; j < w; j++) {
            put_pixel(x + j, y + i, color);
        }
    }
}
