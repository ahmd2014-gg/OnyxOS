#include "rand.h"

// قيمة البذرة لتوليد الأرقام العشوائية
static unsigned long seed = 123456789;

// دالة لتوليد رقم عشوائي
int rand() {
    // تطبيق خوارزمية توليد الأرقام العشوائية (خوارزمية LCG)
    seed = (seed * 1103515245 + 12345) & 0x7fffffff;
    return (int)(seed % 32768);  // إرجاع رقم عشوائي بين 0 و 32767
}

// دالة لضبط البذرة
void srand(unsigned long new_seed) {
    seed = new_seed;
}
