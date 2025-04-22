#include "disk.h"
#include "screen.h"

// دالة لقراءة البيانات من القرص
void read_sector(uint32_t sector, void* buffer) {
    // نحن نفترض أن لدينا دالة تعالج القراءة من القرص
    // هذه الطريقة هي مجرد مثال توضيحي
    // سيتم استخدام التعليمات المناسبة لقراءة القطاع
    printk("Reading sector %d into buffer\n", sector);
    
    // قراءة البيانات من القرص ونسخها إلى الـ buffer
    // مثال على محاكاة القراءة من القرص
    // في الحقيقة ستكون هذه القراءة أكثر تعقيداً وتعتمد على آلية معينة (مثل IDE أو SATA)
}

// دالة لتحميل القطاع الأول من القرص
void load_first_sector() {
    char buffer[512];  // كل قطاع يحتوي على 512 بايت
    read_sector(0, buffer);
    printk("First sector loaded\n");
}
