#include "screen.h"

#define VGA_MEMORY 0xB8000
#define SCREEN_WIDTH 80
#define SCREEN_HEIGHT 25

typedef struct {
    uint8_t character;
    uint8_t color;
} vga_char;

volatile vga_char* const vga = (volatile vga_char*)VGA_MEMORY;

// دالة للطباعة على الشاشة
void printk(const char* str) {
    int i = 0;
    while (str[i] != '\0') {
        vga[i].character = str[i];
        vga[i].color = 0x0F;  // اللون الأبيض على الخلفية السوداء
        i++;
    }
}

// دالة لمسح الشاشة
void clear_screen() {
    for (int i = 0; i < SCREEN_WIDTH * SCREEN_HEIGHT; i++) {
        vga[i].character = ' ';
        vga[i].color = 0x0F;  // اللون الأبيض
    }
}

// دالة لتحريك المؤشر إلى بداية السطر الجديد
void newline() {
    static int current_line = 0;
    static int current_column = 0;
    
    current_column = 0;
    current_line++;
    
    if (current_line == SCREEN_HEIGHT) {
        current_line = 0;
        clear_screen();  // إذا وصلنا إلى آخر السطر، نقوم بمسح الشاشة
    }
}
