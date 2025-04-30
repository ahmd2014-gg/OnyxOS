[bits 16]
[global]

config_start:
    ; تهيئة الوضع المحمي
    mov ax, 0x00         ; وضع المعالج الحقيقي
    mov cr0, ax          ; تمكين الوضع المحمي
    ; المزيد من التهيئة حسب الحاجة
config_end:
    ret
