#include "vga_text.h"
#include "screen.h"

#define VGA_MEMORY 0xB8000
#define SCREEN_WIDTH 80
#define SCREEN_HEIGHT 25

// هيكلية تمثل البكسل (character cell) على الشاشة
typedef struct {
    uint8_t character;
    uint8_t color;
} vga_char;

// العنوان الأساسي لذاكرة VGA
volatile vga_char* const vga = (volatile vga_char*)VGA_MEMORY;

void vga_print(const char* str) {
    int i = 0;
    while (str[i] != '\0') {
        vga[i].character = str[i];
        vga[i].color = 0x0F;  // اللون الأبيض على الخلفية السوداء
        i++;
    }
}

void vga_clear() {
    for (int i = 0; i < SCREEN_WIDTH * SCREEN_HEIGHT; i++) {
        vga[i].character = ' ';
        vga[i].color = 0x0F;
    }
}
