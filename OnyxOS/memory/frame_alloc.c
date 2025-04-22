#include "frame_alloc.h"
#include "memory.h"

#define TOTAL_FRAMES 0x1000000  // فرضًا 16 مليون إطار (هذا يعتمد على النظام)
static uint8_t frames[TOTAL_FRAMES / 8];  // مصفوفة لتتبع الإطارات

// دالة لتخصيص إطار ذاكرة
void* alloc_frame() {
    for (uint32_t i = 0; i < TOTAL_FRAMES / 8; i++) {
        if (frames[i] != 0xFF) {
            for (uint32_t j = 0; j < 8; j++) {
                if (!(frames[i] & (1 << j))) {
                    frames[i] |= (1 << j);
                    return (void*)(i * 8 + j);
                }
            }
        }
    }
    return NULL;  // لا توجد إطارات متاحة
}

// دالة لتحرير إطار ذاكرة
void free_frame(void* frame) {
    uint32_t frame_num = (uint32_t)frame;
    frames[frame_num / 8] &= ~(1 << (frame_num % 8));  // تحرير الإطار
}
