#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <stdint.h>

void put_pixel(uint16_t x, uint16_t y, uint8_t color);
void draw_rect(uint16_t x, uint16_t y, uint16_t w, uint16_t h, uint8_t color);
void fill_rect(uint16_t x, uint16_t y, uint16_t w, uint16_t h, uint8_t color);

#endif
